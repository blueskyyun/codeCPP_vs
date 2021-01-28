#include "pch.h"
#include "HuffmanTree.h"


void HuffmanTree::CreateHT(HTNode ht[], int n)
{
	int i, k, lNode, rNode;
	double min1, min2;
	for (i = 0; i < 2*n-1; i++) {
		ht[i].parent = -1;
		ht[i].lChild = -1;
		ht[i].rChild = -1;
	}
	for (i = n; i <= 2 * n - 2; i++) {
		min1 = 32767;
		min2 = 32767;
		lNode = -1;
		rNode = -1;
		for (k = 0; k <= i - 1; k++) {
			if (ht[k].parent == -1) {
				if (ht[k].weight < min1) {
					min2 = min1;
					rNode = lNode;
					min1 = ht[k].weight;
					lNode = k;
				}
				else if (ht[k].weight < min2) {
					min2 = ht[k].weight;
					rNode = k;
				}
			}
		}
		ht[i].weight = ht[lNode].weight + ht[rNode].weight;
		ht[lNode].parent = i;
		ht[rNode].parent = i;
		ht[i].lChild = lNode;
		ht[i].rChild = rNode;

	}
}

void HuffmanTree::CreateHCode(HTNode ht[], HCode hcd[] , int n)
{
	int i, f=0, c=0;	//c:当前结点的下标 f: 当前结点的父母的下标
	
	//hc.cdv = new char[n];
	for (i = 0; i < n; i++) {

		HCode hc;
		//hc.start = n-1; 
		c = i;
		f = ht[i].parent;

		while (f != -1) {
			if (ht[f].lChild == c) {
				//hc.cdv[hc.start--] = '0';
				hc.cdv.push_back('0');
			}
			else {
				//hc.cdv[hc.start--] = '1';
				hc.cdv.push_back('1');
			}
			
			c = f;
			f = ht[f].parent;
		}
		//hc.start++;
		char ch;
		hcd[i] = hc;
	}
}

void HuffmanTree::DispHCode(HTNode ht[], HCode hc[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << i << " " << ht[i].data << " " << ht[i].weight << ":   ";
		for (int j = hc[i].cdv.size()-1; j >= 0; j--) {
			cout << hc[i].cdv[j];
		}
		

		cout << endl;
	}
}



HuffmanTree::HuffmanTree()
{
}


HuffmanTree::~HuffmanTree()
{
}
