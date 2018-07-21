#include "appdata.h"
#include "method.h"

AppData::AppData(QObject *parent)
    : QObject(parent)
{
    methodList.append(new Method(
                          "てすとてすと",
                          "てすとのてすとがてすとで"
                          ));
    methodList.append(new Method(
                          "ほげほげ",
                          "ほげほげでふふが"
                          ));
    methodList.append(new Method(
                          "でふふが",
                          "ほげほげでふふが"
                          ));
    methodList.append(new Method(
                          "ふがふがふが",
                          "ほげほげでふふが"
                          ));
}

QList<QObject*> AppData::getMethods()
{
    return methodList;
}






















