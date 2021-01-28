#include "PCB.h"



PCB::PCB()
{
}

PCB::PCB(string pName)
{
	processName = pName;
}

PCB::PCB(string pName, int runTimeRequest, int priority)
{
	this->processName = pName;
	this->runTimeRequest = runTimeRequest;
	this->priority = priority;
	state = 'R';
}

string PCB::getProcessName()
{
	return processName;
}

//void PCB::setNextPCB(PCB* nPCB)
//{
//	nextPCB = nPCB;
//}
//
//PCB* PCB::getNextPCB()
//{
//	return nextPCB;
//}

void PCB::setRunTimeRequest(int runT)
{
	runTimeRequest = runT;
}

int PCB::getRunTimeRequest()
{
	return runTimeRequest;
}

void PCB::setPriority(int pri)
{
	priority = pri;
}

int PCB::getPriority()
{
	return priority;
}

void PCB::setState(char s)
{
	state = s;
}

char PCB::getState()
{
	return state;
}

bool PCB::operator==(const PCB& pcb) {
	if (processName != pcb.processName)
	{
		return false;
	}
	return true;
}


PCB::~PCB()
{
}
