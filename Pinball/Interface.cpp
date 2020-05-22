#include "Interface.h"
using namespace sf;
#include<iostream>
using namespace std;

Interface::Interface()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Pinball", sf::Style::Titlebar, settings);
    window.setVerticalSyncEnabled(true);
}

void Interface::getControls(bool & exit, bool & left, bool & right)
{
    sf::Event event;
    while (window.pollEvent(event));
    exit = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Interface::clear()
{
    window.clear(backgroundColor);
}

void Interface::display()
{
    window.display();
}

void Interface::drawBall(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(ballFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}

void Interface::drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius)
{
    float flip = type == LEFT ? 1.0f : -1.0f;

    // Draw the major circle outline
    sf::CircleShape majorCircleOutline(majorRadius);
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(majorRadius, majorRadius);
    majorCircleOutline.setPosition(center.x, center.y);
    window.draw(majorCircleOutline);

    // Draw the minor circle outline
    sf::CircleShape minorCircleOutline(minorRadius);
    minorCircleOutline.setOutlineThickness(outlineThickness);
    minorCircleOutline.setOutlineColor(outlineColor);
    minorCircleOutline.setFillColor(flipperFillColor);
    minorCircleOutline.setOrigin(minorRadius - length, minorRadius);
    minorCircleOutline.setPosition(center.x, center.y);
    minorCircleOutline.rotate(angle);
    minorCircleOutline.setScale(flip, 1.0f);
    window.draw(minorCircleOutline);

    // Draw the convex shape connecting the two circles
    sf::ConvexShape convexBody(4);
    convexBody.setPoint(0, sf::Vector2f(0, -outlineThickness));
    convexBody.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    convexBody.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    convexBody.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    convexBody.setFillColor(flipperFillColor);
    convexBody.setOrigin(0, majorRadius);
    convexBody.setPosition(center.x, center.y);
    convexBody.setRotation(angle);
    convexBody.setScale(flip, 1.0f);
    window.draw(convexBody);

    // Draw the inside circle
    sf::CircleShape insideCircle(minorRadius);
    insideCircle.setFillColor(outlineColor);
    insideCircle.setOrigin(minorRadius, minorRadius);
    insideCircle.setPosition(center.x, center.y);
    window.draw(insideCircle);

    // Draw the top line
    sf::ConvexShape topLine(4);
    topLine.setPoint(0, sf::Vector2f(0, -outlineThickness));
    topLine.setPoint(1, sf::Vector2f(0, 0));
    topLine.setPoint(2, sf::Vector2f(length, majorRadius - minorRadius));
    topLine.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    topLine.setFillColor(outlineColor);
    topLine.setOrigin(0, majorRadius);
    topLine.setPosition(center.x, center.y);
    topLine.setRotation(angle);
    topLine.setScale(flip, 1.0f);
    window.draw(topLine);

    // Draw the bottom line
    sf::ConvexShape bottomLine(4);
    bottomLine.setPoint(0, sf::Vector2f(0, 2 * majorRadius));
    bottomLine.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    bottomLine.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    bottomLine.setPoint(3, sf::Vector2f(length, majorRadius + minorRadius));
    bottomLine.setFillColor(outlineColor);
    bottomLine.setOrigin(0, majorRadius);
    bottomLine.setPosition(center.x, center.y);
    bottomLine.setRotation(angle);
    bottomLine.setScale(flip, 1.0f);
    window.draw(bottomLine);
}

void Interface::drawWall(float position)
{
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f(position, 0), outlineColor),
                    sf::Vertex(sf::Vector2f(position, GAME_HEIGHT), outlineColor)
            };
    window.draw(line, 2, sf::Lines);
}

