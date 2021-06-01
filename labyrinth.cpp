#include "labyrinth.h"
#include "player.h"
#include "minotaur.h"
#include <ctime>
using namespace std;

// converts all characters in string into lowercase
string Labyrinth::same(string x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i] = tolower(x[i]);
    }
    
    return x;
}

Labyrinth::Labyrinth()
{
    size = 100;
    x = 0;
    y = 0;
    turn = 0;
    
    for (int i = 0; i < 10; i++)
    {
        for (int n = 0; n < 10; n++)
        {
            map[i][n] = "x";
        }
    }
}

// getters to enable storing of previous coordinates of Minotaur and Player
int Labyrinth::getX()
{
    return x;
}

int Labyrinth::getY()
{
    return y;
}

int Labyrinth::getPx()
{
    return px;
}

int Labyrinth::getPy()
{
    return py;
}

void Labyrinth::setX(int juan)
{
    x = juan;
}

void Labyrinth::setY(int juann)
{
    y = juann;
}

void Labyrinth::setPx(int mom)
{
    px = mom;
}

void Labyrinth::setPy(int dad)
{
    py = dad;
}

void Labyrinth::setTurn(int bob)
{
    turn = bob;
}

int Labyrinth::getTurn()
{
    return turn;
}

// uses for loop to run through the map array
void Labyrinth::displayMap()
{
    cout << "" << endl;
    cout << "PROGRESS" << endl;
    cout << "P = you, M = Minotaur" << endl;
    cout << "----------" << endl;
        
    for (int i = 0; i < 10; i++)
    {
        for (int n = 0; n < 10; n++)
        {
            cout << map[i][n];
        }
        
        cout << "" << endl;
    }
    
    cout << "----------" << endl;
}

// sets minotaur and player objects
void Labyrinth::setPlayer(Player p)
{
    players = p;
}

void Labyrinth::setMinotaur(Minotaur m)
{
    minotaurs = m;
}

// sets positions of minotaur and player based on their progress integer value
// sets previous position as "x" (empty)
void Labyrinth::setMap(string player, int progress)
{
    int row = progress/10;
    int column = progress%10;
    
    if (player == "p")
    {
        if (getTurn() != 0)
        {
           map[getPx()][getPy()] = "x"; 
        }
        
        map[row][column] = player;
        
        setPx(row);
        setPy(column);
    }
    
    else {
    
    if (column >= 1) {
    
    map[getX()][getY()] = "x";
    map[row][column] = player;
    
    setX(row);
    setY(column);
    
    }}
}

