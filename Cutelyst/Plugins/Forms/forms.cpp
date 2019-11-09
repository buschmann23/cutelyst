#include "forms_p.h"

#include <Cutelyst/Application>
#include <Cutelyst/Context>

#include <QStringList>
#include <QLoggingCategory>
#include <QFileInfo>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlError>

#ifdef PLUGIN_CSRFPROTECTION_ENABLED
#include <Cutelyst/Plugins/CSRFProtection/CSRFProtection>
#endif

Q_LOGGING_CATEGORY(C_FORMS, "cutelyst.plugin.forms", QtWarningMsg)

using namespace Cutelyst;

static thread_local Forms *forms = nullptr;

FormsContextObject::FormsContextObject(const QString &form, Context *c) : QObject(c), m_form(form), m_c(c)
{

}

QString FormsContextObject::cTr(const QString &sourceText, const QString &disambiguation, int n) const
{
    return m_c->translate(m_form.toUtf8().constData(), sourceText.toUtf8().constData(), disambiguation.toUtf8().constData(), n);
}

QUrl FormsContextObject::cUriFor(const QString &path, const QStringList &args, const QVariantMap &queryValues) const
{
    if (queryValues.empty()) {
        return m_c->uriFor(path, args);
    } else {
        ParamsMultiMap map;
        auto it = queryValues.cbegin();
        while (it != queryValues.cend()) {
            map.insert(it.key(), it.value().toString());
            it++;
        }
        return m_c->uriFor(path, args, map);
    }
}

QString FormsContextObject::cCsrfToken()
{
#ifdef PLUGIN_CSRFPROTECTION_ENABLED
    return QString::fromLatin1(CSRFProtection::getToken(m_c));
#else
    qCWarning(C_FORMS, "%s", "The CSRF protection plugin has not been built.");
    return QString();
#endif
}

Forms::Forms(Application *parent) : Plugin(parent), d_ptr(new FormsPrivate)
{
    Q_D(Forms);
    d->engine.setOutputWarningsToStandardError(false);
    connect(&d->engine, &QQmlEngine::warnings, &d->engine, [](const QList<QQmlError> &warnings){
        for (const QQmlError &warning : warnings) {
            qCWarning(C_FORMS) << warning.toString();
        }
    });
}

Forms::~Forms()
{
    delete d_ptr;
}

void Forms::addImportPath(const QString &path)
{
    Q_D(Forms);
    d->engine.addImportPath(path);
}

QStringList Forms::importPaths() const
{
    Q_D(const Forms);
    return d->engine.importPathList();
}

void Forms::setIncludePaths(const QStringList &paths)
{
    Q_D(Forms);
    d->includePaths = paths;
}

QStringList Forms::includePaths() const
{
    Q_D(const Forms);
    return d->includePaths;
}

Form* Forms::getForm(const QString &name, Context *c)
{
    if (!forms) {
        qCCritical(C_FORMS) << "Forms plugin not registered";
        return nullptr;
    }

    QFileInfo fi;
    for (const QString &path : forms->includePaths()) {
        const QString fn = path + QLatin1Char('/') + name + QLatin1String(".qml");
        fi.setFile(fn);
        if (fi.exists()) {
            break;
        }
    }

    if (!fi.exists()) {
        qCWarning(C_FORMS) << "Can not find form" << name;
        return nullptr;
    }

    QQmlContext qmlContext(&forms->d_func()->engine);
    qmlContext.setContextObject(new FormsContextObject(name, c));
    auto it = c->stash().cbegin();
    while (it != c->stash().cend()) {
        qmlContext.setContextProperty(it.key(), it.value());
        it++;
    }

    QQmlComponent component(&forms->d_func()->engine, fi.filePath());
    auto formObject = component.create(&qmlContext);
    if (!formObject) {
        qCWarning(C_FORMS) << "Failed to load form" << name << "from QML file:" << component.errorString();
        return nullptr;
    }
    auto realFormObject = qobject_cast<Form*>(formObject);
    if (!realFormObject) {
        qCWarning(C_FORMS) << "Failed to load form" << name << "from QML file. Maybe the root item in the QML file is not of type Form.";
        return nullptr;
    }
    realFormObject->setObjectName(name);
    realFormObject->setParent(c);
    return realFormObject;
}

bool Forms::setup(Application *app)
{
    connect(app, &Application::postForked, this, [](Application *app){
        forms = app->plugin<Forms *>();
    });

    return true;
}

#include "moc_forms.cpp"
