/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 14 - 1
binarytree.h

*/


#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstdlib>	// for size_t
#include "LL.h"

class binarytree 
{

	public:
		typedef std::size_t size_type;
		binarytree();
		~binarytree();
		binarytree( const binarytree& copyData );
		binarytree operator=( const binarytree& copyData );

		void insert(int item);
		void print() const;
		int find(int target, bool& found) const;
		void del(int target, bool& found);

		size_type size() const;
		int numPrimes() const;
		LL<int> toLL() const;


	private:
		struct treenode 
		{
			int data;
			treenode* left;
			treenode* right;
		};
		treenode* root;

		size_type mSize;
		static int numPrimes_aux( const treenode* root );
		static void toLL_aux( LL<int> &linkedList, const treenode* rootptr );

		static void copy( treenode*& target, const treenode* source );
		static void clear( treenode*& root );

		static void insert_aux(treenode*& root, int item);
		static void print_aux(const treenode* root);
		static size_type size_aux(const treenode* root);
		static int find_aux(const treenode* root, int target, bool& found);
		static void del_aux(treenode*& root, int target, bool& found);
		static void remove_max(treenode*& root, int& max);
};
#endif