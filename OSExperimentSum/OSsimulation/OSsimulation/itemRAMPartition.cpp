#include "itemRAMPartition.h"



itemRAMPartition::itemRAMPartition()
{
	
}

itemRAMPartition::itemRAMPartition(int start, int len, int sts)
{
	

	startAddr = start;
	lengthPart = len;
	status = sts;
}

void itemRAMPartition::showInfo()
{
	cout << startAddr << "KB" << "\t\t" << lengthPart << "KB" << "\t\t" << status << endl;
}


itemRAMPartition::~itemRAMPartition()
{
}
