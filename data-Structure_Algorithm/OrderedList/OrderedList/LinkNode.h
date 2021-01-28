#pragma once
#include "ElemType.h"
class LinkNode
{
public:
	ElemType data;
	LinkNode* next;

public:
	LinkNode();
	~LinkNode();
};

