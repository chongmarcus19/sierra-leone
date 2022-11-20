#ifndef MAP_H
#define MAP_H
#include "player.h"
#include "tmz.h"
#include <iostream>
#include <string>
using namespace std;

class Map
{
public:
    Map();

    int getX();
    int getY();
    int getPx();
    int getPy();

    void displayMap();
    void setX(int);
    void setY(int);
    void setPx(int);
    void setPy(int);
    void scavenge();
    void setMap(string, int);
    int getTurn();

    //player and tmz functions
    void setPlayer(Player);
    void setTmz(Tmz);
    void rest(int);
    int eat(int);
    void inventory();
    int getHunger();
    int getItems();
    int getFood();
    int getHealth();
    int getPlayerSpeed();
    int getProgress();
    int getProgressT();
    int getSpeedT();
    int getItems(int);
    string getTheses();
    void setTheses(string);
    void setProgress(int);
    void setTurn(int);
    void setProgressT(int);
    void setSpeedT(int);
    void setHunger(int);
    void setHealth(int);
    void setItems(int, int);

private:
    int size;
    int lighting;
    int obstacles;
    int x;
    int y;
    int turn;
    int px;
    int py;
    string map[11][10];

    Player players;
    Tmz tmzs;

    string same(string);
};
#endif