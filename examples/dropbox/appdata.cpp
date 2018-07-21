#include "appdata.h"
#include "method.h"

AppData::AppData(QObject *parent)
    : QObject(parent)
{
    methodList.append(new Method("てすとてすと"));
    methodList.append(new Method("ほげほげ"));
}

QList<QObject*> AppData::getMethods()
{
    return methodList;
}






















