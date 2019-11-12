// Clientprogram.cpp
// Drew Bies
// username: abies2
// description: this program loads phone numbers and names from a seperate 
//		file. these items are then printed to the screen. some of the items
//		are then searched for and deleted and then printed out again.

#include "Dictionary.h"
#include <fstream>
#include <cstdlib>

// searches the dictionay for the numbers
// pre book is assigned
// post the search numbers from book are printed to the screen
void search(Dictionary& book);

// prints a message
// pre message is assigned
// post the message is posted to the screen
void printMessage(string message);

// prints a message
// pre message is assigned, anItem is assigned
// post the message and anItem is posted to the screen
void printMessage(string message, Item& anItem);

// prints the dictionary
// pre book is assigned
// post book is printed to the screen
void printDictionary(Dictionary& book);

// loads the dictionary from the file
// pre infile and book are assigned
// post book is loaded into infile
void loadDictionary(ifstream& infile, Dictionary& book);

// opens the file
// pre infile is assigned
// post opens infile is the file exists. exits program if not found
void openInputFile(ifstream& infile);

// prints lines to the screen
// pre num is assigned
// post the desired num of lines are printed to the screen
void printNewLines(int num);

int main()
{
	Item anItem;
	bool isFound, isDone;
	Key delKey("1234567");
	Dictionary book;
	ifstream infile;
	openInputFile(infile);
	
	loadDictionary(infile, book);
	printDictionary(book);
	
	printMessage("Adding three with the same address");
	loadDictionary(infile, book);
	printDictionary(book);
	
	printMessage("Adding two more to search for");
	loadDictionary(infile, book);
	printDictionary(book);
	
	search(book);
	
	printMessage("Deleting an item");
	book.search(delKey, anItem, isFound);
	book.remove(delKey, isDone);
	printDictionary(book);
	
	printMessage("Item deleted", anItem);
	search(book);
	
	
	return 0;
}

// searches the dictionay for the numbers
// pre book is assigned
// post the search numbers from book are printed to the screen
void search(Dictionary& book)
{
	Item anItem;
	bool isFound;
	Key aKey("1234567");
	book.search(aKey, anItem, isFound);
	cout << "Searching for: " << aKey << endl;
	cout << "Item of number: " << anItem << endl << endl;
	
	Key bKey("9191919");
	book.search(bKey, anItem, isFound);
	cout << "Searching for: " << bKey << endl;
	cout << "Item of number: " << anItem << endl;
}

// prints a message
// pre message is assigned
// post the message is posted to the screen
void printMessage(string message)
{
	cout << message << ": " << endl;
}

// prints a message
// pre message is assigned, anItem is assigned
// post the message and anItem is posted to the screen
void printMessage(string message, Item& anItem)
{
	cout << message << ": " << anItem << endl;
}

// prints the dictionary
// pre book is assigned
// post book is printed to the screen
void printDictionary(Dictionary& book)
{
	cout << book;
	printNewLines(3);
}

// loads the dictionary from the file
// pre infile and book are assigned
// post book is loaded into infile
void loadDictionary(ifstream& infile, Dictionary& book)
{
	infile >> book;
}

// opens the file
// pre infile is assigned
// post opens infile is the file exists. exits program if not found
void openInputFile(ifstream& infile)
{
	infile.open("Input.dat");
	if(infile.fail())
	{
		cout << "ERROR in opening Input.dat !!!" << endl;
		exit(1);
	}
}

// prints lines to the screen
// pre num is assigned
// post the desired num of lines are printed to the screen
void printNewLines(int num)
{
	for(int i = 0; i < num; i++)
	{
		cout << endl;
	}
}