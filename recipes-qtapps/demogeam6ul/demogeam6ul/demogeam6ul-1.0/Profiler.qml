import QtQuick 1.1

Rectangle {    
    color:"transparent"

    width: parent.width
    height: parent.height / 5

    Text
    {
        id:testo
        anchors.fill: parent
        text:""
        horizontalAlignment: Text.AlignHCenter
    }

    Timer {
        interval: 500; running: true; repeat: true
        onTriggered:
        {
            testo.text = "CPU : " + CPPProfiler.cpuPercentage() +
                    "    VMEM: " + CPPProfiler.vMEMVAlue();
        }
    }
}

