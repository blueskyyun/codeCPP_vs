#pragma once
#include <iostream>
using namespace std;
class itemRAMPartition
{
public:
	
	int startAddr;
	int lengthPart;
	int status;
public:
	itemRAMPartition();
	itemRAMPartition(int, int, int);
	void showInfo();
	~itemRAMPartition();
};

