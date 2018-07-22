#include "appdata.h"
#include "method.h"
#include <QDebug>

AppData::AppData(QObject *parent)
    : QObject(parent)
{
    // void setAppKeyAndSecret(const QString& appKey, const QString& appSecret);
    methodList.append(
                new Method(
                    "setAppKeyAndSecret",
                    "set App Key and App Secret",
                    MethodArgs()
                    << new MethodArg(QMetaType::QString, "appKey", "application key")
                    << new MethodArg(QMetaType::QString, "appSecret", "application secret"),
                    [&](const QJSValue& args) {
        const QString& appKey = args.property("appKey").toString();
        const QString& appSecret = args.property("appSecret").toString();
        qDebug() << "setAppKeyAndSecret"<< appKey << appSecret;
    }));

    // void authenticate();
    methodList.append(
                new Method(
                    "authenticate",
                    "OAuth authentication method",
                    MethodArgs(),
                    [&](const QJSValue& args) {
        qDebug() << "authenticate";
    }));

    // void setPinCode(const QString& code);
    methodList.append(
                new Method(
                    "setPinCode",
                    "OAuth oob(Out-of-Band) PIN code present method",
                    MethodArgs()
                    << new MethodArg(QMetaType::QString, "code", "PIN code"),
                    [&](const QJSValue& args) {
        const QString& code = args.property("code").toString();
        qDebug() << "setPinCode"<< code;
    }));

}

QList<QObject*> AppData::getMethods()
{
    return methodList;
}






















