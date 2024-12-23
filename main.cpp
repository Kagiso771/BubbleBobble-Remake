#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    

    cout << "Initializing Raylib" << endl;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Blank screen using raylib");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(BLACK);
    
        EndDrawing();
    }

    CloseWindow();
}