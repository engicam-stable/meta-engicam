import QtQuick 1.1

Rectangle {
    color: "transparent"

    signal backPressed()

    Image
    {
        width:parent.width
        height: parent.height
        source: "images/" + pref_image + "/backbtn.png"
    }

    MouseArea {
        id: button
        width:parent.width
        height: parent.height
        onClicked:
        {
            backPressed();
        }
    }
}

