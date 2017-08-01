import QtQuick 1.1

Image
{
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    fillMode: Image.PreserveAspectFit
    width:0
    z: 12

    function showBanner()
    {
        showBn.start()
    }

    function hideBanner()
    {
        hideBn.start()
    }

    NumberAnimation on width
    {
        id: showBn
        running: false
        to: 380
        duration: 150
    }

    NumberAnimation on width
    {
        id: hideBn
        running: false
        to: 0
        duration: 100
    }

}
