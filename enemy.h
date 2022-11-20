#ifndef ENEMY_H
#define ENEMY_H
#include "map.h"
#include <iostream>
#include <string>
using namespace std;

class Enemy
{
public:
    void setMap(Map);
    int encounter();

private:
    Map m;
};

#endif