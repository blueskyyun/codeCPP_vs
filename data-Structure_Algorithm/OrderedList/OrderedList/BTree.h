#pragma once
#include "BTNode.h"
class BTree
{
	
public:





	void PreOrderByRecur(BTNode *b);
	void PreOrderByNonRecur(BTNode *b);
	void createBTree(BTNode*& b, char * str);
	void DestroyBTree(BTNode *&b);
	
	

	BTree();
	~BTree();
};

