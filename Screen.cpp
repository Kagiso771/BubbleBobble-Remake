#include "Screen.h"

using namespace std;

Screen::Screen(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    this->SCREEN_HEIGHT=SCREEN_HEIGHT;
    this->SCREEN_WIDTH=SCREEN_WIDTH;

      //Reading Grid Characteristics From Text File, For Easier Game Screen Management
    string filePath = "./resources/grid.txt";
    ifstream file(filePath);
    if (!file.is_open()) 
    {
        cerr << "Failed to open file: " << filePath << endl;
    }
    string line;
    while (getline(file, line)) 
    {
        gridLines.push_back(line);
    }
    file.close();

    //Developing Screen Structure
    wallLocations();
    mazeBlocks();
}

Screen::~Screen(){}

void Screen::blockCalculator(vector<Vector2>& Positions, char blockRep)
{
    for(auto linePos = 0; linePos < gridLines.size(); linePos++)
    {
        string temp = gridLines[linePos];
        for(auto blockPos = 0; blockPos < temp.length(); blockPos++)
        {
            if(temp[blockPos]== blockRep)
            {
                Vector2 tempVec {float(blockPos*50), float(linePos*50)};
                Positions.push_back(tempVec);
            }
        }
    }
}
void Screen::wallLocations()
{
    blockCalculator(wallPositions, '#');
}

void Screen::mazeBlocks()
{
    blockCalculator(blockPositions, 'M');
}

void Screen::draw()
{
    for(auto i=0; i < wallPositions.size(); i++)
    {
        Rectangle temp = {wallPositions[i].x,wallPositions[i].y,blockSize.x,blockSize.y};
        DrawRectangleRec(temp, PINK);
    }
    for(auto i=0; i < blockPositions.size(); i++)
    {
        Rectangle temp = {blockPositions[i].x,blockPositions[i].y,blockSize.x,blockSize.y};
        gridBlocks.push_back(temp);
        DrawRectangleRec(temp, PINK);
    }
    walkingPads();
}
void Screen::walkingPads()
{
    Rectangle groundLevel = {50,745,500,5};
    walkingPath.push_back(groundLevel);
    Rectangle firstLevel = {200,545,200,5};
    walkingPath.push_back(firstLevel);
    Rectangle secondLevel = {200,345,200,5};
    walkingPath.push_back(secondLevel);
    DrawRectangleRec(groundLevel, WHITE);
    DrawRectangleRec(firstLevel, WHITE);
    DrawRectangleRec(secondLevel, WHITE);

    
}