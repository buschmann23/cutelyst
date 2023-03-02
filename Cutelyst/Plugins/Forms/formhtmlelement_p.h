#ifndef C_FORMHTMLELEMENT_P_H
#define C_FORMHTMLELEMENT_P_H

#include "formhtmlelement.h"

namespace Cutelyst {

class FormHtmlElementPrivate
{
public:
    FormHtmlElementPrivate(FormHtmlElement *q);

    virtual ~FormHtmlElementPrivate();

    FormHtmlElement *q_ptr;

    QString htmlId;
    QString htmlClass;
    QString accesskey;
    QString contextmenu;
    QString lang;
    QString style;
    QString title;

    int tabindex = -2;
    FormHtmlElement::TextDirection dir = FormHtmlElement::AutoDir;
    FormHtmlElement::DraggableState draggable = FormHtmlElement::DragAuto;
    bool contenteditable = false;
    bool hidden = false;
    bool spellcheck = true;

private:
    Q_DECLARE_PUBLIC(FormHtmlElement)
    Q_DISABLE_COPY(FormHtmlElementPrivate)
};

}

#endif // C_FORMHTMLELEMENT_P_H
