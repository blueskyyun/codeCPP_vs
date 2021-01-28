#include "pch.h"
#include "mgPathResursion.h"
#include <iostream>

using namespace std;

void mgPathResursion::mgPath(int xi, int yi, int xe, int ye)
{
	int di, k, i, j;
	if (xi == xe && yi == ye) {
		path[length].i = xi;
		path[length].j = yi;
		length++;
		
		printf("ÃÔ¹¬Â·¾¶%dÈçÏÂ\n", ++count);
		for (k = 0; k < length; k++) {
			printf("\t(%d, %d)", path[k].i, path[k].j);
			if (k % 5 == 4)printf("\n");
		}
		printf("\n");
	}
	else {
		if (*((int*)mg + xi * col + yi)==0) {
			{
				di = 0;
				while (di < 4) {
					path[length].i = xi;
					path[length].j = yi;
					length++;
					switch (di) {
					case 0:	i = xi - 1; j = yi; break;
					case 1:	i = xi; j = yi + 1; break;
					case 2:	i = xi + 1; j = yi; break;
					case 3:	i = xi; j = yi -1; break;
					}
					*((int*)mg + xi * col + yi) = -1;
					mgPath(i, j, xe, ye);
					*((int*)mg + xi * col + yi) = 0;
					length--;
					di++;	
				}
			}
		}
	}
}

mgPathResursion::mgPathResursion()
{
}

mgPathResursion::mgPathResursion(int ** mg, int row, int col)
{
	this->col = col;
	this->row = row;
	this->mg = mg;
}


mgPathResursion::~mgPathResursion()
{
}
