#include "method.h"
#include <QDebug>

Method::Method(const QString &name_, const QString &description_)
    : QObject()
    , m_name(name_)
    , m_description(description_)
{
    m_prototype = m_name + "()";
}

void Method::exec()
{
    qDebug() << m_prototype;
}
