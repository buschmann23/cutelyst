#ifndef C_FORM_H
#define C_FORM_H

#include "formhtmlelement.h"
#include "fieldset.h"
#include "button.h"
#include <Cutelyst/cutelyst_global.h>
#include <QObject>
#include <QQmlListProperty>
#include <QUrl>
#include <vector>

namespace Cutelyst {

class FormPrivate;

class CUTELYST_PLUGIN_FORMS_EXPORT Form : public FormHtmlElement
{
    Q_OBJECT
    Q_PROPERTY(QUrl action READ action WRITE setAction)
    Q_PROPERTY(QStringList acceptCharset READ acceptCharset WRITE setAcceptCharset)
    Q_PROPERTY(bool autocomplete READ autocomplete WRITE setAutocomplete)
    Q_PROPERTY(Cutelyst::Form::EncType enctype READ enctype WRITE setEnctype)
    Q_PROPERTY(Cutelyst::Form::Method method READ method WRITE setMethod)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(bool novalidate READ novalidate WRITE setNovalidate)
    Q_PROPERTY(Cutelyst::Form::Target target READ target WRITE setTarget)
    Q_PROPERTY(QString label READ label WRITE setLabel)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QQmlListProperty<Cutelyst::Fieldset> fieldsets READ fieldsets)
    Q_PROPERTY(QQmlListProperty<Cutelyst::Button> buttons READ buttons)
    Q_PROPERTY(Cutelyst::Form::Type type READ type WRITE setType)
    Q_CLASSINFO("DefaultProperty", "fieldsets")
public:
    explicit Form(QObject *parent = nullptr);
    virtual ~Form() override;

    enum EncType {
        WwwFormUrlEncoded   = 0,
        MultipartFormData,
        TextPlain
    };
    Q_ENUM(EncType)

    enum Method {
        Post    = 0,
        Get
    };
    Q_ENUM(Method)

    enum Target {
        Self    = 0,
        Blank,
        Parent,
        Top
    };
    Q_ENUM(Target)

    enum Type : quint8 {
        Vertical    = 0,
        Horizontal  = 1,
        Inline      = 2
    };
    Q_ENUM(Type)

    QUrl action() const;
    void setAction(const QUrl &action);

    QStringList acceptCharset() const;
    void setAcceptCharset(const QStringList &acceptCharset);

    bool autocomplete() const;
    void setAutocomplete(bool autocomplete);

    Cutelyst::Form::EncType enctype() const;
    void setEnctype(Cutelyst::Form::EncType enctype);

    Cutelyst::Form::Method method() const;
    void setMethod(Cutelyst::Form::Method method);

    QString name() const;
    void setName(const QString &name);

    bool novalidate() const;
    void setNovalidate(bool novalidate);

    Cutelyst::Form::Target target() const;
    void setTarget(Cutelyst::Form::Target target);

    QString label() const;
    void setLabel(const QString &label);

    QString description() const;
    void setDescription(const QString &description);

    Cutelyst::Form::Type type() const;
    void setType(Cutelyst::Form::Type type);

    QQmlListProperty<Cutelyst::Fieldset> fieldsets();
    void appendFieldset(Fieldset *fieldset);
    int fieldsetCount() const;
    Fieldset *fieldset(int idx) const;
    void clearFieldsets();
    std::vector<Fieldset*> fieldsetList() const;

    QQmlListProperty<Cutelyst::Button> buttons();
    void appendButton(Button *button);
    int buttonCount() const;
    Button *button(int idx) const;
    void clearButtons();
    std::vector<Button*> buttonList() const;

protected:
    Form(FormPrivate &dd, QObject *parent = nullptr);

private:
    Q_DISABLE_COPY(Form)
    Q_DECLARE_PRIVATE(Form)
};

}

#endif // C_FORM_H
