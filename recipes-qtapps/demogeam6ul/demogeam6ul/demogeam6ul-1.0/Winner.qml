import QtQuick 1.1

Rectangle {
    id:m_winnner
    width:parent.width / 3
    height:parent.height / 3
    color: "transparent"

    property int starty:0

    property string winnername:""

    Image
    {
        y: 60
        width:parent.width -10
        height:parent.height -10
        fillMode: Image.PreserveAspectFit
        source:winnername
    }


    ParallelAnimation {
        id:m_animation
        running: true
        loops: Animation.Infinite

        SequentialAnimation
        {
            NumberAnimation { target: m_winnner; property: "y"; to: starty - 50; duration: 300 }
            NumberAnimation { target: m_winnner; property: "y"; to: starty ; duration: 200 }
        }
    }
}

