#include "select_p.h"

using namespace Cutelyst;

SelectPrivate::SelectPrivate(Select *q) :
    FieldPrivate(q)
{
    type = Field::Select;
}

Select::Select(QObject *parent) :
    Field(* new SelectPrivate(this), parent)
{

}

Select::Select(SelectPrivate &dd, QObject *parent) :
    Field(dd, parent)
{

}

Select::~Select()
{

}

bool Select::multiple() const
{
    Q_D(const Select);
    return d->multiple;
}

void Select::setMultiple(bool multiple)
{
    Q_D(Select);
    d->multiple = multiple;
}

int Select::size() const
{
    Q_D(const Select);
    return d->size;
}

void Select::setSize(int size)
{
    Q_D(Select);
    d->size = size;
}

QQmlListProperty<Cutelyst::SelectContent> Select::options()
{
    Q_D(Select);
    return {this, &d->content};
}

void Select::appendContent(SelectContent *content)
{
    Q_D(Select);
    d->content.push_back(content);
}

QList<SelectContent*>::size_type Select::contentCount() const
{
    Q_D(const Select);
    return static_cast<int>(d->content.size());
}

SelectContent* Select::content(QList<SelectContent*>::size_type idx) const
{
    Q_D(const Select);
    if (idx < d->content.size()) {
        return d->content.at(idx);
    } else {
        return nullptr;
    }
}

void Select::clearContent()
{
    Q_D(Select);
    qDeleteAll(d->content);
    d->content.clear();
}

QList<SelectContent*> Select::contentList() const
{
    Q_D(const Select);
    return d->content;
}

#include "moc_select.cpp"
