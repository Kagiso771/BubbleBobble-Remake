#include "shooter.h"

using namespace std;

Shooter::Shooter(Vector2 startingPos1)
{
    playerPos = startingPos1;
    facing=RIGHT;
    translationalMove=true;
}

Shooter::~Shooter() {}

void Shooter::draw()
{
    DrawRectangleV(playerPos,shooterSize,GREEN);
    playerRect = {playerPos.x,playerPos.y,shooterSize.x,shooterSize.y};
}

void Shooter::update(vector<Rectangle>& walls)
{
    RestrictWithinWalls();
    if(IsKeyDown(KEY_RIGHT) && translationalMove==true)
    {
        playerPos.x +=10;
        facing = RIGHT;
    }
    else if(IsKeyDown(KEY_LEFT) && translationalMove==true)
    {
        playerPos.x -=10;
        facing = LEFT;
       // translationalMove=true;
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
        
    }
    
}
void Shooter::RestrictWithinWalls()
{
  if (playerPos.x <= horizontalWalls.x)
  {
    playerPos.x = 50;
  }
  else if ((playerPos.x+40) >= horizontalWalls.y)
  {
    playerPos.x = 510;
  }
  
}
