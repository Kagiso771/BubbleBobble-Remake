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
    vector<Vector2> blockPositions;
    Vector2 blockSize {50,50};
protected:
    void blockCalculator(vector<Vector2>& Positions, char blockRep);
    void wallLocations();
    void mazeBlocks();
public:
    Screen(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Screen();
    void draw();
    vector<Rectangle> gridBlocks;
};

#endif /*SCREEN*/
