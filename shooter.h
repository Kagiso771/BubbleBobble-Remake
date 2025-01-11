#ifndef SHOOTER
#define SHOOTER
#include <iostream>
#include <fstream>
#include <vector>
#include <raylib.h>
#include <string>

using namespace std;


class Shooter
{
private:
    Vector2 playerPos;
    Vector2 shooterSize {40, 80};
    enum faceDirection {LEFT, RIGHT};
    faceDirection facing;
    bool translationalMove;
    Rectangle playerRect;
    Vector2 horizontalWalls {50,550};
    Vector2 verticalWalls {150, 750};
    bool jumpFlag;
protected:
    void jump();
    void collisionDetector(vector<Rectangle>& walls);
    void RestrictWithinWalls();
    void falling();
public:
    Shooter(Vector2 startingPos);
    ~Shooter();
    void draw();
    void update(vector<Rectangle>& walls);
    
};

#endif /*SHOOTER*/
