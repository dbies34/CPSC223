//Two34Tree.cpp
//Drew Bies
//username: abies2

// struct: the Two34TreeNode consists of an array of three keys (int) and 
//				an array of four kids (ptr)
// the Two34Tree consists of Two34TreeNodes connected together

#include "Two34Tree.h"
#include "Two34TreeNode.h"
#include <iomanip>


/** other helper functions**/

// checks if the node is full
// pre treep exsist
// post returns true if the node is full
//		else returns false
bool isFull(Two34TreeNode* treep)
{
	Key eKey;
	eKey.emptyIt();
	for (int i = 0; i < 3; i++)
    {
        if (treep->keys[i] == eKey)
            return false;
    }
    return true;
}

// swaps two keys
// pre aKey and bKey exsist
// post aKey and bKey are swapped
void swap(Key& aKey, Key& bKey)
{
	Key tempKey;
	tempKey = aKey;
	aKey = bKey;
	bKey = tempKey;
}

// determines if a tree node is a leaf
// pre treep is not nullptr
// post if treep has no children return true
//			else return false
bool isLeaf(Two34TreeNode* treep)
{
	for(int i = 0; i < 3; i++)
	{
		if(treep -> kids[i] != nullptr)
			return false;
	}
	return true;
}

// determines what type a tree node is, either 1 node, 2 node or 3 node
// pre treep is not nullptr
// post an integer will be returned based on how many keys 
//			the child has.
int treeNodeType(Two34TreeNode* treep)
{
	Key eKey;
	eKey.emptyIt();
    for (int i = 2; i >= 0; i--)
    {
        if (!(treep->keys[i] == eKey))
            return i + 1;
    }
    return 0;
}

// frees the heap memory of a tree
// pre: treep is assigned but may be empty
// post: all nodes in the tree with root treep
//       have been released back to the heap and
//       treep is empty
// usage: destroyTree (mroot);
void destroyTree(Two34TreeNode*& treep)
{
	if(treep != nullptr)
	{
		for(int i = 0; i < 4; i++)
		{
			destroyTree(treep -> kids[i]);
		}
		delete treep;
		treep = nullptr;
	}
}

// creates an empty 2-3-4 Tree
// post: object is empty
Two34Tree::Two34Tree()
{
	root = nullptr;
}

// destroys a 2-3-4 Tree
// pre: object exists
// post: object does not exist, all pre-memory released
Two34Tree::~Two34Tree()
{
	destroyTree(root);
	root = nullptr;
}

