#include "selectcontent_p.h"

using namespace Cutelyst;

SelectContentPrivate::SelectContentPrivate(SelectContent *q) :
    FormHtmlElementPrivate(q)
{

}

SelectContent::SelectContent(QObject *parent) :
    FormHtmlElement(* new SelectContentPrivate(this), parent)
{

}

SelectContent::SelectContent(SelectContentPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

SelectContent::~SelectContent()
{

}

bool SelectContent::isDisabled() const
{
    Q_D(const SelectContent);
    return d->disabled;
}

void SelectContent::setDisabled(bool disabled)
{
    Q_D(SelectContent);
    d->disabled = disabled;
}

QString SelectContent::label() const
{
    Q_D(const SelectContent);
    return d->label;
}

void SelectContent::setLabel(const QString &label)
{
    Q_D(SelectContent);
    d->label = label;
}

#include "moc_selectcontent.cpp"
