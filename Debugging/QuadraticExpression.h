#pragma once
#include <iostream>
#include <cmath>
using namespace std;



// Credit: Joe Bryant & Erik Santana - Quadratic Expression

void mainMenu();
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);

class QuadraticExpression
{
private:
    int coefficientA, coefficientB, coefficientC, coefficientX;

public:

    // Pre-Condition: no parameters
    // Post-Condition: no return. No argument constructor. Initializer constructor
    QuadraticExpression();

    // Pre-Condition: parameters - int newCoefficientA, int newCoefficientB, int newCoefficientC, int newCoefficientX. These parameters are assigned to the private member variables.
    // Post-Condition: no return. Argument constructor
    QuadraticExpression(int newCoefficientA, int newCoefficientB, int newCoefficientC, int newCoefficientX);

    //                                      Mutators

    // Pre-Condition: parameter int newCoefficientA is assigned to the private member variable coefficientA.
    // Post-Condition: no return. This mutator member function sets/changes the private variable coefficientA. 
    void setA(int newCoefficientA);

    // Pre-Condition: parameter int newCoefficientB is assigned to the private member variable coefficientB.
    // Post-Condition: no return. This mutator member function sets/changes the private variable coefficientB. 
    void setB(int newCoefficientB);

    // Pre-Condition: parameter int newCoefficientC is assigned to the private member variable coefficientC.
    // Post-Condition: no return. This mutator member function sets/changes the private variable coefficientC.
    void setC(int newCoefficientC);

    // Pre-Condition: parameter int newCoefficientX is assigned to the private member variable coefficientX.
    // Post-Condition: no return. This mutator member function sets/changes the private variable coefficientX. 
    void setX(int newCoefficientX);

    //                                      Accessors

    // Pre-Condition: no parameters.
    // Post-Condition: returns coefficientA. Accessors function to get(view) the value of coefficientA
    int getA() const;

    // Pre-Condition: no parameters.
    // Post-Condition: returns coefficientB. Accessors function to get(view) the value of coefficientB
    int getB() const;

    // Pre-Condition: no parameters.
    // Post-Condition: returns coefficientC. Accessors function to get(view) the value of coefficientC
    int getC() const;

    // Pre-Condition: no parameters.
    // Post-Condition: returns coefficientX. Accessors function to get(view) the value of coefficientX
    int getX() const;

    // Pre-Condition: no parameters
    // Post-Condition: no return. Destructor
    ~QuadraticExpression();

    // Pre-Condition: no parameters
    // Post-Condition: no return. Sub menu, user picks an option.
    void quadraticExpressionMenu();


};
