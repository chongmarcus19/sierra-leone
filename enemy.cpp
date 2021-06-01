#include "enemy.h"
#include "labyrinth.h"
#include <ctime>
using namespace std;

void Enemy::setLabyrinth(Labyrinth ok)
{
    l = ok;
}

//enemy function that returns integer based on decision made by user and monster randomly generated
int Enemy::encounter()
{
    srand(time(NULL));
    
    int x = (rand() %10);
    
    if (x >= 0 && x <= 5)
    {
        int trigger = 0;
        while (trigger != 1) {
        cout << "YOU HAVE ENCOUNTERED A GOBLIN" << endl;
        cout << "1. Fight?" << endl;
        cout << "2. Run?" << endl;
        string choice;
        cin >> choice;
        
        if (choice == "1")
        {
            return 11;
            trigger = 1;
        }
        
        if (choice == "2")
        {
            return 12;
            trigger = 1;
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
        int trigger2 = 0;
        
        while (trigger2 != 1) {
        cout << "YOU HAVE ENCOUNTERED A GORGON" << endl;
        cout << "1. Fight?" << endl;
        cout << "2. Run?" << endl;
        string choice2;
        cin >> choice2;
        
        if (choice2 == "1")
        {
            return 21;
            trigger2 = 1;
        }
        
        if (choice2 == "2")
        {
            return 22;
            trigger2 = 1;
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
        int trigger3 = 0;
        
        while (trigger3 != 1) {
            
        cout << "YOU HAVE ENCOUNTERED A CYCLOPS" << endl;
        cout << "1. fight?" << endl;
        cout << "2. run?" << endl;
        string choice3;
        cin >> choice3;
        
        if (choice3 == "1")
        {
            return 31;
            trigger3 = 1;
        }
        
        if (choice3 == "2")
        {
            return 32;
            trigger3 = 1;
        }
        
        else 
        {
            //user error
            cout << "Not an option" << endl;
        }
        
        }
    }
}
