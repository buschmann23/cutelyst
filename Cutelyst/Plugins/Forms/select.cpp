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
    return QQmlListProperty<SelectContent>(this, this,
                                      [](QQmlListProperty<SelectContent>* list, SelectContent *content){
        reinterpret_cast<Select*>(list->data)->appendContent(content);
    },
                                      [](QQmlListProperty<SelectContent>* list){
        return reinterpret_cast<Select*>(list->data)->contentCount();
    },
                                      [](QQmlListProperty<SelectContent> *list, int idx){
        return reinterpret_cast<Select*>(list->data)->content(idx);
    },
                                      [](QQmlListProperty<SelectContent> *list){
        reinterpret_cast<Select*>(list->data)->clearContent();
    });
}

void Select::appendContent(SelectContent *content)
{
    Q_D(Select);
    d->content.push_back(content);
}

int Select::contentCount() const
{
    Q_D(const Select);
    return static_cast<int>(d->content.size());
}

SelectContent* Select::content(int idx) const
{
    Q_D(const Select);
    std::vector<SelectContent*>::size_type _idx = static_cast<std::vector<SelectContent*>::size_type>(idx);
    if (idx > -1 && _idx < d->content.size()) {
        return d->content.at(_idx);
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

std::vector<SelectContent*> Select::contentList() const
{
    Q_D(const Select);
    return d->content;
}

#include "moc_select.cpp"
