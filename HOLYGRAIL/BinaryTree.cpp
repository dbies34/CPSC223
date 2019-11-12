//file BinaryTree.cpp
//Drew Bies
//username: abies2

//data object: a binary tree which is composed of TreeNodes linked together
//data structure: a linked binary tree
//operations: (a scaled-down version)
//       create, destroy, copy, operator=,
//       traversals (preorder, inorder, postorder)

#include "BinaryTree.h"
using namespace std;

// ***************** recursive helpers *****************

//Releases memory for a binary tree
//pre: treep points to the root of a binary tree
//post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
//usage: destroyTree (mroot);
void destroyTree(TreeNode*& treep)
{
	if(treep != nullptr)
	{
		destroyTree(treep -> leftChild);
		destroyTree(treep -> rightChild);
		delete treep;
		treep = nullptr;
	}
}

//Copies one binary tree to another
//pre oldtreep points to the root of a binary tree
//post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
//usage: copyTree (newptr, oldptr);
void copyTree(TreeNode*& newtreep, TreeNode* oldtreep) throw (Exception)
{
	if(newtreep != nullptr) 
		destroyTree(newtreep);
	if(oldtreep != nullptr)
		newtreep = nullptr;
	else
	{
		// preorder traversals
		newtreep = new (nothrow) TreeNode(oldtreep -> item, nullptr, nullptr);
		if(newtreep == nullptr) 
			throw Exception("operator=: no space in the heap");
		copyTree(newtreep -> leftChild, newtreep -> leftChild);
		copyTree(newtreep -> rightChild, newtreep -> rightChild);
	}
}

// recursive helper for prettyDisplay.
//pre treep exists
//post treep is printed out with the help of level and branch
//usage writePretty(treep, level, branch);
void writePretty(TreeNode* treep, int level, int child)
{
	if(treep != nullptr)
	{
		writePretty(treep -> rightChild, level + 1, 2);
		int space = 0;
		if(level == 2) space = 25;
		if(level == 3) space = 40;
		if(level == 1) cout << "root -> ";
		cout << setw(space);
		if(child == 1) cout << '\\' << endl << setw(space);
		cout << treep -> item;
		if(child == 2) cout << setw(space) << '/' << endl;
		writePretty(treep -> leftChild, level + 1, 1);
	}
}

// ********** recursive helpers for the traversals ****************
//pre: treep points to the root of a binary tree to be traversed
//post: prints the item objects in the nodes on the screen in the 
//     specified order. the items are separated by commas
//usage: preorder (mroot);   
//       similarly for the others
void preorder(TreeNode* treep)
{
	if (treep != nullptr)
	{
		cout << treep -> item;
		preorder(treep -> leftChild);
		preorder(treep -> rightChild);
	}
}

void inorder(TreeNode* treep, ostream& output)
{
	if (treep != nullptr)
	{
		inorder(treep -> leftChild, output);
		output << treep -> item;
		inorder(treep -> rightChild, output);
	}
}


void postorder(TreeNode* treep)
{
	if (treep != nullptr)
	{
		postorder(treep -> leftChild);
		postorder(treep -> rightChild);
		cout << treep -> item;
	}
}

// **************************public methods************************


//creates an empty binary tree
//post: object is an empty binary tree
//usage: BinaryTree zags;
BinaryTree::BinaryTree()
{
	root = nullptr;
}

//creates a new binary tree that is a copy of an existing tree
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: BinaryTree zags (bulldog);
BinaryTree::BinaryTree(const BinaryTree& rightHandSideTree) throw (Exception)
{
	root = nullptr;
	copyTree(root, rightHandSideTree.root);
}

//releases the memory of a binary tree
//pre: object exists
//post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
BinaryTree::~BinaryTree()
{
	destroyTree(root);
}

// ******************** member functions ********************************************
//@pre: binary tree object exists
// **********************************************************************************

//checks for an empty tree
//post: returns true if the object is empty; else returns false
//usage: if (tree.isEmpty())
bool BinaryTree::isEmpty() const
{
   return (root == nullptr);
}

//copies one tree to another
//pre: rightHandSideTree is an assigned tree.
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: atree = btree = ctree;
BinaryTree& BinaryTree::operator=(const BinaryTree& rightHandSideTree) throw (Exception)
{
	if(this != &rightHandSideTree)
	{
		copyTree(root, rightHandSideTree.root);
	}
	return *this;
}

//prints the tree to look like a computer science tree
//post: outputs the tree as in the example below
//
//                        bar
//                  foo
//                        geeU
//  root ->  queue
//                        stack
//                  list
//                        array
//nodes at the same level are indented the same.
//Viewer must rotate head 90 degrees in order to look like a cs tree
//usage: tree.prettyDisplay();
void BinaryTree::prettyDisplay()
{
	writePretty(root, 1, -1);
}

// *************** on the following traversals

//post: prints the objects in the tree in order specified
//usage: tree.preorderTraverse();  
//similarly for the other traversals
// *****************************************************
void BinaryTree::preorderTraverse()
{
	preorder(root);
}

void BinaryTree::inorderTraverse(ostream& output)
{
	inorder(root, output);
}

void BinaryTree::postorderTraverse()
{
	postorder(root);
}