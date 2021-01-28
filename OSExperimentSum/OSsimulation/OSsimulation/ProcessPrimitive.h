#pragma once
#include "PCB.h"
#include <list>
using std::list;

class ProcessPrimitive
{
	
public:
	ProcessPrimitive();
	PCB* createProcess(PCB* p,string nm, int runT, int pri);
	void insertRunnableQueue(list<PCB> &pRunnableQ, PCB *instPCB);
	void removeRunnableQueue(list<PCB> &pRunnableQ, PCB *instPCB);
	PCB* run(list<PCB>& pRunnableQ, PCB* pcb);
	~ProcessPrimitive();
};

