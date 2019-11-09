#ifndef C_FORMHTMLELEMENT_H
#define C_FORMHTMLELEMENT_H

#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include <QScopedPointer>

namespace Cutelyst {

class FormHtmlElementPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT FormHtmlElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString htmlId READ htmlId WRITE setHtmlId)
    Q_PROPERTY(QString htmlClass READ htmlClass WRITE setHtmlClass)
    Q_PROPERTY(QString accesskey READ accesskey WRITE setAccesskey)
    Q_PROPERTY(bool contenteditable READ isContenteditable WRITE setContenteditable)
    Q_PROPERTY(QString contextmenu READ contextmenu WRITE setContextmenu)
    Q_PROPERTY(Cutelyst::FormHtmlElement::TextDirection dir READ dir WRITE setDir)
    Q_PROPERTY(Cutelyst::FormHtmlElement::DraggableState draggable READ draggable WRITE setDraggable)
    Q_PROPERTY(bool hidden READ isHidden WRITE setHidden)
    Q_PROPERTY(QString lang READ lang WRITE setLang)
    Q_PROPERTY(bool spellcheck READ spellcheck WRITE setSpellcheck)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(int tabindex READ tabindex WRITE setTabindex)
    Q_PROPERTY(QString title READ title WRITE setTitle)
public:
    explicit FormHtmlElement(QObject *parent = nullptr);
    virtual ~FormHtmlElement() override;

    enum TextDirection {
        AutoDir = 0,
        Ltr,
        Rtl
    };
    Q_ENUM(TextDirection)

    enum DraggableState {
        DragAuto    = 0,
        DragTrue,
        DragFalse
    };
    Q_ENUM(DraggableState)

    QString htmlId() const;
    void setHtmlId(const QString &htmlId);

    QString htmlClass() const;
    void setHtmlClass(const QString &htmlClass);

    QString accesskey() const;
    void setAccesskey(const QString &accesskey);

    bool isContenteditable() const;
    void setContenteditable(bool contenteditable);

    QString contextmenu() const;
    void setContextmenu(const QString &contextmenu);

    Cutelyst::FormHtmlElement::TextDirection dir() const;
    void setDir(Cutelyst::FormHtmlElement::TextDirection dir);

    Cutelyst::FormHtmlElement::DraggableState draggable() const;
    void setDraggable(Cutelyst::FormHtmlElement::DraggableState draggable);

    bool isHidden() const;
    void setHidden(bool hidden);

    QString lang() const;
    void setLang(const QString &lang);

    bool spellcheck() const;
    void setSpellcheck(bool spellcheck);

    QString style() const;
    void setStyle(const QString &style);

    int tabindex() const;
    void setTabindex(int tabindex);

    QString title() const;
    void setTitle(const QString &title);

protected:
    const QScopedPointer<FormHtmlElementPrivate> d_ptr;
    FormHtmlElement(FormHtmlElementPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(FormHtmlElement)
    Q_DECLARE_PRIVATE(FormHtmlElement)
};

}

#endif // C_FORMHTMLELEMENT_H
