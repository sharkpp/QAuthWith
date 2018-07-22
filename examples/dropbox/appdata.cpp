#include "appdata.h"
#include "method.h"

AppData::AppData(QObject *parent)
    : QObject(parent)
{
    methodList.append(new Method(
                          "てすとてすと",
                          "てすとのてすとがてすとで",
                          MethodArgs()
                          << new MethodArg(QMetaType::Int, "hoge", "hogehoge, hoge")
                          << new MethodArg(QMetaType::Bool, "fuga", false, "fuga, fugafuga")
                          ));
    methodList.append(new Method(
                          "ほげほげ",
                          "ほげほげでふふが",
                          MethodArgs()
                          ));
    methodList.append(new Method(
                          "でふふが",
                          "ほげほげでふふが",
                          MethodArgs()
                          ));
    methodList.append(new Method(
                          "ふがふがふが",
                          "ほげほげでふふが",
                          MethodArgs()
                          ));
}

QList<QObject*> AppData::getMethods()
{
    return methodList;
}






















