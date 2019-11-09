#include "optgroup_p.h"

using namespace Cutelyst;

OptgroupPrivate::OptgroupPrivate(Optgroup *q) :
    SelectContentPrivate(q)
{

}

Optgroup::Optgroup(QObject *parent) :
    SelectContent(* new OptgroupPrivate(this), parent)
{

}

Optgroup::Optgroup(OptgroupPrivate &dd, QObject *parent) :
    SelectContent(dd, parent)
{

}

Optgroup::~Optgroup()
{

}

QQmlListProperty<Cutelyst::Option> Optgroup::options()
{
    return QQmlListProperty<Option>(this, this,
                                      [](QQmlListProperty<Option>* list, Option *option){
        reinterpret_cast<Optgroup*>(list->data)->appendOption(option);
    },
                                      [](QQmlListProperty<Option>* list){
        return reinterpret_cast<Optgroup*>(list->data)->optionCount();
    },
                                      [](QQmlListProperty<Option> *list, int idx){
        return reinterpret_cast<Optgroup*>(list->data)->option(idx);
    },
                                      [](QQmlListProperty<Option> *list){
        reinterpret_cast<Optgroup*>(list->data)->clearOptions();
    });
}

void Optgroup::appendOption(Option *option)
{
    Q_D(Optgroup);
    d->options.push_back(option);
}

int Optgroup::optionCount() const
{
    Q_D(const Optgroup);
    return static_cast<int>(d->options.size());
}

Option* Optgroup::option(int idx) const
{
    Q_D(const Optgroup);
    const std::vector<Option*>::size_type _idx = static_cast<std::vector<Option*>::size_type>(idx);
    if (idx > -1 && _idx < d->options.size()) {
        return d->options.at(_idx);
    } else {
        return nullptr;
    }
}

void Optgroup::clearOptions()
{
    Q_D(Optgroup);
    qDeleteAll(d->options);
    d->options.clear();
}

std::vector<Option*> Optgroup::optionList() const
{
    Q_D(const Optgroup);
    return d->options;
}

#include "moc_optgroup.cpp"
