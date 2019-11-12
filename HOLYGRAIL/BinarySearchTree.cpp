//BinarySearchTree.cpp
// Drew Bies
// username: abies2


//Implementation of Binary Search Tree
//		abstract definition


//data structure: a linked binary tree

#include "BinarySearchTree.h"



//recursive helpers***********************************
//binary search on a dynamic data structure

// helper for search
void searchHelper(TreeNode* treep, const Key& targetPhone, Item& anItem) throw(Exception)
{
	if(treep == nullptr)
		throw Exception("Error: The phone number could not be found in the dictionary.");
	else if(targetPhone == treep -> item)
		anItem = treep -> item;
	else if(targetPhone < treep -> item)
		searchHelper(treep -> leftChild, targetPhone, anItem);
	else
		searchHelper(treep -> rightChild, targetPhone, anItem);
}

// helper for insert
void insertHelper(TreeNode*& treep, const Item& newItem) throw(Exception)
{
	if(treep == nullptr)
	{
		treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
		if(treep == nullptr)
			throw Exception("Error: no more room for the new item.");
		else numberOfEntrees++;
	}
	else if(newItem == treep -> item)
		throw Exception("Error: item already exists in the dictionary.");
	else if(newItem < treep -> item)
		insertHelper(treep -> leftChild, newItem);
	else
		insertHelper(treep -> rightChild, newItem);
}

// helper for remove
void findSuccessor(TreeNode* treep, Item& successor)
{
	if(treep -> leftChild == nullptr)
		successor = treep -> item;
	else
		findSuccessor(treep -> leftChild, successor);
}

// helper for remove
void removeHelper(TreeNode*& treep, const Key& targetPhone) throw(Exception)
{
	if(treep == nullptr)
		throw Exception("Error: item to be deleted was not found.");
	if(targetPhone < treep -> item)
		removeHelper(treep -> leftChild, targetPhone);
	else if(treep -> item < targetPhone)
		removeHelper(treep -> rightChild, targetPhone);
	else
	{
		TreeNode* delptr;
		if(treep -> rightChild == nullptr && treep -> leftChild == nullptr)
		{
			delptr = treep;
			delete delptr;
			treep = nullptr;
			numberOfEntrees--;
		}
		else if(treep -> rightChild == nullptr)
		{
			delptr = treep;
			treep = treep -> leftChild;
			delete delptr;
			numberOfEntrees--;
		}
		else if(treep -> leftChild == nullptr)
		{
			Item successor;
			findSuccessor(treep -> rightChild, successor);
			removeNode(successor);
			treep -> item = successor;
		}
	}
}

// helper for rebalance
void readTree(TreeNode*& treep, int numOfEntrees, istream& inputFile)
{
	if(numOfEntrees > 0)
	{
		treep = new (nothrow) TreeNode();
		if(treep == nullptr)
			throw Exception("Error: no more room in memory.");
		TreeNode* leftPtr = treep -> leftChild;
		readTree(leftPtr, numOfEntrees / 2, inputFile);
		treep -> leftChild = leftPtr;
		Item newItem;
		inputFile >> newItem;
		treep -> item = newItem;
		TreeNode* rightPtr = treep -> rightChild;
		readTree(rightPtr, (numOfEntrees - 1) / 2, inputFile);
		treep -> rightChild = rightPtr;
	}
}

// helper for inorderTraverse
void inorder(TreeNode* treep, ostream& output)
{
	if(treep != nullptr)
	{
		inorder(treep -> leftChild, output);
		output << treep -> item;
		inorder(treep -> rightChild, output);
	}
}

// constructor
BinarySearchTree::BinarySearchTree()
{
	numberOfEntrees = 0;
}

// deconstructor
BinarySearchTree::~BinarySearchTree()
{
	numberOfEntrees = 0;
}
	
// copy constructor	
BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree)
{
	copyTree(root, rhsBinarySearchTree.root);
	numberOfEntrees = rhsBinarySearchTree.numberOfEntrees;
}

// searches for theItem given the targetPhone
// pre targetPhone and theItem exists
// post if found theItem now the item of targetPhone, else throws error exception
void BinarySearchTree::search(const Key& targetPhone, Item& theItem) throw(Exception)
{
	searchHelper(root, targetPhone, theItem);
}

// inserts theItem
// pre newItem exists
// post newItem is inserted in the correct area
//		throws exception if there is no more space in the heap
void BinarySearchTree::insert(const Item& newItem) throw(Exception)
{
	insertHelper(root, newItem);
}

// rebalances the tree
// pre inputFile is right before the number on the first line
// post inputfile is left below the last item.
//		the binary search tree is rebalanced from inputFile
//		throws exception if no more memory in heap
void BinarySearchTree::rebalance(istream& inputFile) throw(Exception)
{
	char enter;
	inputFile >> numberOfEntrees;
	inputFile.get(enter);
	readTree(root, numberOfEntrees, inputFile);
}
	
// pre treep points to the root. targetPhone exists
// post the item of targetPhone has been deleted
//		throws exception if targetPhone is not found
void BinarySearchTree::removeNode(const Key& targetPhone) throw(Exception)
{
	removeHelper(root, targetPhone);
}

// pre treep points to the root of a binary tree to be traversed
// post prints the item objects in the nodes to output in the 
//     specified order.
void BinarySearchTree::inorderTraverse(ostream& output)
{
	inorder(root, output);
}