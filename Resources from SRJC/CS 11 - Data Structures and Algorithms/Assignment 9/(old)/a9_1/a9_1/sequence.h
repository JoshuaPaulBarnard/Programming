#ifndef sequence_h
#define sequence_h
//#include <list>
#include <iostream>

namespace cs_sequence 
{
	class sequence 
	{
		typedef int value_type;
		typedef size_t size_type;


	public:


		sequence();
		// postcondition: The sequence has been initialized to an empty sequence.

		void clear();
		void copy(const sequence& copyMe);
		sequence(const sequence& copyMe);
		~sequence();
		sequence operator=(const sequence& right);
		void remove_current();

		void start();
		// postcondition: The first item in the sequence becomes the current item (but if the
		// sequence is empty, then there is no current item).

		void advance();
		// precondition: is_item() returns true
		// Postcondition: If the current item was already the last item in the sequence, then there
		// is no longer any current item. Otherwise, the new current item is the item immediately after
		// the original current item.

		void insert(const value_type& entry);
		// Postcondition: A new copy of entry has been inserted in the sequence before the
		// current item. If there was no current item, then the new entry has been inserted at the
		// front. In either case, the new item is now the current item of the sequence.
		//
		void attach(const value_type& entry);
		//// Not required this week
		//// Postcondition: A new copy of entry has been inserted in the sequence after the current
		//// item. If there was no current item, then the new entry has been attached to the end of
		//// the sequence. In either case, the new item is now the current item of the sequence.
		//
		//void remove_current();
		//// Not required this week
		//// Precondition: is_item returns true.
		//// Postcondition: The current item has been removed from the sequence, and the
		//// item after this (if there is one) is now the new current item.
		//
		size_type size() const;
		//// Postcondition: Returns the number of items in the sequence.
		//
		bool is_item() const;
		//// Postcondition: A true return value indicates that there is a valid "current" item that
		//// may be retrieved by the current member function (listed below). A false return value
		//// indicates that there is no valid current item.
		//
		value_type current() const;
		//// Precondition: is_item() returns true
		//// Postcondition: The current item in the sequence is returned.

	private:
		struct node
		{
			value_type data;
			node *next;
		};
		value_type numItems;
		node *headPtr;
		node *tailPtr;
		node *cursor;
		node *preCursor;

	};
}

#endif /* sequence_h */