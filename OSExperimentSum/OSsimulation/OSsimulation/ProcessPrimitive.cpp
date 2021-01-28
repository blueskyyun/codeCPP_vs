#include "ProcessPrimitive.h"



ProcessPrimitive::ProcessPrimitive()
{
}

PCB* ProcessPrimitive::createProcess(PCB* p,string nm,int runT, int pri)
{

	p = new PCB(nm,runT,pri);
	return p;
}

void ProcessPrimitive::insertRunnableQueue(list<PCB>& pRunnableQ, PCB* instPCB)
{
	int count = pRunnableQ.size();
	if (pRunnableQ.empty()) {
		pRunnableQ.push_front(*instPCB);
	}
	else {
		for (list<PCB>::iterator itr = pRunnableQ.begin(); itr != pRunnableQ.end(); ++itr) {
			if (itr->getPriority() < instPCB->getPriority()) {
				pRunnableQ.insert(itr,*instPCB);
				break;
			}
		}
	}
	if (pRunnableQ.size() == count) {
		pRunnableQ.push_back(*instPCB);
	}
}

void ProcessPrimitive::removeRunnableQueue(list<PCB> &pRunnableQ, PCB* instPCB)
{
	/*for (list<PCB>::iterator itr = pRunnableQ.begin(); itr != pRunnableQ.end(); ++itr) {
		if (itr->getProcessName() == *instPCB->getProcessName) {
			pRunnableQ.remove();
		}
	}*/
	pRunnableQ.remove(*instPCB);
}

PCB* ProcessPrimitive::run(list<PCB>& pRunnableQ, PCB* pcb)
{
	
	if (!pRunnableQ.empty()) {
		pcb = &(pRunnableQ.front());
		//pRunnableQ.pop_front();
		return pcb;
	}
	return nullptr;
}



ProcessPrimitive::~ProcessPrimitive()
{
}
