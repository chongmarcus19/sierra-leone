#ifndef TMZ_H
#define TMZ_H
#include <iostream>
#include <string>
using namespace std;

class Tmz
{
public:
    Tmz();
    int getSpeed();
    int getProgress();
    void setSpeed(int);
    void setProgress(int);

private:
    int speed;
    int progress;
};

#endif