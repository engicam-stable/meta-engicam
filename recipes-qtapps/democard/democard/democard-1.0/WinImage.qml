import QtQuick 2.2
import "deckCreation.js" as MyScript
import QtQuick.Window 2.2

Image
{
    fillMode: Image.PreserveAspectFit
    smooth: true
    z: 12
    x: (Screen.width - width) / 2;
    y: (Screen.height - height) / 2;
    source: "winner.png"

    function showBanner()
    {
        width = 0;
        visible = true;
        x = (parent.width - width) / 2;
        y = (parent.height - height) / 2;
        m_animation.start();
    }

    function endBanner()
    {
        m_animation.stop();
    }

    function changePos()
    {
        x = MyScript.getRandomInt(100, Screen.width - 100);
        y = MyScript.getRandomInt(100, Screen.height - 100);
    }

    ParallelAnimation
    {
        id: m_animation
        running: false
        loops: Animation.Infinite

        SequentialAnimation
        {
            NumberAnimation { target: winImg; property: "width"; to: 447; duration: 2000 }
            NumberAnimation { target: winImg; property: "width"; to: 0; duration: 2000 }
            ScriptAction { script: changePos(); }
        }
    }
}
