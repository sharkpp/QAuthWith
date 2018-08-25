#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QObject>
#include <QList>

class Argument
    : public QObject
{
    Q_OBJECT

    QString         m_prototype;
    QMetaType::Type m_type;
    bool            m_required;
    QString         m_name;
    QString         m_description;

public:
    Argument(const QMetaType::Type type_, const QString &name_, const QString &description_);
    Argument(const QMetaType::Type type_, const QString &name_, bool required_, const QString &description_);

    Q_PROPERTY(QString prototype   MEMBER m_prototype   CONSTANT)
    Q_PROPERTY(int     type        MEMBER m_type        CONSTANT)
    Q_PROPERTY(QString required    MEMBER m_required    CONSTANT)
    Q_PROPERTY(QString name        MEMBER m_name        CONSTANT)
    Q_PROPERTY(QString description MEMBER m_description CONSTANT)

private:
    void updateProtorype();
};

typedef QList<QObject*> Arguments;

#endif // ARGUMENTS_H
