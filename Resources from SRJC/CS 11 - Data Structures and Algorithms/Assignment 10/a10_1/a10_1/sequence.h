/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 10
sequence.h

*/


#ifndef sequence_h
#define sequence_h
#include <iostream>

namespace cs_sequence 
{
	class sequence 
	{
	public:
		typedef int value_type;
		typedef std::size_t size_type;

		sequence( );
		sequence(const sequence& inputData);
		~sequence( );
		sequence& operator=( const sequence& inputData );

		void remove_current( );
		void start( );
		void advance( );
		void insert( const value_type& entry );
		void attach( const value_type& entry );

		size_type size( ) const;
		value_type current( ) const;

		bool is_item( ) const;

	private:
		size_type numItems;
		void clear( );
		void copy( const sequence& inputData );

		struct node
		{
			value_type data;
			node *next;
		};
		node *headPtr;
		node *tailPtr;
		node *cursor;
		node *preCursor;


	#endif /* sequence_h */
	};
}
