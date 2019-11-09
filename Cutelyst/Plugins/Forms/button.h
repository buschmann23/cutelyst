#ifndef C_BUTTON_H
#define C_BUTTON_H

#include "formhtmlelement.h"
#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include <QUrl>

namespace Cutelyst {

class ButtonPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Button : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(bool autofocus READ autofocus WRITE setAutofocus)
    Q_PROPERTY(bool disabled READ isDisabled WRITE setDisabled)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(Cutelyst::Button::Type type READ type WRITE setType)
    Q_PROPERTY(QString value READ value WRITE setValue)
    Q_PROPERTY(QString text READ text WRITE setText)
public:
    explicit Button(QObject *parent = nullptr);
    virtual ~Button() override;

    enum Type {
        Btn     = 0,
        Submit,
        Reset
    };

    bool autofocus() const;
    void setAutofocus(bool autofocus);

    bool isDisabled() const;
    void setDisabled(bool disabled);

    QString name() const;
    void setName(const QString &name);

    Cutelyst::Button::Type type() const;
    void setType(Cutelyst::Button::Type type);

    QString value() const;
    void setValue(const QString &value);

    QString text() const;
    void setText(const QString &text);

protected:
    Button(ButtonPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Button)
    Q_DECLARE_PRIVATE(Button)
};

}

#endif // C_BUTTON_H
