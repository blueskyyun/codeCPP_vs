#include "pch.h"
#include "SqStack.h"
#include "Box.h"
#include "Stack.h"
#include "LinkNode.h"
#include "ElemType.h"

//template <typename T>
//void SqStack<T>::InitStack(Stack<T> *&s)
//{
//	s = (Stack<T>*)malloc(sizeof(Stack<T>));
//	s->top = -1;
//}
//template <typename T>
//void SqStack<T>::DestroyStack(Stack<T> *&s)
//{
//	free(s);
//}
//template <typename T>
//bool SqStack<T>::StackEmpty(Stack<T> *s)
//{
//	return (s->top == -1);
//}
//
//template<typename T>
//bool SqStack<T>::Push(Stack<T>*& s, T e)
//{
//	if (s->top == (s->size - 1))return false;
//	s->top++;
//	s->data[s->top] = e;
//	return true;
//}
//
//template <typename T>
//bool SqStack<T>::Pop(Stack<T> *&s, T & e)
//{
//	if (s->top == -1)return false;
//	e = s->data[s->top];
//	s->top--;
//	return true;
//}
//template <typename T>
//bool SqStack<T>::GetTop(Stack<T> * s, T &b)
//{
//	if (s->top == -1)return false;
//	b = s->data[s->top];
//	return true;
//}


void SqStack::InitStack(Stack *&s)
{
	s = (Stack*)malloc(sizeof(Stack));
	s->top = -1;
}



void SqStack::DestroyStack(Stack *&s)
{
	free(s);
}

bool SqStack::StackEmpty(Stack *s)
{
	return (s->top==-1);
}

bool SqStack::Push(Stack *&s, Box e)
{
	if(s->top == (s->size-1))return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool SqStack::Pop(Stack *&s, Box & e)
{
	if (s->top == -1)return false;
	e = s->data[s->top];
	s->top--;
	return true;
	
}

//bool SqStack::Push(Stack *&st, BTNode *btNode)
//{
//	if (st->top == (st->size - 1))return false;
//	st->top++;
//	st->data[st->top] = btNode;
//	return true;
//	return false;
//}

bool SqStack::GetTop(Stack * s, Box & b)
{
	if (s->top == -1)return false;
	b = s->data[s->top];
	return true;
}

bool SqStack::mgPath(int **mg, int row, int col, int xi, int yi, int xe, int ye)
{
	
	Box path[1000], e;
	int pathIndex = 0;
	bool find;
	int x = xi, y = yi, d;
	int x0, y0;
	e.i = xi;
	e.j = yi;
	e.di = -1;
	Stack* st;
	InitStack(st);
	Push(st, e);
	*((int*)mg + xi * col + yi) = -1;
	while (!StackEmpty(st)) {
		GetTop(st, e);
		x0 = e.i;
		y0= e.j;
		d = e.di;
		if (x == xe && y == ye) {
			cout << "一条迷宫的路径如下" << endl;
			while (!StackEmpty(st)) {
				Pop(st, e);
				path[pathIndex] = e;
				pathIndex++;
			}
			while (pathIndex >= 1) {
				pathIndex--;
				printf("\t(%d,%d)",path[pathIndex].i, path[pathIndex].j);
				if ((pathIndex + 4) % 5 == 0)printf("\n");
			}
			printf("\n");
			DestroyStack(st);
			return true;
		}
		find = false;
		while (d < 4 && !find) {
			d++; //d=-1
			switch (d)
			{
			case 0: x = x0 - 1; y = y0; break;
			case 1: x = x0; y = y + 1; break;
			case 2: x = x0 + 1; y = y0; break;
			case 3: x = x0; y = y0 - 1; break;
			}
			if (*((int*)mg + x * col + y) == 0)find = true;
		}
		if (find) {
			st->data[st->top].di = d;
			e.i = x; e.j = y; e.di = -1;
			Push(st, e);
			*((int*)mg + x * col + y) = -1;
		}
		else {
			Pop(st, e);
			*((int*)mg + e.i * col + e.j) = 0;
		}
	}
	DestroyStack(st);
	return false;
}
SqStack::SqStack()
{
}
SqStack::~SqStack()
{
}
//template <typename T>
//SqStack<T>::SqStack()
//{
//}
//
//template <typename T>
//SqStack<T>::~SqStack()
//{
//}
