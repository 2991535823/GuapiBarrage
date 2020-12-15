#include "screeninfo.h"

ScreenInfo::ScreenInfo(QGuiApplication *app):_app(app)
{
    pscreen = QGuiApplication::primaryScreen();
    screens = QGuiApplication::screens();
    updata();
    connect(app,SIGNAL(screenAdded(QScreen*)),this,SLOT(updata()));
    connect(app,SIGNAL(screenRemoved(QScreen*)),this,SLOT(updata()));
}


int ScreenInfo::getWindowX()
{
    return _windowx;
}

int ScreenInfo::getWindowY()
{
    return _windowy;
}

int ScreenInfo::getWindowWidth()
{
    return _width;
}

int ScreenInfo::getWindowHeight()
{
    return _height;
}

void ScreenInfo::updataScreenInfo()
{
    QSize screenSize =  pscreen->size();
    if(screens.size()>1)
    {
        //有多块屏幕

        _height=screenSize.height()*0.3;
        _width=0;
        for(int i=0;i<screens.size();i++)
        {
            _width+=screens[i]->size().width();
            _height=qMin(_height,screens[i]->size().height());
        }
        _windowx=_width-screenSize.width();
        _windowy=0;
    }else {
        _width=screenSize.width();
        _height=screenSize.height()*0.3;
        _windowx=0;
        _windowy=0;
    }
}

void ScreenInfo::updata()
{
    pscreen = QGuiApplication::primaryScreen();
    screens = QGuiApplication::screens();
    updataScreenInfo();
    emit listener();
}
