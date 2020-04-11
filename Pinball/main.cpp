#include "Game.h"

int main()
{
    // Create an object of ApplicationManager
    Game game;
    while (!game.exited())
    {
        // Read new user (or whatever else)
        game.readInterfaceInput();
        // Simulate the game for one more frame
        game.simulate();
        // Update the game graphical interface
        game.updateInterfaceOutput();
        //checks if the player lost or not
        game.GameOver();
    }
    return 0;
}


/*This code was written for CIE 202 course project */