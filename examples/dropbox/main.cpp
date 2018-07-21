#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>
#include <QIcon>
#include "appdata.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setApplicationName("AuthWithDropboxApiHelp");
    QGuiApplication::setOrganizationName("sharkpp");

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QIcon::setThemeName("material-design-icons");

    QSettings settings;
    QString style = QQuickStyle::name();
    if (!style.isEmpty()) {
        settings.setValue("style", style);
    }
    else {
        QQuickStyle::setStyle(settings.value("style").toString());
    }

    // application context & custom type

    AppData data;

    //qmlRegisterType<ApiReqest>("net.sharkpp.authwith", 1, 0, "ApiReqest");

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("appData", &data);

    engine.rootContext()->setContextProperty("availableStyles", QQuickStyle::availableStyles());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
