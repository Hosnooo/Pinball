#pragma once
#include "Obstacles/Obstacle.h"



class SpeedBoosters:public Obstacle
{
private:
    float radius;  // Radius of the speedbooster
    Vector2D center;  // The instantaneous center of the ball
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)
      
public:

    SpeedBoosters();
    explicit SpeedBoosters(float radius,Vector2D center);  // Constructor

    // Accessors
    float getRadius() const;
    Vector2D getCenter() const;
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;



};

