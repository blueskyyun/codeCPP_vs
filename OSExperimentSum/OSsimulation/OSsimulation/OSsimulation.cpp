// OSsimulation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "PCB.h"
#include "ProcessPrimitive.h"
#include "RAMPartitionTable.h"

void processDemo(int n);
void hanoi(int n, char a, char b, char c);
int allocate(char* d, int len);
void printBit(char a);
void showBitMap(char* d, int len);
bool recycle(char* d, int len, int surfaceNo, int bitNo);
int main()
{
	//-----------------------------------01---------------------------
#if 0
	int num = 5;
	PCB* pcbPtrArr[5] = {nullptr,nullptr,nullptr,nullptr ,nullptr};
	list<PCB> pQ;
	int pri[5];
	int runT[5];
	cout << "请输入5个进程的优先级数：" << endl;
	for (int i = 0; i < num; i++) {
		cin >> pri[i];
	}
	cout << "请输入5个进程的请求运行时间数：" << endl;
	for (int i = 0; i < num; i++) {
		cin >> runT[i];
	}
	ProcessPrimitive* pp = new ProcessPrimitive();
	for (int i = 0; i < num; i++) {
		pcbPtrArr[i] = pp->createProcess(pcbPtrArr[i], "P"+to_string(i), runT[i], pri[i]);
	}
	for (int i = 0; i < num; i++) {
		pp->insertRunnableQueue(pQ, pcbPtrArr[i]);
	}
	while (true) {
		cout << "----------------------------------------" << endl;
		PCB* pcb = nullptr;
		pcb = pp->run(pQ, pcb);
		cout <<"----" << pcb->getProcessName() << "正在运行" << "----"<< endl;
		pcb->setRunTimeRequest(pcb->getRunTimeRequest() - 1);
		pcb->setPriority(pcb->getPriority() - 1);
		for (list<PCB>::iterator itr = pQ.begin(); itr != pQ.end(); ++itr) {
			if (itr == pQ.begin()) continue;
			cout << itr->getProcessName() << "    优先数:" << itr->getPriority() << "   剩余运行时间:" << itr->getRunTimeRequest() << endl;
		}
		if (pcb->getRunTimeRequest() != 0) {
			pp->insertRunnableQueue(pQ, pcb);
			pQ.pop_front();
		}else {
			pQ.pop_front();
		}
		if (pQ.size() == 0) {
			break;
		}
		//break;

	}
	delete pp;
	#endif
	//----------------------------------------------02---------------------------------
#if 0
	int sizeR = 0;
	
	cout << "请输入内存大小:" ;
	cin >> sizeR;
	RAMPartitionTable* ramTable = new RAMPartitionTable(sizeR);
	while (true) {
		int choice = 0;
		cout << "选择您需要的服务: 1. 分配内存， 2.回收内存分区， 3.退出， 请输入：" ;
		cin >> choice;
		if (choice == 1) {
			int reqSize = 0;
			cout << "--------------------------------------------" << endl;
			cout << "请输入请求分配内存的大小:" << endl;
			cin >> reqSize;
			if (ramTable->RAMAllocate(reqSize)) {
				cout << "内存分配已完成" << endl;
				cout << "起始地址" << "\t" << "分区大小" << "\t" << "状态(0:空闲 | 1: 已分)" << endl;
				for (vector<itemRAMPartition>::iterator it = ramTable->ramPartTable.begin(); it != ramTable->ramPartTable.end(); it++) {
					it->showInfo();
				}
			}
			else {
				cout << "找不到足够的分区，内存分配已被拒绝" << endl;
			}
		}
		else if(choice == 2){
			int startA;
			cout << "--------------------------------------------" << endl;
			cout << "请输入需要回收内存分区的起始地址：" << endl;
			cin >> startA;
			if (ramTable->RAMRecycle(startA)) {
				cout << "内存回收已完成" << endl;
				cout << "起始地址" << "\t" << "分区大小" << "\t" << "状态(0:空闲 | 1: 已分)" << endl;
				for (vector<itemRAMPartition>::iterator it = ramTable->ramPartTable.begin(); it != ramTable->ramPartTable.end(); it++) {
					it->showInfo();
				}
			}
			else {
				cout << "找不到此起始地址的分区, 无法进行内存回收" << endl;
			}
			
		}
		else {
			break;
		}
	
		
	}
#endif
	//-------------------------------03---------------------------------------
#if 1
	const static int length = 8;
	char disk[length] = { 0b00010100, 0b11111000, 0b00001100, 0b00010010,  0b11111100,  0b01111111,  0b11111111, 0b00011111};
	while (true) {
		
		int choice = 0;
		cout << "1.请求分配磁盘空间， 2.回收磁盘空间， 3.退出\n请选择： ";
		cin >> choice;
		if (choice == 1) {
			cout << "分配前：" << endl;
			showBitMap(disk, length);
			int physicAddress = allocate(disk,length);
			if (physicAddress != -1) {
				cout << "分配的磁盘空间的物理地址是： 第" << physicAddress / 10  << "柱面，第" << physicAddress % 10 / 4 + 1 << "磁道， 第" << physicAddress % 10 % 4 << "扇区" << endl;
				cout << "分配后：" << endl;
				showBitMap(disk, length);
			
			}else{
				cout << "磁盘已满，分配失败" << endl;
			}
		}
		else if (choice == 2) {
			showBitMap(disk, length);
			int physicAd = 0;
			cout << "请输入需要回收的磁盘物理地址(0-63):  ";
			cin >> physicAd;
			cout << "回收磁盘块对应的位示图字节号：" << physicAd / 8 << ", 位数：" << physicAd % 8 << endl;
			if (recycle(disk, length, physicAd / 8, physicAd % 8)) {
				showBitMap(disk, length);
			}
			else {
				cout << "回收磁盘块失败" << endl;
			}
		}
		else {
			break;
		}
	}

#endif

}

