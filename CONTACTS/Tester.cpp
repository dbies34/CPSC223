// Tester.cpp
// Drew Bies
// username: abies2
// tester for Key.cpp and Item.cpp

#include "Key.h"
#include "Item.h"


//prints new lines
//pre num is a positive integer
//post num amount of lines are printed out
//usage printNewLines(5);
void printNewLines(int num);

int main()
{
	Key akey, bkey, ckey("9925639"), dkey;
	
	cout << "Enter a 7-digit phone number without spaces or dashes -> ";
	cin >> akey;
	cout << "Phone Number you just entered: " << akey << endl;
	cout << "Sum of the phone number: " << akey.sumDigits() << endl << endl;
	
	
	
	bkey = akey;
	cout << akey << " and " << bkey << " are ";
	if(!(akey == bkey)) cout << "not ";
	cout << "equal." << endl << endl;
	
	cout << akey << " and " << ckey << " are ";
	if(!(akey == ckey)) cout << "not ";
	cout << "equal." << endl << endl;
	
	cout << akey << " is less than " << ckey << ": ";
	if(akey < ckey) cout << "true.";
	else cout << "false";
	
	printNewLines(3);
	
	cout << ckey << " is less than " << ckey << ": ";
	if(ckey < ckey) cout << "true.";
	else cout << "false";
	
	printNewLines(3);
	
	
	Item aitem, ditem, eitem;
	cout << "Enter a 7-digit phone number then a space then a first name space last name -> ";
	cin >> aitem;
	cout << endl << "Number and name: " << aitem << endl << endl;
	
	Item bitem(aitem);
	cout << "Copied number and name (using copy constructor): " << bitem << endl << endl;
	
	cout << "Sum of the phone number: " << aitem.sumDigits() << endl << endl;
	
	
	Item citem;
	citem = aitem;
	cout << "Copied number and name (using operator=): " << citem << endl << endl;
	
	cout << endl << "Enter a different 7-digit phone number then a space then a first name space last name -> ";
	cin >> ditem;
	
	cout << aitem << " and " << bitem << " are ";
	if(!(aitem == bitem)) cout << "not ";
	cout << "equal." << endl << endl;
	
	cout << aitem << " and " << ditem << " are ";
	if(!(aitem == ditem)) cout << "not ";
	cout << "equal." << endl << endl;
	
	cout << eitem << " is less than " << ditem << ": ";
	if(eitem < ditem) cout << "true.";
	else cout << "false";
	
	printNewLines(3);
	
	cout << ditem << " is less than " << ditem << ": ";
	if(ditem < ditem) cout << "true.";
	else cout << "false";

	printNewLines(3);
	
	return 0;
}

//prints new lines
//pre num is a positive integer
//post num amount of lines are printed out
//usage printNewLines(5);
void printNewLines(int num)
{
	for(int i = 0; i < num; i++)
	{
		cout << endl;
	}
}