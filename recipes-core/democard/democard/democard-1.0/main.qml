import QtQuick 2.2
import "cards"
import "deckCreation.js" as MyScript
import QtQuick.Window 2.2

Rectangle
{
    id: desk
    visible: true
    width:  Screen.width
    height: Screen.height
    color: "darkgreen"
    property int cards_selected: 0
    property variant firstObJ
    property bool mouseDisable: false
    property int pairs: 0
    property alias imgId: winImg
    property var cardsPos: [0, 1, 2, 3, 4, 5]
    property var tempCardsPos: [0, 1, 2, 3, 4, 5] // Per demoMode
    property bool demoMode: true

    Component.onCompleted:
    {
        MyScript.createDesk(width, height);
    }

    Text
    {
        id: demoText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: "DEMO MODE"
        color: "white"
        font.bold: true
        font.pixelSize: 20
        z: 10
    }

    // Fisher-Yate Shuffle
    function refreshDeck()
    {
    var m, i , t;

        m = MyScript.positions.length;

        while (m)
        {
            i = Math.floor(Math.random() * m--);

            // And swap it with the current element.
            t = MyScript.positions[m];

            MyScript.positions[m] = MyScript.positions[i];
            MyScript.positions[i] = t;
        }
    }

    function selectedCard(object, isShowed)
    {
    var i;                       // demoModeTimer.start();

        if (isShowed === true)
        {
            if (cards_selected == 0) // Save the ref
            {
                firstObJ = object;
                cards_selected = 1;

                if (demoMode === true)
                {
                    demoModeTimer.interval = 1000;
                }
            }
            else if (firstObJ !== object) // Check the results
            {
                if (firstObJ.source !== object.source)
                {
                    firstObJ.flipped = true;
                    object.flipped = true;

                    if (demoMode) // Ripristino la lista delle carte
                    {
                        demoModeTimer.interval = 2000;
                        tempCardsPos = cardsPos.slice(0);
                    }
                }
                else
                {
                    pairs ++;
                    if (pairs == 3) // End game
                    {
                        if (demoMode === false)
                        {
                            for (i = 0; i < MyScript.NCARDS; i ++)
                            {
                                MyScript.cards[i].disableMouseArea();
                            }
                            winImg.showBanner()
                        }

                        refreshDeck(); // Change the positions
                        if (demoMode)
                        {
                            cardsPos = [0, 1, 2, 3, 4, 5];
                            tempCardsPos = cardsPos.slice(0);
                            demoModeTimer.interval = 5000;
                            deckMouseArea.clicked(Qt.MouseEventSynthesizedByApplication);
                        }
                    }
                    else if (demoMode)
                    {
                        cardsPos = tempCardsPos.slice(0);
                        demoModeTimer.interval = 2000;
                    }
                }

                cards_selected = 0;
            }
        }
        mouseDisable = false;

        if (demoMode)
        {
            demoModeTimer.start();
        }
    }

    WinImage
    {
        id: winImg
        visible: false;
    }

    Timer
    {
        id: demoModeTimer
        interval: 1000
        running: true
        repeat: false
        onTriggered:
        {
            if (demoMode === false) // Riattivo la modalita' demoMode
            {
                interval = 1000;
                demoMode = true;
                cardsPos = [0, 1, 2, 3, 4, 5]
                tempCardsPos = cardsPos.slice(0)
                refreshDeck();
                pairs = 3;
                demoText.visible = true;
                deckMouseArea.clicked(Qt.MouseEventSynthesizedByApplication); // Forzo il reset
                start();
            }
            else
            {
                var idx = MyScript.getRandomInt(0, tempCardsPos.length-1);
                var card = tempCardsPos[idx];
                tempCardsPos.splice(idx, 1);
                MyScript.cards[card].cardMouseArea.clicked(Qt.MouseEventSynthesizedByApplication);
            }
        }
    }

    MouseArea
    {
        id: deckMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: // Reset the game
        {
          if (pairs == 3) // Fine del gioco
          {
            cards_selected = 0
            firstObJ = undefined;
            pairs = 0;
            winImg.visible = false;
            winImg.endBanner();
            for (var i = 0; i < MyScript.NCARDS; i ++)
            {
                MyScript.cards[i].x = MyScript.positions[i].x;
                MyScript.cards[i].y = MyScript.positions[i].y;
                MyScript.cards[i].flipped = true;
                MyScript.cards[i].enableMouseArea();
            }
          }
        }
        onPositionChanged:
        {
            if (demoMode === true) // Esco dalla demoMode
            {
                demoMode = false;
                demoModeTimer.stop();

                demoText.visible = false;
                refreshDeck();
                pairs = 3;
                deckMouseArea.clicked(Qt.MouseEventSynthesizedByApplication); // Forzo il reset

                demoModeTimer.interval = 90000;
            }
            else
            {
                demoModeTimer.restart();
            }
        }
    }
}

