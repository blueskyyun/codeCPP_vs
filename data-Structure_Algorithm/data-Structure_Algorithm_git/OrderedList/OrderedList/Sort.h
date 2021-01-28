#pragma once
#include "ElemType.h"
class Sort
{
public:
	void ShellSort(ElemType[], int n);
	int partition(ElemType e[], int, int);

	Sort();
	~Sort();
};

