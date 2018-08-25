#include "arguments.h"

//--------------------------------------------------------------------
// MethodArg class
//--------------------------------------------------------------------

Argument::Argument(const QMetaType::Type type_, const QString &name_, const QString &description_)
    : QObject()
    , m_type(type_)
    , m_required(true)
    , m_name(name_)
    , m_description(description_)
{
    updateProtorype();
}

Argument::Argument(const QMetaType::Type type_, const QString &name_, bool required_, const QString &description_)
    : QObject()
    , m_type(type_)
    , m_required(required_)
    , m_name(name_)
    , m_description(description_)
{
    updateProtorype();
}

void Argument::updateProtorype()
{
    m_prototype = QString("const ") + QString(QMetaType::typeName(m_type)) + "& " + m_name;
}
