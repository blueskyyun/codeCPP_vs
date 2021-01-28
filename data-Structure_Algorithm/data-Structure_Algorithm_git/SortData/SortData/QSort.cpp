#include "pch.h"
#include "QSort.h"
#include <ctime>
#include <iostream>

using namespace std;

QSort::QSort()
{
	
}
int QSort::partition(int * arr, int s, int e)
{
	int tmp = arr[s];
	int j = s, k = e;
	//int index; //正在处理的下标
	while (j < k) {
		while (j < k &&arr[k] > tmp) {
			--k;
		}
		arr[j] = arr[k];
		while (j < k && arr[j] <= tmp) {
			++j;
		}
		arr[k] = arr[j];
	}
	//cout << tmp << "\t" << j << "\t";
	arr[j] = tmp;
	return j;

}

void QSort::QuickSort(int * arr, int s, int t)
{
	
		int i;
		if (s < t) {
			i = partition(arr, s, t);
			QuickSort(arr, s, i-1);
			QuickSort(arr, i+1, t);
		}

	
}

QSort::~QSort()
{
}
