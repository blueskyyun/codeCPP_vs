#pragma once
#include "Stack.h"
//template <typename T>
class SqStack
{
public:
	/*void InitStack(Stack<T>*&);
	void DestroyStack(Stack<T>*&);
	bool StackEmpty(Stack<T>*);
	bool Push(Stack<T>*&, T);
	bool Pop(Stack<T>*&, T& e);
	bool GetTop(Stack<T>* s, T &b);*/
	
	void InitStack(Stack*&);
	void DestroyStack(Stack*&);
	bool StackEmpty(Stack*);
	bool Push(Stack*&, Box);
	bool Pop(Stack*&, Box& e);
	/*bool Push(Stack*&, BTNode*);
	bool Pop(Stack*&, BTNode*&);*/
	bool GetTop(Stack* s, Box &b);
	//bool Match(char[], int n);
	bool mgPath(int **mg,int row, int col, int xi, int yi, int xe, int ye);
	SqStack();
	~SqStack();
};