// randomly generates a variety of items with different uses
// stores them into items array
// prompts user whether they want to pick up the item or not
void Labyrinth::scavenge()
{
        srand(time(NULL));
        
        int random = (rand() %101);
        int random2 = (rand() % 11);
        int currentItems = players.getNumItems();
        
        if (random >= 0 && random < 45)
        {
            int fud = players.getFood();
            
            if (random2 >= 0 && random2 <= 6)
            {
                players.setFood(fud + 1);
                players.setNumItems(currentItems + 1);
                players.setItems(fud + 1, 0);
                
                cout << "you have found one slice of bread" << endl;
            }
            
            if (random2 > 6 && random2 < 9)
            {
                players.setFood(fud + 2);
                players.setNumItems(currentItems + 1);
                players.setItems(fud + 2, 0);
                
                cout << "you have found two slices of bread" << endl;
            }
            
            if (random2 >= 9 && random2 <= 10)
            {
                players.setFood(fud + 3);
                players.setNumItems(currentItems + 1);
                players.setItems(fud + 3, 0);
                
                cout << "you have found three slices of bread" << endl;
            }
        }
        
        
        if (random >= 45 && random < 70)
        {
            if (random2 >= 0 && random2 < 6)
            {
                cout << "you have found a standard blade (power level 1)" << endl;
                cout << "pick up weapon? y/n (picking up a weapon will replace your current one)" << endl;
                
                string weaponChoice;
                cin >> weaponChoice;
                
                string lowerW = same(weaponChoice);
                
                if (lowerW == "y")
                {
                    if (players.getPowerItem() != 0)
                    {
                        cout << "Weapon successfully replaced" << endl;
                        players.setItems(1, 2);
                        players.setPlayerPower(40);
                        players.setPowerItem(1);
                    }
                    
                    if (players.getPowerItem() == 0)
                    {
                        cout << "Weapon successfully picked up" << endl;
                        players.setItems(1, 2);
                        players.setNumItems(currentItems + 1);
                        players.setPowerItem(1);
                        players.setPlayerPower(40);
                    }
                    
                }
                
                if (lowerW == "n")
                {
                    cout << "Weapon not picked up" << endl;
                }
            }
            
            if (random2 >= 6 && random2 <= 8)
            {
                cout << "you have found a dark axe (power level 2)" << endl;
                cout << "pick up weapon? y/n (picking up a weapon will replace your current one)" << endl;
                
                string weaponChoice2;
                cin >> weaponChoice2;
                
                string lowerW2 = same(weaponChoice2);
                
                if (lowerW2 == "y")
                {
                    if (players.getPowerItem() != 0)
                    {
                        cout << "Weapon successfully replaced" << endl;
                        players.setItems(2, 2);
                        players.setPowerItem(2);
                        players.setPlayerPower(60);
                    }
                
                    if (players.getPowerItem() == 0)
                    {
                        cout << "Weapon successfully picked up" << endl;
                        players.setItems(2, 2);
                        players.setNumItems(currentItems + 1);
                        players.setPowerItem(2);
                        players.setPlayerPower(60);
                    }
                }
                
                if (lowerW2 == "n")
                {
                    cout << "Weapon not picked up" << endl;
                }
                
            }
            
            if (random2 > 8 && random2 <= 10)
            {
                cout << "you have found an emerald flail (power level 3)" << endl;
                cout << "pick up weapon? y/n (picking up a weapon will replace your current one)" << endl;
                
                string weaponChoice3;
                cin >> weaponChoice3;
                
                string lowerW3 = same(weaponChoice3);
                
                if (lowerW3 == "y")
                {
                    if (players.getPowerItem() != 0)
                    {
                        cout << "Weapon successfully replaced" << endl;
                        players.setItems(3, 2);
                        players.setPlayerPower(80);
                        players.setPowerItem(3);
                    }
                
                    if (players.getPowerItem() == 0)
                    {
                        cout << "Weapon successfully picked up" << endl;
                        players.setItems(3, 2);
                        players.setNumItems(currentItems + 1);
                        players.setPowerItem(3);
                        players.setPlayerPower(80);
                    }
                }
                
                if (lowerW3 == "n")
                {
                    cout << "Weapon not picked up" << endl;
                }
            }
        }
        
        
        if (random >= 70 && random < 85)
        {
            
            if (random2 >= 0 && random2 <= 9)
            {
                cout << "you have found combat boots (speed level 1)" << endl;
                cout << "pick up boots? y/n (picking up boots will replace your current boots)" << endl;
                
                string speedChoice2;
                cin >> speedChoice2;
                
                string lowerS2 = same(speedChoice2);
                
                if (lowerS2 == "y")
                {
                    if (players.getSpeedItem() == 1)
                    {
                        cout << "Boots succesfully replaced" << endl;
                        players.setItems(1, 3);
                        players.setPlayerSpeed(3);
                    }
                    
                    if (players.getSpeedItem() == 0)
                    {
                        cout << "Boots successfully picked up" << endl;
                        players.setItems(1, 3);
                        players.setNumItems(currentItems + 1);
                        players.setSpeedItem(1);
                        players.setPlayerSpeed(3);
                    }
                }
                
                if (lowerS2 == "n")
                {
                    cout << "Boots not picked up" << endl;
                }
                
            }
            
            if (random2 > 9 && random2 <= 10)
            {
                cout << "you have found enchanted boots (speed level 2)" << endl;
                cout << "pick up boots? y/n (picking up boots will replace your current boots)" << endl;
                
                string speedChoice3;
                cin >> speedChoice3;
                
                string lowerS3 = same(speedChoice3);
                
                if (lowerS3 == "y")
                {
                    if (players.getSpeedItem() == 1)
                    {
                        cout << "Boots succesfully replaced" << endl;
                        players.setItems(2, 3);
                        players.setPlayerSpeed(4);
                    }
                    
                    if (players.getSpeedItem() == 0)
                    {
                        cout << "Boots successfully picked up" << endl;
                        players.setItems(2, 3);
                        players.setNumItems(currentItems + 1);
                        players.setSpeedItem(1);
                        players.setPlayerSpeed(4);
                    }
                }
                
                if (lowerS3 == "n")
                {
                    cout << "Boots not picked up" << endl;
                }
                
            }
            
        }

        if (random >= 85 && random < 90)
        {
            cout << "There are no items in this room" << endl;
        }

        
        if (random >= 90 && random <= 100)
        {
            cout << "you've found one candle" << endl;
            
            int currentCandles = players.getCandles();
            
            players.setItems(currentCandles + 1, 1);
            players.setNumItems(currentItems + 1);
            players.setCandles(currentCandles + 1);
        }
        
}

// PLAYER AND MINOTAUR FUNCTIONS

void Labyrinth::rest(string x)
{
    players.rest(x);
}

int Labyrinth::eat(int y)
{
    return players.eat(y);
}

int Labyrinth::getHunger()
{
    return players.getHunger();
}

int Labyrinth::getItems(int oh)
{
    return players.getItems(oh);
}

int Labyrinth::getCandles()
{
    return players.getCandles();
}

int Labyrinth::getFood()
{
    return players.getFood();
}

int Labyrinth::getHealth()
{
    return players.getHealth();
}

int Labyrinth::getPlayerSpeed()
{
    return players.getPlayerSpeed();
}

int Labyrinth::getProgress()
{
    return players.getProgress();
}

int Labyrinth::getProgressM()
{
    return minotaurs.getProgress();
}

int Labyrinth::getSpeedM()
{
    return minotaurs.getSpeed();
}

string Labyrinth::getTheses()
{
    return players.getTheses();
}

void Labyrinth::inventory()
{
    players.inventory();
}

void Labyrinth::setProgress(int e)
{
    players.setProgress(e);
}

void Labyrinth::setProgressM(int f)
{
    minotaurs.setProgress(f);
}

void Labyrinth::setSpeedM(int g)
{
    minotaurs.setSpeed(g);
}

void Labyrinth::setHunger(int hungry)
{
    players.setHunger(hungry);
}

void Labyrinth::setHealth(int h)
{
    players.setHealth(h);
}

void Labyrinth::setItems(int what, int the)
{
    players.setItems(what, the);
}

void Labyrinth::setCandles(int boi)
{
    players.setCandles(boi);
}