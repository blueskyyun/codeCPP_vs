#pragma once
#include <vector>
#include "itemRAMPartition.h"
#include "freeItemRAMPartition.h"
using namespace std;
class RAMPartitionTable
{
public:
	vector<freeItemRAMPartition> freePartTable;
	vector<itemRAMPartition> ramPartTable;
	int sizeRAM = 0;
	bool isFind = false;
public:
	RAMPartitionTable();
	RAMPartitionTable(int sizeRAM);
	bool RAMAllocate(int size);
	bool RAMRecycle(int startAd);
	~RAMPartitionTable();
};

