#pragma once
using namespace std;
class HTNode
{
public:
	char data;
	double weight;
	int parent;
	int lChild;
	int rChild;
public:
	HTNode();
	HTNode(char, double);
	HTNode(double);
	~HTNode();
};

