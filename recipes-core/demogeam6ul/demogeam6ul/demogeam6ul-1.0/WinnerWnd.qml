import QtQuick 1.1

Rectangle {
    width: parent.width
    height: parent.height

    property string winner:""
    signal mbackpressed();

    Image
    {
        width: parent.width
        height: parent.height
        id:mainImage
        source: "images/" + pref_image + "/podio.png"
        smooth: smooth_enabled
    }

    Winner
    {
       winnername:winner
       x: ((parent.width - width )/ 2)
       //y: (screen_height == 480 ? 200 : ((parent.height - height)/ 2))
       starty: y
    }

    BackBTN
    {
        height: (screen_height ==  480 ? 75 : parent.height/7)
        width: (screen_width ==  800 ? 150 : parent.width/5)
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        //y:((parent.height - height) - 10)
        //x:(parent.width - width) / 2
        onBackPressed:
        {
            mbackpressed();
        }
    }
}

