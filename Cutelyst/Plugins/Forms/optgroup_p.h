#ifndef C_FORMS_OPTGROUP_P_H
#define C_FORMS_OPTGROUP_P_H

#include "optgroup.h"
#include "selectcontent_p.h"

namespace Cutelyst {

class OptgroupPrivate : public SelectContentPrivate
{
public:
    OptgroupPrivate(Optgroup *q);

    std::vector<Option*> options;

private:
    Q_DECLARE_PUBLIC(Optgroup)
    Q_DISABLE_COPY(OptgroupPrivate)
};

}

#endif // C_FORMS_OPTGROUP_P_H
