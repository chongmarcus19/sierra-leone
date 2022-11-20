#include "player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    health = 100;
    hunger = 100;
    progress = 1;
    playerSpeed = 2;
    playerPower = 10;
    candles = 0;
    powerItem = 0;
    speedItem = 0;
    food = 0;
    numItems = 0;
    x = 0;
    y = 0;
    theses = "";

    for (int m = 0; m < 5; m++)
    {
        items[m] = 0;
    }
}

string Player::getTheses()
{
    return theses;
}

int Player::getHealth()
{
    return health;
}

int Player::getHunger()
{
    return hunger;
}

int Player::getFood()
{
    return food;
}

int Player::getProgress()
{
    return progress;
}

int Player::getPlayerSpeed()
{
    return playerSpeed;
}

int Player::getPlayerPower()
{
    return playerPower;
}

int Player::getPowerItem()
{
    return powerItem;
}

int Player::getSpeedItem()
{
    return speedItem;
}

int Player::getNumItems()
{
    return numItems;
}

int Player::getItems(int indx)
{
    return items[indx];
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

void Player::setTheses(string win)
{
    theses = win;
}

void Player::setHealth(int playerHealth)
{
    health = playerHealth;
}

void Player::setHunger(int playerHunger)
{
    hunger = playerHunger;
}

void Player::setFood(int playerFood)
{
    food = playerFood;
}

void Player::setProgress(int playerProgress)
{
    progress = playerProgress;
}

void Player::setPlayerSpeed(int s)
{
    playerSpeed = s;
}

void Player::setPlayerPower(int p)
{
    playerPower = p;
}

void Player::setSpeedItem(int si)
{
    speedItem = si;
}

void Player::setPowerItem(int pi)
{
    powerItem = pi;
}

void Player::setItems(int item, int idx)
{
    items[idx] = item;
}

void Player::setNumItems(int items)
{
    numItems = items;
}

void Player::setX(int row)
{
    x = row;
}

void Player::setY(int col)
{
    y = col;
}

// inventory represented by matrix
void Player::inventory()
{
    int invetoryCur = 0;

    // row = category of item
    // column = item rarity
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        invetoryCur = invetoryCur + getItems(i);
        if (i == 1) // bread
        {
            if (getItems(i) != 0)
            {
                cout << getItems(i) << " slice(s) of bread" << endl;
            }
        }
        if (i == 2)
        {
            if (getItems(i) == 1)
            {
                cout << "- Pair of Nikes (Power level 1)" << endl;
            }

            if (getItems(i) == 2)
            {
                cout << "- Green Homer Baby (Power level 2)" << endl;
            }

            if (getItems(i) == 3)
            {
                cout << "- Green Hair Dye (Power level 3)" << endl;
            }
        }
        if (i == 3)
        {
            if (getItems(i) == 1)
            {
                cout << "- White Ferrari (Speed Level 1)" << endl;
            }

            if (getItems(i) == 2)
            {
                cout << "- Orange BMW E30 (Speed level 2)" << endl;
            }
        }
    }

    if (invetoryCur == 0)
    {
        cout << "No items in inventory" << endl;
    }
}

// Increase player health and move TMZ along map
void Player::rest(int restChoice)
{
    int currentHealth = getHealth();
    int newHealth = currentHealth + restChoice * 10;
    if (newHealth > 100)
    {
        setHealth(100);
    }
    else
    {
        setHealth(newHealth);
    }
}

int Player::eat(int eatChoice)
{
    int currentFood = getFood();
    int currentHunger = getHunger();
    if (currentFood < eatChoice)
    {
        return 0;
    }
    int newHunger = currentHunger + eatChoice * 10;
    if (newHunger > 100)
    {
        setHunger(100);
    }
    else
    {
        setHunger(newHunger);
    }
    return 1;
}