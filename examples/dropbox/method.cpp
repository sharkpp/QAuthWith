#include "method.h"
#include <QDebug>
//#include <QJSValueIterator>

//--------------------------------------------------------------------
// Method class
//--------------------------------------------------------------------

Method::Method(const QString &name_,
        const QString &description_,
        const Arguments &args_,
        const std::function<void(const QJSValue&) >& invoker_
  ) : QObject()
    , m_name(name_)
    , m_description(description_)
    , m_args(args_)
    , m_invoker(invoker_)
{

    // build displayed prototype
    QString argsText;
    for (Arguments::iterator
            ite = m_args.begin(),
            last= m_args.end();
         ite != last; ++ite) {
        argsText += qobject_cast<Argument*>(*ite)->property("prototype").toString() + ", ";
    }

    m_prototype = m_name + "(" + argsText.left(argsText.size() - 2) + ");";
}

void Method::exec(const QJSValue& args)
{
    m_invoker(args);
}
