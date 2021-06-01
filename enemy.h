#ifndef ENEMY_H
#define ENEMY_H
#include "labyrinth.h"
#include <iostream>
#include <string>
using namespace std;

class Enemy
{
    public:
        void setLabyrinth(Labyrinth);
        int encounter();
    
    private:
        Labyrinth l;
};

#endif