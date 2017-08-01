import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MultiPointTouchArea {
           anchors.fill: parent
           touchPoints: [
               TouchPoint { id: point1 },
               TouchPoint { id: point2 },
               TouchPoint { id: point3 },
               TouchPoint { id: point4 },
               TouchPoint { id: point5 }
           ]
       }


    Text {
        text: "X: " + point1.x + " Y: " + point1.y
        anchors.centerIn: parent
    }


    Rectangle {
         width: 10; height: 10
         color: "green"
         x: point1.x
         y: point1.y
     }

     Rectangle {
         width: 10; height: 10
         color: "yellow"
         x: point2.x
         y: point2.y
     }


     Rectangle {
         width: 10; height: 10
         color: "red"
         x: point3.x
         y: point3.y
     }

     Rectangle {
         width: 10; height: 10
         color: "blue"
         x: point4.x
         y: point4.y
     }

     Rectangle {
         width: 10; height: 10
         color: "pink"
         x: point5.x
         y: point5.y
     }

}
