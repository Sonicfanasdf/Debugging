#pragma once
#include <iostream>
using namespace std;

int inputInteger(string prompt);
char inputChar(string prompt);

class Pseudorandom
{
private:
    int seed;
    int multiplier;
    int increment;
    int modulus;

public:
    Pseudorandom();
    int getSeed() const { return seed; }
    int getMultiplier() const { return multiplier; }
    int getIncrement() const { return increment; }
    int getModulus() const { return modulus; }
    void setSeed(int newSeed);
    void setMultiplier(int newMultiplier);
    void setIncrement(int newIncrement);
    void setModulus(int newModulus);
    void generateSeed();
    double generateNextIndirectNum();
    void pseudorandomMenu();
    char pseudorandomMenuOption();
    void generateIndirectNumTable(Pseudorandom pseudorandom);
};

