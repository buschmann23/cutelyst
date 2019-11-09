#ifndef C_FORMS_P_H
#define C_FORMS_P_H

#include "forms.h"
#include <QQmlEngine>

namespace Cutelyst {

class FormsPrivate
{
public:
    QQmlEngine engine;
    QStringList includePaths;
};

class FormsContextObject : public QObject
{
    Q_OBJECT
public:
    explicit FormsContextObject(const QString &form, Context *c);

    Q_INVOKABLE QString cTr(const QString &sourceText, const QString &disambiguation = QString(), int n = -1) const;
    Q_INVOKABLE QUrl cUriFor(const QString &path = QString(), const QStringList &args = QStringList(), const QVariantMap &queryValues = QVariantMap()) const;
    Q_INVOKABLE QString cCsrfToken();

private:
    const QString m_form;
    Context *m_c;
};

}

#endif // C_FORMS_P_H
