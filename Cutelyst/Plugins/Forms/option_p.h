#ifndef C_FORMS_OPTION_P_H
#define C_FORMS_OPTION_P_H

#include "option.h"
#include "selectcontent_p.h"

namespace Cutelyst {

class OptionPrivate : public SelectContentPrivate
{
public:
    OptionPrivate(Option *q);

    QString text;
    QString value;
    bool selected;

private:
    Q_DECLARE_PUBLIC(Option)
    Q_DISABLE_COPY(OptionPrivate)
};

}

#endif // C_FORMS_OPTION_P_H
