// SortData.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "QSort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
void ShellSort(int *arr, int n);
void StraightInsertSort(int* arr, int n);
//int partition(int *arr, int s, int n);
//
//int partition(int * arr, int s, int e)
//{
//	int tmp = arr[s];
//	int j=s, k=e;
//	int index; //正在处理的下标
//	while (j < k) {
//		while (j < k &&arr[k] > tmp) {
//			k--;
//		}
//		arr[j] = arr[k];
//		while (j<k && arr[j] <= tmp) {
//			j++;
//		}
//		arr[k] = arr[j];
//	}
//	arr[j] = tmp;
//	return j;
//}
//void QuickSort(int *arr, int s, int t);
//void QuickSort(int *arr, int s, int t) {
//	int i;
//	if (s < t) {
//		i = partition(arr, s, t);
//		QuickSort(arr, s, i-1);
//		QuickSort(arr, i+1, t);
//	}
//
//}
void StraightInsertSort(int* arr, int n) {
	int index;
	int tmp;
	for (index = 1; index < n; index++) {
		tmp = arr[index];
		int j = index-1;//移动寻找
		while (j >= 0 && arr[j] > tmp) {
			arr[j + 1] = arr[j];
			j--;
		}
		j++;
		arr[j] = tmp;
		if (index % 1000 == 0) {
			cout << tmp << "\t";
		}
		if (index % 10000 == 0) {
			cout << endl;
		}
	}
}

void ShellSort(int* arr, int n)
{
	int i;
	int j;
	int d;//组数
	int tmp;
	d = n / 2;
	int index;
	while (d > 0)
	{
		
		for (i = 0; i < d; i++)
		{
			index = i + d;
			

			while (index < n) {

				tmp = arr[index];
				j = index-d;
				while (j >= 0 && tmp < arr[j]) {
					arr[j + d] = arr[j];
					j -= d;
				}
				j += d;
				arr[j] = tmp;

				index += d;
			}
			tmp = arr[i];
			j = i+d;
			
		}
		d = d / 2;
	}
}

int main()
	{
	const int c = 10000, m = 100000, b = 100, a = 100;
	clock_t s1, e1, s2, e2, s3, e3;
	srand((int)time(0));
	int *arr = new int[b];
	for (int i = 0; i < b; i++) {
		arr[i] = rand() % 100;
		
	}
		//s1 = clock();
		//StraightInsertSort(arr, b);
		//e1 = clock();
		//s2 = clock();
		//ShellSort(arr, b);
		//e2 = clock();
		
		//clock_t s3, e3;
		
		QSort *qSort = new QSort();
		//s3 = clock();
		qSort->QuickSort(arr, 0, b-1);
		//e3 = clock();
		//cout << "QuickSort:" << (double)(e3 - s3) / CLOCKS_PER_SEC << endl;
		
		/*cout << endl;
		cout << "StraightInsertSort:" << (double)(e1 - s1) / CLOCKS_PER_SEC << endl;
		cout << endl;*/
		
		
		//cout << "ShellSort:" << (double)(e2 - s2) / CLOCKS_PER_SEC << endl;
		//cout << "StraightInsertSort:" << endl;
		cout << "QuickSort:" << endl;
		//cout << "ShellSort:" << endl;
		for (int i = 0; i < b; i++)
		{
			cout << arr[i] << "\t"; 
			if (i % 10 == 9)cout << endl;
		}
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


	
