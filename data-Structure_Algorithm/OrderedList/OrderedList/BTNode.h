#pragma once
#include "ElemType.h"
class BTNode
{
public:
	ElemType data;
	BTNode* lchild;
	BTNode* rchild;
public:

	BTNode();
	~BTNode();
};

