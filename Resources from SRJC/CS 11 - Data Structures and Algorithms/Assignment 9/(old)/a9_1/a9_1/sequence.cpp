#include <stdio.h>
#include "sequence.h"
#include <cassert>

namespace cs_sequence 
{
	sequence::sequence()
	{
		numItems = 0;
		headPtr = nullptr;
		tailPtr = nullptr;
		cursor = nullptr;
		preCursor = nullptr;
	}






	sequence::sequence( const sequence& copyMe )
	{
		copy( copyMe );
	}






	sequence::~sequence()
	{
		clear();
		numItems = 0;
	}






	void sequence::copy(const sequence& copyMe)
	{
		if (copyMe.headPtr == nullptr) {
			headPtr = nullptr;
			tailPtr = nullptr;
			cursor = nullptr;
			preCursor = nullptr;
		}
		else {

			headPtr = new node;
			headPtr->data = copyMe.headPtr->data;
			preCursor = nullptr;
			if (copyMe.headPtr == copyMe.cursor) {
				cursor = headPtr;
			}
			else {
				cursor = nullptr;
			}

			if (copyMe.headPtr == copyMe.preCursor) {
				preCursor = headPtr;
			}
			node* newList = headPtr;
			node* sourcePtr = copyMe.headPtr->next;
			while (sourcePtr != nullptr) {
				newList->next = new node;
				if (sourcePtr == copyMe.preCursor) {
					preCursor = newList->next;
				}
				newList = newList->next;
				newList->data = sourcePtr->data;

				if (sourcePtr == copyMe.cursor) {
					cursor = newList;
				}
				sourcePtr = sourcePtr->next;
			}

			tailPtr = newList;
			newList->next = nullptr;
		}
		numItems = copyMe.numItems;
	}







	void sequence::clear()
	{

		node* deleteMe;
		while (headPtr != nullptr) {
			deleteMe = headPtr;
			headPtr = headPtr->next;
			delete deleteMe;
		}
		numItems = 0;
	}






	sequence sequence::operator=(const sequence& right)
	{
		if (this != &right) {
			clear();
			copy(right);
		}
		return *this;
	}






	void sequence::start()
	{
		cursor = headPtr;
		preCursor = nullptr;
	}






	void sequence::advance()
	{
		assert(is_item());
		preCursor = cursor;
		cursor = cursor->next;


	}






	void sequence::insert(const value_type& entry) {
		numItems++;
		node* tempPtr = new node;
		tempPtr->data = entry;
		if (headPtr == nullptr) {
			preCursor = nullptr;
			tempPtr->next = nullptr;
			headPtr = tempPtr;
			tailPtr = tempPtr;
		}
		else if (cursor == nullptr || cursor == headPtr) {
			tempPtr->next = headPtr;
			headPtr = tempPtr;
		}
		else {
			tempPtr->next = cursor;
			preCursor->next = tempPtr;
		}
		cursor = tempPtr;
	}






	void sequence::attach(const value_type& entry)
	{
		numItems++;
		node *tempPtr = new node;
		tempPtr->data = entry;
		if (headPtr == nullptr) {
			tempPtr->next = nullptr;
			headPtr = tempPtr;
			tailPtr = tempPtr;
			cursor = headPtr;
			preCursor = nullptr;
		}
		else if (!is_item()) {
			preCursor = tailPtr;
			tailPtr = tempPtr;
			preCursor->next = tailPtr;
			tempPtr->next = nullptr;
		}
		else {
			preCursor = cursor;
			cursor = tempPtr;
			tempPtr->next = preCursor->next;
			preCursor->next = tempPtr;
			if (tailPtr == preCursor) {
				tailPtr = tailPtr->next;
			}
		}
		cursor = tempPtr;
	}






	void sequence::remove_current()
	{
		assert(is_item());
		numItems--;
		if (headPtr == cursor && headPtr->next == nullptr) {
			delete headPtr;
			headPtr = nullptr;
			tailPtr = nullptr;
			cursor = nullptr;
			preCursor = nullptr;
		}
		else if (headPtr == cursor && headPtr->next != nullptr) {
			node* tempPtr;
			tempPtr = headPtr->next;
			delete headPtr;
			headPtr = tempPtr;
			cursor = headPtr;
			preCursor = nullptr;

		}
		else {
			preCursor->next = cursor->next;
			delete cursor;
			cursor = preCursor->next;
			if (preCursor->next == nullptr) {
				tailPtr = preCursor;
				preCursor = nullptr;

			}
		}
	}






	size_t sequence::size() const
	{
		return numItems;
	}






	bool sequence::is_item() const
	{
		bool result;
		if (cursor != nullptr) {
			result = true;
		}
		else {
			result = false;
		}
		return result;
	}






	int sequence::current() const
	{
		assert(is_item());
		return cursor->data;

	}
}