void Interface::drawFloor(float lenght, float angle, FlipperType type) {

}

    // draws a kicker
    void Interface::drawKicker(FlipperType type, Vector2D refpoint, float length, float base, float top) {
        float flip = type == RIGHT ? 1.0f : -1.0f;

        sf::ConvexShape kicker(4);
        kicker.setPoint(0, sf::Vector2f(refpoint.x, refpoint.y));
        kicker.setPoint(1, sf::Vector2f(refpoint.x, refpoint.y + length));
        kicker.setPoint(2, sf::Vector2f(refpoint.x - base, refpoint.y + length));
        kicker.setPoint(3, sf::Vector2f(refpoint.x - top, refpoint.y));

        kicker.setOrigin(refpoint.x, refpoint.y);
        kicker.setPosition(refpoint.x, refpoint.y);
        kicker.setFillColor(fillColor);
        kicker.setOutlineColor(outlineColor);
        kicker.setOutlineThickness(2);
        kicker.setScale(flip, 1.0f);

        window.draw(kicker);

}

	void Interface::drawSwitch(Vector2D refpoint, float length, float angle)
	{
        sf::RectangleShape Gate(sf::Vector2f(length, 5.f));
        Gate.rotate(angle);

        Gate.setPosition(refpoint.x,refpoint.y);
        Gate.setFillColor(gateFillColor);
        Gate.setOutlineColor(outlineColor);

        window.draw(Gate);

	}

    void Interface::drawGate(Vector2D refpoint, float arclength, float angle)
    {
        sf::ConvexShape Arc;
        Arc.setPointCount(9);

        // define the points
        Arc.setPoint(0, sf::Vector2f(refpoint.x, refpoint.y));
        Arc.setPoint(1, sf::Vector2f(refpoint.x + arclength/7, refpoint.y + 10));
        Arc.setPoint(2, sf::Vector2f(refpoint.x + 2*arclength/7, refpoint.y + 2 * 10));
        Arc.setPoint(3, sf::Vector2f(refpoint.x + 3 * arclength/7, refpoint.y + 2.2 * 10));
        Arc.setPoint(4, sf::Vector2f(refpoint.x + 4 * arclength / 7, refpoint.y + 2.5 * 10));
        Arc.setPoint(5, sf::Vector2f(refpoint.x + 5 * arclength/ 7, refpoint.y + 2.2 * 10));
        Arc.setPoint(6, sf::Vector2f(refpoint.x + 6*arclength/7, refpoint.y + 2 * 10));
        Arc.setPoint(7, sf::Vector2f(refpoint.x +  7* arclength/7, refpoint.y + 10));
        Arc.setPoint(8, sf::Vector2f(refpoint.x + 8* arclength/7, refpoint.y));
        Arc.setOutlineThickness(outlineThickness);
        Arc.setFillColor(switchFillColor);
        Arc.setOutlineColor(outlineColor);
       // Arc.setOrigin(sf::Vector2f(refpoint.x + sqrt((pow(2 * arclength, 2) - 4)), (refpoint.y + 2 * 1) - (-1 + (sqrt(pow(arclength, 2) - 1)) / 2))); // origin equation
        Arc.setOrigin(refpoint.x, refpoint.y);
        Arc.setPosition(refpoint.x, refpoint.y);
        Arc.setRotation(angle);
        window.draw(Arc);
    }

    void Interface::drawBumper(Vector2D center, float radius, bool coat) {
        sf::CircleShape bumper(radius);
        bumper.setOrigin(radius, radius);
        bumper.setPosition(center.x, center.y);
        bumper.setFillColor(fillColor);
        bumper.setOutlineColor(outlineColor);
        bumper.setOutlineThickness(2);

        if (coat) {
            bumper.setOutlineColor(sf::Color::Red);
            bumper.setOutlineThickness(6);
        }


        window.draw(bumper);
    }

    void Interface::drawSpeedBooster(Vector2D center, float radius)
    {

        CircleShape triangle;
        triangle.setRadius(radius);
        triangle.setPointCount(3);
        triangle.setOrigin(radius, radius);
        triangle.setPosition(center.x, center.y);
        triangle.setFillColor(Color::Green);
        triangle.setOutlineThickness(2.f);
        triangle.setOutlineColor(Color::Black);
        window.draw(triangle);
    }

    void Interface::drawCollectable(Vector2D center, float radius, Color color)
    {
        CircleShape C;
        C.setRadius(radius);
        C.setOrigin(radius, radius);
        C.setPosition(center.x, center.y);
        C.setFillColor(color);
        C.setOutlineThickness(2.f);
        C.setOutlineColor(Color::Black);
        window.draw(C);
    }

    void Interface::drawScoreMultiplier(Vector2D center, float radius)
    {
        CircleShape M;
        CircleShape N;

        M.setRadius(radius);
        M.setOrigin(radius, radius);
        M.setPosition(center.x, center.y);
        M.setFillColor(Color::Blue);
        M.setOutlineThickness(2.f);
        M.setOutlineColor(Color::Black);
        window.draw(M);

        N.setRadius(radius / 2);
        N.setOrigin(radius / 2, radius / 2);
        N.setPointCount(5);
        N.setPosition(center.x, center.y);
        N.setFillColor(Color::Yellow);
        N.setOutlineThickness(2.f);
        N.setOutlineColor(Color::Black);
        window.draw(N);
    }

    void Interface::drawScore(Vector2D center)
    {
        Font font;
        font.loadFromFile("Pacifico.ttf");

        if (!font.loadFromFile("Pacifico.ttf"))
        {
            cout << "error loading font";
        }

        else
        {
            if (isover == false)

            {
                Text text;
                text.setFont(font);
                text.setString("Score:"+to_string(SCORE));
                text.setFillColor(Color::Blue);
                text.setOutlineColor(Color::Black);
                text.setPosition(0, 0);
                text.setCharacterSize(20);
                text.setStyle(Text::Bold);
                window.draw(text);
            }

            else
            {
                Text text;
                text.setFont(font);
                text.setString("Game Over\nScore:" + to_string(SCORE));
                text.setFillColor(Color::Red);
                text.setOutlineColor(Color::Black);
                text.setPosition(200, 200);
                text.setCharacterSize(70);
                text.setStyle(Text::Bold);
                window.clear();
                window.draw(text);

            }

        }
    }
    
    void Interface::drawGameover(Vector2D center)
    {
        Font font;
        font.loadFromFile("Pacifico.ttf");

        if (!font.loadFromFile("Pacifico.ttf"))
        {
            cout << "error loading font";
        }

        else
        {
            Text text;
            text.setFont(font);
            text.setString("GAME OVER");
            text.setFillColor(Color::Blue);
            text.setOutlineColor(Color::Black);
            text.setPosition(center.x, center.y);
            text.setCharacterSize(220);
            text.setStyle(Text::Bold);
            window.draw(text);
        }
    }

    void Interface::setIsOver(bool x)
    {
        isover = x;

    }

    bool Interface::getIsOver()
    {
        return isover;
    }

    void Interface::setSCORE(int s)
    {
        SCORE = s;
    }

    int Interface::getSCORE()
    {
        return SCORE;
    }