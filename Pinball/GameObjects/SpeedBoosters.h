#pragma once
#include "Drawable.h"




class SpeedBoosters:public Drawable
{
private:
    float radius;  // Radius of the speedbooster
    Vector2D center;  // The instantaneous center of the ball
      
public:

    SpeedBoosters();
    explicit SpeedBoosters(float radius,Vector2D center);  // Constructor

    // Accessors
    float getRadius() const;
    Vector2D getCenter() const;
    void draw(Interface& interface) override;



};

