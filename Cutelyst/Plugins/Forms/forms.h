#ifndef C_FORMS_H
#define C_FORMS_H

#include <Cutelyst/cutelyst_global.h>
#include <Cutelyst/plugin.h>
#include "form.h"

namespace Cutelyst {

class Context;
class FormsPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Forms : public Plugin
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Forms)
    Q_DISABLE_COPY(Forms)
public:
    explicit Forms(Application *parent);

    virtual ~Forms() override;

    void addImportPath(const QString &path);
    QStringList importPaths() const;

    void setIncludePaths(const QStringList &paths);
    QStringList includePaths() const;

    static Form* getForm(const QString &name, Context *c);

protected:
    virtual bool setup(Application *app) override;

private:
    FormsPrivate *const d_ptr;
};

}

#endif // C_FORMS_H
