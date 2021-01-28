#include "pch.h"
#include "StackBTNode.h"


void StackBTNode::InitStack(StackBTNode *&st)
{
	st = (StackBTNode*)malloc(sizeof(StackBTNode));
	st->top = -1;
}

void StackBTNode::DestroyStack(StackBTNode *&st)
{
	free(st);
}

bool StackBTNode::StackEmpty(StackBTNode *st)
{
	if (st->top == -1)return true;
	return false;
}

bool StackBTNode::Push(StackBTNode *&st, BTNode *btNd)
{
	if (st->top == (st->size - 1))return false;
	st->top++;
	st->btNode[st->top] = btNd;
	return true;
	
}

bool StackBTNode::Pop(StackBTNode *&st, BTNode *& e)
{
	if (st->top == -1)return false;
	e = st->btNode[st->top];
	st->top--;
	return true;
}

bool StackBTNode::GetTop(StackBTNode * st, BTNode *& b)
{
	if (st->top == -1)return false;
	b = st->btNode[st->top];
	return true;
}

StackBTNode::StackBTNode()
{
}



StackBTNode::~StackBTNode()
{
}
