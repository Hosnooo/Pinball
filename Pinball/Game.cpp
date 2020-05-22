#include "Game.h"
using namespace sf;
#include<iostream>
using namespace std;

#define GRAVITY 400.0f

Game::Game() : leftFlipper(LEFT, Vector2D{ FLIPPER1_POSITION_X, FLIPPER_POSITION_Y }, FLIPPER_LENGTH, 30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
            rightFlipper(RIGHT, Vector2D{ FLIPPER2_POSITION_X, FLIPPER_POSITION_Y }, FLIPPER_LENGTH, 30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),

            leftFloor(LEFT, 50.0f, 200.0f),
            rightFloor(RIGHT, 50.0f, 200.0f),

            rightKicker(RIGHT, Vector2D{ GAME_WIDTH, FLIPPER_POSITION_Y - KICKER_LENGTH }, KICKER_LENGTH, KICKER_BASE, KICKER_TOP),
            leftKicker(LEFT, Vector2D{ 0, FLIPPER_POSITION_Y - KICKER_LENGTH }, KICKER_LENGTH, KICKER_BASE, KICKER_TOP),

            Gate1(Vector2D{ GAME_WIDTH - 40 - ARC_LENGTH, GAME_HEIGHT - 300 + ARC_LENGTH }, ARC_LENGTH, 0),
            Gate2(Vector2D{ 200 + ARC_LENGTH, GAME_HEIGHT - 300 }, ARC_LENGTH, 0),
            Gate3(Vector2D{ GAME_WIDTH - 100, GAME_HEIGHT - 650 + ARC_LENGTH }, ARC_LENGTH, 0),
            Gate4(Vector2D{ 100 + 3 / 2 * ARC_LENGTH, GAME_HEIGHT - 650 }, ARC_LENGTH, 0),

            Switch1(Vector2D{ GAME_WIDTH - 2 - GATE_LENGTH, GAME_HEIGHT - 500 }, GATE_LENGTH, GATE_HORIZONTAL),
            Switch2(Vector2D{ 25, GAME_HEIGHT - 500 }, GATE_LENGTH, GATE_HORIZONTAL), 
            Switch3(Vector2D{ GAME_WIDTH - 100, GAME_HEIGHT - 250 }, GATE_LENGTH, GATE_HORIZONTAL),
            Switch4(Vector2D{ 100, GAME_HEIGHT - 250 }, GATE_LENGTH, GATE_HORIZONTAL),
            
            //Odd numbered bumpers have coating.
            bumper1( Vector2D{ 500.0f,200.0f }, 40.0f, true),
            bumper2( Vector2D{ 400.0f,250.0f }, 35.0f, false),
            bumper3( Vector2D{ 300.0f,200.0f }, 40.0f, true),
            bumper4( Vector2D{ 400.0f,150.0f }, 30.0f, false),

            Sp1(SPEEDBOOSTER_RADIUS, Vector2D{ GAME_WIDTH / 2, GAME_HEIGHT - 200 }),
            Sp2(SPEEDBOOSTER_RADIUS, Vector2D{ GAME_WIDTH / 2,GAME_HEIGHT - 175 }),
            Sp3(SPEEDBOOSTER_RADIUS, Vector2D{ GAME_WIDTH / 2,GAME_HEIGHT - 150 }),
            Sp4(SPEEDBOOSTER_RADIUS, Vector2D{ GAME_WIDTH / 2,GAME_HEIGHT - 125 }),


            C1(COLLECTABLE_RADIUS, Vector2D{ GAME_WIDTH - 150,GAME_HEIGHT - 380 }),
            C2(COLLECTABLE_RADIUS, Vector2D{ GAME_WIDTH - 200,GAME_HEIGHT - 400 }),
            C3(COLLECTABLE_RADIUS, Vector2D{ GAME_WIDTH - 170,GAME_HEIGHT - 450 }),

            M1(MULTIPLIERS_RADIUS, Vector2D{ GAME_WIDTH - 500,GAME_HEIGHT - 475 }),
            M2(MULTIPLIERS_RADIUS, Vector2D{ GAME_WIDTH - 400,GAME_HEIGHT - 350 }),
            M3(MULTIPLIERS_RADIUS, Vector2D{ GAME_WIDTH - 550,GAME_HEIGHT - 300 }),

            s(Vector2D{ 0, 0 }),

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
    resultantAcceleration += Switch1.collideWith(ball, deltaTime);
    resultantAcceleration += Switch2.collideWith(ball, deltaTime);
    resultantAcceleration += Switch3.collideWith(ball, deltaTime);
    resultantAcceleration += Switch4.collideWith(ball, deltaTime);
    resultantAcceleration += Gate1.collideWith(ball, deltaTime);
    resultantAcceleration += Gate2.collideWith(ball, deltaTime);
    resultantAcceleration += Gate3.collideWith(ball, deltaTime);
    resultantAcceleration += Gate4.collideWith(ball, deltaTime);
    resultantAcceleration += M1.collideWith(ball, deltaTime);
    resultantAcceleration += M2.collideWith(ball, deltaTime);
    resultantAcceleration += M3.collideWith(ball, deltaTime);

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

void Game::GameOver()
{
     if (ball.getCenter().y - GAME_HEIGHT >= 0)
     {
         interface.drawGameover(Vector2D{ GAME_WIDTH / 2,GAME_HEIGHT / 2 });
     }

 }

    void Game::updateInterfaceOutput()
    {
        interface.clear();

        leftFlipper.draw(interface);
        rightFlipper.draw(interface);

        // The following two lines be replaced with a loop over collidable obstacles
        leftWall.draw(interface);
        rightWall.draw(interface);

        leftFloor.draw(interface);
        rightFloor.draw(interface);

        rightKicker.draw(interface);
        leftKicker.draw(interface);

        Gate1.draw(interface);
        Gate2.draw(interface);
        Gate3.draw(interface);
        Gate4.draw(interface);

        Switch1.draw(interface);
        Switch2.draw(interface);
        Switch3.draw(interface);
        Switch4.draw(interface);

        bumper1.draw(interface);
        bumper2.draw(interface);
        bumper3.draw(interface);
        bumper4.draw(interface);

        Sp1.draw(interface);
        Sp2.draw(interface);
        Sp3.draw(interface);
        Sp4.draw(interface);

        C1.draw(interface);
        C2.draw(interface);
        C3.draw(interface);

        M1.draw(interface);
        M2.draw(interface);
        M3.draw(interface);

        s.draw(interface);

        ball.draw(interface);
        interface.display();
    }
bool Game::exited() {
   /* if(GameOver())
        exit = GameOver();*/

    return exit;
}