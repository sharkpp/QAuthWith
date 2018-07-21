#ifndef METHOD_H
#define METHOD_H

#include <QObject>

class Method
    : public QObject
{
    Q_OBJECT

    QString m_name;
    QString m_prototype;
    QString m_description;

public:
    Method(const QString &name_);

    Q_PROPERTY(QString name        MEMBER m_name        CONSTANT)
    Q_PROPERTY(QString prototype   MEMBER m_prototype   CONSTANT)
    Q_PROPERTY(QString description MEMBER m_description CONSTANT)
    Q_INVOKABLE void   exec();
};

#endif // METHOD_H
