// Marcus Chong
// LIBERATION: MINOTAUR

#include "player.h"
#include "player.cpp"
#include "minotaur.h"
#include "minotaur.cpp"
#include "labyrinth.h"
#include "labyrinth.cpp"
#include "enemy.h"
#include "enemy.cpp"
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

// changes all characters in string to lowercae
string same(string x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i] = tolower(x[i]);
    }
    
    return x;
}

int main(){
cout << "" << endl;
cout << "----- LIBERATION: MINOTAUR -----" << endl;
cout << "" << endl;
cout << "You are a prisoner of war to the Greek kingdom of Crete" << endl;
cout << "King Minos has thrown you into his infamous Labyrinth where you are left to be eaten alive by the Minotaur!" << endl;
cout << "------------------------------------------------" << endl;
cout << "your main objective is to ESCAPE" << endl;
cout << "You have no fighting chance against the mighty Minotaur" << endl;
cout << "------------------------------------------------" << endl;
cout << "Every twist and turn holds an abundance of mystery - such as items or monsters" << endl;
cout << "- some items can speed up how fast you can traverse the labyrinth" << endl;
cout << "- some items will help you fight monsters" << endl;
cout << "- Your hunger will slowly deteriote. Make sure you eat regularly (food are also items that can be found)" << endl;
cout << "- Resting will help you regain health. However, it will give time for the Minotaur to gain up on you" << endl;
cout << "- Find these items by scavenging the rooms you are in. However, some rooms are too dark to be scavenged unless you have candles" << endl;
cout << "- Scavenging will also cause you to stop in your progress momentarily, so scavenge with awareness of the minotaur (you can only scavenge once per turn)" << endl;
cout << "HINT: YOU WILL HAVE A SLIGHT HEAD START OVER THE MINOTAUR. USE THIS TIME TO SCAVENGE WHILE HE'S ASLEEP" << endl;
cout << "" << endl;

string choice;
Player p;
Minotaur m;
Labyrinth l;
Enemy e;
l.setPlayer(p);
l.setMinotaur(m);

int ok = 0; // checks if room is already scavenged or not. Prevents rooms from being scavenged twice
int minotaurSpeed = 1;
int dark = 0;

while (choice != "6")
{
    // game lose condition: Minotaur progress exceeds or equals yours (he caught and killed you)
    if (l.getProgressM() >= l.getProgress())
    {
        cout << "THE MINOTAUR HAS CAUGHT AND SLAIN YOU" << endl;
        cout << "GAME OVER" << endl;
        break;
    }
    
    // game lose condition 2: Hunger points hit 0
    if (l.getHunger() <= 0)
    {
        cout << "YOU'VE STARVED TO DEATH" << endl;
        cout << "GAMEOVER" << endl;
        break;
    }
    
    // game lose condition 3: Health points hit 0
    if (l.getHealth() <= 0)
    {
        cout << "YOU HAVE DIED FROM THE MONSTER" << endl;
        cout << "GAMEOVER" << endl;
        break;
    }
    
    // made it to end of maze
    if (l.getProgress() >= 100)
    {
        cout << "YOU HAVE BEATEN THE ODDS AND ESCAPED THE LABYRINTH" << endl;
        cout << "YOU ARE NOW FREE!" << endl;
        break;
    }
    
    else {
        
    srand(time(NULL));
    
    cout << "" << endl;
    cout << "What will you do next?" << endl;
    cout << "1. Move forward" << endl;
    cout << "2. Rest" << endl; //second menu
    cout << "3. Eat bread" << endl; // second menu
    cout << "4. Scavenge room" << endl;
    cout << "5. View inventory" << endl;
    cout << "6. Exit Game" << endl;
    cout << "" << endl;
    
    cin >> choice;
    
    if (choice == "1")
    {
        dark = 0;
        int choiceMade = 0;
        
        while (choiceMade != 1) {
        cout << "Which way?" << endl;
        cout << "1. Take a left" << endl;
        cout << "2. Take a right" << endl;
        
        string direction;
        cin >> direction;
        
        int x = (rand() %101);
        
        if (direction == "1")
        {
            if (x > 60 && x <= 100)
            {
                int monster = e.encounter();
                
                if (monster == 11)
                {
                    cout << "you have slain the goblin!" << endl;
                    
                    // different if statements represent health lost based on strength of held weapon
                    if (l.getItems(2) == 0)
                    {
                        l.setHealth(l.getHealth() - 15);
                    }
                    
                    if (l.getItems(2) == 1)
                    {
                        l.setHealth(l.getHealth() - 10);
                    }
                    
                    if (l.getItems(2) == 2)
                    {
                        l.setHealth(l.getHealth() - 5);
                    }
                    
                    if (l.getItems(2) == 3)
                    {
                        l.setHealth(l.getHealth() - 0);
                    }
                }
                
                if (monster == 12)
                {
                    cout << "Successfully ran away" << endl;
                    l.setHunger(l.getHunger() - 5);
                }
                
                if (monster == 21)
                {
                    cout << "you have slain the gorgon!" << endl;
                    
                    // different if statements represent health lost based on strength of held weapon
                    if (l.getItems(2) == 0)
                    {
                        l.setHealth(l.getHealth() - 25);
                    }
                    
                    if (l.getItems(2) == 1)
                    {
                        l.setHealth(l.getHealth() - 20);
                    }
                    
                    if (l.getItems(2) == 2)
                    {
                        l.setHealth(l.getHealth() - 15);
                    }
                    
                    if (l.getItems(2) == 3)
                    {
                        l.setHealth(l.getHealth() - 10);
                    }
                }
                
                if (monster == 22)
                {
                    cout << "Successfully ran away" << endl;
                    l.setHunger(l.getHunger() - 10);
                }
                
                if (monster == 31)
                {
                    cout << "you have slain the cyclops!" << endl;
                    
                    // different if statements represent health lost based on strength of held weapon
                    if (l.getItems(2) == 0)
                    {
                        l.setHealth(l.getHealth() - 30);
                    }
                    
                    if (l.getItems(2) == 1)
                    {
                        l.setHealth(l.getHealth() - 25);
                    }
                    
                    if (l.getItems(2) == 2)
                    {
                        l.setHealth(l.getHealth() - 20);
                    }
                    
                    if (l.getItems(2) == 3)
                    {
                        l.setHealth(l.getHealth() - 15);
                    }
                }
                
                if (monster == 32)
                {
                    cout << "Successfully ran away" << endl;
                    l.setHunger(l.getHunger() - 15);
                }
            }
            
            if (x >= 0 && x <= 5)
            {
                // triggers condition that only allows scavenging if user has candles
                dark = 1;
            }
            
            choiceMade = 1;
        }
        
        if (direction == "2")
        {
            if (x > 80 && x <= 100)
            {
                int monster2 = e.encounter();
                
                if (monster2 == 11)
                {
                    cout << "you have slain the goblin!" << endl;
                    if (l.getItems(2) == 0)
                    {
                        l.setHealth(l.getHealth() - 30);
                    }
                    
                    if (l.getItems(2) == 1)
                    {
                        l.setHealth(l.getHealth() - 20);
                    }
                    
                    if (l.getItems(2) == 2)
                    {
                        l.setHealth(l.getHealth() - 10);
                    }
                    
                    if (l.getItems(2) == 3)
                    {
                        l.setHealth(l.getHealth() - 0);
                    }
                }
                
                if (monster2 == 12)
                {
                    cout << "Successfully ran away" << endl;
                    l.setHunger(l.getHunger() - 5);
                }
                
                if (monster2 == 21)
                {
                    cout << "you have slain the gorgon!" << endl;
                    if (l.getItems(2) == 0)
                    {
                        l.setHealth(l.getHealth() - 40);
                    }
                    
                    if (l.getItems(2) == 1)
                    {
                        l.setHealth(l.getHealth() - 30);
                    }
                    
                    if (l.getItems(2) == 2)
                    {
                        l.setHealth(l.getHealth() - 20);
                    }
                    
                    if (l.getItems(2) == 3)
                    {
                        l.setHealth(l.getHealth() - 10);
                    }
                }
                
                if (monster2 == 22)
                {
                    cout << "Successfully ran away" << endl;
                    l.setHunger(l.getHunger() - 10);
                }
                
                if (monster2 == 31)
                {
                    cout << "you have slain the cyclops!" << endl;
                    if (l.getItems(2) == 0)
                    {
                        l.setHealth(l.getHealth() - 50);
                    }
                    
                    if (l.getItems(2) == 1)
                    {
                        l.setHealth(l.getHealth() - 40);
                    }
                    
                    if (l.getItems(2) == 2)
                    {
                        l.setHealth(l.getHealth() - 30);
                    }
                    
                    if (l.getItems(2) == 3)
                    {
                        l.setHealth(l.getHealth() - 20);
                    }
                }
                
                if (monster2 == 32)
                {
                    cout << "Successfully ran away" << endl;
                    l.setHunger(l.getHunger() - 15);
                }
            }
            
            if (x >= 0 && x < 10)
            {
                int dark = 1;
            }
            
            choiceMade = 1;
        }
        
        }
        
        ok = 0;
        
        // progress mintoaur and player through the map
        l.setSpeedM(minotaurSpeed);
        l.setProgress(l.getProgress() + l.getPlayerSpeed());
        l.setProgressM(l.getProgressM() + l.getSpeedM());
        l.setMap("p", l.getProgress());
        l.setMap("m", l.getProgressM());
        l.displayMap();
        l.setTurn(l.getTurn() + 1);
        l.setHunger(l.getHunger() - 5);
    }
    
    
    else if (choice == "2")
    {
        int trigger2 = 0;
        
        while (trigger2 != 1) {
        cout << "" << endl;
        cout << "For how long?" << endl;
        cout << "1. 1 hour" << endl;
        cout << "2. 2 hours" << endl;
        cout << "3. 3 hours" << endl;
        cout << "" << endl;
        
        string restChoice;
        
        cin >> restChoice;
        
        l.rest(restChoice);
        
        
        if (restChoice == "1")
        {
            l.setProgressM(l.getProgressM() + 1);
            trigger2 = 1;
        }
        
        if (restChoice == "2")
        {
            l.setProgressM(l.getProgressM() + 2);
            trigger2 = 1;
        }
        
        if (restChoice == "3")
        {
            l.setProgressM(l.getProgressM() + 3);
            trigger2 = 1;
        }
        
        }
        
        cout << "" << endl;
        cout << "You now have " << l.getHealth() << " health points" << endl;
        cout << "" << endl;
        
        //minotaur map progression
        l.setSpeedM(minotaurSpeed);
        l.setMap("m", l.getProgressM());
        l.displayMap();
        l.setTurn(l.getTurn() + 1);
    }
    
    



    else if (choice == "3")
    {
        cout << "" << endl;
        cout << "How many slices?" << endl;
        cout << "1. one slice of bread" << endl;
        cout << "2. two slices of bread" << endl;
        cout << "3. three slices of bread" << endl;
        cout << "" << endl;
        
        int eatChoice;
            
        cin >> eatChoice;
            
        int eatObj = l.eat(eatChoice);
            
        if (eatObj == 0)
        {
            cout << "You do not have any bread" << endl;
        }

        if (eatObj == 2)
        {
            cout << "You do not have enough bread" << endl;
        }
            
        else if (eatObj == 1)
        {
            cout << "" << endl;
            cout << "Bread successfully consumed" << endl;
            cout << "Slices of bread left: " << l.getFood() << endl;
            cout << "" << endl; 
        }
        
        l.setSpeedM(minotaurSpeed);
        l.setProgressM(l.getProgressM() + l.getSpeedM());
        l.setMap("m", l.getProgressM());
        l.displayMap();
        l.setTurn(l.getTurn() + 1);


    }
    
    
    else if (choice == "4")
    {
        if (ok == 0)
        {
            // dark room: must have candles to scavenge
            if (dark == 1)
            {
                // condition: if played has candles or not
                if (l.getItems(1) == 0)
                {
                    cout << "The room is too dark to scavenge!" << endl;
                    cout << "You must need candles!" << endl; 
                }
                
                if (l.getItems(1) > 0)
                {
                    l.scavenge();
                    l.displayMap();
                    l.setItems(l.getCandles()-1, 1);
                    l.setCandles(l.getCandles()-1);
            
                    ok = 1;
                    
                    if (l.getProgress() > 4)
                    {
                        l.setSpeedM(minotaurSpeed);
                        l.setProgressM(l.getProgressM() + l.getSpeedM());
                        l.setMap("m", l.getProgressM());
                        l.displayMap();
                    }
                }
            }
            
            else
            {
                l.scavenge(); // randomly generates items
                ok = 1; 
            
            if (l.getProgress() > 4)
            {
                l.setSpeedM(minotaurSpeed);
                l.setProgressM(l.getProgressM() + l.getSpeedM());
                l.setMap("m", l.getProgressM());
            }
            
            }
        }
        
        else
        {
            cout << "You have scavenged this room already!" << endl;
        }
        
    }
    
    else if (choice == "5")
    {
        l.inventory(); //displays inventory of player. Does not count as a turn
    }
    
    else if (choice == "6")
    {
        cout << "Thank you for playing!" << endl;
    }
    
    else
    {
        // user error
        cout << "invalid choice" << endl;
    }
    
    
    // minotaur speed varies and changes every turn
    int minotaurSpeedRandom = (rand() % 11);
    
    if (minotaurSpeedRandom >= 0 && minotaurSpeedRandom <= 6)
    {
        minotaurSpeed = 1;
    }
    
    if (minotaurSpeedRandom > 7 && minotaurSpeedRandom <= 9)
    {
        minotaurSpeed = 2;
    }
    
    if (minotaurSpeedRandom == 10)
    {
        minotaurSpeed = 3;
    }
    
    // displays user stats every turn
    cout << "" << endl;
    cout << "Hunger points: " << l.getHunger() << endl;
    cout << "Health: " << l.getHealth() << endl;
    
    }
}



}