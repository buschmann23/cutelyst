#ifndef C_LEGEND_H
#define C_LEGEND_H

#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include "formhtmlelement.h"

namespace Cutelyst {

class LegendPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Legend : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
public:
    explicit Legend(QObject *parent = nullptr);
    virtual ~Legend() override;

    QString text() const;
    void setText(const QString &text);

protected:
    Legend(LegendPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Legend)
    Q_DECLARE_PRIVATE(Legend)
};

}

#endif // C_LEGEND_H
