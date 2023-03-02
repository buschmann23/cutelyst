#include <Cutelyst/Plugins/Forms/formhtmlelement.h>
#include <Cutelyst/Plugins/Forms/form.h>
#include <Cutelyst/Plugins/Forms/fieldset.h>
#include <Cutelyst/Plugins/Forms/legend.h>
#include <Cutelyst/Plugins/Forms/button.h>
#include <Cutelyst/Plugins/Forms/field.h>
#include <Cutelyst/Plugins/Forms/select.h>
#include <Cutelyst/Plugins/Forms/selectcontent.h>
#include <Cutelyst/Plugins/Forms/option.h>
#include <Cutelyst/Plugins/Forms/optgroup.h>

#include <QtQml>

class QmlCutelystFormsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid FILE "plugin.json")
public:
    QmlCutelystFormsPlugin(QObject *parent = nullptr) : QQmlExtensionPlugin(parent) {}

    virtual void registerTypes(const char *uri) override
    {
        if (Q_LIKELY(QLatin1String(uri) == QLatin1String("org.cutelyst.forms"))) {

            const int major = 1;
            const int minor = 0;

            // @uri org.cutelyst.forms
            qmlRegisterAnonymousType<Cutelyst::FormHtmlElement>(uri, major);
            qmlRegisterType<Cutelyst::Form>(uri, major, minor, "Form");
            qmlRegisterType<Cutelyst::Fieldset>(uri, major, minor, "Fieldset");
            qmlRegisterType<Cutelyst::Legend>(uri, major, minor, "Legend");
            qmlRegisterType<Cutelyst::Button>(uri, major, minor, "Button");
            qmlRegisterType<Cutelyst::Field>(uri, major, minor, "Field");
            qmlRegisterType<Cutelyst::Select>(uri, major, minor, "Select");
            qmlRegisterAnonymousType<Cutelyst::SelectContent>(uri, major);
            qmlRegisterType<Cutelyst::Option>(uri, major, minor, "Option");
            qmlRegisterType<Cutelyst::Optgroup>(uri, major, minor, "Optgroup");

        } else {
            qCritical("Unsupported URI given to load Cutelyst Forms QML plugin: %s", uri);
        }
    }
};

#include "qmlcutelystformsplugin.moc"
