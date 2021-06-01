#include "minotaur.h"
using namespace std;

Minotaur::Minotaur()
{
    speed = 2;
    progress = -10; // starting position, giving player a headstart
}

int Minotaur::getSpeed()
{
    return speed;
}

int Minotaur::getProgress()
{
    return progress;
}

void Minotaur::setProgress(int a)
{
    progress = a;
}

void Minotaur::setSpeed(int b)
{
    speed = b;
}
