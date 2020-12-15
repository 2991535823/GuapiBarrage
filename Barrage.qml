import QtQuick 2.0
import QtGraphicalEffects 1.14
import "StrUtil.js" as StrUtil
Item {
    id:root
    width:StrUtil.getStrLength(contentText)*content.font.pixelSize*0.5+height*0.75
    height: 40
//    property alias rectangleBordercolor: rectangle.border.color
    property alias contentText: content.text
    property int xlimit: 1920
    x:xlimit
    signal exit()
    Rectangle{
        id: rectangle
        anchors.fill: parent
//        radius: height/2
//        border{
//            width: 1
//            color: "#8081ce75"
//        }
        color: "#00ebdedd"
        Text {
            id: content
            color: "#ffffff"
            anchors.fill: parent
            text: qsTr("text")
            font.bold: false
            font.pixelSize: 30
            textFormat: Text.AutoText
            font.weight: Font.ExtraLight
//            anchors.rightMargin: root.height/2
//            anchors.leftMargin: root.height/2
            font.family: "Tahoma"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            layer{
                enabled: true
                effect: Glow{
                    color:"black"
                    radius: 2
                    samples: 5
                    spread: 0.6
                    transparentBorder:true
                    smooth: true
                }
            }
        }
    }
    Timer{
        id:timer
        interval: 10; running: true; repeat: true
        onTriggered: {
            root.x-=1.5;
            if(root.x<-1*root.width)
            {
                timer.stop();
                root.exit();
            }
        }
    }
}
