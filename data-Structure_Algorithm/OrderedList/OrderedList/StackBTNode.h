#pragma once
#include "BTNode.h"
class StackBTNode
{
public:
	const static int size = 100;
	BTNode* btNode[size];
	int top = -1;
public:
	void InitStack(StackBTNode*&);
	void DestroyStack(StackBTNode*&);
	bool StackEmpty(StackBTNode*);
	bool Push(StackBTNode*&, BTNode*);
	bool Pop(StackBTNode*&, BTNode* &e);
	bool GetTop(StackBTNode* s, BTNode* &b);
	StackBTNode();
	~StackBTNode();
};

