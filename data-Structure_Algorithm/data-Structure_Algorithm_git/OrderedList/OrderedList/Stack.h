#pragma once
#include "Box.h"
#include "ElemType.h"
#include "BTNode.h"

//template <typename T>
class Stack
{
public:
	static const int size = 256;
	/*T data[size];*/
	
	Box data[size];
	ElemType elemType[size];
	Box *box;
	ElemType *elem;
	BTNode* btNode;
	int top;
public:

	Stack();
	Stack(Box*& );
	Stack(ElemType*& );
	Stack(BTNode*&);

	~Stack();
};

