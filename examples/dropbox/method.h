#ifndef METHOD_H
#define METHOD_H

#include <QObject>
#include <QList>

class MethodArg
    : public QObject
{
    Q_OBJECT

    QString         m_prototype;
    QMetaType::Type m_type;
    bool            m_required;
    QString         m_name;
    QString         m_description;

public:
    MethodArg(const QMetaType::Type type_, const QString &name_, const QString &description_);
    MethodArg(const QMetaType::Type type_, const QString &name_, bool required_, const QString &description_);

    Q_PROPERTY(QString prototype   MEMBER m_prototype   CONSTANT)
    Q_PROPERTY(int     type        MEMBER m_type        CONSTANT)
    Q_PROPERTY(QString required    MEMBER m_required    CONSTANT)
    Q_PROPERTY(QString name        MEMBER m_name        CONSTANT)
    Q_PROPERTY(QString description MEMBER m_description CONSTANT)
};

typedef QList<QObject*> MethodArgs;

class Method
    : public QObject
{
    Q_OBJECT

    QString         m_prototype;
    QString         m_name;
    QString         m_description;
    QList<QObject*> m_args;

public:
    Method(const QString &name_, const QString &description_, const MethodArgs& args_);

    Q_PROPERTY(QString         prototype   MEMBER m_prototype   CONSTANT)
    Q_PROPERTY(QString         name        MEMBER m_name        CONSTANT)
    Q_PROPERTY(QString         description MEMBER m_description CONSTANT)
    Q_PROPERTY(QList<QObject*> args        MEMBER m_args        CONSTANT)
    Q_INVOKABLE void   exec();
};

#endif // METHOD_H
