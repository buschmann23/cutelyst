#ifndef C_FORMS_FIELDSET_H
#define C_FORMS_FIELDSET_H

#include "formhtmlelement.h"
#include "legend.h"
#include "field.h"
#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include <QQmlListProperty>
#include <vector>

namespace Cutelyst {

class FieldsetPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Fieldset : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(bool disabled READ isDisabled WRITE setDisabled)
    Q_PROPERTY(QString form READ form WRITE setForm)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(Cutelyst::Legend* legend READ legend WRITE setLegend)
    Q_PROPERTY(QQmlListProperty<Cutelyst::Field> fields READ fields)
    Q_CLASSINFO("DefaultProperty", "fields")
public:
    explicit Fieldset(QObject *parent = nullptr);
    virtual ~Fieldset() override;

    bool isDisabled() const;
    void setDisabled(bool disabled);

    QString form() const;
    void setForm(const QString &form);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    Cutelyst::Legend* legend() const;
    void setLegend(Cutelyst::Legend *legend);

    QQmlListProperty<Cutelyst::Field> fields();
    void appendField(Field *field);
    QList<Field*>::size_type fieldCount() const;
    Field *field(QList<Field*>::size_type idx) const;
    void clearFields();
    QList<Field*> fieldList() const;

protected:
    Fieldset(FieldsetPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Fieldset)
    Q_DECLARE_PRIVATE(Fieldset)
};

}

#endif // C_FORMS_FIELDSET_H
