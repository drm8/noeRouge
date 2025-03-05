// noeRouge - Terminal rouge-like ascii dungeon crawler game

// Includes
#include <iostream>
#include <vector>
#include <cstdlib>

// Local includes
#include "object.h"

/*
// TODO list (class voted it to be here)
// This list is worse than a todo at each thing because you have to just figure
// out where to work on each item listed here
//
// Doing it this way is objectivly worse in every way and has only
// disadvantages. I will comply but I beg that everyone agrees to 
// do it the other way instead
//
// 00 - Create a "game" class that holds deltatime, the map, the handlers, and
//      the game loop isRunning flag. This object will be global
// 01 - Game loop with time code
*/

int main() {
    // TODO 00
    bool isGameRunning = true;
    // Create the objectHandler
    class objectHandler objectHandler;
    class gameObject *testObject;

    // Print version info
    std::cout << "noeRouge alpha v0.1\n";

    // Test object creation
    objectHandler.createObject();
    testObject = objectHandler.getObject(0);
    std::cout << testObject->getId() << std::endl;

    objectHandler.tickAll();

    // TODO 01
    /*
    while (isGameRunning) {
        time stuff

        if (tick) {
            objectHandler.tickAll();
        }
    }
    */

    return 0;
}
