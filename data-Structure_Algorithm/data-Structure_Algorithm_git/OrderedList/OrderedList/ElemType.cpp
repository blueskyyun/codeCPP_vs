#include "pch.h"
#include "ElemType.h"
#include <string>
using namespace std;
ElemType::ElemType()
{
}


ElemType::ElemType(int a)
{
	this->key = a;
}

ElemType::~ElemType()
{
}
ostream& operator<<(ostream &out, ElemType& e)
{
	out << e.key;
	return out;

}

