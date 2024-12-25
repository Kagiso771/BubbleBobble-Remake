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

}

Screen::~Screen(){}

void Screen::wallLocations()
{
    for(auto linePos = 0; linePos < gridLines.size(); linePos++)
    {
        string temp = gridLines[linePos];
        for(auto blockPos = 0; blockPos < temp.length(); blockPos++)
        {
            if(temp[blockPos]=='#')
            {
                Vector2 tempVec {float(blockPos*50), float(linePos*50)};
                wallPositions.push_back(tempVec);
            }
        }
    }
}

void Screen::draw()
{
    for(auto i=0; i < wallPositions.size(); i++)
    {
        Rectangle temp = {wallPositions[i].x,wallPositions[i].y,blockSize.x,blockSize.y};
        walls.push_back(temp);
        DrawRectangleRec(temp, PINK);
    }
}