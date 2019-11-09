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

QQmlListProperty<Cutelyst::Fieldset> Form::fieldsets()
{
    return QQmlListProperty<Fieldset>(this, this,
                                      [](QQmlListProperty<Fieldset>* list, Fieldset *fieldset){
        reinterpret_cast<Form*>(list->data)->appendFieldset(fieldset);
    },
                                      [](QQmlListProperty<Fieldset>* list){
        return reinterpret_cast<Form*>(list->data)->fieldsetCount();
    },
                                      [](QQmlListProperty<Fieldset> *list, int idx){
        return reinterpret_cast<Form*>(list->data)->fieldset(idx);
    },
                                      [](QQmlListProperty<Fieldset> *list){
        reinterpret_cast<Form*>(list->data)->clearFieldsets();
    });
}

void Form::appendFieldset(Fieldset *fieldset)
{
    Q_D(Form);
    d->fieldsets.push_back(fieldset);
}

int Form::fieldsetCount() const
{
    Q_D(const Form);
    return static_cast<int>(d->fieldsets.size());
}

Fieldset* Form::fieldset(int idx) const
{
    Q_D(const Form);
    std::vector<Fieldset*>::size_type _idx = static_cast<std::vector<Fieldset*>::size_type>(idx);
    if (idx > -1 && _idx < d->fieldsets.size()) {
        return d->fieldsets.at(_idx);
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

std::vector<Fieldset*> Form::fieldsetList() const
{
    Q_D(const Form);
    return d->fieldsets;
}

QQmlListProperty<Cutelyst::Button> Form::buttons()
{
    return QQmlListProperty<Button>(this, this,
                                      [](QQmlListProperty<Button>* list, Button *button){
        reinterpret_cast<Form*>(list->data)->appendButton(button);
    },
                                      [](QQmlListProperty<Button>* list){
        return reinterpret_cast<Form*>(list->data)->buttonCount();
    },
                                      [](QQmlListProperty<Button> *list, int idx){
        return reinterpret_cast<Form*>(list->data)->button(idx);
    },
                                      [](QQmlListProperty<Button> *list){
        reinterpret_cast<Form*>(list->data)->clearButtons();
    });
}

void Form::appendButton(Button *button)
{
    Q_D(Form);
    d->buttons.push_back(button);
}

int Form::buttonCount() const
{
    Q_D(const Form);
    return static_cast<int>(d->buttons.size());
}

Button* Form::button(int idx) const
{
    Q_D(const Form);
    std::vector<Button*>::size_type _idx = static_cast<std::vector<Button*>::size_type>(idx);
    if (idx > -1 && _idx < d->buttons.size()) {
        return d->buttons.at(_idx);
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

std::vector<Button*> Form::buttonList() const
{
    Q_D(const Form);
    return d->buttons;
}

#include "moc_form.cpp"
