#pragma once
#include"Obstacle.h"

class ScoreMultipliers:public Obstacle


{

    private:
        float radius;  // Radius of the speedbooster
        Vector2D center;  // The instantaneous center of the ball


    public:

        ScoreMultipliers();
        explicit ScoreMultipliers(float radius, Vector2D center);  // Constructor

        // Accessors
        float getRadius() const;
        Vector2D getCenter() const;
        void draw(Interface & interface) override;
        Vector2D collideWith(Ball& ball, float collisionTime) override;


};

