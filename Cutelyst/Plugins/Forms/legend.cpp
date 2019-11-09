#include "legend_p.h"

using namespace Cutelyst;

LegendPrivate::LegendPrivate(Legend *q) :
    FormHtmlElementPrivate(q)
{

}

Legend::Legend(QObject *parent) :
    FormHtmlElement(* new LegendPrivate(this), parent)
{

}

Legend::Legend(LegendPrivate &dd, QObject *parent) :
    FormHtmlElement(dd, parent)
{

}

Legend::~Legend()
{

}

QString Legend::text() const
{
    Q_D(const Legend);
    return d->text;
}

void Legend::setText(const QString &text)
{
    Q_D(Legend);
    d->text = text;
}

#include "moc_legend.cpp"
