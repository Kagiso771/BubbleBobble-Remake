#include "shooter.h"

using namespace std;

Shooter::Shooter(Vector2 startingPos1)
{
    playerPos = startingPos1;
    facing=RIGHT;
}

Shooter::~Shooter() {}

void Shooter::draw()
{
    DrawRectangleV(playerPos,shooterSize,GREEN);
    playerRect = {playerPos.x,playerPos.y,shooterSize.x,shooterSize.y};
}

void Shooter::update(vector<Rectangle>& walls)
{
    if(IsKeyDown(KEY_RIGHT))
    {
        playerPos.x +=10;
        facing = RIGHT;
        translationalMove=true;
    }
    else if(IsKeyDown(KEY_LEFT))
    {
        playerPos.x -=10;
        facing = LEFT;
        translationalMove=true;
    }
    jump();
    collisionDetector(walls);
}

void Shooter::jump()
{
    if(IsKeyDown(KEY_UP))
    {
        playerPos.y -= 30;
        if(facing==faceDirection::RIGHT)
        {
            playerPos.x +=10;
        }
        else if(facing==faceDirection::LEFT)
        {
            playerPos.x -=10;
        }
    }
}

void Shooter::collisionDetector(vector<Rectangle>& walls)
{
    for(auto wall:walls)
    {
        if(translationalMove==true && facing==RIGHT && CheckCollisionRecs(playerRect, wall))
        {
            playerPos.x -=10;
        }
    }
    
}
