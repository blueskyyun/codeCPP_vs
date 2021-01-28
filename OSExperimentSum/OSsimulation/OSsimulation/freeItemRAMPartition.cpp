#include "freeItemRAMPartition.h"



freeItemRAMPartition::freeItemRAMPartition()
{
}

freeItemRAMPartition::freeItemRAMPartition(int no, int start, int len)
{
	noPart = no;
	startAddr = start;
	lengthPart = len;
}


freeItemRAMPartition::~freeItemRAMPartition()
{
}
