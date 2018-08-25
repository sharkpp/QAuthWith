#include "appdata.h"
#include "method.h"
#include "signal.h"
#include "arguments.h"
#include "dropbox.h"
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>

AppData::AppData(QObject *parent)
    : QObject(parent)
    , m_appName("dropbox")
    , m_dropbox(new Dropbox(this))
{
    // void setAppKeyAndSecret(const QString& appKey, const QString& appSecret);
    m_definitions.append(
                new Method(
                    "setAppKeyAndSecret",
                    "set App Key and App Secret",
                    Arguments()
                    << new Argument(QMetaType::QString, "appKey", "application key")
                    << new Argument(QMetaType::QString, "appSecret", "application secret"),
                    [&](const QJSValue& args) {
        const QString& appKey = args.property("appKey").toString();
        const QString& appSecret = args.property("appSecret").toString();
        qDebug() << "setAppKeyAndSecret"<< appKey << appSecret;
        m_dropbox->setAppKeyAndSecret(appKey, appSecret);
    }));

    // void authenticate();
    m_definitions.append(
                new Method(
                    "authenticate",
                    "OAuth authentication method",
                    Arguments(),
                    [&](const QJSValue& args) {
        qDebug() << "authenticate";
        m_dropbox->authenticate();
    }));

    // void setPinCode(const QString& code);
    m_definitions.append(
                new Method(
                    "setPinCode",
                    "OAuth oob(Out-of-Band) PIN code present method",
                    Arguments()
                    << new Argument(QMetaType::QString, "code", "PIN code"),
                    [&](const QJSValue& args) {
        const QString& code = args.property("code").toString();
        qDebug() << "setPinCode"<< code;
        m_dropbox->setPinCode(code);
    }));



    // bool upload(const QByteArray& data, const QString& path);
    m_definitions.append(
                new Method(
                    "upload",
                    "data upload method",
                    Arguments()
                    << new Argument(QMetaType::QByteArray, "data", "data")
                    << new Argument(QMetaType::QString, "path", "path"),
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
    m_definitions.append(
                new Method(
                    "download",
                    "data download method",
                    Arguments()
                    << new Argument(QMetaType::QString, "path", "path"),
                    [&](const QJSValue& args) {
        const QString& path = args.property("path").toString();
        qDebug() << "download"<< path;
        m_dropbox->download(path);
    }));

    // bool remove(const QString& path);
    m_definitions.append(
                new Method(
                    "remove",
                    "data delete method",
                    Arguments()
                    << new Argument(QMetaType::QString, "path", "path"),
                    [&](const QJSValue& args) {
        const QString& path = args.property("path").toString();
        qDebug() << "remove"<< path;
        m_dropbox->remove(path);
    }));

  // signals

    // void authenticated();
    m_definitions.append(
                new Signal(
                    "authenticated",
                    "This signal is emitted when authenticate completed",
                    Arguments(),
                    [&](const std::function<void(const QVariantList&) >& callback) {
        connect(m_dropbox, &Dropbox::authenticated, [&]() {
            callback( QVariantList() );
        });
    }));

    // void uploaded(const QString& path);
    m_definitions.append(
                new Signal(
                    "uploaded",
                    "This signal is emitted when upload completed",
                    Arguments()
                    << new Argument(QMetaType::QString, "path", "path"),
                    [&](const std::function<void(const QVariantList&) >& callback) {
        connect(m_dropbox, &Dropbox::uploaded, [&](const QString& path) {
            callback(QVariantList()
                     << QVariant(path)
                     );
        });
    }));

    // void downloaded(const QString& path, const QByteArray& data);
    m_definitions.append(
                new Signal(
                    "downloaded",
                    "This signal is emitted when download completed",
                    Arguments()
                    << new Argument(QMetaType::QString, "path", "path")
                    << new Argument(QMetaType::QByteArray, "data", "download data"),
                    [&](const std::function<void(const QVariantList&) >& callback) {
        connect(m_dropbox, &Dropbox::downloaded, [&](const QString& path, const QByteArray& data) {
            callback(QVariantList()
                     << path
                     );
        });
    }));

    // void removed(const QString& path);
    m_definitions.append(
                new Signal(
                    "removed",
                    "This signal is emitted when remove completed",
                    Arguments()
                    << new Argument(QMetaType::QString, "path", "path"),
                    [&](const std::function<void(const QVariantList&) >& callback) {
        connect(m_dropbox, &Dropbox::removed, [&](const QString& path) {
            callback(QVariantList()
                     << path
                     );
        });
    }));

}



















