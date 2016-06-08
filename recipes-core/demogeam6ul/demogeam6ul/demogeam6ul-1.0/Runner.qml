import QtQuick 1.1

Rectangle
{
  id:maincontainer
  width: height
  height: parent.height / (screen_width == 800 ? 3 : 4)
  color: "transparent"

  property int m_y
  property int endline: 800
  property string m_image: "images/" + pref_image + "/neo.png"
  property int minus:0
  property int maxspeed:10
  signal win()

  y : m_y

  Behavior on x
  {
    PropertyAnimation
    {
        easing.period: 1
        easing.amplitude: 2.5
        properties: "x,y"
        easing.type: Easing.InOutExpo
        duration: 480
    }
  }

  Image
  {
      width:parent.width
      height: parent.height
      source: m_image
  }

  function tickevent()
  {
    maincontainer.x = maincontainer.x + Math.floor(Math.random() * maxspeed) % maxspeed;
    if (maincontainer.x > endline)
    {
        win();
    }

    if (minus==1)
    {
        maincontainer.y= maincontainer.y -Math.floor(+ Math.random() * 10) % 10;
        minus=0;
    }
    else
    {
        maincontainer.y= maincontainer.y +Math.floor(+ Math.random() * 10) % 10;
        minus=1;
    }
  }
}


