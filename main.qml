import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import "HttpUtil.js" as HttpUtil
//import ScreenManager 1.0
Window {
    id:window
    visible: true
    width: ScreenInfo.windowWidth
    height: ScreenInfo.windowHeight
    x:ScreenInfo.windowX
    y:ScreenInfo.windowY
    title: qsTr("小明弹幕")
    flags: Qt.Window|Qt.FramelessWindowHint|Qt.WindowStaysOnTopHint
    color: "transparent"
    property var name: ["*^_^*"]
    property var stack: []
    property Component barrage: Qt.createComponent("Barrage.qml");
    MouseArea{
        acceptedButtons: Qt.MidButton
        anchors.fill: parent
        onDoubleClicked: {
            Qt.quit();
        }
    }

    Timer{
        interval: 500; running: true; repeat: true
        onTriggered: {
            HttpUtil.getbarrage("http://139.196.210.11/api.php",
                                function (result,json){
                                    if(json["barrage"]!==null)
                                    {
                                        name=json["barrage"];
                                    }
                                }, function (){
                                    console.log("error")},)
        }
    }
    Timer{
        interval: 500; running: true; repeat: true
        onTriggered: {
            if(name.length>0)
            {
                for(var i=0;i<name.length;i++)
                {
                    stack.push(name[i])
                    var ypos=Math.random()*window.height;
                    var obj=barrage.createObject(window,
                                                 {x:ScreenInfo.windowWidth*(1+Math.random()*0.3),
                                                     contentText:name[i],
                                                     y:ypos>40?ypos-40:ypos})
                    obj.exit.connect(function(){stack.pop();obj.destroy()});
                }
            }
            name=[];
            window.visible=(stack.length>0);
        }
    }
}
