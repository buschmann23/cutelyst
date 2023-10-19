#ifndef C_FORMS_SELECT_P_H
#define C_FORMS_SELECT_P_H

#include "select.h"
#include "field_p.h"

namespace Cutelyst {

class SelectPrivate : public FieldPrivate
{
public:
    SelectPrivate(Select *q);

    QList<SelectContent*> content;
    int size = 0;
    bool multiple = false;

private:
    Q_DECLARE_PUBLIC(Select)
    Q_DISABLE_COPY(SelectPrivate)
};

}

#endif // C_FORMS_SELECT_P_H
