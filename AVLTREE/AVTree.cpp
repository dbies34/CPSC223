// AVLTree.cpp
// Drew Bies

// |h(TR)-h(TL)|<=1

#include "AVLTree.h"

struct SearchPath
{
   TreeNode* path[MAXHEIGHT];
   int pathSize;
   int pivotIndex; // to be explained later
   SearchPath();
};

void BSTinsertAndMakeSearchPath(TreeNode*& treep, const Item& newItem, SearchPath& search) throw (Exception)
{
	
}

void fixBalances(SearchPath search, int start)
{
	
}

SearchPath::SearchPath() // constructor for the struct
{
	for(int i = 0, i < MAXHEIGHT; i++)
	{
		path[i] = nullptr;
	}
	pathSize = 0;
	pivotIndex = -1;
}

AVLTree::AVLTree()
{
	
}

AVLTree::~AVLTree()
{
	
}

bool hasNoPivot(SearchPath& search)
{
	
}

// sets the pivotIndex if a pivot exists else leaves it as -1
// returns true if and returns false if
bool isAddedToShortSide(const SearchPath& search)
{
	
}

void AVLTree::insert(const Item& newItem) throw (Exception)
{
	SearchPath search;
	
	BSTinsertAndMakeSearchPath(root, newItem, search);
	if(hasNoPivot(search))
		fixBalances(search, 0);
	else if (isAddedToShortSide(search))
		fixBalances(search, search.pivotIndex);
	else if (isSingleLeftRotation(search))
		//doSingleLeftRotation
	else if (isSingleRightRotation(search))
		//doSingleRightRotation
	else if (isDoubleLeftRightRotation(search))
		//doDoubleLeftRightRotation
	else
		//doDoubleRightLeftRotation
}