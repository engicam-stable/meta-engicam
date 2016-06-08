import QtQuick 1.1

Rectangle {
    id:buttonPen
    signal penguindpressed(string name)
    color:"transparent"
    property string imageName;
    property int selected:0;
    MouseArea {
        id: button
        width:parent.width
        height: parent.height
        onClicked:
        {
            if(selected===1) return;
            selected=1;
            m_animation.running=false;
            penguindpressed(imageName);
        }
    }

    function reset()
    {
        selected=0;
        m_animation.running=true;
    }

    function stop()
    {
        m_animation.running=false;
    }

    Image
    {
        id:buttonimage
        fillMode: Image.PreserveAspectFit
        source: imageName
        width: (parent.width) ;
        height: (parent.height);
    }


    ParallelAnimation {
        id:m_animation
        running: true
        loops: Animation.Infinite
        SequentialAnimation
        {
            NumberAnimation { target: buttonimage; property: "rotation"; to: 50; duration: 200 }
            NumberAnimation { target: buttonimage; property: "rotation"; to: -50; duration: 300 }
        }
        SequentialAnimation
        {
            NumberAnimation { target: buttonimage; property: "scale"; to: 0.8; duration: 300 }
            NumberAnimation { target: buttonimage; property: "scale"; to: 0.5; duration: 200 }
        }
    }

}

