#include "method.h"
#include <QDebug>

Method::Method(const QString &name_)
    : QObject()
    , m_name(name_)
{
    m_prototype = m_name + "()";
}

void Method::exec()
{
    qDebug() << m_prototype;
}
