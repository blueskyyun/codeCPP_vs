#include "pch.h"
#include "Sort.h"


void Sort::ShellSort(ElemType e[], int n)
{
	
	int i, j, d;
	ElemType elemType;
	d = n / 2;
	while (d > 0) {
		for (i = 0; i < n; i++) {
			elemType = e[i];
			j = i - d;
			while (j >= 0 && elemType.key < e[j].key) {
				e[j + d] = e[j];
				j = j - d;
			}
			e[j + d] = elemType;
		}
		d = d / 2;
	}

}

int Sort::partition(ElemType e[], int s, int t)
{
	int i = s;
	int j = t;
	ElemType elem = e[i];
	while (i < j) {
		while (j > i &&e[j].key >= elem.key)
			j--;
		e[i] = e[j];
		while (i < j && e[i].key <= elem.key)
			i++;
		e[j] = e[i];
	}
	e[i] = elem;
	return i;
	
}

Sort::Sort()
{
}


Sort::~Sort()
{
}
