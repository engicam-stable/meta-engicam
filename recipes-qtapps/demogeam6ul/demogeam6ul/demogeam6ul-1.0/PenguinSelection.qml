import QtQuick 1.1

Rectangle
{
    width: parent.width
    height: parent.height
    color:"transparent"
    property string runner1name: "images/" + pref_image + "/neo.png"
    property string runner2name: "images/" + pref_image + "/rambo.png"
    property int step:0
    signal selectionDone()


    Image
    {
        width: parent.width
        height: parent.height
        source: "images/" + pref_image + "/base.png"
        smooth: smooth_enabled
    }


    Image
    {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        source:"images/select.png"
    }

    function setName(name)
    {
        if(step === 0)
        {
            runner1name=name;
            step=1;
        }
        else
        {
            runner2name=name;
            step=0;
            selectionDone();
        }
    }

    function resetForm()
    {
        penguin1.reset();
        penguin2.reset();
        penguin3.reset();
        penguin4.reset();
        penguin5.reset();
        penguin6.reset();
    }


    Grid
    {
        id: penguinGrid
        width: parent.width
        height: (parent.height * 4 )/ 6
        x:0
        y:parent.height / (screen_height == 480 ? 4 : 3)
        property int p_height: (screen_height == 480 ? 1.5 : 2)
        property int p_width: (screen_width == 800 ? 2.5 : 3)
        columns: 3
        spacing: 2
        PenguinButton
        {
            id:penguin1
            width: (parent.width - 10) / penguinGrid.p_width;
            height: (parent.height - 10) / penguinGrid.p_height;
            imageName: "images/" + pref_image + "/neo.png"
            onPenguindpressed:
            {
                setName(imageName);
            }
        }

        PenguinButton {
            id:penguin2
            width: (parent.width -10) / penguinGrid.p_width;
            height: (parent.height - 10) / penguinGrid.p_height;
            imageName: "images/" + pref_image + "/link.png"
            onPenguindpressed:
            {
                setName(imageName);
            }
        }

        PenguinButton {
            id:penguin3
            width: (parent.width -10) / penguinGrid.p_width;
            height: (parent.height - 10) / penguinGrid.p_height;
            imageName: "images/" + pref_image + "/gandalf.png"
            onPenguindpressed:
            {
                setName(imageName);
            }
        }

        PenguinButton {
            id:penguin4
            width: (parent.width -10) / penguinGrid.p_width;
            height: (parent.height - 10) / penguinGrid.p_height;
            imageName: "images/" + pref_image + "/misstux.png"
            onPenguindpressed:
            {
                setName(imageName);
            }
        }

        PenguinButton {
            id:penguin5
            width: (parent.width -10) / penguinGrid.p_width;
            height: (parent.height - 10) / penguinGrid.p_height;
            imageName: "images/" + pref_image + "/rambo.png"
            onPenguindpressed:
            {
                setName(imageName);
            }
        }

        PenguinButton {
            id:penguin6
            width: (parent.width -10) / penguinGrid.p_width;
            height: (parent.height - 10) / penguinGrid.p_height;
            imageName: "images/" + pref_image + "/october.png"
            onPenguindpressed:
            {
                setName(imageName);
            }
        }
    }
}

