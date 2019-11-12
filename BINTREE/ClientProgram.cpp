// ClientProgram.cpp
// Drew Bies
// username: abies2


#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "BinaryTree.h"

using namespace std;

void printFirstTree(BinaryTree& tree);

void printSecondTree(BinaryTree& tree);

void printTraversal(BinaryTree& tree);

void openInputFile(ifstream& infile);

void readOneTreeNode(ifstream& infile, Item& newItem, int& left, int& right);

void readTreeNodesAndInsert(ifstream& infile, BinaryTree& tree);

int main()
{
	ifstream infile;
	openInputFile(infile);
	BinaryTree firstTree, secondTree;
	
	readTreeNodesAndInsert(infile, firstTree);
	printFirstTree(firstTree);
	
	readTreeNodesAndInsert(infile, secondTree);
	printSecondTree(secondTree);
	
	
	return 0;
}

void printFirstTree(BinaryTree& tree)
{
	cout << "A Full Tree of Height 3" << endl << endl;
	cout << "                              1111111 Allie F" << endl;
	cout << "                             /              \\ " << endl;
	cout << "                2222222 Evan S               3333333 Mason D" << endl;
	cout << "                /           \\                 /           \\ " << endl;
	cout << " 4444444 Michael H   5555555 Kevin S   5656565 Reggie M    6767676 Spike L" << endl << endl;
	
	printTraversal(tree);
}

void printSecondTree(BinaryTree& tree)
{
	cout << "A Degenerate Tree of Height 4" << endl << endl;
	cout << "  7878787 Kyrie Irving" << endl;
	cout << "                  \\ " << endl;
	cout << "            7777777 Steph Curry" << endl;
	cout << "                            \\ " << endl;
	cout << "                         8888888 Kevin Love" << endl;
	cout << "                                        \\ " << endl;
	cout << "                                  9999999 Boogie Cousins" << endl << endl;
	
	printTraversal(tree);
}

// prints the traversals of the binary tree
// pre tree exists
// post the tree has been printed as each of the traversals
// usage printTraversal(tree);
void printTraversal(BinaryTree& tree)
{
	cout << "Preorder Traversal:" << endl << endl;
	tree.preorder();
	cout << "Inorder Traversal:" << endl << endl;
	tree.inorder();
	cout << "Postorder Traversal:" << endl << endl;
	tree.postorder();
}

// opens input file
// pre infile exists
// post opens "Input.dat" into infile
//		else exits the program
// usage openInputFile(infile);
void openInputFile(ifstream& infile)
{
	infile.open("Input.dat");
	if(infile.fail())
	{
		cout << "ERROR in opening Input.dat !!!" << endl;
		exit(1);
	}
}

// reads one tree node
// pre infile is filled from the file. newItem, left, and right exists
//		infile's pointer is at the beginning of the item
//		item at the top with the two children integers below
//		example:
//		1111111 Alli F
//		1 2 
//		
// post newItem, left, and right have been filled from infile
//		infile's pointer is after the newline
// usage readOneTreeNode(infile, newItem, left, right);
void readOneTreeNode(ifstream& infile, Item& newItem, int& left, int& right)
{
	char newline;
	
	infile >> newItem;
	infile >> left;
	infile >> right;
	infile.get(newline);
}

// reads and inserts the tree nodes
// pre infile is filled & tree exists
//		infile's pointer is before the number of nodes
//		the first line has the number of nodes to be read
//		infile has next item 
//		ex.
//		2
//		1111111 Alli F
//		1 -1
//		2222222 Drew B
//		-1 -1
//		
// post tree is filled from infile
// usage readTreeNodesAndInsert(infile, tree);
void readTreeNodesAndInsert(ifstream& infile, BinaryTree& tree)
{
	int numberOfNodes, left, right;
	Item newItem;
	char newline;
	
	infile >> numberOfNodes;
	infile.get(newline);
	for(int i = 0; i < numberOfNodes; i++)
	{
		readOneTreeNode(infile, newItem, left, right);
		tree.insert(newItem, left, right);
	}
}