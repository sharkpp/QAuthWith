#include "method.h"
#include <QDebug>

MethodArg::MethodArg(const QMetaType::Type type_, const QString &name_, const QString &description_)
    : QObject()
    , m_type(type_)
    , m_required(true)
    , m_name(name_)
    , m_description(description_)
{
    m_prototype = QString(QMetaType::typeName(type_)) + " " + m_name;
}

MethodArg::MethodArg(const QMetaType::Type type_, const QString &name_, bool required_, const QString &description_)
    : QObject()
    , m_type(type_)
    , m_required(required_)
    , m_name(name_)
    , m_description(description_)
{
    m_prototype = QString(QMetaType::typeName(type_)) + " " + m_name;
}

Method::Method(const QString &name_, const QString &description_, const MethodArgs& args_)
    : QObject()
    , m_name(name_)
    , m_description(description_)
    , m_args(args_)
{
    m_prototype = m_name + "()";
}

void Method::exec()
{
    qDebug() << m_prototype;
}
