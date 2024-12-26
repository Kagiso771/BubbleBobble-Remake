#include <iostream>
#include <fstream>
#include <vector>
#include <raylib.h>
#include <string>
#include "Screen.h"
#include "shooter.h"

using namespace std;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;

int main () 
{
    Screen gameScreen(SCREEN_WIDTH,SCREEN_HEIGHT);
    Shooter greenPlayer({80,660});

    cout << "Initializing Raylib" << endl;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Kagiso's Bubble Bobble");
    
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        gameScreen.draw();
        greenPlayer.update(gameScreen.walls);
        greenPlayer.draw();
        ClearBackground(BLACK);
    
        EndDrawing();
    }

    CloseWindow();
}