#include "signal.h"
#include <QDebug>

//--------------------------------------------------------------------
// Method class
//--------------------------------------------------------------------

Signal::Signal(const QString &name_,
        const QString &description_,
        const Arguments &args_,
        const std::function<void(const std::function<void(const QVariantList&) >&) >& initializer
  ) : QObject()
    , m_name(name_)
    , m_description(description_)
    , m_args(args_)
{

    QString argsText;
    for (Arguments::iterator
            ite = m_args.begin(),
            last= m_args.end();
         ite != last; ++ite) {
        argsText += qobject_cast<Argument*>(*ite)->property("prototype").toString() + ", ";
        //
        m_argsItem.append(nullptr);
    }

    m_prototype = "void " + m_name + "(" + argsText.left(argsText.size() - 2) + ");";

    initializer([&](const QVariantList& args) {
        qDebug() << args;
    });
}

void Signal::bind(int argIndex, QObject* object)
{
    qDebug() << "Signal::bind" << argIndex << object;

    m_argsItem.replace(argIndex, object);

    //object->setProperty("text", "aaaa");
}


