#include "map.h"
#include "player.h"
#include "tmz.h"
#include <ctime>
using namespace std;

string Map::same(string x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i] = tolower(x[i]);
    }
    return x;
}

Map::Map()
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

int Map::getX()
{
    return x;
}

int Map::getY()
{
    return y;
}

int Map::getPx()
{
    return px;
}

int Map::getPy()
{
    return py;
}

void Map::setX(int xx)
{
    x = xx;
}

void Map::setY(int yy)
{
    y = yy;
}

void Map::setPx(int pxx)
{
    px = pxx;
}

void Map::setPy(int pyy)
{
    py = pyy;
}

void Map::setTurn(int playerTurn)
{
    turn = playerTurn;
}

int Map::getTurn()
{
    return turn;
}

// print map matrix
void Map::displayMap()
{
    cout << endl
         << "PROGRESS" << endl
         << "F = you, T = tmz" << endl
         << "----------" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int n = 0; n < 10; n++)
        {
            cout << map[i][n];
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

void Map::setPlayer(Player p)
{
    players = p;
}

void Map::setTmz(Tmz m)
{
    tmzs = m;
}

// set positions of tmz and player
void Map::setMap(string player, int progress)
{
    int row = progress / 10;
    int column = progress % 10;
    if (player == "F")
    {
        if (getTurn() != 0)
        {
            map[getPx()][getPy()] = "x";
        }
        map[row][column] = player;
        setPx(row);
        setPy(column);
    }
    else
    {
        if (column >= 1)
        {
            map[getX()][getY()] = "x";
            map[row][column] = player;
            setX(row);
            setY(column);
        }
    }
}

// store genereated items into matrix
void Map::scavenge()
{
    srand(time(NULL));
    int random = (rand() % 101);
    int random2 = (rand() % 11);
    int currentItems = players.getNumItems();

    // food
    if (random >= 0 && random < 45)
    {
        int currentFood = players.getFood();
        if (random2 >= 0 && random2 <= 6)
        {
            players.setFood(currentFood + 1);
            players.setItems(currentFood + 1, 1);
            cout << "you have found one slice of bread" << endl;
        }
        if (random2 > 6 && random2 < 9)
        {
            players.setFood(currentFood + 2);
            players.setItems(currentFood + 2, 1);
            cout << "you have found two slices of bread" << endl;
        }
        if (random2 >= 9 && random2 <= 10)
        {
            players.setFood(currentFood + 3);
            players.setItems(currentFood + 3, 1);
            cout << "you have found three slices of bread" << endl;
        }
        players.setNumItems(currentItems + 1);
    }

    // power item
    if (random >= 45 && random < 70)
    {
        int powerItem;
        if (random2 >= 0 && random2 < 6)
        {
            powerItem = 1;
            cout << "you have found a pair of Nikes (power level 1)" << endl
                 << "pick up item? y/n (picking up a power item will replace your current power item)" << endl;
        }
        if (random2 >= 6 && random2 <= 9)
        {
            cout << "you have found a green Homer baby (power level 2)" << endl
                 << "pick up item? y/n (picking up a power item will replace your current power item)" << endl;
            powerItem = 2;
        }
        if (random2 == 10)
        {
            cout << "you have found green hair dye (power level 3)" << endl
                 << "pick up item? y/n (picking up a weapon will replace your current power item)" << endl;
            powerItem = 3;
        }
        string weaponChoice;
        cin >> weaponChoice;
        string lowerW = same(weaponChoice);

        if (lowerW == "y")
        {
            if (players.getPowerItem() != 0)
            {
                cout << "Power item successfully replaced" << endl;
            }
            if (players.getPowerItem() == 0)
            {
                cout << "Power item successfully picked up" << endl;
                players.setNumItems(currentItems + 1);
            }
            players.setPlayerPower(20 + powerItem * 20);
            players.setPowerItem(powerItem);
            players.setItems(powerItem, 2);
        }
        if (lowerW == "n")
        {
            cout << "Item not picked up" << endl;
        }
    }

    // speed item
    if (random >= 70 && random < 85)
    {
        int speedItem;
        if (random2 >= 0 && random2 <= 8)
        {
            cout << "you have found a white Ferrari (speed level 1)" << endl
                 << "take the car? y/n (taking speed item will replace current one)" << endl;
            speedItem = 1;
        }
        if (random2 >= 9)
        {
            cout << "you have found an orange BMW E30 (speed level 2)" << endl
                 << "take the car? y/n (taking speed item will replace current one)" << endl;
            speedItem = 2;
        }
        string speedChoice2;
        cin >> speedChoice2;
        string lowerS2 = same(speedChoice2);
        if (lowerS2 == "y")
        {
            if (players.getSpeedItem() == 1)
            {
                cout << "Speed item successfully replaced" << endl;
            }
            if (players.getSpeedItem() == 0)
            {
                cout << "Speed item succesfully possessed" << endl;
                players.setNumItems(currentItems + 1);
            }
            players.setPlayerSpeed(2 + speedItem);
            players.setSpeedItem(speedItem);
            players.setItems(speedItem, 3);
        }
        if (lowerS2 == "n")
        {
            cout << "Speed item not taken" << endl;
        }
    }

    // No items
    if (random >= 85 && random < 100)
    {
        cout << "There are no items in this room" << endl;
    }
}

// Player and TMZ functions
void Map::rest(int x)
{
    players.rest(x);
}

int Map::eat(int y)
{
    return players.eat(y);
}

int Map::getHunger()
{
    return players.getHunger();
}

int Map::getItems(int oh)
{
    return players.getItems(oh);
}

int Map::getFood()
{
    return players.getFood();
}

int Map::getHealth()
{
    return players.getHealth();
}

int Map::getPlayerSpeed()
{
    return players.getPlayerSpeed();
}

int Map::getProgress()
{
    return players.getProgress();
}

int Map::getProgressT()
{
    return tmzs.getProgress();
}

int Map::getSpeedT()
{
    return tmzs.getSpeed();
}

string Map::getTheses()
{
    return players.getTheses();
}

void Map::inventory()
{
    players.inventory();
}

void Map::setProgress(int e)
{
    players.setProgress(e);
}

void Map::setProgressT(int f)
{
    tmzs.setProgress(f);
}

void Map::setSpeedT(int g)
{
    tmzs.setSpeed(g);
}

void Map::setHunger(int hungry)
{
    players.setHunger(hungry);
}

void Map::setHealth(int h)
{
    players.setHealth(h);
}

void Map::setItems(int what, int the)
{
    players.setItems(what, the);
}