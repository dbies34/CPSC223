// Clientprogram.cpp
// Drew Bies
// username: abies2

// this program opens the infile and fills the Two34Tree with each of the keys
//		and prints each of the cases to the outfile

#include "Two34Tree.h"
#include "Exception.h"
#include <fstream>

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

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenOutputFile(ofstream& outputFile, string filename) 
{
	outputFile.open(filename);
	if (outputFile.fail())
	{
		cout << "ERROR: \"" << filename << "\" failed to open!!!!" << endl;
		exit(1);
	}
}

// inserts to the tree
// pre infile and outfile have been assigned
// post using infile, the keys are inserted to the tree
// 		and printed to outfile
void insertToTree(istream& infile, ostream& outfile)
{
	Two34Tree tree;
	Key newKey;
	int numOfItems;
	infile >> numOfItems;
	for(int i = 0; i < numOfItems; i++)
	{
		infile >> newKey;
		try{
			tree.insert(newKey);
		} catch (Exception ex){
			outfile << ex.What() << endl << endl;
		}
			
	}
	tree.display(outfile, 'p');
	infile >> newKey;
	outfile << "Insert (" << newKey << ")" << endl << endl;
	try{
		tree.insert(newKey);
	} catch (Exception ex){
		outfile << ex.What() << endl << endl;
	}
	tree.display(outfile, 'p');
	outfile << endl << endl;
}

// runs all the cases
// pre infile and outfile have been assigned
// post all the cases have been printed from infile to the outfile
void runSubCases(istream& infile, ostream& outfile)
{
	outfile << endl << "		Insert to Root: Subcase: insert to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert to Root: Subcase: insert to middle" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert to Root: Subcase: insert to right" << endl << endl;
	insertToTree(infile, outfile);
	
	outfile << endl << "		Cause root node to split: Subcase: insert to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause root node to split: Subcase: insert to middle and to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause root node to split: Subcase: insert to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause root node to split: Subcase: insert to middle and to right" << endl << endl;
	insertToTree(infile, outfile);
	
	outfile << endl << "		Into a level 2 node: Subcase: insert to left to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to right to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to right to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to left to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to right to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to right to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to right to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to left to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to left to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to right to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to left to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Into a level 2 node: Subcase: insert to left to right" << endl << endl;
	insertToTree(infile, outfile);
	
	outfile << endl << "		Cause level 2 node to split: Subcase: insert to left to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 node to split: Subcase: insert to left to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 node to split: Subcase: insert to middle to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 node to split: Subcase: insert to middle to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 node to split: Subcase: insert to right to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 node to split: Subcase: insert to right to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 node to split: Subcase: insert to middle to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 node to split: Subcase: insert to middle to left" << endl << endl;
	insertToTree(infile, outfile);
	
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to left to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to left to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to middle to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to middle to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to right to left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to right to right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to left to middle" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to middle to middle" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to right to middle" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Insert into three level 2 nodes: Subcase: insert to right to middle" << endl << endl;
	insertToTree(infile, outfile);
	
	outfile << endl << "		Cause level 2 split to make 4 children: Subcase: insert right, middle, right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 split to make 4 children: Subcase: insert right, middle, left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 split to make 4 children: Subcase: insert right, right, right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 split to make 4 children: Subcase: insert right, right, left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 split to make 4 children: Subcase: insert left, left, right" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 split to make 4 children: Subcase: insert left, middle, left" << endl << endl;
	insertToTree(infile, outfile);
	outfile << endl << "		Cause level 2 split to make 4 children: Subcase: insert left, middle, right" << endl << endl;
	insertToTree(infile, outfile);
}

int main()
{
	ifstream infile;
	ofstream outfile;
	
	OpenInputFile(infile, "Input.dat");
    OpenOutputFile(outfile, "Two.out");
	
	runSubCases(infile, cout);
	
	return 0;
}

