//BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"



class BinarySearchTree
{
public:

	BinarySearchTree();
	
	~BinarySearchTree();
	
	BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree);
	
	void search(const Key& targetPhone, Item& theItem) throw(Exception);
	
	void insert(const Item& newItem) throw(Exception);
	
	void removeItem(const Key& targetPhone) throw(Exception);
	
	void rebalance(istream& inputFile) throw(Exception);
	
	void inorderTraverse(ostream& output);
	
	int numberOfEntrees;
	
};
//#include "BinarySearchTree.cpp"
#endif