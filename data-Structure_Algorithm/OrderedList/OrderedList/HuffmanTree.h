#pragma once
#include "HTNode.h"
#include "HCode.h"
class HuffmanTree
{
public:
	static void CreateHT(HTNode[], int);
	static void CreateHCode(HTNode[], HCode[], int);
	static void DispHCode(HTNode[], HCode[], int);
	

	HuffmanTree();
	~HuffmanTree();
};

