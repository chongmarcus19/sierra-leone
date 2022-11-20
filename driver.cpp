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

int main()
{
    cout << endl
         << "----- LIBERATION: MINOTAUR -----" << endl
         << "You are a prisoner of war to the Greek kingdom of Crete" << endl
         << "King Minos has thrown you into his infamous Labyrinth where you are left to be eaten alive by the Minotaur!" << endl
         << "------------------------------------------------" << endl
         << "your main objective is to ESCAPE" << endl
         << "You have no fighting chance against the mighty Minotaur" << endl
         << "------------------------------------------------" << endl
         << "Every twist and turn holds an abundance of mystery - such as items or monsters" << endl
         << "- some items can speed up how fast you can traverse the labyrinth" << endl
         << "- some items will help you fight monsters" << endl
         << "- Your hunger will slowly deteriote. Make sure you eat regularly (food are also items that can be found)" << endl
         << "- Resting will help you regain health. However, it will give time for the Minotaur to gain up on you" << endl
         << "- Find these items by scavenging the rooms you are in. However, some rooms are too dark to be scavenged unless you have candles" << endl
         << "- Scavenging will also cause you to stop in your progress momentarily, so scavenge with awareness of the minotaur (you can only scavenge once per turn)" << endl
         << "HINT: YOU WILL HAVE A SLIGHT HEAD START OVER THE MINOTAUR. USE THIS TIME TO SCAVENGE WHILE HE'S ASLEEP" << endl;

    string choice;
    Player p;
    Minotaur m;
    Labyrinth l;
    Enemy e;
    l.setPlayer(p);
    l.setMinotaur(m);

    int minotaurSpeed = 1;
    bool dark = false;
    bool scavenged = false;

    while (choice != "6")
    {
        dark = false;
        int choiceMade = 0;

        // establish end game conditions
        if (l.getProgressM() >= l.getProgress())
        { // player caught by minotuar
            cout << "THE MINOTAUR HAS CAUGHT AND SLAIN YOU" << endl;
            cout << "GAME OVER" << endl;
            break;
        }
        if (l.getHunger() <= 0)
        { // player starved
            cout << "YOU'VE STARVED TO DEATH" << endl;
            cout << "GAMEOVER" << endl;
            break;
        }
        if (l.getHealth() <= 0)
        { // player health is less than 0
            cout << "YOU HAVE DIED FROM THE MONSTER" << endl;
            cout << "GAMEOVER" << endl;
            break;
        }
        if (l.getProgress() >= 100)
        { // player reached end of maze
            cout << "YOU HAVE BEATEN THE ODDS AND ESCAPED THE LABYRINTH" << endl;
            cout << "YOU ARE NOW FREE!" << endl;
            break;
        }

        else
        {
            srand(time(NULL)); // set random seeding

            cout << endl
                 << "What will you do next?" << endl
                 << "1. Move forward" << endl
                 << "2. Rest" << endl
                 << "3. Eat bread" << endl
                 << "4. Scavenge room" << endl
                 << "5. View inventory" << endl
                 << "6. Exit Game" << endl;

            cin >> choice;

            if (choice == "1")
            {
                scavenged = false;
                while (choiceMade != 1)
                {
                    cout << endl
                         << "Which way?" << endl
                         << "1. Take a left" << endl
                         << "2. Take a right" << endl;

                    string direction;
                    cin >> direction;

                    int x = (rand() % 101);

                    if (direction == "1")
                    {
                        if (x > 60 && x <= 100)
                        {
                            int monster = e.encounter();

                            if (monster == 11)
                            {
                                cout << endl
                                     << "you have slain the goblin!" << endl;

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
                                cout << endl
                                     << "Successfully ran away" << endl;
                                l.setHunger(l.getHunger() - 5);
                            }

                            if (monster == 21)
                            {
                                cout << endl
                                     << "you have slain the gorgon!" << endl;

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
                                cout << endl
                                     << "Successfully ran away" << endl;
                                l.setHunger(l.getHunger() - 10);
                            }

                            if (monster == 31)
                            {
                                cout << endl
                                     << "you have slain the cyclops!" << endl;

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
                                cout << endl
                                     << "Successfully ran away" << endl;
                                l.setHunger(l.getHunger() - 15);
                            }
                        }

                        if (x >= 0 && x <= 5)
                        {
                            // triggers condition that only allows scavenging if user has candles
                            dark = true;
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
                                cout << endl
                                     << "you have slain the goblin!" << endl;
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
                                cout << endl
                                     << "Successfully ran away" << endl;
                                l.setHunger(l.getHunger() - 5);
                            }

                            if (monster2 == 21)
                            {
                                cout << endl
                                     << "you have slain the gorgon!" << endl;
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
                                cout << endl
                                     << "Successfully ran away" << endl;
                                l.setHunger(l.getHunger() - 10);
                            }

                            if (monster2 == 31)
                            {
                                cout << endl
                                     << "you have slain the cyclops!" << endl;
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
                                cout << endl
                                     << "Successfully ran away" << endl;
                                l.setHunger(l.getHunger() - 15);
                            }
                        }

                        if (x >= 0 && x < 10)
                        {
                            dark = true;
                        }

                        choiceMade = 1;
                    }
                }

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

                while (trigger2 != 1)
                {
                    cout << endl
                         << "For how long?" << endl
                         << "1. 1 hour" << endl
                         << "2. 2 hours" << endl
                         << "3. 3 hours" << endl
                         << endl;

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

                cout << endl
                     << "You now have " << l.getHealth() << " health points" << endl;

                //minotaur map progression
                l.setSpeedM(minotaurSpeed);
                l.setMap("m", l.getProgressM());
                l.displayMap();
                l.setTurn(l.getTurn() + 1);
            }

            else if (choice == "3")
            {
                cout << endl
                     << "How many slices?" << endl
                     << "1. one slice of bread" << endl
                     << "2. two slices of bread" << endl
                     << "3. three slices of bread" << endl
                     << endl;

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
                    cout << endl
                         << "Bread successfully consumed" << endl
                         << "Slices of bread left: " << l.getFood() << endl;
                }

                l.setSpeedM(minotaurSpeed);
                l.setProgressM(l.getProgressM() + l.getSpeedM());
                l.setMap("m", l.getProgressM());
                l.displayMap();
                l.setTurn(l.getTurn() + 1);
            }

            else if (choice == "4")
            {
                if (scavenged == false)
                {
                    // dark room: must have candles to scavenge
                    if (dark == true)
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
                            l.setItems(l.getCandles() - 1, 1);
                            l.setCandles(l.getCandles() - 1);

                            scavenged = true;

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
                        scavenged = true;

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

            else if (choice == "5") // display player inventory
            {
                l.inventory();
            }

            else if (choice == "6") // end game
            {
                cout << "Thank you for playing!" << endl;
            }

            else
            {
                // user error
                cout << "invalid choice" << endl;
            }

            // change minotaur spead
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

            // display user stats
            cout << endl
                 << "Hunger points: " << l.getHunger() << endl
                 << "Health: " << l.getHealth() << endl;
        }
    }
}