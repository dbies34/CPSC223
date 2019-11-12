//file Clientprogram.cpp
//Drew Bies
//username: abies2

// struct: root pointing to a binary search tree. each node containing an item and two pointers to the children
//			the item being an array of chars and a phoneNumber which is also an array of chars
// discription: this program runs an electric dictionary containing contacts(name and number). 
//				the options given to the user are:  delete a contact, find a contact, insert a contact, list the contacts, 
//													print the tree in a pretty fashion, rebalance the tree, save the contacts,
//													and exit which also saves the contacts.



#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "Exception.h"
#include "BinaryTree.h"
#include "Item.h"
using namespace std;

// prints the menu
// pre none
// post the menu is printed onto the screen
void printMenu();

// does the option
// pre choice, dictionary, and inputFile exists
// post using choice, the desired option is done on dictionary and inputFile
void doOption(char choice, BinaryTree& dictionary);

// gets the option from the user 
// pre none
// post returns a char
char getOption();

// finds a contact
// pre dictionary exists
// post given a phone number, an item is returned from the dictionary
void findContact(BinaryTree& dictionary);

// inserts a contact
// pre dictionary exists
// post inserts an item to the dictionary
void insertContact(BinaryTree& dictionary);

// lists the items
// pre dictionary exists
// post prints the items from dictionary to the screen
void listItems(BinaryTree& dictionary);

// saves the dictionary
// pre dictionary and inputFile exists 
// post dictionary has been saved to inputFile
void saveTree(BinaryTree& dictionary, ifstream& inputFile);

// rebalances the tree
// pre dictionary and output exists
// post dictionary has been rebalanced and printed to output
void rebalanceTree(BinaryTree& dictionary, ostream& output);

// prints the tree
// pre dictionary exists
// post dictionary has been printed to the screen
void printTree(BinaryTree& dictionary);

// deletes an item
// pre dictionary exists
// post the item from the dictionary has been deleted given the phone number
//		throws exception if the item id not found
void deleteItem(BinaryTree& dictionary);

// checks if choice is not an exit
// pre choice exists
// post returns false if choice is the exit char, 
//		returns true if not an exit char
bool isNotExit(char choice);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename);

int main()
{
	ifstream infile;
	BinaryTree dictionary;
	OpenInputFile(infile, "dictionary.dat");
	
	printMenu();
	char choice = getOption();
	while(isNotExit(choice))
	{
		doOption(choice, dictionary, inputFile);
		printMenu();
		choice = getOption();
	}
	saveTree(dictionary, inputFile);
	
	return 0;
}

// prints the menu
// pre none
// post the menu is printed onto the screen
void printMenu()
{
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << endl << "Your options are:" << endl << endl;
	cout << " d : deletes a phone number and name from the dictionary" << endl;
	cout << " f : find the name of the contact, given their phone number" << endl;
	cout << " i : insert a new item (phone number and name) into the dictionary" << endl;
	cout << " l : list the items in the entire dictionary on the screen in inorder fashion" << endl;
	cout << " p : print the tree in pretty fashion (showing only the phone numbers)" << endl;
	cout << " r : rebalance the tree" << endl;
	cout << " s : save the dictionary to the file in sorted order – inorder --  ready to be read" << endl;
	cout << " e : exit the program which automatically does option s" << endl << endl;
	cout << "Enter your option > ";
}

// does the option
// pre choice, dictionary, and inputFile exists
// post using choice, the desired option is done on dictionary and inputFile
void doOption(char choice, BinaryTree& dictionary, ifstream& inputFile)
{
	if(choice == 'f')
		findContact(dictionary);
	else if(choice == 'i')
		insertContact(dictionary);
	else if(choice == 'l')
		listItems(dictionary);
	else if(choice == 'p')
		printTree(dictionary);
	else if(choice == 'r')
		rebalanceTree(dictionary, inputFile);
	else if(choice == 's')
		saveTree(dictionary, inputFile);
	else if(choice == 'd')
		deleteItem(dictionary);
	else
		cout << "Sorry input was not valid." << endl;
}

// gets the option from the user 
// pre none
// post returns a char 
char getOption()
{
	char choice, enter;
	cin >> choice;
	cin >> enter;
	cout << endl;
	return choice;
}

// finds a contact
// pre dictionary exists
// post given a phone number, an item is returned from the dictionary
void findContact(BinaryTree& dictionary)
{
	Key phoneNumber;
	Item name;
	cout << "Enter the phone number-> ";
	cin >> phoneNumber;
	cout << endl << endl;
	try {
		dictionary.search(phoneNumber, name);
		cout << "The name found with the given phone number: " << name << endl;
	}
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
}

// inserts a contact
// pre dictionary exists
// post inserts an item to the dictionary
void insertContact(BinaryTree& dictionary)
{
	Item newItem;
	cout << "Enter your contact like so with two spaces and no caps, \"1234567 first last\" -> ";
	cin >> newItem;
	cout << endl;
	try {
		dictionary.insert(newItem);
	}
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
}

// lists the items
// pre dictionary exists
// post prints the items from dictionary to the screen
void listItems(BinaryTree& dictionary)
{
	cout << "Listing Contacts:" << endl << endl;
	try	{
		dictionary.BinarySearchTree::inorderTraverse(cout);
	}
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
}

// saves the dictionary
// pre dictionary and inputFile exists 
// post dictionary has been saved to inputFile
void saveTree(BinaryTree& dictionary, ifstream& inputFile)
{
	try {
		dictionary.BinarySearchTree::inorderTraverse(inputFile);
		cout << "**Save Successful**" << endl << endl;
	}
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
}

// rebalances the tree
// pre dictionary and output exists
// post dictionary has been rebalanced and printed to output
void rebalanceTree(BinaryTree& dictionary, ostream& output)
{
	try {
		dictionary.BinarySearchTree::inorderTraverse(output);
	}
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
}

// prints the tree
// pre dictionary exists
// post dictionary has been printed to the screen
void printTree(BinaryTree& dictionary)
{
	dictionary.prettyDisplay();
}

// deletes an item
// pre dictionary exists
// post the item from the dictionary has been deleted given the phone number
//		throws exception if the item id not found
void deleteItem(BinaryTree& dictionary)
{
	Key delPhone;
	cout << "Enter the phone number of the contact you would like to remove with no spaces-> ";
	cin >> delPhone;
	try {
		dictionary.removeNode(delPhone);
		cout << "**Contact Successfully Deleted**" << endl;
	}
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
}

// checks if choice is not an exit
// pre choice exists
// post returns false if choice is the exit char, 
//		returns true if not an exit char
bool isNotExit(char choice)
{
	return (choice != 'e');
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