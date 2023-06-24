/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 4 - 1
Fraction.cpp

Fractions Class
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "Fraction.h"
using namespace std;

namespace cs_Fraction
{
	// This function receives a fraction consisting of seperate dividend and divisor integers.
	// This function will find their greatest common factor and reduce them to their lowest numbers.
	void Fraction::simplify()
	{
		int gcd = 1;
		int smallNumber, largeNumber, remainder1, remainder2;

		if (divisor < 0)
		{
			dividend = dividend * -1;
			divisor = divisor * -1;
		}

		if (dividend == 0)
		{
			divisor = 1;
		}

		if (dividend > divisor)
		{
			largeNumber = dividend;
			smallNumber = divisor;
		}
		else
		{
			largeNumber = divisor;
			smallNumber = dividend;
		}

		for (int index = 1; index <= smallNumber; index++)
		{
			remainder1 = smallNumber % index;
			remainder2 = largeNumber % index;

			if (remainder1 == 0 && remainder2 == 0)
			{
				gcd = index;
			}
		}

		dividend = dividend / gcd;
		divisor = divisor / gcd;
	}





	Fraction::Fraction(int getDividend, int getDivisor)
	{
		assert(getDivisor != 0);

		dividend = getDividend;
		divisor = getDivisor;

		simplify();
	}





	std::ostream &operator<<(std::ostream &out, const Fraction &right)
	{
		if (right.dividend == 0)
		{
			out << "0";
		}
		else if (right.divisor == 1)
		{
			out << right.dividend;
		}
		else if (right.dividend == right.divisor)
		{
			out << "1";
		}
		else if (right.dividend > right.divisor)
		{
			int temp1 = right.dividend / right.divisor;
			int temp2 = right.dividend - (temp1 * right.divisor);

			if (temp2 == 0)
			{
				out << temp1;
			}
			else
			{
				out << temp1 << "+" << temp2 << "/" << right.divisor;
			}
		}
		else
		{
			out << right.dividend << "/" << right.divisor;
		}


		return out;
	}





	std::istream &operator>>(std::istream &in, Fraction &right)
	{
		int temp1, temp2, temp3;

		in >> temp1;

		if (in.peek() == '+')
		{
			in.ignore();
			in >> temp2;
			in.ignore();
			in >> temp3;

			if (temp1 < 0)
			{
				right.dividend = -(abs(temp1 * temp3) + temp2);
			}
			if (temp1 > 0)
			{
				right.dividend = (temp1 * temp3) + temp2;
			}
			right.divisor = temp3;
			right.simplify();
		}
		else if (in.peek() == '/')
		{
			in.ignore();
			in >> temp2;
			right.dividend = temp1;
			right.divisor = temp2;
			right.simplify();

		}
		else
		{
			right.dividend = temp1;
			right.divisor = 1;
		}

		return in;
	}





	bool operator<(const Fraction& left, const Fraction& right)
	{
		bool status = false;
		if ((left.dividend * right.divisor) < (right.dividend * left.divisor))
		{
			status = true;
		}

		return status;
	}





	bool operator<=(const Fraction& left, const Fraction& right)
	{
		bool status = false;
		if ((left.dividend * right.divisor) <= (right.dividend * left.divisor))
		{
			status = true;
		}

		return status;
	}





	bool operator>(const Fraction& left, const Fraction& right)
	{
		bool status = false;
		if ((left.dividend * right.divisor) > (right.dividend * left.divisor))
		{
			status = true;
		}

		return status;
	}





	bool operator>=(const Fraction& left, const Fraction& right)
	{
		bool status = false;
		if ((left.dividend * right.divisor) >= (right.dividend * left.divisor))
		{
			status = true;
		}

		return status;
	}





	bool operator==(const Fraction& left, const Fraction& right)
	{
		bool status = false;
		if ((left.dividend * right.divisor) - (right.dividend * left.divisor) == 0)
		{
			status = true;
		}

		return status;
	}





	bool operator!=(const Fraction& left, const Fraction& right)
	{
		bool status = false;
		if ((left.dividend * right.divisor) - (right.dividend * left.divisor) != 0)
		{
			status = true;
		}

		return status;
	}





	Fraction operator+(const Fraction& left, const Fraction& right)
	{
		Fraction temp;
		if (left.divisor == right.divisor)
		{
			temp.dividend = left.dividend + right.dividend;
			temp.divisor = left.divisor;
		}
		else
		{
			temp.dividend = (left.dividend * right.divisor) + (right.dividend * left.divisor);
			temp.divisor = left.divisor * right.divisor;
		}

		temp.simplify();
		return temp;
	}





	Fraction operator-(const Fraction& left, const Fraction& right)
	{
		Fraction temp;
		if (left.divisor == right.divisor)
		{
			temp.dividend = left.dividend - right.dividend;
			temp.divisor = left.divisor;
		}
		else
		{
			temp.dividend = (left.dividend * right.divisor) - (right.dividend * left.divisor);
			temp.divisor = left.divisor * right.divisor;
		}

		temp.simplify();
		return temp;
	}





	Fraction operator*(const Fraction& left, const Fraction& right)
	{
		Fraction temp;

		temp.dividend = left.dividend * right.dividend;
		temp.divisor = left.divisor * right.divisor;

		temp.simplify();
		return temp;
	}





	Fraction operator/(const Fraction& left, const Fraction& right)
	{
		Fraction temp;

		temp.dividend = left.dividend * right.divisor;
		temp.divisor = left.dividend * right.dividend;

		temp.simplify();
		return temp;
	}





	Fraction Fraction::operator+=(const Fraction& right)
	{
		*this = *this + right;

		simplify();
		return *this;
	}





	Fraction Fraction::operator-=(const Fraction& right)
	{
		*this = *this - right;

		simplify();
		return *this;
	}





	Fraction Fraction::operator*=(const Fraction& right)
	{
		*this = *this * right;

		simplify();
		return *this;
	}





	Fraction Fraction::operator/=(const Fraction& right)
	{
		*this = *this / right;

		simplify();
		return *this;
	}





	Fraction Fraction::operator++()
	{
		dividend = dividend + divisor;

		simplify();
		return *this;
	}





	Fraction Fraction::operator++(int)
	{
		Fraction temp(dividend, divisor);
		dividend = dividend + divisor;

		temp.simplify();
		return temp;
	}





	Fraction Fraction::operator--()
	{
		dividend = dividend - divisor;

		simplify();
		return *this;
	}





	Fraction Fraction::operator--(int)
	{
		Fraction temp(dividend, divisor);
		dividend = dividend - divisor;

		temp.simplify();
		return temp;
	}

}

/*

*/