#include "enemy.h"
#include "map.h"
#include <ctime>
using namespace std;

void Enemy::setMap(Map mapObj)
{
    m = mapObj;
}

// returns integer based on decision made by user and enemey
int Enemy::encounter()
{
    srand(time(NULL));
    int x = (rand() % 10);
    int choiceMade = false;
    if (x >= 0 && x <= 5)
    {
        while (choiceMade != true)
        {
            cout << endl
                 << "A WILD CHRIS BROWN APPEARS" << endl
                 << "1. Throw hands" << endl
                 << "2. Run away" << endl;
            string choice;
            cin >> choice;
            if (choice == "1" || choice == "2")
            {
                choiceMade = true;
            }
            if (choice == "1")
            {
                return 11;
            }
            if (choice == "2")
            {
                return 12;
            }
            else
            {
                // user error
                cout << "Not an option" << endl;
            }
        }
    }
    if (x > 5 && x <= 8)
    {
        while (choiceMade != true)
        {
            cout << endl
                 << "A WILD TYLER THE CREATOR APPEARS" << endl
                 << "1. Throw hands" << endl
                 << "2. Ignore him and run" << endl;
            string choice2;
            cin >> choice2;
            if (choice2 == "1" || choice2 == "2")
            {
                choiceMade = true;
            }
            if (choice2 == "1")
            {
                return 21;
            }

            if (choice2 == "2")
            {
                return 22;
            }
            else
            {
                // user error
                cout << "Not an option" << endl;
            }
        }
    }
    if (x == 9)
    {
        while (choiceMade != true)
        {
            cout << endl
                 << "MOM JUST CALLED" << endl
                 << "1. Listen to her rant about being yourself" << endl
                 << "2. Hang up and keep running" << endl;
            string choice3;
            cin >> choice3;
            if (choice3 == "1" || choice3 == "2")
            {
                choiceMade = true;
            }
            if (choice3 == "1")
            {
                return 31;
            }
            if (choice3 == "2")
            {
                return 32;
            }
            else
            {
                //user error
                cout << "Not an option" << endl;
            }
        }
    }
    return -1;
}
