#ifndef C_FORMS_FIELD_H
#define C_FORMS_FIELD_H

#include "formhtmlelement.h"
#include <Cutelyst/cutelyst_global.h>

namespace Cutelyst {

class FieldPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Field : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(Cutelyst::Field::Type type READ type WRITE setType)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(int colspan READ colspan WRITE setColspan)
public:
    explicit Field(QObject *parent = nullptr);
    virtual ~Field() override;

    enum Type {
        Text            = 0,
        Search,
        Password,
        Tel,
        Url,
        Email,
        Number,
        Range,
        Radio,
        Checkbox,
        Hidden,
        File,
        Color,
        Date,
        DatetimeLocal,
        Week,
        Month,
        Time,
        Select,
        Textarea
    };
    Q_ENUM(Type)

    Cutelyst::Field::Type type() const;
    void setType(Cutelyst::Field::Type type);

    QString name() const;
    void setName(const QString &name);

    QString label() const;
    void setLabel(const QString &label);

    QString description() const;
    void setDescription(const QString &description);

    int colspan() const;
    void setColspan(int colspan);

protected:
    Field(FieldPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Field)
    Q_DECLARE_PRIVATE(Field)
};

}

#endif // C_FORMS_FIELD_H
