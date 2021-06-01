#ifndef MINOTAUR_H
#define MINOTAUR_H
#include <iostream>
#include <string>
using namespace std;

class Minotaur
{
    public:
        Minotaur();
        int getSpeed();
        int getProgress();
        void setSpeed(int);
        void setProgress(int);
        
    private:
        int speed;
        int progress;
};

#endif