// inserts a new key into the tree
// pre: tree object exists. newKey is assigned.
// post: newKey is placed in the appropriately sorted
//       position in the 2-3-4 tree object
// usage: tree.insert(mykey);
void Two34Tree::insert(const Key& newKey) throw(Exception)
{
	Key eKey;
	eKey.emptyIt();
	Two34TreeNode* targetPtr;
	Two34TreeNode* parentPtr;
	int nodeType = 0;
	
	if (root == nullptr)
	{
		root = new (nothrow) Two34TreeNode(newKey);
		if (root == nullptr)
			throw Exception("Insert: no room in the heap.");
	}else{
		targetPtr = root;
		parentPtr = targetPtr;
	
		while (targetPtr != nullptr)
		{
			if (isFull(targetPtr))
			{
				nodeType = treeNodeType(parentPtr);
				if (nodeType == 1)
				{
					if (parentPtr -> keys[0] < targetPtr -> keys[1])
					{
						parentPtr -> keys[1] = targetPtr -> keys[1];
						parentPtr -> kids[1] = new (nothrow) Two34TreeNode(targetPtr -> keys[0], targetPtr -> kids[0], targetPtr -> kids[1]);
						if (parentPtr -> kids[1] == nullptr)
							throw Exception("Insert: no room in the heap.");
						parentPtr -> kids[2] = new (nothrow) Two34TreeNode(targetPtr -> keys[2], targetPtr -> kids[2], targetPtr -> kids[3]);
						if (parentPtr -> kids[2] == nullptr)
							throw Exception("Insert: no room in the heap.");
					}else{
						parentPtr -> keys[1] = parentPtr -> keys[0];
						parentPtr -> kids[2] = parentPtr -> kids[1];
						parentPtr -> keys[0] = targetPtr -> keys[1];
						parentPtr -> kids[0] = new (nothrow) Two34TreeNode(targetPtr -> keys[0], targetPtr -> kids[0], targetPtr -> kids[1]);
						if (parentPtr -> kids[0] == nullptr)
							throw Exception("Insert: no room in the heap.");
						parentPtr -> kids[1] = new (nothrow) Two34TreeNode(targetPtr -> keys[2], targetPtr -> kids[2], targetPtr -> kids[3]);
						if (parentPtr -> kids[1] == nullptr)
							throw Exception("Insert: no room in the heap.");
					}
	
					if (newKey < parentPtr -> keys[0])
					{
						targetPtr = parentPtr -> kids[0];
					}else if (newKey < parentPtr -> keys[1]){
						targetPtr = parentPtr -> kids[1];
					}else if (parentPtr -> keys[1] < newKey){
						targetPtr = parentPtr -> kids[2];
					}
				}else if (nodeType == 2){
					if (parentPtr -> keys[1] < targetPtr -> keys[1])
					{
						parentPtr -> keys[2] = targetPtr -> keys[1];
						parentPtr -> kids[2] = new (nothrow) Two34TreeNode(targetPtr -> keys[0], targetPtr -> kids[0], targetPtr -> kids[1]);
						if (parentPtr -> kids[2] == nullptr)
							throw Exception("Insert: no room in the heap.");
						parentPtr -> kids[3] = new (nothrow) Two34TreeNode(targetPtr -> keys[2], targetPtr -> kids[2], targetPtr -> kids[3]);
						if (parentPtr -> kids[3] == nullptr)
							throw Exception("Insert: no room in the heap.");
					}else if (parentPtr -> keys[0] < targetPtr -> keys[1]){
						parentPtr -> keys[2] = parentPtr -> keys[1];
						parentPtr -> kids[3] = parentPtr -> kids[2];
						parentPtr -> keys[1] = targetPtr -> keys[1];
						parentPtr -> kids[1] = new (nothrow) Two34TreeNode(targetPtr -> keys[0], targetPtr -> kids[0], targetPtr -> kids[1]);
						if (parentPtr -> kids[1] == nullptr)
							throw Exception("Insert: no room in the heap.");
						parentPtr -> kids[2] = new (nothrow) Two34TreeNode(targetPtr -> keys[2], targetPtr -> kids[2], targetPtr -> kids[3]);
						if (parentPtr -> kids[2] == nullptr)
						{
							throw Exception("Insert: no room in the heap.");
					}else{
						parentPtr -> keys[2] = parentPtr -> keys[1];
						parentPtr -> kids[3] = parentPtr -> kids[2];
						parentPtr -> keys[1] = parentPtr -> keys[0];
						parentPtr -> kids[2] = parentPtr -> kids[1];
						parentPtr -> keys[0] = targetPtr -> keys[1];
						parentPtr -> kids[0] = new (nothrow) Two34TreeNode(targetPtr -> keys[0], targetPtr -> kids[0], targetPtr -> kids[1]);
						if (parentPtr -> kids[0] == nullptr)
							throw Exception("Insert: no room in the heap.");
						parentPtr -> kids[1] = new (nothrow) Two34TreeNode(targetPtr -> keys[2], targetPtr -> kids[2], targetPtr -> kids[3]);
						if (parentPtr -> kids[1] == nullptr)
							throw Exception("Insert: no room in the heap.");
					}
	
					if (newKey < parentPtr -> keys[0])
					{
						targetPtr = parentPtr -> kids[0];
					}else if (newKey < parentPtr -> keys[1]){
						targetPtr = parentPtr -> kids[1];
					}else if (newKey < parentPtr -> keys[2]){
						targetPtr = parentPtr -> kids[2];
					}else if (parentPtr -> keys[2] < newKey){
						targetPtr = parentPtr -> kids[3];
					}
				}else{
					root = new Two34TreeNode(targetPtr -> keys[1]);
					if (root == nullptr)
						throw Exception("Insert: no room in the heap.");
					root -> kids[0] = new (nothrow) Two34TreeNode(targetPtr -> keys[0], targetPtr -> kids[0], targetPtr -> kids[1]);
					if (root -> kids[0] == nullptr)
						throw Exception("Insert: no room in the heap.");
					root -> kids[1] = new (nothrow) Two34TreeNode(targetPtr -> keys[2], targetPtr -> kids[2], targetPtr -> kids[3]);
					if (root -> kids[1] == nullptr)
						throw Exception("Insert: no room in the heap.");	
					parentPtr = root;	
					if (newKey < root -> keys[0])
					{
						targetPtr = root -> kids[0];
					}else if (root -> keys[0] < newKey){
						targetPtr = root -> kids[1];
					}
				}
			}
	
			if (isLeaf(targetPtr))
			{
				nodeType = treeNodeType(targetPtr);
	
				if (nodeType == 1)
				{
					if (targetPtr -> keys[0] < newKey)
					{
						targetPtr -> keys[1] = newKey;
						return;
					}else if (newKey < targetPtr -> keys[0]){
						targetPtr -> keys[1] = targetPtr -> keys[0];
						targetPtr -> keys[0] = newKey;
						return;
					}
				}else if (nodeType == 2){
					if (targetPtr -> keys[1] < newKey)
					{
						targetPtr -> keys[2] = newKey;
						return;
					}else if (targetPtr -> keys[0] < newKey){
						targetPtr -> keys[2] = targetPtr -> keys[1];
						targetPtr -> keys[1] = newKey;
					}else if (newKey < targetPtr -> keys[0]){
						targetPtr -> keys[2] = targetPtr -> keys[1];
						targetPtr -> keys[1] = targetPtr -> keys[0];
						targetPtr -> keys[0] = newKey;
					}
				}
			}else {
				nodeType = treeNodeType(targetPtr);
	
				parentPtr = targetPtr;
	
				if (nodeType == 1)
				{
					if (newKey < targetPtr -> keys[0])
					{
						targetPtr = targetPtr -> kids[0];
					}else {
						targetPtr = targetPtr -> kids[1];
					}
				}else if (nodeType == 2){
					if (newKey < targetPtr -> keys[0])
					{
						targetPtr = targetPtr -> kids[0];
					}else if (newKey < targetPtr -> keys[1]){
						targetPtr = targetPtr -> kids[1];
					}else{
						targetPtr = targetPtr -> kids[2];
					}
				}
			}
			}
		}
	}
}



