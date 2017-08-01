import QtQuick 1.1

Rectangle
{
    property int screen_width
    property int screen_height
    property string pref_image: "800x480"
    property bool smooth_enabled: false

    width:screen_width
    height:screen_height

    Information // Information area
    {
        id: areaInformation
        visible: false
        width: parent.width
        height: parent.height
        z: 12
    }

    PopImage
    {
        id: fight;
        source: "images/Fight!.png";
    }

    Image // Button to enable information area
    {
        id: info_btn
        source: "images/info_ico.png"
        width: screen_width == 800 ? 80 : 30
        fillMode: Image.PreserveAspectFit
        x: parent.width - width
        y: -5
        z: 12

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                areaInformation.setValue()
                areaInformation.visible = true
                info_btn.visible = false
            }
        }
    }

    PenguinSelection
    {
        id: penguinSelectTable
        visible:true
        onSelectionDone: // Show the Fight banner
        {
            disableSelection.enabled = true
            fight.showBanner()
            hideBannerTimer.start()
        }

        Timer
        {
            id: hideBannerTimer
            interval: 400
            running: false
            repeat: false
            onTriggered:
            {
                fight.hideBanner()
                runTimer.start()
            }
        }

        Timer
        {
            id: runTimer
            interval: 150
            running: false
            repeat: false
            onTriggered:
            {
                disableSelection.enabled = false; // Enable the penguins selection
                roundTable.runner1name=penguinSelectTable.runner1name;
                roundTable.runner2name=penguinSelectTable.runner2name;
                penguinSelectTable.visible=false;
                roundTable.visible=true;
                penguinSelectTable.visible=false;
                roundTable.startRound();
            }

        }

        MouseArea // To prevent the penguins selection
        {
            id: disableSelection
            anchors.fill: parent
            enabled: false
        }
    }

    Round
    {
        id:roundTable
        visible:false

        onWinnerPenguin:
        {
            roundTable.visible = false;
            winner.winner = winname;
            winner.visible = true;
        }
    }

    WinnerWnd
    {
        visible:false
        id:winner
        onMbackpressed:
        {
            winner.visible=false;
            penguinSelectTable.visible=true;
            penguinSelectTable.resetForm();
        }
    }
}

