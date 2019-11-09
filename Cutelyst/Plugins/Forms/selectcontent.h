#ifndef C_FORMS_SELECTCONTENT_H
#define C_FORMS_SELECTCONTENT_H

#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include "formhtmlelement.h"

namespace Cutelyst {

class SelectContentPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT SelectContent : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(bool disabled READ isDisabled WRITE setDisabled)
    Q_PROPERTY(QString label READ label WRITE setLabel)
public:
    explicit SelectContent(QObject *parent = nullptr);
    virtual ~SelectContent() override;

    bool isDisabled() const;
    void setDisabled(bool disabled);

    QString label() const;
    void setLabel(const QString &label);

protected:
    SelectContent(SelectContentPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(SelectContent)
    Q_DECLARE_PRIVATE(SelectContent)
};

}

#endif // C_FORMS_SELECTCONTENT_H
