#include "player.h"
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

int Player::getCandles()
{
    return candles;
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

// runs through items array and outputs based on value in the given index
void Player::inventory()
{
    cout << "" << endl;
    
    int oops = 0;
    
    for (int okie = 0; okie < 4; okie++)
    {
        oops = oops + getItems(okie);
        
        if (okie == 0)
        {
            if (getItems(okie) != 0)
            {
                cout << getItems(okie) << " slice(s) of bread" << endl;
            }
            
        }
        
        if (okie == 1)
        {
            if (getItems(okie) != 0)
            {
                cout << getItems(okie) << " candle(s)" << endl;
            }
        }
        
        if (okie == 2)
        {
            if (getItems(okie) == 1)
            {
                cout << "- Standard Blade (Power level 1)" << endl;
            }
            
            if (getItems(okie) == 2)
            {
                cout << "- Dark Axe (Power level 2)" << endl;
            }
            
            if (getItems(okie) == 3)
            {
                cout << "- Emerald Flail (Power level 3)" << endl;
            }
        }
        
        if (okie == 3)
        {
            if (getItems(okie) == 1)
            {
                cout << "- Combat Boots (Speed Level 2)" << endl;
            }
            
            if (getItems(okie) == 2)
            {
                cout << "- Enchanted Boots (Speed level 2)" << endl;
            }

        }
    }
    
    if (oops == 0)
    {
        cout << "No items in inventory" << endl;
    }
}
    
void Player::setTheses(string win)
{
    theses = win;
}

void Player::setHealth(int a)
{
    health = a;
}

void Player::setHunger(int b)
{
    hunger = b;
}

void Player::setFood(int z)
{
    food = z;
}

void Player::setCandles(int c)
{
    candles = c;
}

void Player::setProgress(int e)
{
    progress = e;
}

void Player::setPlayerSpeed(int g)
{
    playerSpeed = g;
}

void Player::setPlayerPower(int i)
{
    playerPower = i;
}

// Player can have only one speed item at a time
// depending on the integer that correlates with the item
// the player speed will be increase depending on what item it is
void Player::setSpeedItem(int h)
{
    speedItem = h;
}

// Player can have only one power item at a time
// depending on the integer that correlates with the item
// the player power will change depending on what item it is
// power is used to defend against enemies that aren't the minotaur
void Player::setPowerItem(int j)
{
    powerItem = j;
}


void Player::setItems(int ok, int idx)
{
    items[idx] = ok;
}

void Player::setNumItems(int bby)
{
    numItems = bby;
}

void Player::setX(int one)
{
    x = one;
}

void Player::setY(int two)
{
    y = two;
}

// player health recovers depending on how many hours player decides to rest.
// player will be static
// minotaur will still move
void Player::rest(string restChoice)
{
        int current = getHealth();
        
        if (restChoice == "1")
        {
            if (current >= 80)
            {
                setHealth(100);
            }
            
            else
            {
                setHealth(current + 20);
            }
            
        }
        
        if (restChoice == "2")
        {
            if (current >= 70)
            {
                setHealth(100);
            }
            
            else
            {
               setHealth(current + 30); 
            }
            
        }
        
        if (restChoice == "3")
        {
            if (current >= 50)
            {
                setHealth(100);
            }
            
            else
            {
                setHealth(current + 50);
            }
            
        }
}

//option 3 in menu
int Player::eat(int eatChoice)
{
    int currentFood = getFood();
    int currentHunger = getHunger();
        
    if (currentFood == 0)
    {
        return 0;
    }
    
    else {
        
    if (eatChoice == 1)
    {
        if (currentHunger >= 90)
        {
            setHunger(100);
            setFood(currentFood - 1);
            setItems(currentFood - 1, 0);
            return 1;
        }
                
        else
        {
            setHunger(currentHunger + 10);
            setFood(currentFood - 1);
            setItems(currentFood - 1, 0);
            return 1;
        }
    }
            
    if (eatChoice == 2)
    {
        if (currentFood < 2)
        {
           return 2;
        }
                
        else if (currentHunger >= 80)
        {
            setHunger(100);
            setFood(currentFood - 2);
            setItems(currentFood - 2, 0);
            return 1;
        }
                
        else
        {
            setHunger(currentHunger + 20);
            setFood(currentFood - 2);
            setItems(currentFood - 2, 0);
            return 1;
        }
    }
            
    if (eatChoice == 3)
    {
        if (currentFood < 3)
        {
            return 2;
        }
                
        else if (currentHunger >= 70)
        {
            setHunger(100);
            setFood(currentFood - 3);
            setItems(currentFood - 3, 0);
            return 1;
        }
                
        else
        {
            setHunger(currentHunger + 30);
            setFood(currentFood - 3);
            setItems(currentFood - 3, 0);
            return 1;
        }
    }

    }

}