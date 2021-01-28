#pragma once
class freeItemRAMPartition
{
public:
	int noPart;
	int startAddr;
	int lengthPart;
public:
	freeItemRAMPartition();
	freeItemRAMPartition(int, int, int);

	~freeItemRAMPartition();
};