/** recursive helper functions **/

// shows the data in the tree in inorder
// pre: treep is assigned but may be empty
//      output is open
// post: the data items in the nodes of treep's tree
//       are printed to output in inorder
void inorder(ostream& output, Two34TreeNode* treep)
{
	Key eKey;
	eKey.emptyIt();
	if(treep != nullptr)
	{
		inorder(output, treep -> kids[0]);
		inorder(output, treep -> kids[1]);
		int i = 0;
		while(!(treep -> keys[i] == eKey))
		{
			output << treep -> keys[i] << " ";
			i++;
		}
		inorder(output, treep -> kids[2]);
		inorder(output, treep -> kids[3]);
	}
}

// shows the data in the tree in its tree structure
// pre: output is open. treep is assigned a tree.
//      level is assigned
// post: the data items of the nodes of treep at level
//       in the tree are printed to output with spacing
//       to denote the level.
// usage: pretty (output, mroot, 1);
void pretty(ostream& output, Two34TreeNode* treep, int level)
{
	Key eKey;
	eKey.emptyIt();
	if(treep != nullptr)
	{
		pretty(output, treep->kids[3], level + 1);
        pretty(output, treep->kids[2], level + 1);
		output << setw(15 * level);
		output << "( ";
		for(int i = 0; i < 3; i++)
		{
			if(!(treep -> keys[i] == eKey))
				output << treep -> keys[i] << " ";
		}
		output << ")" << endl;
		pretty(output, treep->kids[1], level + 1);
        pretty(output, treep->kids[0], level + 1);
		if (treep->kids[0] != nullptr)
			output << endl;
	}
}

// displays a tree in one of two formats
// pre: which is either 'i' or 'p'
//      output is open
// post: if which is 'i' the tree is displayed inorder
//       else the tree is displayed showing its tree
//       structure
// usage: tree.display (cout, 'p');
void Two34Tree::display(ostream& output, char which)
{
	if(which == 'i')
	{
		inorder(output, root);
	} else{
		pretty(output, root, 0);
	}
}