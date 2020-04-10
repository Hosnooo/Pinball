
#include "Game.h"

#define GRAVITY 400.0f

Game::Game(): leftFlipper(LEFT, Vector2D{ GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f }, FLIPPER_LENGTH, 30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
            rightFlipper(RIGHT, Vector2D{ GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f }, FLIPPER_LENGTH, 30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),

            rightKicker(RIGHT, Vector2D{ GAME_WIDTH, GAME_HEIGHT - 200 }, KICKER_LENGTH, KICKER_BASE, KICKER_TOP),
            leftKicker(LEFT, Vector2D{ 0, GAME_HEIGHT - 200 }, KICKER_LENGTH, KICKER_BASE, KICKER_TOP),

            Gate1hor(Vector2D{ GAME_WIDTH - 25- GATE_LENGTH, GAME_HEIGHT - 500 }, GATE_LENGTH, GATE_HORIZONTAL),
            Gate2hor(Vector2D{ 25, GAME_HEIGHT - 500 }, GATE_LENGTH, GATE_HORIZONTAL),
            Gate1ver(Vector2D{ GAME_WIDTH - 100, GAME_HEIGHT - 250 }, GATE_LENGTH, GATE_VERTICAL),
            Gate2ver(Vector2D{ 100, GAME_HEIGHT - 250 }, GATE_LENGTH, GATE_VERTICAL),

            Switch1(Vector2D{ GAME_WIDTH - 200 - ARC_LENGTH, GAME_HEIGHT - 300 + ARC_LENGTH }, ARC_LENGTH, -70),
            Switch2(Vector2D{ 200 + ARC_LENGTH, GAME_HEIGHT - 300 }, ARC_LENGTH, 70),
            Switch3(Vector2D{ GAME_WIDTH - 100, GAME_HEIGHT - 650 + ARC_LENGTH}, ARC_LENGTH, - SWITCH_ROTAION),
            Switch4(Vector2D{ 100 + 3/2*ARC_LENGTH, GAME_HEIGHT - 650 }, ARC_LENGTH, SWITCH_ROTAION),

            // add some bumpers here.






               leftWall(1), rightWall(GAME_WIDTH) // This line should be removed
{
    lastFrame = high_resolution_clock::now();
    exit = left = right = false;
}

void Game::readInterfaceInput()
{
    interface.getControls(exit, left, right);
}

void Game::simulate()
{
    // Measuring time elapsed in-between frames
    high_resolution_clock::time_point thisFrame = high_resolution_clock::now();
    duration<float> timeSpan = duration_cast<duration<float>>(thisFrame - lastFrame);
    lastFrame = thisFrame;
    float deltaTime = timeSpan.count();  // Delta time in seconds

    Vector2D resultantAcceleration = {0, GRAVITY};  // Starting with gravity as the first acceleration contributer
    resultantAcceleration += leftWall.collideWith(ball, deltaTime);
    resultantAcceleration += rightWall.collideWith(ball, deltaTime);
    ball.move(resultantAcceleration, deltaTime);

   if (left)
        leftFlipper.rotate(); //this is the rotate flipper function
   else {
       leftFlipper.setAngle(30.f);
   }
   if (right)
       rightFlipper.rotate(); //this is the rotate flipper function
   else {
       rightFlipper.setAngle(-30.f);
   }
   
}

bool Game::GameOver()
{
    if (ball.getCenter().y - GAME_HEIGHT >= 0)
        return true;
    else
        return false;
}

void Game::updateInterfaceOutput()
{
    interface.clear();

    leftFlipper.draw(interface);
    rightFlipper.draw(interface);

    // The following two lines be replaced with a loop over collidable obstacles
    leftWall.draw(interface);
    rightWall.draw(interface);

    rightKicker.draw(interface);
    leftKicker.draw(interface);

    Gate1hor.draw(interface);
    Gate2hor.draw(interface);
    Gate1ver.draw(interface);
    Gate2ver.draw(interface);

    Switch1.draw(interface);
    Switch2.draw(interface);
    Switch3.draw(interface);
    Switch4.draw(interface);

    // draw some bumpers below.


    
    ball.draw(interface);
    interface.display();
}

bool Game::exited() {
    if(GameOver())
    {
        exit = GameOver();
    }
    return exit;
}