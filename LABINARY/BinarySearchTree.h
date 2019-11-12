//BinarySearchTree.h

//#ifndef BINARYSEARCHTREE_H
//#define BINARYSEARCHTREE_H


class BinarySearchTree: public BinaryTree
{
public:

	BinarySearchTree();
	
	~BinarySearchTree();
	
	BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree);
	
	void search(const Key& targetPhone, Item& theItem) throw(Exception);
	
	void insert(const Item& newItem) throw(Exception);
	
	void remove(const Key& targetPhone) throw(Exception);
	
};