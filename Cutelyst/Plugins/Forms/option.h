#ifndef C_FORMS_OPTION_H
#define C_FORMS_OPTION_H

#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include "selectcontent.h"

namespace Cutelyst {

class OptionPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Option : public SelectContent
{
    Q_OBJECT
    Q_PROPERTY(bool selected READ isSelected WRITE setSelected)
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QString value READ value WRITE setValue)
public:
    explicit Option(QObject *parent = nullptr);
    virtual ~Option() override;

    bool isSelected() const;
    void setSelected(bool selected);

    QString text() const;
    void setText(const QString &text);

    QString value() const;
    void setValue(const QString &value);

protected:
    Option(OptionPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Option)
    Q_DECLARE_PRIVATE(Option)
};

}

#endif // C_FORMS_OPTION_H
