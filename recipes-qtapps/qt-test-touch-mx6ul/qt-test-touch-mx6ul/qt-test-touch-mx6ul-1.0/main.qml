import QtQuick 1.1

Rectangle {
    visible: true
    width:800
    height:480

    MouseArea {
        anchors.fill: parent
        onClicked: 
        {
	  console.log("Clicked");
	  pressbtn.x=mouseX;
	  pressbtn.y=mouseY;
	  console.log(mouseX);
	  console.log(mouseY);
	}
    }
    
    Rectangle {
         id:pressbtn
         width: 10; height: 10
         color: "green"
     }

}
