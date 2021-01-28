#include "pch.h"
#include "BTree.h"
#include "StackBTNode.h"






void BTree::PreOrderByRecur(BTNode * b)
{
	if (b != NULL) {
		printf("%c ", b->data.ch);
		PreOrderByRecur(b->lchild);
		PreOrderByRecur(b->rchild);
	}
	
}

void BTree::PreOrderByNonRecur(BTNode * b)
{
	BTNode *p;
	StackBTNode* st = new StackBTNode();
	
	
	if (b != NULL) {
		st->Push(st, b);
		while (!st->StackEmpty(st)) {
			st->Pop(st, p);
			printf("%c ", p->data.ch);
			if (p->rchild != NULL) {
				st->Push(st, p->rchild);
			}
			if (p->lchild != NULL) {
				st->Push(st, p->lchild);
			}
		}
		printf("\n");
	}
	st->DestroyStack(st);
}

void BTree::createBTree(BTNode *& b, char * str)
{
	BTNode* St[1000], *p = (BTNode*)malloc(sizeof(BTNode));
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		case ' ':
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data.ch = ch;
			p->lchild = NULL;
			p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k)
				{
				case 1:
					St[top]->lchild = p; break;
				case 2:
					St[top]->rchild = p; break;
				}
			}

		}
		j++;
		ch = str[j];
		
	}
}

void BTree::DestroyBTree(BTNode *& b)
{
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

BTree::BTree()
{
}


BTree::~BTree()
{
}
