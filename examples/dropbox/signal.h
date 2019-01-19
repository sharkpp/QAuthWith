#ifndef SIGNAL_H
#define SIGNAL_H

#include <QObject>
#include <QVariant>
#include <functional>
#include "arguments.h" // Arguments, Argument

class Signal
        : public QObject
{
    Q_OBJECT

    QString         m_prototype;
    QString         m_name;
    QString         m_description;
    Arguments       m_args;
    QList<QObject*> m_argsItem;
    std::function<void(const QVariantList&) > m_callback;

public:
    Signal(const QString &name_, const QString &description_, const Arguments& args_,
           const std::function<void(const std::function<void(const QVariantList&) >&) >& initializer);

    Q_PROPERTY(QString         definitionType READ   getDefinitionType CONSTANT)

    Q_PROPERTY(QString         prototype      MEMBER m_prototype       CONSTANT)
    Q_PROPERTY(QString         name           MEMBER m_name            CONSTANT)
    Q_PROPERTY(QString         description    MEMBER m_description     CONSTANT)
    Q_PROPERTY(QList<QObject*> args           MEMBER m_args            CONSTANT)
    Q_INVOKABLE void           bind(int argIndex, QObject* object);

protected:
    QString getDefinitionType() const { return "signal"; }
};

#endif // SIGNAL_H
