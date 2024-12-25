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
}

void Shooter::update()
{
    if(IsKeyDown(KEY_RIGHT))
    {
        playerPos.x +=10;
        facing = RIGHT;
    }
    else if(IsKeyDown(KEY_LEFT))
    {
        playerPos.x -=10;
        facing = LEFT;
    }
    jump();
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
