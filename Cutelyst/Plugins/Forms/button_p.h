#ifndef C_BUTTON_P_H
#define C_BUTTON_P_H

#include "button.h"
#include "formhtmlelement_p.h"

namespace Cutelyst {

class ButtonPrivate : public FormHtmlElementPrivate
{
public:
    ButtonPrivate(Button *q);

    QString name;
    QString value;
    QString text;

    Button::Type type = Button::Submit;

    bool autocofus = false;
    bool disabled = false;

private:
    Q_DECLARE_PUBLIC(Button)
    Q_DISABLE_COPY(ButtonPrivate)
};

}

#endif // C_BUTTON_P_H
