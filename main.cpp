#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "screeninfo.h"
#include <QQmlContext>

//test main dev
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    ScreenInfo *screen=new ScreenInfo(&app);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("ScreenInfo",screen);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
