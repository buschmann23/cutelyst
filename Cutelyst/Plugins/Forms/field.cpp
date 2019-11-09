#include "field_p.h"

using namespace Cutelyst;

FieldPrivate::FieldPrivate(Field *q) :
    FormHtmlElementPrivate(q)
{

}

Field::Field(QObject *parent) :
    FormHtmlElement(* new FieldPrivate(this), parent)
{

}

Field::Field(FieldPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

Field::~Field()
{

}

Cutelyst::Field::Type Field::type() const
{
    Q_D(const Field);
    return d->type;
}

void Field::setType(Cutelyst::Field::Type type)
{
    Q_D(Field);
    d->type = type;
}

QString Field::name() const
{
    Q_D(const Field);
    return d->name;
}

void Field::setName(const QString &name)
{
    Q_D(Field);
    d->name = name;
}

QString Field::label() const
{
    Q_D(const Field);
    return d->label;
}

void Field::setLabel(const QString &label)
{
    Q_D(Field);
    d->label = label;
}

QString Field::description() const
{
    Q_D(const Field);
    return d->description;
}

void Field::setDescription(const QString &description)
{
    Q_D(Field);
    d->description = description;
}

#include "moc_field.cpp"
