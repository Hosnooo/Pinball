#pragma once

struct Vector2D  // Represents a 2D vector
{
    float x = 0;  // The first coordinate
    float y = 0;  // The second coordinate
    Vector2D operator*(float scale) { return Vector2D{x * scale, y * scale}; }  // Scalar multiplication
    Vector2D operator/(float scale) { return Vector2D{x / scale, y / scale}; }  // Scalar division
    Vector2D operator+(float scale) { return Vector2D{x + scale, y + scale}; }  // Scalar addition
    Vector2D operator-(float scale) { return Vector2D{x - scale, y - scale}; }  // Scalar subtraction
    Vector2D operator*(const Vector2D & v) { return Vector2D{x * v.x, y * v.y}; }  // Element-wise multiplication
    Vector2D operator/(const Vector2D & v) { return Vector2D{x / v.x, y / v.y}; }  // Element-wise division
    Vector2D operator+(const Vector2D & v) { return Vector2D{x + v.x, y + v.y}; }  // Element-wise addition
    Vector2D operator-(const Vector2D & v) { return Vector2D{x - v.x, y - v.y}; }  // Element-wise subtraction
    Vector2D & operator*=(const Vector2D & v) { x *= v.x; y *= v.y; return *this; }  // Element-wise multiplication
    Vector2D & operator/=(const Vector2D & v) { x /= v.x; y /= v.y; return *this; }  // Element-wise division
    Vector2D & operator+=(const Vector2D & v) { x += v.x; y += v.y; return *this; }  // Element-wise addition
    Vector2D & operator-=(const Vector2D & v) { x -= v.x; y -= v.y; return *this; }  // Element-wise subtraction
};

enum FlipperType { LEFT, RIGHT };

// Should be replaced by a config file!
#define GAME_WIDTH 700
#define GAME_HEIGHT 750
#define BALL_RADIUS 10
#define INITIAL_CENTER {200, 10}
#define INITIAL_VELOCITY {200, 300}
#define FLIPPER_MAJOR_RADIUS 10
#define FLIPPER_MINOR_RADIUS 5
#define FLIPPER_LENGTH 50
#define FLIPPERS_DISTANCE FLIPPER_LENGTH
#define FLIPPER_POSITION_Y GAME_HEIGHT - 50.0f
#define FLIPPER1_POSITION_X  GAME_WIDTH / 2.0f - (FLIPPER_LENGTH)
#define FLIPPER2_POSITION_X  GAME_WIDTH / 2.0f + (FLIPPER_LENGTH)
#define KICKER_LENGTH 100
#define KICKER_TOP 30
#define KICKER_BASE 200
#define GATE_LENGTH 6*BALL_RADIUS
#define GATE_VERTICAL 90
#define GATE_HORIZONTAL 0
#define ARC_LENGTH 6*BALL_RADIUS
#define SWITCH_ROTAION 90
#define SPEEDBOOSTER_RADIUS 15
#define COLLECTABLE_RADIUS 20
#define MULTIPLIERS_RADIUS 40
