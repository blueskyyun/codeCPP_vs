#include "pch.h"
#include "LinkedList.h"
#include "ElemType.h"
#include <iostream>
using namespace std;

void LinkedList::InitList(LinkNode *&L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void LinkedList::DestroyList(LinkNode *&L)
{
	LinkNode* pre = L, *p = L->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);

}

void LinkedList::CreateListR(LinkNode *&L, ElemType a[], int n)
{
	//L是引用，是否会报错;

	InitList(L);
	LinkNode *s, *r;
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	// (LinkNode)malloc(sizeof(LinkNode));
}

void LinkedList::DispList(LinkNode *&L)
{
	LinkNode *p;
	p = L->next;
	while (p != NULL) {
		cout << p->data.key <<"\t";
		p = p->next;

	}
	cout << endl;
}

void LinkedList::BubbleSortI(ElemType a[],int n)
{
	ElemType temp;
	bool exchange;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j].key > a[j + 1].key) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				exchange = true;
			}

		}

		if (!exchange)
			break;
	}
}

void LinkedList::Merge(LinkNode *&L1, LinkNode *&L2, LinkNode*& head)
{
	
	InitList(head);
	LinkNode *r, *s;
	r = L1->next;
	s = L2->next;
	while (r != NULL && s != NULL) {
		if (r->data.key <= s->data.key) {
			ListInsert(head, r->data);
			r = r->next;
		}
		else {
			ListInsert(head, s->data);
			s = s->next;
		}
	}
	while (r != NULL) {
		ListInsert(head, r->data);
		r = r->next;
	}
	while (s != NULL) {
		ListInsert(head, s->data);
		s = s->next;
	}

}

void LinkedList::ListInsert(LinkNode *&L, ElemType eT)
{
	LinkNode* last = L;
	while (last->next != NULL) {
		last = last->next;
	}
	LinkNode* nw = new LinkNode();
	nw->data = eT;
	last->next = nw;
	nw->next = NULL;
}

LinkedList::LinkedList()
{
}
LinkedList::~LinkedList()
{
}
