// stack.cpp
// Drew Bies, Chris Martin
// username: abies2
// Abstract Data Type Stack: 
//    data object is a stack where the most-recently-added (or top) item
//                is most-easily accessible
//    operations on a stack:
//        create an empty stack
//        delete memory or "destroy" the stack
//        add a new item as the most-recently-added or top item
//        retrieve the most-recently-added or top item from the stack and copy
//        remove the most-recently-added (or top item) from the stack
//        check if the stack is empty
//        print the stack

#include <iostream>
#include <cstdlib>
#include "Stack.h"

using namespace std;

struct Node
{
   Item item;
   Node* next;
};

// creates an empty stack (called the constructor)
Stack::Stack()
{
	topPtr = nullptr;
	topPtr = new Node;
}
   
// destroys the stack (called the destructor)
// code after pop() is tested
Stack::~Stack()
{
	while(!isEmpty())
	{
		pop();
	}
}

// adds a new item as the most-recently added or top item
// pre: newItem has been assigned; stack object exists
// post: if the stack is not full, newItem is added at the top
//          and isAdded is true; else isAdded is false
void Stack::push (Item newItem, bool& isAdded)
{
	Node* newNodeptr;
	newNodeptr = new (nothrow) Node;
	if(newNodeptr != nullptr)
	{
		newNodeptr -> item = newItem;
		newNodeptr -> next = topPtr;
		topPtr = newNodeptr;
		isAdded = true;
	} else{
		isAdded = false;
	}
}
   
// removes the most-recently-added or top item
// pre: stack object exists and is not empty
// post: most-recently added or top item has been removed from the stack 
void Stack::pop()
{
	helperPtr = topPtr -> next;
	delete topPtr;
	topPtr = helperPtr;
}

// copies the most-recently added or top item from the stack
// pre: stack object exists and is not empty
// post: top item has been copied into topItem. stack is unchanged.
void Stack::retrieve(Item& topItem)
{
	topItem = topPtr -> item;
}
 
// checks whether or not a stack is empty
// pre: stack object exists
// post: if stack object is empty then returns true; else returns false
bool Stack::isEmpty() const
{
	return (topPtr == nullptr);
}

// copies a stack
// pre rhsStack has been assigned
// post Stack object has a copy of rhsStack
Stack& Stack::operator=(const Stack& rhsStack)
{
	Node* currPtr; 
	Node* rhsPtr;
	if(this != &rhsStack)
	{
		while(!isEmpty())
		{
			pop();
		}
		topPtr = nullptr;
		if(!rhsStack.isEmpty())
		{
			topPtr = new Node;
			rhsPtr = rhsStack.topPtr;
			topPtr -> item = rhsPtr -> item;
			topPtr -> next = nullptr;
			currPtr = topPtr;
			rhsPtr = rhsPtr -> next;
			while(rhsPtr != nullptr)
			{
				currPtr -> next = new Node;
				currPtr = currPtr -> next;
				currPtr -> item = rhsPtr -> item;
				currPtr -> next = nullptr;
				rhsPtr = rhsPtr -> next;
			}
		}
	}
	return *this;
}