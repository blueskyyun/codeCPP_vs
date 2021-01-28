#pragma once
#include "LinkNode.h"
class LinkedStack
{
	
public:
	void InitLinkedStack(LinkNode *& );
	void DestroyLinkedStack(LinkNode *&);
	bool StackEmpty(LinkNode *);
	void Push(LinkNode *&s, ElemType e);
	bool Pop(LinkNode*& s, ElemType &e);
	bool GetTop(LinkNode *s, ElemType &e);
	bool match(ElemType exp[], int n);
	
	LinkedStack();
	~LinkedStack();
};

