#include "pch.h"
#include "Stack.h"

//template <typename T>
//Stack<T>::Stack()
//{
//}

Stack::Stack()
{
}

Stack::Stack(Box *&box)
{

	box = this->box;
	this->box = new Box[size];
	top = -1;
}

Stack::Stack(ElemType *&elem)
{
	elem = this->elem;
	this->elem = new ElemType[size];
	top = -1;
}

Stack::Stack(BTNode *&btNode)
{
	btNode = this->btNode;
	this->btNode = new BTNode[size];
	top = -1;
}

Stack::~Stack()
{
}


//template <typename T>
//Stack<T>::~Stack()
//{
//}
