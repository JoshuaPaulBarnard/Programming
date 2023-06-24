/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 3 - 1
Fraction.h


*/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace cs_Fraction 
{
	class Fraction 
	{
		public:
			Fraction(int getDivident = 0, int getDivisor = 0);
			friend Fraction operator+(const Fraction& left, const Fraction& right);
			friend bool operator<(const Fraction& left, const Fraction& right);
			friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
			Fraction operator<<();
			Fraction operator<();
			Fraction operator<=();
			Fraction operator>();
			Fraction operator>=();
			Fraction operator==();
			Fraction operator!=();
			Fraction operator+(const Fraction &other) const;
			Fraction operator-(const Fraction &other) const;
			Fraction operator*(const Fraction &other) const;
			Fraction operator/(const Fraction &other) const;
			Fraction operator+=();
			Fraction operator-=();
			Fraction operator*=();
			Fraction operator/=();
			Fraction operator++();
			Fraction operator--();
			Fraction operator++(int);
			Fraction operator--(int);
			void print();
		private:
				int dividend;
				int divisor;
	};
}

#endif