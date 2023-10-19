#ifndef C_FORMS_SELECT_H
#define C_FORMS_SELECT_H

#include "field.h"
#include "selectcontent.h"
#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include <QQmlListProperty>
#include <vector>

namespace Cutelyst {

class SelectPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Select : public Field
{
    Q_OBJECT
    Q_PROPERTY(bool multiple READ multiple WRITE setMultiple)
    Q_PROPERTY(int size READ size WRITE setSize)
    Q_PROPERTY(QQmlListProperty<Cutelyst::SelectContent> options READ options)
    Q_CLASSINFO("DefaultProperty", "options")
public:
    explicit Select(QObject *parent = nullptr);
    virtual ~Select() override;

    bool multiple() const;
    void setMultiple(bool multiple);

    int size() const;
    void setSize(int size);

    QQmlListProperty<Cutelyst::SelectContent> options();
    void appendContent(SelectContent *content);
    QList<SelectContent*>::size_type contentCount() const;
    SelectContent *content(QList<SelectContent*>::size_type idx) const;
    void clearContent();
    QList<SelectContent *> contentList() const;

protected:
    Select(SelectPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Select)
    Q_DECLARE_PRIVATE(Select)
};

}

#endif // C_FORMS_SELECT_H
