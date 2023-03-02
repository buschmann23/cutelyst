#include "fieldset_p.h"

using namespace Cutelyst;

FieldsetPrivate::FieldsetPrivate(Fieldset *q) :
    FormHtmlElementPrivate(q)
{

}

Fieldset::Fieldset(QObject *parent) :
    FormHtmlElement(* new FieldsetPrivate(this), parent)
{

}

Fieldset::Fieldset(FieldsetPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

Fieldset::~Fieldset()
{

}

bool Fieldset::isDisabled() const
{
    Q_D(const Fieldset);
    return d->disabled;
}

void Fieldset::setDisabled(bool disabled)
{
    Q_D(Fieldset);
    d->disabled = disabled;
}

QString Fieldset::form() const
{
    Q_D(const Fieldset);
    return d->form;
}

void Fieldset::setForm(const QString &form)
{
    Q_D(Fieldset);
    d->form = form;
}

QString Fieldset::name() const
{
    Q_D(const Fieldset);
    return d->name;
}

void Fieldset::setName(const QString &name)
{
    Q_D(Fieldset);
    d->name = name;
}

QString Fieldset::description() const
{
    Q_D(const Fieldset);
    return d->description;
}

void Fieldset::setDescription(const QString &description)
{
    Q_D(Fieldset);
    d->description = description;
}

Cutelyst::Legend* Fieldset::legend() const
{
    Q_D(const Fieldset);
    return d->legend;
}

void Fieldset::setLegend(Cutelyst::Legend *legend)
{
    Q_D(Fieldset);
    d->legend = legend;
}

QQmlListProperty<Cutelyst::Field> Fieldset::fields()
{
    return QQmlListProperty<Field>(this, this,
                                      [](QQmlListProperty<Field>* list, Field *field){
        reinterpret_cast<Fieldset*>(list->data)->appendField(field);
    },
                                      [](QQmlListProperty<Field>* list){
        return reinterpret_cast<Fieldset*>(list->data)->fieldCount();
    },
                                      [](QQmlListProperty<Field> *list, int idx){
        return reinterpret_cast<Fieldset*>(list->data)->field(idx);
    },
                                      [](QQmlListProperty<Field> *list){
        reinterpret_cast<Fieldset*>(list->data)->clearFields();
    });
}

void Fieldset::appendField(Field *field)
{
    Q_D(Fieldset);
    d->fields.push_back(field);
}

int Fieldset::fieldCount() const
{
    Q_D(const Fieldset);
    return static_cast<int>(d->fields.size());
}

Field* Fieldset::field(int idx) const
{
    Q_D(const Fieldset);
    std::vector<Field*>::size_type _idx = static_cast<std::vector<Field*>::size_type>(idx);
    if (idx > -1 && _idx < d->fields.size()) {
        return d->fields.at(_idx);
    } else {
        return nullptr;
    }
}

void Fieldset::clearFields()
{
    Q_D(Fieldset);
    qDeleteAll(d->fields);
    d->fields.clear();
}

std::vector<Field*> Fieldset::fieldList() const
{
    Q_D(const Fieldset);
    return d->fields;
}

#include "moc_fieldset.cpp"
