#include "method.h"
#include <QDebug>
//#include <QJSValueIterator>

//--------------------------------------------------------------------
// MethodArg class
//--------------------------------------------------------------------

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

//--------------------------------------------------------------------
// Method class
//--------------------------------------------------------------------

Method::Method(
        const QString &name_,
        const QString &description_,
        const MethodArgs& args_,
        const std::function<void(const QJSValue&) >& invoker_
  ) : QObject()
    , m_name(name_)
    , m_description(description_)
    , m_args(args_)
    , m_invoker(invoker_)
{
    m_prototype = m_name + "()";
}

void Method::exec(const QJSValue& args)
{
    //qDebug() << m_prototype << args.hasProperty("hoge") << args.hasProperty("fuga");
    qDebug() << m_prototype << args.property("hoge").toInt() << args.property("fuga").toBool();
    //QJSValueIterator it(args);
    //while (it.hasNext()) {
    //    it.next();
    //    qDebug() << it.name() << ": " << it.value().toString();
    //}
    m_invoker(args);
}
