#pragma once

#include <chrono>

using namespace std::chrono;

#include <string>

#include "Interface.h"
#include "Defs.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Obstacles/Wall.h"
#include "GameObjects/Flipper.h"
#include "GameObjects/Obstacles/Kicker.h"
#include "GameObjects/Obstacles/Gate.h"
#include "GameObjects/Obstacles/Switch.h"
#include"GameObjects/Obstacles/Bumper.h"
#include "GameObjects/Obstacles/ScoreMultipliers.h"
#include "GameObjects/Score.h"
#include "GameObjects/Collectables.h"
#include "GameObjects/SpeedBoosters.h"





// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    high_resolution_clock::time_point lastFrame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right;  // Flags about the user's current controls

    Ball ball;  // The ball (obviously :D)
    Flipper leftFlipper, rightFlipper;  // The right and left flippers
    Kicker rightKicker, leftKicker; // The right and left kickers
    Gate   Gate1, Gate2, Gate3, Gate4; // 4 Gates
    Switch Switch1, Switch2, Switch3, Switch4; // 4 Switches
    Bumper bumper1, bumper2, bumper3, bumper4;  // 4 Bumpers. odd numbered bumpers have coating.
    SpeedBoosters Sp1, Sp2, Sp3, Sp4; //3 speedboosters
    Collectables C1, C2, C3;
    ScoreMultipliers M1, M2, M3;
    Score s;
    
    Wall leftWall, rightWall;  // This line should be replaced by an array of obstacles
public:
    Game();
    void readInterfaceInput();
    void simulate();
    void GameOver();
    void updateInterfaceOutput();
    bool exited();
};
