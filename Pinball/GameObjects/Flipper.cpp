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

void Flipper::rotate() {
    angle =-10;
    std:: cout << angle;
}
