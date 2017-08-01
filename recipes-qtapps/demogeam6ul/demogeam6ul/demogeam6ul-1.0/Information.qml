import QtQuick 1.1

Item
{
    function setValue()
    {
        // Static value
        memTotal.text = "MEM TOTAL: <b>" + CPPProfiler.getMemTotal() + "</b>"
        cpuModel.text = "CPU MODEL: <b>" + CPPProfiler.getCpuModel() + "</b>"
        qtVersion.text = "QT ver. <b>" + CPPProfiler.getQtVersion() + "</b>" + " - QML ver. <b>1.1</b>"

        // Run timers to recover dynamic value and logos scroller
        recoverStatTimer.start()
        logoTimer.start()
    }

    Rectangle // Background
    {
        id: backInfo
        color: "#000000"
        opacity: 0.7
        width: parent.width
        height: parent.height

        MouseArea
        {
            anchors.fill: parent
            enabled: true
        }
    }

    // Logo area
    Rectangle
    {
        width: 240
        height: 200
        x: 200
        y: 65
        parent: info_image
        color: "transparent"
        Component
        {
            id: delegate
            Image
            {
                height: 48
                fillMode: Image.PreserveAspectFit
                smooth: smooth_enabled
                scale: PathView.iconScale
                opacity: PathView.iconOpacity
                source: icon
            }
        }

        PathView
        {
            clip: true
            anchors.fill: parent
            model: LoghiModel {}
            delegate: delegate
            id: path_view
            interactive: false
            path: Path
            {
                startX: 120
                startY: 100
                PathAttribute { name: "iconScale"; value: 1.0 }
                PathAttribute { name: "iconOpacity"; value: 1.0 }
                PathQuad { x: 120; y: 25; controlX: 260; controlY: 75 }
                PathAttribute { name: "iconScale"; value: 0.5 }
                PathAttribute { name: "iconOpacity"; value: 0.5 }
                PathQuad { x: 120; y: 100; controlX: -20; controlY: 75 }
            }

            Timer
            {
                id: logoTimer
                interval: 1200
                running: false
                repeat: true
                onTriggered:
                {
                    path_view.decrementCurrentIndex()
                }
            }
        }
    }

    Image
    {
        id: info_image
        visible: true
        width: 450
        source: "images/Information-background.png"
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
        smooth: smooth_enabled

        MouseArea
        {
            anchors.fill: parent
            hoverEnabled: true
            onClicked:
            {
                areaInformation.visible = false
                info_btn.visible = true
                recoverStatTimer.stop()
                logoTimer.stop()
            }
        }

        Column
        {
            spacing: 10
            x: 24
            y: 30
            Text
            {
                id: cpuModel
                width: 300
                height: 20
                text: ""
            }

           /* Text
            {
                id: cpuPercentage
                width: 300
                height: 20
                text: "CPU USAGE: "
            }*/

            Text
            {
                width: 300
                height: 20
                text: "DDR FREQ.: <b>400 Mhz</b>"
            }

            Text
            {
                id: memTotal
                width: 300
                height: 20
                text: ""
            }

            Text
            {
                id: memFree
                width: 300
                height: 20
                text: ""
            }


            Text
            {
                id: vMem
                width: 300
                height: 20
                text: ""
            }

            Text
            {
                id: qtVersion
                width: 300
                height: 20
                text: ""
             }
        }
    }

    Timer
    {
        id: recoverStatTimer
        interval: 1000
        running: false
        repeat: true
        triggeredOnStart: true
        onTriggered:
        {
            memFree.text = "MEM FREE: <b>" + CPPProfiler.getMemFree() + "</b>";
            //cpuPercentage.text = "CPU USAGE: <b>" + CPPProfiler.cpuPercentage() + "</b>";
            vMem.text = "VMEM: <b>" + CPPProfiler.vMEMVAlue() + "</b>";
        }
    }

}
