// OrderedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "ElemType.h"
#include "LinkNode.h"
//
#include "HCode.h"
#include "HTNode.h"
#include "HuffmanTree.h"
#include "LinkedStack.h"
#include "Sort.h"
#include <ctime>
//
#include "LinkedStack.h"
//
#include "SqStack.h"
//
#include "BoxRecursion.h"
#include "mgPathResursion.h"
//
#include "BTNode.h"
#include "BTree.h"
using namespace std;

int main()
{	
	/*ElemType elemType1[10];
	ElemType elemType2[8];
	for (int i = 0; i < 8; i++) {
		elemType2[i] = ElemType(rand()%100);
		cout << elemType2[i].key << "\t";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		
		elemType1[i] = ElemType(rand()%101);
		cout << elemType1[i].key << "\t";
	}
	cout << endl;
	LinkedList* linkedList = new LinkedList();
	linkedList->BubbleSortI(elemType1, 10);
	linkedList->BubbleSortI(elemType2, 8);
	LinkNode *L1, *L2, *mergeH;
	linkedList->CreateListR(L1, elemType1, 10);
	linkedList->CreateListR(L2, elemType2, 8);	
	linkedList->Merge(L1, L2, mergeH);
	linkedList->DispList(mergeH);
	linkedList->DestroyList(L1);
	linkedList->DestroyList(L2);
	linkedList->DestroyList(mergeH);*/
	//const int n = 10;
	//HTNode htNode[2*n-1];
	//
	//for (int i = 0; i < n; i++) {
	//	htNode[i].data = rand() % 26 + 'A';
	//	htNode[i].weight = (rand() % 100) / 10.0;
	//}
	//for (int i = 0; i < n; i++) {
	//	cout << htNode[i].data << " " << htNode[i].weight << ";\t";
	//}
	//cout << endl;
	//HuffmanTree::CreateHT(htNode,n);
	///*cout << "i" << " data" << " " << "weight" << ":" << " parent" << " lChild" << " " << " rChild" << endl;
	//for (int i = 0; i < 19; i++) {
	//	cout << i <<  " " << htNode[i].data << "\t" << htNode[i].weight << ":\t" << htNode[i].parent << "\t" << htNode[i].lChild << "\t" << htNode[i].rChild << endl;
	//}*/
	///*cout << htNode[0].parent << endl;
	//cout << htNode[1].parent << endl;
	//cout << htNode[2].parent << endl;
	//cout << htNode[3].parent << endl;*/
	//HCode hCode[n];
	//HuffmanTree::CreateHCode(htNode, hCode, n);
	//HuffmanTree::DispHCode(htNode, hCode, n);
	////////////////////////////////////////////
	/*const int n = 100;
	ElemType elemType[n];
	clock_t start, finish;
	double total;

	for (int i = 0; i < n; i++) {

		elemType[i] = ElemType(rand() % 100);
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << elemType[i].key << "\t";
	}
	cout << endl;
	Sort* sort = new Sort();
	start = clock();
	sort->ShellSort(elemType, n);
	finish = clock();
	total = finish - start;
	cout << "所耗时间：" << total << endl;
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << elemType[i].key << "\t";
	}*/
	//cout << endl;
	///////////////////////////////////////////
	SqStack sqStack = SqStack();

	int mg[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	if (!sqStack.mgPath((int**)mg, 10, 10, 1, 1, 8, 8)) {
		printf("该迷宫问题没有解！");
	}
	//delete sqStack;
	//////////////////////////////////////////////////////////////////
	/*int mg[6][6] = {
		{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}
	};
	mgPathResursion* mgPath = new mgPathResursion((int**)mg, 6, 6);
	cout << "递归方法求解迷宫问题：" << endl;
	mgPath->mgPath(1, 1, 4, 4);
	
	delete mgPath;*/
	////////////////////////////////
	/*char expression[] = "A(B(D(H), E(, I)), C(F(J, K), G(L(M, N))))";
	BTree* btree = new BTree();
	BTNode* btNode = new BTNode();
	btree->createBTree(btNode, expression);
	cout << "PreOrderByRecur: ";
	btree->PreOrderByRecur(btNode);
	printf("\n");
	cout << "PreOrderByNonRecur: ";
	btree->PreOrderByNonRecur(btNode);
	delete btree;
	delete btNode;*/
/////////////////////////////////////////////
//LinkedStack* l = new LinkedStack();
//ElemType* elemArr = new ElemType[6];
//elemArr[0].ch = '(';
//elemArr[1].ch = '(';
//elemArr[2].ch = ')';
//elemArr[3].ch = '(';
//elemArr[4].ch = ')';
//elemArr[5].ch = ')';
//cout << "elem数组的字符成员变量括号是否匹配？" << l->match(elemArr, 6) << endl; 

	return 1;
}





// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
