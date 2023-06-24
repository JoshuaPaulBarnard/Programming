/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 8
orderedpair.h

*/


#include <iostream>

/* precondition for setFirst and setSecond: the values of first and second cannot be equal,
except when they are both equal to DEFAULT_VALUE.
*/


namespace cs_pairs 
{
	template <class T>
	class OrderedPair 
	{
	public:
		class DuplicateMemberError {};
		// Use the first of the following two lines to make the non-templated version work.
		// Use the second one when you begin converting to a templated version.

		static const T DEFAULT_VALUE;
		// static const int DEFAULT_VALUE;

		OrderedPair( T newFirst = DEFAULT_VALUE, T newSecond = DEFAULT_VALUE );
		void setFirst( T newFirst );
		void setSecond( T newSecond );
		T getFirst() const;
		T getSecond() const;
		OrderedPair operator+( const OrderedPair& right ) const;
		bool operator<( const OrderedPair& right ) const;
		void print() const;

	private:
		T first;
		T second;
	};


	// Leave the following const declaration commented out when you are testing the non-templated version.
	// Uncomment it when you begin converting to a templated version.

	// To convert to a templated version you will need a template prefix here above this declaration
	template <class T>
	const T OrderedPair<T>::DEFAULT_VALUE = T();

}

#include "orderedpair.cpp"
