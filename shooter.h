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
public:
    Shooter(Vector2 startingPos);
    ~Shooter();
    void draw();
    void update();
    void jump();
};

#endif /*SHOOTER*/
