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

#ifndef STACK_H
#define STACK_H

#include "Item.h"

struct Node;

class Stack
{
public: // operations are called methods or member functions
   // creates an empty stack (called the constructor)
   Stack();
   
   // destroys the stack (called the destructor)
   ~Stack();
   
   // adds a new item as the most-recently added or top item
   // pre: newItem has been assigned; stack object exists
   // post: if the stack is not full, newItem is added at the top
   //          and isAdded is true; else isAdded is false
   void push (Item newItem, bool& isAdded);
   
   // removes the most-recently-added or top item
   // pre: stack object exists and is not empty
   // post: most-recently added or top item has been removed from the stack 
   void pop();
   
   // copies the most-recently added or top item from the stack
   // pre: stack object exists and is not empty
   // post: top item has been copied into topItem. stack is unchanged.
   void retrieve(Item& topItem);
 
   // checks whether or not a stack is empty
   // pre: stack object exists
   // post: if stack object is empty then returns true; else returns false
   bool isEmpty() const;
   
   // copies a stack
   // pre rhsStack has been assigned
   // post Stack object has a copy of rhsStack
   Stack& operator=(const Stack& rhsStack);

   
private:
   Node* topPtr;
   Node* helperPtr;
};
#endif