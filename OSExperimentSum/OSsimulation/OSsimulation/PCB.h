#pragma once
#include <iostream>
#include <string>
using std::string;


class PCB
{
private:
	string processName;
	//PCB* nextPCB;
	int runTimeRequest;
	int priority;
	char state;
public:
	PCB();
	PCB(string pName);
	PCB(string pName, int runTimeRequest, int priority);
	string getProcessName();
	//void setNextPCB(PCB* nPCB);
	//PCB* getNextPCB();
	void setRunTimeRequest(int runT);
	int getRunTimeRequest();
	void setPriority(int pri);
	int getPriority();
	void setState(char s);
	char getState();

	bool operator==(const PCB& pcb);


	
	~PCB();
};

