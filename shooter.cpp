#include "shooter.h"

using namespace std;

Shooter::Shooter(Vector2 startingPos1)
{
    playerPos = startingPos1;
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
    }
    else if(IsKeyDown(KEY_LEFT))
    {
        playerPos.x -=10;
    }
    else if(IsKeyDown(KEY_UP))
    {
        playerPos.y -= 30;
    }
}
