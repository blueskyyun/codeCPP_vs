#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <time.h>
#define R "Runnable";
#define I "Running";
#define B "Block"
#define E "End"
using namespace std;
const int len = 10;
char buffer[10];
int in,out, fullSemaphore,emptySemaphore, mutex, pc;
int PA[5], SA[5];
struct PCB{
	string name;
	string state;
	string reason;
	int nextQuard;
};
typedef struct {
	char* buf;
	int len;


}ThreadParameter;
int P(int s, PCB* pcb);
int V(int s, PCB* pcb);
char produce();
void put(char* buf, int &in, int len, char ch);
char get(char* buf, int &out, int len);
void consume(char ch);
void showBuf(char* buf, int len, int in, int out);
void init();
void gotoL();
void nop();
void displayCurPrcss(PCB* pcb);
void schedule(PCB* pP, PCB* pC, PCB* pcbCurrent);
//DWORD WINAPI Producer(LPVOID);           
//DWORD WINAPI Consumer(LPVOID);
int main()
{
	init();
	PCB* pcbP = new PCB();
	pcbP->name = "producer";
	pcbP->state = R;
	pcbP->nextQuard = 0;
	pcbP->reason = "";
	PCB* pcbC = new PCB();
	pcbC->name = "consumer";
	pcbC->state = R;
	pcbC->nextQuard = 0;
	PCB* pcbCurrent = nullptr;
	schedule(pcbP, pcbC, pcbCurrent);
	delete pcbP;
	delete pcbC;
}
int P(int s, PCB* pcb) {
	s--;
	if (s < 0) {
		pcb->state = B;
		pcb->reason = "s";
	}
	return s;
}
int V(int s, PCB* pcb) {
	s++;
	if (s <= 0) {
		pcb->state = R;
	}
	return s;
}
char produce() {
	srand((int)time(0));
	int i = rand() % 26+65;
	char ch = i;
	cout << "生产" << ch << endl;
	return ch;
}
void put(char* buf, int &in, int len, char ch) {
	buf[in] = ch;
	in = (in + 1) % len;
}

char get(char* buf, int& out, int len)
{
	char ch = buf[out];
	buf[out] = ' ';
	out = (out + 1) % len;
	return ch;
}

void consume(char ch) {
	cout << "消耗" << ch << endl;
}

void showBuf(char* buf, int len, int in, int out)
{
	for (int i = 0; i < len; i++) {
		if (buf[i] >= 65 && buf[i] <= 90) {
			cout << i << ": " << buf[i];
		}
		else {
			cout << i << ": " << "null";
		}
		
		if (i == in) {
			cout << "   <- 生产";
		}
		if (i == out) {
			cout << "   <- 消费";
		}
		cout << endl;
	}
}
void init() {
	in = 0; 
	out = 0; 
	fullSemaphore = 0;
	emptySemaphore = 10;
	for (int i = 0; i < 4; i++) {
		PA[i] = i;
		SA[i] = i;
	}
}

void gotoL()
{
	pc = 0;
}

void nop()
{
	;
}

void displayCurPrcss(PCB* pcb)
{
	cout << "name\t\tstate\treason\tnextQuard" << endl;
	cout << pcb->name << "\t" << pcb->state << "\t" << pcb->reason << "\t" << pcb->nextQuard << endl;
}

void schedule(PCB* pP, PCB* pC, PCB* pcbCurrent) {
	int k = 0;
	char choice = ' ';
	
	int index1, index2;
	while (pP->state != E && pC->state != E) {
		k++;
		if (k%8 == 1 && k != 1) {
			cout << "是否退出(y/n):" << endl;
			cin >> choice;
			if (choice == 'y')
			break;
		}
		
		
		srand((int)time(0));
		int random = rand()%2;
		if (random == 0) {
			pcbCurrent = pP;
		}
		else {
			pcbCurrent = pC;
		}
		displayCurPrcss(pcbCurrent);
		pc = pcbCurrent->nextQuard;
		if (pcbCurrent->name == "producer" && pcbCurrent->state !="Block") {
			index1 = PA[pc];
			pc++;
			switch (index1) {
			case 0:
				emptySemaphore = P(emptySemaphore, pP);
				pcbCurrent->nextQuard = pc;
				break;
			case 1:
				 pcbCurrent->state = I;
				 put(buffer, in, len, produce());
				 showBuf(buffer, len, in, out);
				 pcbCurrent->nextQuard = pc;
				 pcbCurrent->state = R;
				break;
			case 2:
				fullSemaphore = V(fullSemaphore, pC);
				pcbCurrent->state = R;
				pcbCurrent->nextQuard = pc;
				break;
			case 3:
				gotoL();
				
				pcbCurrent->nextQuard = pc;
				break;
			}
		}
		else if (pcbCurrent->name == "consumer" && pcbCurrent->state !="Block") {
			index1 = SA[pc];
			pc++;
			switch (index1)
			{
			case 0:
				fullSemaphore = P(fullSemaphore, pC);
				pcbCurrent->nextQuard = pc;
				break;
			case 1:
				pcbCurrent->state = I;
				consume(get(buffer,out, len));
				showBuf(buffer, len, in, out);
				pcbCurrent->nextQuard = pc;
				break;
			case 2:
				emptySemaphore = V(emptySemaphore, pP);
				pcbCurrent->nextQuard = pc;
				pcbCurrent->state = R;
				break;
			case 3:
				gotoL();
				
				pcbCurrent->nextQuard = pc;
				break;
			}

		}

	}
}

