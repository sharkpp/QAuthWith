#include "appdata.h"
#include "method.h"
#include <QDebug>

AppData::AppData(QObject *parent)
    : QObject(parent)
{
    methodList.append(new Method(
                          "てすとてすと",
                          "てすとのてすとがてすとで",
                          MethodArgs()
                          << new MethodArg(QMetaType::Int, "hoge", "hogehoge, hoge")
                          << new MethodArg(QMetaType::Bool, "fuga", false, "fuga, fugafuga"),
                          [&](const QJSValue& args) {
                            qDebug() << "てすとてすと"<< args.property("hoge").toInt() << args.property("fuga").toBool();
                      }));

    methodList.append(new Method(
                          "ほげほげ",
                          "ほげほげでふふが",
                          MethodArgs(),
                          [&](const QJSValue& args) {
                            qDebug() << "ほげほげ";
                        }));
    methodList.append(new Method(
                          "でふふが",
                          "ほげほげでふふが",
                          MethodArgs(),
                          [&](const QJSValue& args) {
                            qDebug() << "ほげほげ";
                        }));
    methodList.append(new Method(
                          "ふがふがふが",
                          "ほげほげでふふが",
                          MethodArgs(),
                          [&](const QJSValue& args) {
                            qDebug() << "ほげほげ";
                        }));
}

QList<QObject*> AppData::getMethods()
{
    return methodList;
}






















