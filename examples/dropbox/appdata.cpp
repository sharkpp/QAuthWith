#include "appdata.h"
#include "method.h"
#include "dropbox.h"
#include <QFile>
#include <QDebug>

AppData::AppData(QObject *parent)
    : QObject(parent)
    , m_appName("dropbox")
    , m_dropbox(new Dropbox(this))
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
        m_dropbox->setAppKeyAndSecret(appKey, appSecret);
    }));

    // void authenticate();
    methodList.append(
                new Method(
                    "authenticate",
                    "OAuth authentication method",
                    MethodArgs(),
                    [&](const QJSValue& args) {
        qDebug() << "authenticate";
        m_dropbox->authenticate();
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
        m_dropbox->setPinCode(code);
    }));



    // bool upload(const QByteArray& data, const QString& path);
    methodList.append(
                new Method(
                    "upload",
                    "data upload method",
                    MethodArgs()
                    << new MethodArg(QMetaType::QByteArray, "data", "data")
                    << new MethodArg(QMetaType::QString, "path", "path"),
                    [&](const QJSValue& args) {
        //const QByteArray& data = args.property("data").toByteArray();
        const QString& dataLocalPath = args.property("data").toString();
        const QString& path = args.property("path").toString();
        qDebug() << "upload"<< dataLocalPath<< path;
        QFile file(dataLocalPath);
        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }
        QByteArray data = file.readAll();
        m_dropbox->upload(data, path);
    }));

    // bool download(const QString& path);
    methodList.append(
                new Method(
                    "download",
                    "data download method",
                    MethodArgs()
                    << new MethodArg(QMetaType::QString, "path", "path"),
                    [&](const QJSValue& args) {
        const QString& path = args.property("path").toString();
        qDebug() << "download"<< path;
        m_dropbox->download(path);
    }));

    // bool remove(const QString& path);
    methodList.append(
                new Method(
                    "remove",
                    "data delete method",
                    MethodArgs()
                    << new MethodArg(QMetaType::QString, "path", "path"),
                    [&](const QJSValue& args) {
        const QString& path = args.property("path").toString();
        qDebug() << "remove"<< path;
        m_dropbox->remove(path);
    }));


}

QList<QObject*> AppData::getMethods()
{
    return methodList;
}






















