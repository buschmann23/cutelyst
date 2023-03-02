#include "option_p.h"

using namespace Cutelyst;

OptionPrivate::OptionPrivate(Option *q) :
    SelectContentPrivate(q)
{

}

Option::Option(QObject *parent) :
    SelectContent(* new OptionPrivate(this), parent)
{

}

Option::Option(OptionPrivate &dd, QObject *parent) :
    SelectContent(dd, parent)
{

}

Option::~Option()
{

}

bool Option::isSelected() const
{
    Q_D(const Option);
    return d->selected;
}

void Option::setSelected(bool selected)
{
    Q_D(Option);
    d->selected = selected;
}

QString Option::text() const
{
    Q_D(const Option);
    return d->text;
}

void Option::setText(const QString &text)
{
    Q_D(Option);
    d->text = text;
}

QString Option::value() const
{
    Q_D(const Option);
    return d->value;
}

void Option::setValue(const QString &value)
{
    Q_D(Option);
    d->value = value;
}

#include "moc_option.cpp"
