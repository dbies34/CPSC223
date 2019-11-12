// Implementation of ADT Dictionary
// Drew Bies
// username: abies2
//     data object: a bunch of contacts (phone number and name)
//     data structure: a header record in the heap with number of items and
//                     a dynamic array of Item objects as a hash table with linear probing
//     operations: create, destroy
//                 search the dictionary for an item given its phone number
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its phone number

#include "Dictionary.h"

struct DictionaryRecord
{
	int numberOfItems;
	Item* hashPtr;
};

const int TABLESIZE = 11;

int hashFunction(const Key& theKey)
{
	return theKey.sumDigits() % TABLESIZE;
}

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       address    phone       name
//          0       123-4567 Frosty Snowguy
//          1       111-2222 Icy Dog 
// usage: outfile << myDictionary;    
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
	Item nextItem, nItem;
	
	
	output << "address       phone    name" << endl;
	for(int address = 0; address < TABLESIZE; address++)
	{
		nextItem = rightHandSideDictionary.dictionaryPtr -> hashPtr[address];
		output << "   " << address << "         ";
		if(address < 10) output << " ";
		if(nextItem.sumDigits() == 0) output << nItem;
		else output << nextItem;
	}
	return output;
}

// inputs items into a dictionary
// pre: input has been opened if it is a file
//      items are arranged in the following format
//		2
//      1234567 Frosty Snowguy
//      1112222 Icy Dog
// post: if there is room, 
//       all items in the input have been stored in rightHandSideDictionary
// usage: infile >> myDictionary;
istream& operator>> (istream& input, Dictionary& rightHandSideDictionary)
{
	int numberItems;
	char enter;
	Item anItem;
	input >> numberItems;
	input.get(enter);
	bool isFull;
	for(int i = 0; i < numberItems; i++)
	{
		input >> anItem;
		rightHandSideDictionary.insert(anItem, isFull);
	}
	return input;
}

// creates a new dictionary
// post: Dictionary object exists but is empty
// usage: Dictionary myDictionary;
Dictionary::Dictionary()
{
	dictionaryPtr = new DictionaryRecord;
	dictionaryPtr -> numberOfItems = 0;
	dictionaryPtr -> hashPtr = new Item [TABLESIZE];
}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
	delete [] dictionaryPtr -> hashPtr;
	delete dictionaryPtr;
}

// searchs for a contact with a particular phone number
// pre targetPhone has been assigned a 7-digit phone number
// post if an item with phone number the same as targetPhone is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  contacts.search(targetPhone, anItem, isFound);
void Dictionary::search (const Key& targetPhone, Item& theItem, bool& isFound)
{
	int index, count = 0;
	index = hashFunction(targetPhone);
	while(!(dictionaryPtr -> hashPtr[index] == targetPhone) && count < TABLESIZE)
	{
		index = (index + 1) % TABLESIZE;
		count++;
	}
	if(dictionaryPtr -> hashPtr[index] == targetPhone) {
		isFound = true; 
		theItem = dictionaryPtr -> hashPtr[index];
	}else{
		isFound = false;
	}
}

// inserts a new contacts' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object, isFull is false
//            and newItem is appropriately added
//       else isFull is false
// usage: myDictionary.insert(myItem, isFull);
void Dictionary::insert (const Item& newItem, bool& isFull)
{	
	int index;
	Item nItem;

	isFull = (dictionaryPtr -> numberOfItems == TABLESIZE);
	if(!isFull)
	{
		index = hashFunction(newItem);
		
		while(!(dictionaryPtr -> hashPtr[index].sumDigits() == 0))
		{
			index = (index + 1) % TABLESIZE;
		}
		dictionaryPtr -> hashPtr[index] = newItem;
		dictionaryPtr -> numberOfItems = dictionaryPtr -> numberOfItems + 1;
	}
}

// removes the item associated with a given phone number from the dictionary
// pre: targetPhone is assigned
// post: if targetPhone is found in Dictionary object, isDone is true
//           and the associated Item object (phone and name) has been 
//           removed from the Dictionary
//       else isDone is false
// usage: myDictionary.remove(myPhone, isFound);
void Dictionary::remove (const Key& targetPhone, bool& isDone)
{
	int index, count = 0;
	Item newItem;
	index = hashFunction(targetPhone);
	while(!(dictionaryPtr -> hashPtr[index] == targetPhone) && count < TABLESIZE)
	{
		index = (index + 1) % TABLESIZE;
		count++;
	}
	if(dictionaryPtr -> hashPtr[index] == targetPhone) {
		isDone = true; 
		dictionaryPtr -> hashPtr[index] = newItem; 
	}else{
		isDone = false;
	}
}