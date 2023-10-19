#include "form_p.h"

using namespace Cutelyst;

FormPrivate::FormPrivate(Form *q) :
    FormHtmlElementPrivate(q)
{

}

Form::Form(QObject *parent) :
    FormHtmlElement(* new FormPrivate(this), parent)
{

}

Form::Form(FormPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

Form::~Form()
{

}

QUrl Form::action() const
{
    Q_D(const Form);
    return d->action;
}

void Form::setAction(const QUrl &action)
{
    Q_D(Form);
    d->action = action;
}

QStringList Form::acceptCharset() const
{
    Q_D(const Form);
    return d->acceptCharset;
}

void Form::setAcceptCharset(const QStringList &acceptCharset)
{
    Q_D(Form);
    d->acceptCharset = acceptCharset;
}

bool Form::autocomplete() const
{
    Q_D(const Form);
    return d->autocomplete;
}

void Form::setAutocomplete(bool autocomplete)
{
    Q_D(Form);
    d->autocomplete = autocomplete;
}

Cutelyst::Form::EncType Form::enctype() const
{
    Q_D(const Form);
    return d->enctype;
}

void Form::setEnctype(Cutelyst::Form::EncType enctype)
{
    Q_D(Form);
    d->enctype = enctype;
}

Cutelyst::Form::Method Form::method() const
{
    Q_D(const Form);
    return d->method;
}

void Form::setMethod(Cutelyst::Form::Method method)
{
    Q_D(Form);
    d->method = method;
}

QString Form::name() const
{
    Q_D(const Form);
    return d->name;
}

void Form::setName(const QString &name)
{
    Q_D(Form);
    d->name = name;
}

bool Form::novalidate() const
{
    Q_D(const Form);
    return d->novalidate;
}

void Form::setNovalidate(bool novalidate)
{
    Q_D(Form);
    d->novalidate = novalidate;
}

Cutelyst::Form::Target Form::target() const
{
    Q_D(const Form);
    return d->target;
}

void Form::setTarget(Cutelyst::Form::Target target)
{
    Q_D(Form);
    d->target = target;
}

QString Form::label() const
{
    Q_D(const Form);
    return d->label;
}

void Form::setLabel(const QString &label)
{
    Q_D(Form);
    d->label = label;
}

QString Form::description() const
{
    Q_D(const Form);
    return d->description;
}

void Form::setDescription(const QString &description)
{
    Q_D(Form);
    d->description = description;
}

Cutelyst::Form::Type Form::type() const
{
    Q_D(const Form);
    return d->type;
}

void Form::setType(Cutelyst::Form::Type type)
{
    Q_D(Form);
    d->type = type;
}

QQmlListProperty<Cutelyst::Fieldset> Form::fieldsets()
{
    Q_D(Form);
    return {this, &d->fieldsets};
}

void Form::appendFieldset(Fieldset *fieldset)
{
    Q_D(Form);
    d->fieldsets.push_back(fieldset);
}

QList<Fieldset*>::size_type Form::fieldsetCount() const
{
    Q_D(const Form);
    return d->fieldsets.size();
}

Fieldset* Form::fieldset(QList<Fieldset*>::size_type idx) const
{
    Q_D(const Form);
    if (idx < d->fieldsets.size()) {
        return d->fieldsets.at(idx);
    } else {
        return nullptr;
    }
}

void Form::clearFieldsets()
{
    Q_D(Form);
    qDeleteAll(d->fieldsets);
    d->fieldsets.clear();
}

QList<Fieldset*> Form::fieldsetList() const
{
    Q_D(const Form);
    return d->fieldsets;
}

QQmlListProperty<Cutelyst::Button> Form::buttons()
{
    Q_D(Form);
    return {this, &d->buttons};
}

void Form::appendButton(Button *button)
{
    Q_D(Form);
    d->buttons.push_back(button);
}

QList<Button*>::size_type Form::buttonCount() const
{
    Q_D(const Form);
    return d->buttons.size();
}

Button* Form::button(QList<Button*>::size_type idx) const
{
    Q_D(const Form);
    if (idx < d->buttons.size()) {
        return d->buttons.at(idx);
    } else {
        return nullptr;
    }
}

void Form::clearButtons()
{
    Q_D(Form);
    qDeleteAll(d->buttons);
    d->buttons.clear();
}

QList<Button*> Form::buttonList() const
{
    Q_D(const Form);
    return d->buttons;
}

#include "moc_form.cpp"
