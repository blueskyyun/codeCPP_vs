#pragma once
#include "LinkNode.h"
#include <iostream>
using namespace std;
class LinkedList
{
public:
	
public:
	void InitList(LinkNode*&);
	void DestroyList(LinkNode*&);
	void CreateListR(LinkNode*&, ElemType[], int);
	void DispList(LinkNode *&);
	void BubbleSortI(ElemType[],int n);//∑«µ›ºı≈≈–Ú
	void Merge(LinkNode*&, LinkNode*&, LinkNode*&);
	void ListInsert(LinkNode*&,ElemType);
	LinkedList();
	~LinkedList();
};

