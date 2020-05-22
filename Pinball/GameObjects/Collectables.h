#pragma once
#include "Drawable.h"
#include "Ball.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<string>

class Collectables :public Drawable


{
private:
    float radius;  // Radius of the speedbooster
    Vector2D center;  // The instantaneous center of the ball
    bool collidedLastFrame;

public:

    Collectables();
    explicit Collectables(float radius, Vector2D center);  // Constructor

    // Accessors
    float getRadius() const;
    Vector2D getCenter() const;
    void draw(Interface& interface) override;
    void ChangeColor(Ball& ball, Interface& interface);
};