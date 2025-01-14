#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Defs.h"

// Represents the game interface
// This class is the ONLY one that interacts with the user
// This class is also the ONLY one aware of the graphics library being used
// That is, if the graphics library was to be changes, this class is the only thing to be changed
class Interface
{
private:
    sf::RenderWindow window;  // Represents the game window
    const sf::Color  // Colors used for drawing (can change the whole theme of the game)
        backgroundColor = sf::Color::White,
        outlineColor = sf::Color::Black,
        ballFillColor = sf::Color::White,
        fillColor = sf::Color::White,
        flipperFillColor = sf::Color::White,
        gateFillColor = sf::Color::Red,
        switchFillColor = sf::Color::White;
    const float outlineThickness = -2.0f;  // Negative sign means inwards
    bool isover = false;
    int SCORE = 0;
public:
    Interface();  // Constructor
    void getControls(bool & exit, bool & left, bool & right);  // Detects the buttons pressed

    void clear();  // Clears the frame (first step in rendering a new frame)
    void display();  // Displays the frame (last step in rendering a new frame)

    void drawBall(Vector2D center, float radius);  // Draws a ball
    void drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius);  // Draws a flipper
    void drawWall(float position);  // Draws a vertical wall
    void drawFloor(FlipperType type, float lenght, sf::Vector2f position);
    void drawKicker(FlipperType type, Vector2D refpoint, float length, float base, float top);  // Draws a Kicker
    void drawGate(Vector2D refpoint, float length, float angle); //Draws a Gate
    void drawSwitch(Vector2D refpoint, float length, float angle); //Draws a Switch
    void drawBumper(Vector2D center, float radius, bool coat); // Draws any Bumper
    void drawSpeedBooster(Vector2D center, float radius);
    void drawCollectable(Vector2D center, float radius, sf::Color color);
    void drawScoreMultiplier(Vector2D center, float radius);
    void drawScore(Vector2D center);
    void drawGameover(Vector2D center);
    void setIsOver(bool x);
    bool getIsOver();
    void setSCORE(int s);
    int getSCORE();
};
