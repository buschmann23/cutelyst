#ifndef C_FORMS_H
#define C_FORMS_H

#include <Cutelyst/cutelyst_global.h>
#include <Cutelyst/plugin.h>
#include "form.h"

namespace Cutelyst {

class Context;
class FormsPrivate;

/*!
 * \defgroup plugins-forms Forms plugin
 * \brief Provides loading and processing HTML form data written in QML.
 *
 * <h3>Logging</h3>
 * Information is logged to the \c cutelyst.forms logging category. Warnings
 * from the internal QQmlEngine will also be redirected to this category.
 *
 * <h3>Building and using</h3>
 * The plugin is linked to %Cutelyst Core API, QtCore and QtQml. If the
 * CSRFProtection plugin is enabled, it will also be linked against that.
 * To use it in your application, link your application to \a Cutelyst::Forms.
 */

/*!
 * \ingroup plugins-forms
 * \class Forms forms.h <Cutelyst/Plugins/Forms>
 * \brief The Forms plugin class.
 */
class CUTELYST_PLUGIN_FORMS_EXPORT Forms : public Plugin // clazy::exclude(ctor-missing-parent-argument)
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Forms) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    Q_DISABLE_COPY(Forms)
public:
    /*!
     * \brief Constructs a new %Forms plugin object with the given \a parent.
     */
    explicit Forms(Application *parent);

    /*!
     * \brief Destroys the %Forms object.
     */
    ~Forms() override;

    /*!
     * \brief Adds an import \a path to the internal QQmlEngine.
     * \sa importPaths(), QQmlEngine::addImportPath()
     */
    void addImportPath(const QString &path);
    /*!
     * \brief Returns the current list of import paths used by the internal QQmlEngine.
     * \sa addImportPath(), QQmlEngine::importPathList()
     */
    [[nodiscard]] QStringList importPaths() const;

    /*!
     * \brief Sets the list of include \a paths.
     *
     * The include paths are used to load QML files that define a HTML form.
     *
     * Use includePaths() to return a list of currently set paths.
     */
    void setIncludePaths(const QStringList &paths);
    /*!
     * \brief Returns the list of include paths.
     *
     * The include paths are used to load QML files that define a HTML form.
     *
     * Use setIncludePahts() to set the list of paths.
     */
    [[nodiscard]] QStringList includePaths() const;

    static Form* getForm(const QString &name, Context *c);

protected:
    /*!
     * \brief Sets the %Forms plugin up to be used by \a app.
     */
    bool setup(Application *app) override;

private:
    FormsPrivate *const d_ptr;
};

}

#endif // C_FORMS_H
