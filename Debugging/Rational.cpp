#include "Rational.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#pragma once

//************************** Contructors **********************************//

// A default constructor that set the numerator to 0 and the denominator to 1.
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

// A constructor that accepts the values of the numerator and denominator and throw an exception if the denominator is zero.
Rational::Rational(int newN, int newD)
{
	numerator = newN;
	denominator = newD;
	if (denominator == 0)
		throw ZeroDenominator(*this); // throw exception

	normalize();
}

//PreCondition: NA
//PostCondition: returns a string expression of the numerator/denominator.  
string Rational::toString()
{
	return to_string(numerator) + "/" + to_string(denominator);
}

//******************************* Acesssor *********************************//

//PreCondition: NA
//PostCondition: return the numerator private member
int Rational::getNumerator() const
{
	return numerator;
}

//PreCondition: NA
//PostCondition: return the denominator private member
int Rational::getDenominator() const
{
	return denominator;
}

//******************************* Mutator *********************************//

//PreCondition: an interger value
//PostCondition: set the values of the numerator private member
void Rational::setNumerator(int newN)
{
	numerator = newN;
	normalize();
}

//PreCondition: an interger value
//PostCondition: set the values of the denominator private member
void Rational::setDenominator(int newD)
{
	denominator = newD;
	if (denominator == 0)
		throw ZeroDenominator(*this); // throw exception

	normalize();
}

//******************************* Overloading Operator **************************//

//PreCondition: 2 Rational objects
//PostCondition:  return a the object that is the result of the multiplication of the 2 rational objects
Rational operator *(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.numerator = obj1.numerator * obj2.numerator;
	temp.denominator = obj1.denominator * obj2.denominator;

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition:  return a the object that is the result of the division of the 2 rational objects
Rational operator /(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.numerator = obj1.numerator * obj2.denominator;
	temp.denominator = obj1.denominator * obj2.numerator;

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition:  return a the object that is the result of sum of the 2 rational objects
Rational operator +(const Rational& obj1, const Rational& obj2)
{
	Rational temp;
	
	temp.denominator = obj1.denominator * obj2.denominator;

	temp.numerator = (obj1.numerator * obj2.denominator) + (obj2.numerator * obj1.denominator);

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition:  return a the object that is the difference of the 2 rational objects
Rational operator -(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.denominator = obj1.denominator * obj2.denominator;

	temp.numerator = (obj1.numerator * obj2.denominator) - (obj2.numerator * obj1.denominator);

	temp.normalize();

	return temp;
}


//PreCondition: 2 Rational objects
//PostCondition:  return a flag that compares two Rational numbers are equal
bool operator ==(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
}

//PreCondition: 2 Rational objects
//PostCondition: return a flag which indicate one is lesser than another.
bool operator <(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
}

//PreCondition: a ostream object and a Rational object
//PostCondition: return the object that used for display 
ostream& operator << (ostream& out, Rational obj)
{
	out << obj.toString();
	return out;
}

void Rational::rational_Menu()
{
	Rational rational1;
	Rational rational2;

	do
	{
		system("cls");
		cout << "\n\t3> Rational Number menu";
		cout << "\n\t" + string(68, char(205));
		cout << "\n\t\tA. enter values of rational number R1";
		cout << "\n\t\tB. display R1";
		cout << "\n\t\tC. enter values for  rational number R2";
		cout << "\n\t\tD. display R2";
		cout << "\n\t\tE. multiplication of 2 rational numbers (R1 * R2)";
		cout << "\n\t\tF. division of 2 rational numbers (R1 / R2)";
		cout << "\n\t\tG. addition of 2 rational numbers (R1 + R2)";
		cout << "\n\t\tH. subtraction 2 rational numbers (R1 - R2)";
		cout << "\n\t\tI. (R1 == R2)";
		cout << "\n\t\tJ. (R1 < R2)";

		cout << "\n\t" + string(68, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" + string(68, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHIJ0"))))
		{
		case 'A':

			try
			{
				rational1.setNumerator(inputInteger("\n\tEnter the value for the numerator: "));
				rational1.setDenominator(inputInteger("\n\tEnter the value for the denominator: "));
			}
			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot remove a Rational number, " + rational1.toString() + ", that contains a zero denominator value.\n";
			}

			break;

		case 'B':

			cout << "\n\tRational number R1: " << rational1 << "\n";

			break;

		case 'C':

			try
			{
				rational2.setNumerator(inputInteger("\n\tEnter the value for the numerator: "));
				rational2.setDenominator(inputInteger("\n\tEnter the value for the denominator: "));
			}
			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot remove a Rational number, " + rational2.toString() + ", that contains a zero denominator value.\n";
			}

			break;

		case 'D':

			cout << "\n\tRational number R2: " << rational2 << "\n";
			break;

		case 'E':

			cout << "\n\tR1 * R2: " << rational1 * rational2 << "\n";

			break;

		case 'F':

			cout << "\n\tR1 / R2: " << rational1 / rational2 << "\n";

			break;

		case 'G':

			cout << "\n\tR1 + R2: " << rational1 + rational2 << "\n";

			break;

		case 'H':

			cout << "\n\tR1 - R2: " << rational1 - rational2 << "\n";

			break;

		case 'I':

			cout << "\n\tR1 == R2: ";
			rational1 == rational2 ? cout << "true\n" : cout << "false\n";

			break;

		case 'J':

			cout << "\n\tR1 < R2: ";
			rational1 < rational2 ? cout << "true\n" : cout << "false\n";

			break;

		case '0': system("cls"); mainMenu(); return;
		}
		cout << "\n";
		system("pause");
	} while (true);
}
