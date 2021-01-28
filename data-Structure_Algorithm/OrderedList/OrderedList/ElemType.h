#pragma once
#include <iostream>
#include <string>
#include "Object.h" 
using namespace std;
class ElemType:public Object
{
public:
	char ch;
	
public:
	//string toString();

	ElemType();
	friend ostream& operator<<(ostream&, ElemType);
	ElemType(int);
	
	~ElemType();

};