int allocate(char* d, int len) {
	int r = 1;
	r <<= 7;
	bool isFind = false;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 8; j++) {
			if (int(d[i] & r) != 0) {
				r >>= 1;
			}
			else {
				d[i] |= r;
				isFind = true;
				return i * 10 + j;
			}
		}	
		r = 0b10000000;
	}
	if (!isFind) {
		return -1;
	}
}

void printBit(char a)
{
	int i = 0;
	for (i = 7; i >= 0; i--) {
		int b =( a & (1 << i)) == 0 ? 0 : 1;
		std::cout << b << " ";
	}
	cout << endl;
}

void showBitMap(char* d, int len)
{
	std::cout << "-----------------------------------------------------" << endl;
	std::cout << "柱面号" << "\t" << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5 << " " << 6 << " " << 7  << " " << endl;
	std::cout << "—————————————————" << endl;
	for (int i = 0; i < len; i++) {
		std::cout << i << "\t";
		printBit(d[i]);
	}
	cout << "--------------------------------------------------------" << endl;
}

bool recycle(char*d, int len,int surfaceNo, int bitNo)
{
	if (surfaceNo >= len || bitNo > 7) {
		cout << "物理地址不存在" << endl;
		return false;
	}
	else {
		int i = 1<<7;
		if ((d[surfaceNo] & (i >> bitNo)) != 0) {
			d[surfaceNo] = d[surfaceNo] ^ (i >> bitNo);
			return true;
		}
		else
		{
			cout << "此盘块是空闲盘块，无须回收" << endl;
			return false;
		}
	}
	
}





void processDemo(int n) {
	hanoi(n, 'A', 'B', 'C');
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 1) {
		cout << n << " " << a << "->" << c << endl;
	}
	else
	{
		hanoi(n - 1, a, c, b);
		cout << n << " " << a << "->" << c << endl;
		hanoi(n - 1, b, a, c);
	}
}
	




