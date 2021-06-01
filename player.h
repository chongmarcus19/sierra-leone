#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
         Player();
         string getTheses();
         int getHealth();
         int getHunger();
         int getFood();
         int getCandles();
         int getProgress();
         int getPlayerSpeed();
         int getPlayerPower();
         int getPowerItem();
         int getSpeedItem();
         int getNumItems();
         int getItems(int);
         int getX();
         int getY();
         
         void rest(string);
         int eat(int);
         void inventory();
         
         void setTheses(string);
         void setHealth(int);
         void setHunger(int);
         void setCandles(int);
         void setFood(int);
         void setProgress(int);
         void setPlayerSpeed(int);
         void setPlayerPower(int);
         void setSpeedItem(int);
         void setPowerItem(int);
         void itemUse(int, int);
         void setItems(int, int);
         void setNumItems(int);
         void setX(int);
         void setY(int);
        
    private:
        string theses;
        int health;
        int hunger;
        int candles;
        int progress;
        int playerSpeed;
        int playerPower;
        int powerItem;
        int speedItem;
        int food;
        int items[5];
        int numItems;
        int x;
        int y;
        
        
};

#endif