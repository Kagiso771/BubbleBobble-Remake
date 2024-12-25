#ifndef SCREEN
#define SCREEN
#include <iostream>
#include <fstream>
#include <vector>
#include <raylib.h>
#include <string>

using namespace std;

class Screen
{
private:
    
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    vector<string> gridLines;
    vector<Vector2> wallPositions;
    Vector2 blockSize {50,50};
    
public:
    Screen(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Screen();
    void wallLocations();
    void draw();
    vector<Rectangle> walls;
};

#endif /*SCREEN*/
