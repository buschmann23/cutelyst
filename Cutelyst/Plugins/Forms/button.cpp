#include "button_p.h"

using namespace Cutelyst;

ButtonPrivate::ButtonPrivate(Button *q) :
    FormHtmlElementPrivate(q)
{

}

Button::Button(QObject *parent) :
    FormHtmlElement(* new ButtonPrivate(this), parent)
{

}

Button::Button(ButtonPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

Button::~Button()
{

}

bool Button::autofocus() const
{
    Q_D(const Button);
    return d->autocofus;
}

void Button::setAutofocus(bool autofocus)
{
    Q_D(Button);
    d->autocofus = autofocus;
}

bool Button::isDisabled() const
{
    Q_D(const Button);
    return d->disabled;
}

void Button::setDisabled(bool disabled)
{
    Q_D(Button);
    d->disabled = disabled;
}

QString Button::name() const
{
    Q_D(const Button);
    return d->name;
}

void Button::setName(const QString &name)
{
    Q_D(Button);
    d->name = name;
}

Cutelyst::Button::Type Button::type() const
{
    Q_D(const Button);
    return d->type;
}

void Button::setType(Cutelyst::Button::Type type)
{
    Q_D(Button);
    d->type = type;
}

QString Button::value() const
{
    Q_D(const Button);
    return d->value;
}

void Button::setValue(const QString &value)
{
    Q_D(Button);
    d->value = value;
}

QString Button::text() const
{
    Q_D(const Button);
    return d->text;
}

void Button::setText(const QString &text)
{
    Q_D(Button);
    d->text = text;
}

#include "moc_button.cpp"
