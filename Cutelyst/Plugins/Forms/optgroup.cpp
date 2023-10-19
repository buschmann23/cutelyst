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
    Q_D(Optgroup);
    return {this, &d->options};
}

void Optgroup::appendOption(Option *option)
{
    Q_D(Optgroup);
    d->options.push_back(option);
}

QList<Option*>::size_type Optgroup::optionCount() const
{
    Q_D(const Optgroup);
    return static_cast<int>(d->options.size());
}

Option* Optgroup::option(QList<Option*>::size_type idx) const
{
    Q_D(const Optgroup);
    if (idx < d->options.size()) {
        return d->options.at(idx);
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

QList<Option*> Optgroup::optionList() const
{
    Q_D(const Optgroup);
    return d->options;
}

#include "moc_optgroup.cpp"
