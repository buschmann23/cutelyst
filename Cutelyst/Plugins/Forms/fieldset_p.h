#ifndef C_FORMS_FIELDSET_P_H
#define C_FORMS_FIELDSET_P_H

#include "fieldset.h"
#include "formhtmlelement_p.h"

namespace Cutelyst {

class FieldsetPrivate : public FormHtmlElementPrivate
{
public:
    FieldsetPrivate(Fieldset *q);

    QList<Field*> fields;
    QString form;
    QString name;
    QString label;
    QString description;
    Legend *legend = nullptr;
    bool disabled = false;

private:
    Q_DECLARE_PUBLIC(Fieldset)
    Q_DISABLE_COPY(FieldsetPrivate)
};

}

#endif // C_FORMS_FIELDSET_P_H
