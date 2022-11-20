#include <ctime>
#include <iostream>
#include <string>
#include "player.h"
#include "player.cpp"
#include "tmz.h"
#include "tmz.cpp"
#include "map.h"
#include "map.cpp"
#include "enemy.h"
#include "enemy.cpp"
using namespace std;

int main()
{
    cout << endl
         << "---------- SIERRA LEONE ----------" << endl
         << "You are famous R&B artist Frank Ocean." << endl
         << endl
         << "Mysteriously, you wake up in the middle of a desert with no phone." << endl
         << "In the distance, you see TMZ in the distance running towards you! How did they even find you?" << endl
         << "You hear them begging for a new album in the distance." << endl
         << "You have no choice but to turn and sprint the other way!" << endl
         << endl
         << "your main objective is to ESCAPE!" << endl
         << "You have no chance of fighting off the press." << endl
         << "------------------------------------------------" << endl
         << "You will be able to find items as you get away from TMZ." << endl
         << "- Speed items: increase how fast you can move" << endl
         << "- Power items: help you fight off unexpected enemies." << endl
         << "- Food: Make sure you eat regularly." << endl
         << "------------------------------------------------" << endl
         << "Find these items by scavenging every turn (you can only scavenge once per turn)" << endl
         << "Scavenging will also cause you to stop in your progress momentarily, so scavenge carefull!" << endl
         << "Resting will help you regain health. However, it will give time for TMZ to gain up on you." << endl
         << "HINT: YOU WILL HAVE A SLIGHT HEAD START OVER TMZ. USE THIS TIME TO SCAVENGE!" << endl;

    // initialize objects
    string choice;
    Player p;
    Map m;
    Enemy e;
    Tmz t;
    m.setPlayer(p);
    m.setTmz(t);
    int tmzSpeed = 1;
    bool scavenged = false;

    while (choice != "6")
    {
        bool choiceMade = false;

        // end game conditions
        if (m.getProgressT() >= m.getProgress())
        { // player caught by tmz
            cout << endl
                 << "TMZ HAS CAUGHT YOU" << endl;
            cout << "GAME OVER" << endl;
            break;
        }
        if (m.getHunger() <= 0)
        { // player starved
            cout << endl
                 << "YOU STARVED TO DEATH" << endl;
            cout << "GAMEOVER" << endl;
            break;
        }
        if (m.getHealth() <= 0)
        { // player health is less than 0
            cout << endl
                 << "YOU HAVE NO MORE HEALTH" << endl
                 << "GAMEOVER" << endl;
            break;
        }
        if (m.getProgress() >= 100)
        { // player reached end of maze
            cout << endl
                 << "YOU HAVE BEATEN THE ODDS AND ESCAPED" << endl
                 << "YOU ARE NOW FREE!" << endl;
            break;
        }

        else
        {
            srand(time(NULL)); // set random seeding

            cout << endl
                 << "What will you do next?" << endl
                 << "1. Keep Moving" << endl
                 << "2. Rest" << endl
                 << "3. Eat" << endl
                 << "4. Scavenge" << endl
                 << "5. View inventory" << endl
                 << "6. Exit Game" << endl
                 << endl;

            cin >> choice;

            if (choice == "1") // keep moving
            {
                scavenged = false;
                while (choiceMade == false)
                {
                    cout << endl
                         << "Which way?" << endl
                         << "1. Take a left" << endl
                         << "2. Take a right" << endl
                         << endl;
                    string direction;
                    cin >> direction;
                    int x = (rand() % 101);
                    if (((x > 60 && x <= 100) && direction == "1") || ((x > 80 && x <= 100) && direction == "2"))
                    {
                        int enemy = e.encounter();
                        // level 1 enemy
                        if (enemy == 11) // fought
                        {
                            cout << endl
                                 << "You beat up Chris Brown" << endl;
                            // health lost based on strength of held weapon
                            m.setHealth(m.getHealth() - (15 - m.getItems(2) * 5));
                        }
                        if (enemy == 12) // ran
                        {
                            cout << endl
                                 << "You successfully ran" << endl;
                            m.setHunger(m.getHunger() - 5);
                        }
                        // level 2 enemy
                        if (enemy == 21)
                        {
                            cout << endl
                                 << "You beat up Tyler!" << endl;
                            m.setHealth(m.getHealth() - (25 - m.getItems(2) * 5));
                        }
                        if (enemy == 22)
                        {
                            cout << endl
                                 << "You successfully ran away" << endl;
                            m.setHunger(m.getHunger() - 10);
                        }
                        // level 3 enemy
                        if (enemy == 31)
                        {
                            cout << endl
                                 << "You endured her rant!" << endl;
                            m.setHealth(m.getHealth() - (35 - m.getItems(2) * 5));
                        }
                        if (enemy == 32)
                        {
                            cout << endl
                                 << "You successfully hang up" << endl;
                            m.setHunger(m.getHunger() - 15);
                        }
                    }
                    choiceMade = true;
                }
                // progress tmz and player through map
                m.setSpeedT(tmzSpeed);
                m.setProgress(m.getProgress() + m.getPlayerSpeed());
                m.setProgressT(m.getProgressT() + m.getSpeedT());
                m.setMap("F", m.getProgress());
                m.setMap("T", m.getProgressT());
                m.displayMap();
                m.setTurn(m.getTurn() + 1);
                m.setHunger(m.getHunger() - 5);
            }

            else if (choice == "2") // rest
            {
                bool choiceMade = false;
                while (choiceMade == false)
                {
                    cout << endl
                         << "For how long?" << endl
                         << "1. 1 hour" << endl
                         << "2. 2 hours" << endl
                         << "3. 3 hours" << endl
                         << endl;
                    int restChoice;
                    cin >> restChoice;
                    m.rest(restChoice);
                    if (restChoice == 1 || restChoice == 2 || restChoice == 3)
                    {
                        m.setProgressT(m.getProgressT() + restChoice);
                        cout << endl
                             << "You now have " << m.getHealth() << " health points" << endl;
                        choiceMade = true;
                    }
                    else
                    {
                        cout << "invalid choice" << endl;
                    }
                }
                // progress and update map
                m.setSpeedT(tmzSpeed);
                m.setMap("T", m.getProgressT());
                m.displayMap();
                m.setTurn(m.getTurn() + 1);
            }

            else if (choice == "3") // eat
            {
                bool choiceMade = false;
                while (choiceMade == false)
                {
                    cout << endl
                         << "How many slices?" << endl
                         << "1. one slice of bread" << endl
                         << "2. two slices of bread" << endl
                         << "3. three slices of bread" << endl
                         << endl;
                    int eatChoice;
                    cin >> eatChoice;
                    if (eatChoice > 0 && eatChoice <= 3)
                    {
                        int eatObj = m.eat(eatChoice);
                        choiceMade = true;
                        if (eatObj == 0)
                        {
                            cout << endl
                                 << "You do not have enough bread" << endl;
                        }
                        if (eatObj == 1)
                        {
                            cout << endl
                                 << "Bread successfully consumed" << endl
                                 << "Slices of bread left: " << m.getFood() << endl;
                        }
                        choiceMade = true;
                    }
                    else
                    {
                        cout << endl
                             << "invalid choice" << endl;
                    }
                }
                m.setSpeedT(tmzSpeed);
                m.setProgressT(m.getProgressT() + m.getSpeedT());
                m.setMap("T", m.getProgressT());
                m.displayMap();
                m.setTurn(m.getTurn() + 1);
            }

            else if (choice == "4") // scavenge
            {
                if (scavenged == false)
                {
                    m.scavenge(); // randomly generate items
                    scavenged = true;
                    if (m.getProgress() > 4) // move tmz
                    {
                        m.setSpeedT(tmzSpeed);
                        m.setProgressT(m.getProgressT() + m.getSpeedT());
                        m.setMap("T", m.getProgressT());
                    }
                }
                else
                {
                    cout << "You have scavenged this room already!" << endl;
                }
            }

            else if (choice == "5") // display player inventory
            {
                m.inventory();
            }

            else if (choice == "6") // end game
            {
                cout << endl
                     << "Thank you for playing!" << endl;
                break;
            }

            else
            {
                // handle invalid user input
                cout << "invalid choice" << endl;
            }

            // randomize tmz speed
            int tmzSpeedRandom = (rand() % 11);
            if (tmzSpeedRandom >= 0 && tmzSpeedRandom <= 6)
            {
                tmzSpeed = 1;
            }
            if (tmzSpeedRandom > 7 && tmzSpeedRandom <= 9)
            {
                tmzSpeed = 2;
            }
            if (tmzSpeedRandom == 10)
            {
                tmzSpeed = 3;
            }

            // display user health and hunger
            cout << endl
                 << "Hunger points: " << m.getHunger() << endl
                 << "Health: " << m.getHealth() << endl;
        }
    }
}