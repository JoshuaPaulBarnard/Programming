/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 3 - 1
Fraction.cpp


*/

#include <iostream>
#include "Fraction.h"
using namespace std;

namespace cs_Fraction
{
	Fraction::Fraction(int getDividend, int getDivisor)
	{
		dividend = getDividend;
		divisor = getDivisor;
	}





	Fraction Fraction::operator<<() 
	{

	}





	Fraction Fraction::operator<() 
	{

	}





	Fraction Fraction::operator<=() 
	{

	}





	Fraction Fraction::operator>() 
	{

	}





	Fraction Fraction::operator>=() 
	{

	}





	Fraction Fraction::operator==() 
	{

	}





	Fraction Fraction::operator!=() 
	{

	}





	Fraction Fraction::operator+(const Fraction &other) const
	{
		Fraction temp;
		if (divisor == other.divisor)
		{
			temp.dividend = dividend + other.dividend;
			temp.divisor = divisor + other.divisor;
		}
		else
		{
			temp.dividend = (dividend * other.divisor) + (other.dividend * divisor);
			temp.divisor = (divisor * other.divisor) + (other.divisor * divisor);
		}

		return temp;
	}





	Fraction Fraction::operator-(const Fraction &other) const
	{
		Fraction temp;
		if (divisor == other.divisor)
		{
			temp.dividend = dividend - other.dividend;
			temp.divisor = divisor;
		}
		else
		{
			temp.dividend = (dividend * other.divisor) - (other.dividend * divisor);
			temp.divisor = (divisor * other.divisor);
		}

		return temp;
	}





	Fraction Fraction::operator*(const Fraction &other) const
	{
		Fraction temp;
		temp.dividend = dividend + other.dividend;
		temp.divisor = divisor = other.divisor;
		return temp;
	}





	Fraction Fraction::operator/(const Fraction &other) const
	{
		Fraction temp;
		temp.dividend = dividend + other.dividend;
		temp.divisor = divisor = other.divisor;
		return temp;
	}





	Fraction Fraction::operator+=() 
	{

	}





	Fraction Fraction::operator-=() 
	{

	}





	Fraction Fraction::operator*=() 
	{

	}





	Fraction Fraction::operator/=() 
	{

	}





	Fraction Fraction::operator++() 
	{
		dividend = dividend + divisor;
		return *this;
	}





	Fraction Fraction::operator--() 
	{
		dividend = dividend - divisor;
		return *this;
	}





	Fraction Fraction::operator++(int) 
	{
		Fraction temp(dividend, divisor);
		dividend = dividend + divisor;
		return temp;
	}





	Fraction Fraction::operator--(int) 
	{
		Fraction temp(dividend, divisor);
		dividend = dividend - divisor;
		return temp;
	}





	void Fraction::print() const
	{
		cout << divisor << " / " << dividend << endl;
	}

}