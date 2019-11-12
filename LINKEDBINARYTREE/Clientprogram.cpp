//filename: Clientprogram.cpp
//Drew Bies
//username: abies2
//discription: opens "Input.dat" and stores to infile. 
//		prints two different binary trees to the screen with traversals and labels.
//		treeOne being a full binary tree of height 2.
//		treeTwo being a full binary tree of height 3.

#include "BinaryTree.h"
#include "Exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

//opens and prints the tree
//pre infile is before the first item. tree, title, and treeNum exists
//post infile is on the newline after the last item. tree is filled with the items
//		& printed to the screen with labels. prints except if an exception is caught.
//usage openAndPrintTree(infile, tree, title, treeNum);
void openAndPrintTree(ifstream& infile, BinaryTree& tree, string title, int treeNum);

// prints the traversals of the binary tree
// pre tree exists
// post the tree has been printed as each of the traversals 
// usage printTraversal(tree);
void printTraversal(BinaryTree& tree);

int main()
{
	BinaryTree treeOne, treeTwo;
	ifstream infile;
	
	OpenInputFile(infile, "Input.dat");
	
	openAndPrintTree(infile, treeOne, "Tree One: full binary tree of height 2.", 1);
	openAndPrintTree(infile, treeTwo, "Tree Two: full binary tree of height 3.", 2);
	
	return 0;
}

//opens and prints the tree
//pre infile is before the first item. tree, title, and treeNum exists
//post infile is on the newline after the last item. tree is filled with the items
//		& printed to the screen with labels. prints except if an exception is caught.
//usage openAndPrintTree(infile, tree, title, treeNum);
void openAndPrintTree(ifstream& infile, BinaryTree& tree, string title, int treeNum)
{
	try {
		cout << endl << title << endl << endl;
		if(treeNum == 1) 
			tree.makeTreeOne(infile);
		else 
			tree.makeTreeTwo(infile);
	}
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
	tree.prettyDisplay();
	printTraversal(tree);
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename) 
{
	inputFile.open(filename);
	if (inputFile.fail())
	{
		cout << "ERROR: \"" << filename << "\" failed to open!!!!" << endl;
		exit(1);
	}
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except)
{
	cout << endl << endl;
	cout << except.What();
	cout << endl << endl;
}

// prints the traversals of the binary tree
// pre tree exists
// post the tree has been printed as each of the traversals
// usage printTraversal(tree);
void printTraversal(BinaryTree& tree)
{
	cout << endl << "Preorder Traversal:" << endl;
	tree.preorderTraverse();
	cout << endl << "Inorder Traversal:" << endl;
	tree.inorderTraverse();
	cout << endl << "Postorder Traversal:" << endl;
	tree.postorderTraverse();
	cout << endl;
}