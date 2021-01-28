#pragma once
#include "BoxRecursion.h"
class mgPathResursion
{
public:
	const static int MaxSize = 1000;
	BoxRecursion path[MaxSize];
	int length = 0;
	int row;
	int col;
	int **mg;
	//记录路径条数
	int count = 0;
public:
	void mgPath(int xi, int yi, int xe, int ye);
	mgPathResursion();
	mgPathResursion(int** mg,int row, int col);
	~mgPathResursion();
};

