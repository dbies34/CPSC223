// Clientprogram.cpp
// Drew Bies
// username: abies2
// This program will test the operations in class Heap and revised class Key
//	the functions insert and remove are tested in this program. the trees 
//	being tested are printed to the screen. 

#include "Exception.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Key.h"
#include "Heap.h"

//opens an input file with a chosen name
//post if name for inputFile exists in directory, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile);

//runs an example of the functions of Heap.cpp
//pre maxheap is filled from the infile
//post 2 examples of insert and remove have been done
//	and printed to the screen
//usage runExample(maxheap);
void runExample(Heap& maxheap);

//prints new lines
//pre num has been assigned
//post the num amount of new lines have been printed
void printNewLines(int num);

int main()
{
	ifstream infile;
	Heap maxheap;
	
	openInputFile(infile);
	
	infile >> maxheap;
	runExample(maxheap);
	
	return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void openInputFile(ifstream& inputFile) 
{
   inputFile.open("Heap.dat");
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}

//runs an example of the functions of Heap.cpp
//pre maxheap is filled from the infile
//post 2 examples of insert and remove have been done
//	and printed to the screen
//usage runExample(maxheap);
void runExample(Heap& maxheap)
{
	Key maxKey;
	Key akey(55);
	Key bkey(30);
	
	cout << maxheap;
	printNewLines(3);
	
	cout << "insert(" << akey << ")" << endl;
	maxheap.insert(akey);
	cout << maxheap;
	printNewLines(3);
	
	cout << "insert(" << bkey << ")" << endl;
	maxheap.insert(bkey);
	cout << maxheap;
	printNewLines(3);
	
	cout << "removing the max key:" << endl;
	maxheap.remove(maxKey);
	cout << maxheap;
	printNewLines(3);
	
	cout << "removing the max key:" << endl;
	maxheap.remove(maxKey);
	cout << maxheap;
	printNewLines(3);
}	

//prints new lines
//pre num has been assigned
//post the num amount of new lines have been printed
void printNewLines(int num)
{
	for(int i = 0; i < num; i++)
	{
		cout << endl;
	}
}