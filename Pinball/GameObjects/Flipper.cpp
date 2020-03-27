#include "Flipper.h"
#include <iostream>

Flipper::Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius):
    type(type), center(center), length(length), angle(angle), majorRadius(majorRadius), minorRadius(minorRadius) {}

Vector2D Flipper::collideWith(Ball & ball, float collisionTime)
{
    return Vector2D {0, 0};  // Should be replaced with the actual collision logic
}

void Flipper::draw(Interface & interface)
{
    interface.drawFlipper(type, center, length, angle, majorRadius, minorRadius);
}


//Rotate the flipper.
void Flipper::rotate() {
    if( type== LEFT&& angle>-50)
    angle-=20; // negative sign to rotate counterclock wise for the left flipper.
   
    if (type == RIGHT && angle <50)
        angle += 20; 
      std:: cout << angle; // to see the change in angle in the console window.
}

void Flipper::setAngle(float angle) {
    this->angle = angle;
}