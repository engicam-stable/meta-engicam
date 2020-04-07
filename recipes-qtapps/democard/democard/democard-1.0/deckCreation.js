var cards = [];

var WCARD = 135;
var HCARD = 200;
var NCARDS = 6;
var w_margin = 130;
var h_margin = 35;

var positions = [];

function createDesk(WDESK, HDESK)
{
var card_name = ["card_one.png", "card_one.png", "card_two.png", "card_two.png", "card_three.png", "card_three.png"];

    var x_inc = (WDESK - (w_margin * 2) - (WCARD * 3)) / 2;
    var y_inc = (HDESK - (h_margin * 2) - (HCARD * 2));
    for (var i = 0, x = w_margin, y = h_margin; i < NCARDS; i++)
    {
        var component = Qt.createComponent("cards/Card.qml");

        var pos = getRandomInt(0, (NCARDS - 1) - i);

        positions.push({"x": x, "y": y}); // Save the position (for the refresh)

        var card = component.createObject(desk, {"source": card_name[pos], "angle": 180, "yAxis": 1, "x": x, "y": y});
        cards.push(card);
        card_name.splice(pos, 1);

        if (i == 2)
        {
            x = w_margin;
            y += HCARD + y_inc;

            continue;
        }

        x += WCARD + x_inc;
    }
}

function getRandomInt(min, max)
{
  return Math.floor(Math.random() * (max - min + 1)) + min;
}
