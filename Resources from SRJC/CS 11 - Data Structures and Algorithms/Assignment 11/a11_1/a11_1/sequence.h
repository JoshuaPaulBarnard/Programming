/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 11
sequence.h

*/

#ifndef sequenceStack_h
#define sequenceStack_h
#include <iostream>
#include <stack>

namespace cs_sequence
{
    class sequence 
	{
		public:
			typedef int value_type;
			typedef size_t size_type;

			void start();        
			void advance();
        
			void insert(const value_type& entry);
			void attach(const value_type& entry);
			void remove_current();

			size_type size() const;
			value_type current() const;

			bool is_item() const;


		private:
			std::stack<int> FirstStack;
			std::stack<int> SecondStack;

#endif /* sequenceStack_h */
    };
}
