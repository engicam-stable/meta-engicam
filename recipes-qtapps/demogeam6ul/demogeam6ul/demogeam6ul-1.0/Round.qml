import QtQuick 1.1

Rectangle {
    id:mainrectangle
    width: parent.width  ; height: parent.height
    border.width: 1
    radius: 5
    smooth: smooth_enabled

    property string runner1name: "images/" + pref_image + "/neo.png"
    property string runner2name: "images/" + pref_image + "/rambo.png"
    property int thereIsAWinner:0

    signal winnerPenguin(string winname);

    function startRound()
    {
        runningTick.running = true;
        runner1.x = 0;
        runner2.x = 0;
        runner1.y = ((mainrectangle.height - runner1.height) / 4);
        runner2.y = (((mainrectangle.height - runner2.height) / 4) * (screen_height == 480 ? 3.5 : 3));
        thereIsAWinner = 0;
    }

    Image
    {
        id:filed
        width: parent.width
        height: parent.height
        source: "images/" + pref_image + "/base.png"
        smooth: smooth_enabled
    }

    Timer {
      id:runningTick
      interval: 500;
      running: false
      repeat: true

      onTriggered: {
            runner1.tickevent();
            runner2.tickevent();
        }
    }

    Runner
    {
        x:0
        id:runner1
        maxspeed: parent.width /10
        endline: parent.width - (screen_width == 800 ? 150 : 90)
        m_y:((parent.height - height) / 4)
        m_image:runner1name
        onWin:
        {
            if (thereIsAWinner===1)
            {
                return;
            }
            thereIsAWinner=1;
            runningTick.running=false;

            winnerPenguin(m_image);
            runner1.x=0;
            runner2.x=0;
        }
    }


    Runner
    {
        x:0
        id: runner2
        maxspeed: parent.width /10
        endline: parent.width - (screen_width == 800 ? 150 : 90)
        m_y:((parent.height - height) / 4) * 3
        m_image:runner2name
        onWin:
        {
            if (thereIsAWinner===1)
            {
                return;
            }

            thereIsAWinner=1;
            runningTick.running=false;            
            winnerPenguin(m_image);
            runner1.x=0;
            runner2.x=0;
        }
    }
}
