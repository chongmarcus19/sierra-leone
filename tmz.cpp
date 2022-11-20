#include "tmz.h"
using namespace std;

Tmz::Tmz()
{
    speed = 2;
    progress = -10; // starting position giving player a headstart
}

int Tmz::getSpeed()
{
    return speed;
}

int Tmz::getProgress()
{
    return progress;
}

void Tmz::setProgress(int a)
{
    progress = a;
}

void Tmz::setSpeed(int b)
{
    speed = b;
}
