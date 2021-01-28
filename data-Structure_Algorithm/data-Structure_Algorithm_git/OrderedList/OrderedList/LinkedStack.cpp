#include "pch.h"
#include "LinkedStack.h"


void LinkedStack::InitLinkedStack(LinkNode *&s)
{
	s = (LinkNode*)malloc(sizeof(LinkNode));
	s->next = NULL;
}

void LinkedStack::DestroyLinkedStack(LinkNode *&s)
{
	LinkNode* pre = s, *p = s->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(p);
}

bool LinkedStack::StackEmpty(LinkNode *s)
{
	return (s->next == NULL);
}

void LinkedStack::Push(LinkNode *& s, ElemType e)
{
	LinkNode *p;
	p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool LinkedStack::Pop(LinkNode *& s, ElemType& e)
{
	LinkNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool LinkedStack::GetTop(LinkNode * s, ElemType & e)
{
	if (s->next == NULL)return false;
	e = s->next->data;
	return true;
}

bool LinkedStack::match(ElemType exp[], int n)
{
	ElemType e;
	int i = 0;
	bool match = true;
	LinkNode* s;
	InitLinkedStack(s);
	while (i < n && match) {
		if (exp[i].ch == '(') {
			Push(s, exp[i]);
		}
		else if (exp[i].ch == ')') {
			if (GetTop(s, e)) {
				if (e.ch != '(') {
					match = false;
				}
				else
				{
					Pop(s, e);
				}
			}
			else match = false;
		}
		i++;
	}
	if(!StackEmpty(s)){
		match = false;
	}
	DestroyLinkedStack(s);
	return match;
}

LinkedStack::LinkedStack()
{

}


LinkedStack::~LinkedStack()
{
}
