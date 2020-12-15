#ifndef SCREENINFO_H
#define SCREENINFO_H
#include <QtDebug>
#include <QObject>

#include <QGuiApplication>
#include <QScreen>

class ScreenInfo:public QObject
{
    Q_OBJECT
public:
    ScreenInfo(QGuiApplication* app);
    Q_PROPERTY(int windowX READ getWindowX NOTIFY listener)
    Q_PROPERTY(int windowY READ getWindowY NOTIFY listener)
    Q_PROPERTY(int windowWidth READ getWindowWidth NOTIFY listener)
    Q_PROPERTY(int windowHeight READ getWindowHeight NOTIFY listener)
private:
    int getWindowX();
    int getWindowY();
    int getWindowWidth();
    int getWindowHeight();
    int _width=1920;
    int _height=1058;
    int _windowx=0;
    int _windowy=0;
    void updataScreenInfo();
    QScreen* pscreen=NULL;
    QList <QScreen *> screens;
    QGuiApplication *_app=NULL;
signals:
    void listener();
    // QObject interface
private slots:
    void updata();
};

#endif // SCREENINFO_H
