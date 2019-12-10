#ifndef C_FORMS_FIELD_P_H
#define C_FORMS_FIELD_P_H

#include "field.h"
#include "formhtmlelement_p.h"

namespace Cutelyst {

class FieldPrivate : public FormHtmlElementPrivate
{
public:
    FieldPrivate(Field *q);

    QString name;
    QString label;
    QString description;
    int colspan = 0;
    Field::Type type = Field::Text;

private:
    Q_DECLARE_PUBLIC(Field)
    Q_DISABLE_COPY(FieldPrivate)
};

}

#endif // C_FORMS_FIELD_P_H
