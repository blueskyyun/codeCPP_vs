#include "RAMPartitionTable.h"



RAMPartitionTable::RAMPartitionTable()
{
}

RAMPartitionTable::RAMPartitionTable(int sizeRAM)
{
	this->sizeRAM = sizeRAM;
	freeItemRAMPartition i = freeItemRAMPartition(1, 0, this->sizeRAM);
	freePartTable.push_back(i);
	ramPartTable.push_back(itemRAMPartition(0, this->sizeRAM, 0));
}

bool RAMPartitionTable::RAMAllocate(int size)
{
	
	if (size > sizeRAM) {
	
		return isFind;
	}
	for (vector<freeItemRAMPartition>::iterator it = freePartTable.begin(); it != freePartTable.end(); ++it) {
		if (it->lengthPart >= size) {
			isFind = true;
			if (it->lengthPart > size) {
				
				for (vector<itemRAMPartition>::iterator iter = ramPartTable.begin(); iter != ramPartTable.end(); ++iter) {
					if (it->startAddr == iter->startAddr) {
						iter->lengthPart = size;
						iter->status = 1;
						ramPartTable.insert(iter + 1, itemRAMPartition(iter->startAddr + size, it->lengthPart - size, 0));
						break;
					}
				}
				it->lengthPart -= size;
				it->startAddr += size;
				break;
			}
			else{
				
				for (vector<itemRAMPartition>::iterator iter = ramPartTable.begin(); iter != ramPartTable.end(); ++iter) {
					if (it->startAddr == iter->startAddr) {
						iter->status = 1;
						break;
					}
					
				}
				freePartTable.erase(it);
			}
			break;
		}
		
	}
	return isFind;
}

bool RAMPartitionTable::RAMRecycle(int startAd)
{
	int countFree = 0;

	for (int i = 0; i < ramPartTable.size(); i++) {
		if (ramPartTable[i].startAddr == startAd) {
			isFind = true;
			
			int start = 0;
			int len = 0;
			if (i != 0 && ramPartTable[i-1].status == 0) {
				start = ramPartTable[i-1].startAddr;
			}
			else {
				start = ramPartTable[i].startAddr;
				
			}
			if (i != ramPartTable.size()-1 && ramPartTable[i+1].status == 0) {
				len = ramPartTable[i + 1].startAddr + ramPartTable[i + 1].lengthPart - start;
				
			}
			else {
				len = ramPartTable[i].startAddr + ramPartTable[i].lengthPart - start;
				
			}
			
			
			if (start == ramPartTable[i].startAddr && len == ramPartTable[i].lengthPart) {
				countFree = 1;
				for (int j = 0; j < freePartTable.size(); j++ ) {
					if (freePartTable[j].startAddr > ramPartTable[i].startAddr) {
						vector<freeItemRAMPartition>::iterator iter = freePartTable.begin() + j;
						freePartTable.insert(iter, freeItemRAMPartition(freePartTable[j].lengthPart, start, len));
						//int index = &*iter - &freePartTable[0]+1;
						//cout << index;
						for (j += 1; j < freePartTable.size(); j++) {
							freePartTable[j].noPart += 1;
						}
						break;
					}
					else {
						freePartTable.push_back(freeItemRAMPartition(freePartTable[j].noPart + 1, start, len));
					}
				}
			}else if ((start == ramPartTable[i].startAddr && len > ramPartTable[i].lengthPart)||(start+len == ramPartTable[i].startAddr+ramPartTable[i].lengthPart)) {
				countFree = 2;
				for (vector<freeItemRAMPartition>::iterator iter = freePartTable.begin(); iter != freePartTable.end(); ++iter) {
					if (iter->startAddr >= start) {
						iter->startAddr = start;
						iter->lengthPart = len;
						break;
					}
				}
			}
			else {
				countFree = 3;
				for (int j = 0; j < freePartTable.size(); j++) {
					if (freePartTable[j].startAddr == start) {
						freePartTable[j].lengthPart = len;
						vector<freeItemRAMPartition>::iterator iter = freePartTable.begin() + j+1;
						
						freePartTable.erase(iter);
						////int index = 1;
						//iter = iter + 1;
						//for (iter; iter != freePartTable.end(); iter++) {
						//	if (index == 1) {
						//		//index++;
						//		//continue;
						//	//}
						//	//else {
						//		iter->noPart -= 1;
						//	//}
						//	
						//}
						
						for (j += 1; j < freePartTable.size(); j++) {
							freePartTable[j].noPart -= 1;
						}
						break;
					}
				}
				
			}
			if (countFree == 1) {
				ramPartTable[i].status = 0;
			}
			else if(countFree == 2){
				if (start == ramPartTable[i].startAddr) {
					ramPartTable[i + 1].startAddr = start;
					ramPartTable[i + 1].lengthPart = len;
					vector<itemRAMPartition>::iterator it = ramPartTable.begin() + i;
					ramPartTable.erase(it);
				}
				else
				{
					ramPartTable[i - 1].lengthPart = len;
					vector<itemRAMPartition>::iterator it = ramPartTable.begin() + i;
					ramPartTable.erase(it);
				}
				
			}
			else if (countFree == 3) {
				ramPartTable[i - 1].lengthPart = len;
				vector<itemRAMPartition>::iterator it = ramPartTable.begin() + i;
				ramPartTable.erase(it, it + 2);
			}
			
			break;
		}
		
	}
	return isFind;
}




RAMPartitionTable::~RAMPartitionTable()
{
}
