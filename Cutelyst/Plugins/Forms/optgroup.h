#ifndef C_FORMS_OPTGROUP_H
#define C_FORMS_OPTGROUP_H

#include "selectcontent.h"
#include "option.h"
#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include <QQmlListProperty>
#include <vector>

namespace Cutelyst {

class OptgroupPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Optgroup : public SelectContent
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Cutelyst::Option> options READ options)
    Q_CLASSINFO("DefaultProperty", "options")
public:
    explicit Optgroup(QObject *parent = nullptr);
    virtual ~Optgroup() override;

    QQmlListProperty<Cutelyst::Option> options();
    void appendOption(Option *option);
    int optionCount() const;
    Option *option(int idx) const;
    void clearOptions();
    std::vector<Option*> optionList() const;

protected:
    Optgroup(OptgroupPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Optgroup)
    Q_DECLARE_PRIVATE(Optgroup)
};

}

#endif // C_FORMS_OPTGROUP_H
