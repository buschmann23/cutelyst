#include "formhtmlelement_p.h"

using namespace Cutelyst;

FormHtmlElementPrivate::FormHtmlElementPrivate(FormHtmlElement *q) :
    q_ptr(q)
{

}

FormHtmlElementPrivate::~FormHtmlElementPrivate()
{

}

FormHtmlElement::FormHtmlElement(QObject *parent) :
    QObject(parent), d_ptr(new FormHtmlElementPrivate(this))
{

}

FormHtmlElement::FormHtmlElement(FormHtmlElementPrivate &dd, QObject *parent) :
    QObject(parent), d_ptr(&dd)
{

}

FormHtmlElement::~FormHtmlElement()
{

}

QString FormHtmlElement::htmlId() const
{
    Q_D(const FormHtmlElement);
    return d->htmlId;
}

void FormHtmlElement::setHtmlId(const QString &htmlId)
{
    Q_D(FormHtmlElement);
    d->htmlId = htmlId;
}

QString FormHtmlElement::htmlClass() const
{
    Q_D(const FormHtmlElement);
    return d->htmlClass;
}

void FormHtmlElement::setHtmlClass(const QString &htmlClass)
{
    Q_D(FormHtmlElement);
    d->htmlClass = htmlClass;
}

QString FormHtmlElement::accesskey() const
{
    Q_D(const FormHtmlElement);
    return d->accesskey;
}

void FormHtmlElement::setAccesskey(const QString &accesskey)
{
    Q_D(FormHtmlElement);
    d->accesskey = accesskey;
}

bool FormHtmlElement::isContenteditable() const
{
    Q_D(const FormHtmlElement);
    return d->contenteditable;
}

void FormHtmlElement::setContenteditable(bool contenteditable)
{
    Q_D(FormHtmlElement);
    d->contenteditable = contenteditable;
}

QString FormHtmlElement::contextmenu() const
{
    Q_D(const FormHtmlElement);
    return d->contextmenu;
}

void FormHtmlElement::setContextmenu(const QString &contextmenu)
{
    Q_D(FormHtmlElement);
    d->contextmenu = contextmenu;
}

Cutelyst::FormHtmlElement::TextDirection FormHtmlElement::dir() const
{
    Q_D(const FormHtmlElement);
    return d->dir;
}

void FormHtmlElement::setDir(Cutelyst::FormHtmlElement::TextDirection dir)
{
    Q_D(FormHtmlElement);
    d->dir = dir;
}

Cutelyst::FormHtmlElement::DraggableState FormHtmlElement::draggable() const
{
    Q_D(const FormHtmlElement);
    return d->draggable;
}

void FormHtmlElement::setDraggable(Cutelyst::FormHtmlElement::DraggableState draggable)
{
    Q_D(FormHtmlElement);
    d->draggable = draggable;
}

bool FormHtmlElement::isHidden() const
{
    Q_D(const FormHtmlElement);
    return d->hidden;
}

void FormHtmlElement::setHidden(bool hidden)
{
    Q_D(FormHtmlElement);
    d->hidden = hidden;
}

QString FormHtmlElement::lang() const
{
    Q_D(const FormHtmlElement);
    return d->lang;
}

void FormHtmlElement::setLang(const QString &lang)
{
    Q_D(FormHtmlElement);
    d->lang = lang;
}

bool FormHtmlElement::spellcheck() const
{
    Q_D(const FormHtmlElement);
    return d->spellcheck;
}

void FormHtmlElement::setSpellcheck(bool spellcheck)
{
    Q_D(FormHtmlElement);
    d->spellcheck = spellcheck;
}

QString FormHtmlElement::style() const
{
    Q_D(const FormHtmlElement);
    return d->style;
}

void FormHtmlElement::setStyle(const QString &style)
{
    Q_D(FormHtmlElement);
    d->style = style;
}

int FormHtmlElement::tabindex() const
{
    Q_D(const FormHtmlElement);
    return d->tabindex;
}

void FormHtmlElement::setTabindex(int tabindex)
{
    Q_D(FormHtmlElement);
    d->tabindex = tabindex;
}

QString FormHtmlElement::title() const
{
    Q_D(const FormHtmlElement);
    return d->title;
}

void FormHtmlElement::setTitle(const QString &title)
{
    Q_D(FormHtmlElement);
    d->title = title;
}

#include "moc_formhtmlelement.cpp"
