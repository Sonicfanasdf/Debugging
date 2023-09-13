#pragma once
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char inputChar(string prompt, string options);
int inputInteger(string prompt);

// A rational number is a number that is expressed as the ratio of two integers, where the denominator should not be equal to zero.
// Rational class is designed to expressed the rational number in the form of (numerator) / (denominator) 
class Rational
{
private:
	int numerator;
	int denominator;

	//PreCondition: integer a and b parameter
	//PostCondition: return the greatest common divisor between a and b
	int gcd(int a, int b)
	{
		if (a == 0 || b == 0)
			return 0;
		else if (a == b)
			return a;
		else if (a > b)
			return gcd(a - b, b);
		else return gcd(a, b - a);
	}

	// nomarlize: If the denominator is negative, then the negative sign is moved to the numerator and reduce if there is a GCD (greatest common divisor). 
	void normalize()
	{
		if (denominator < 0)
		{
			denominator *= -1;
			numerator *= -1;
		}

		int temp = gcd(abs(numerator), abs(denominator));

		if (temp != 0)
		{
			numerator /= temp;
			denominator /= temp;
		}
	}
public:

	// ZeroDenominator is used to throw an exception if the denominator is zero.
	class ZeroDenominator
	{
	private:
		string rational;
	public:
		ZeroDenominator()
		{}

		ZeroDenominator(Rational r)
		{
			rational = r.toString();
		}

		string toString()
		{
			return rational;
		}
	};

	Rational();
	Rational(int, int);

	string toString();
	int getNumerator() const;
	int getDenominator() const;

	void setNumerator(int);
	void setDenominator(int);

	friend Rational operator * (const Rational& obj1, const Rational& obj2);
	friend Rational operator /(const Rational& obj1, const Rational& obj2);
	friend Rational operator +(const Rational& obj1, const Rational& obj2);
	friend Rational operator -(const Rational& obj1, const Rational& obj2);

	friend bool operator ==(const Rational& obj1, const Rational& obj2);
	friend bool operator <(const Rational& obj1, const Rational& obj2);
	friend ostream& operator << (ostream& out, Rational obj);

	void rational_Menu();

};



