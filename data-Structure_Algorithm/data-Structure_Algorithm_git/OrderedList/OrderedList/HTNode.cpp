#include "pch.h"
#include "HTNode.h"
#include <iostream>
using namespace std;


HTNode::HTNode()
{
}


HTNode::HTNode(char c, double d)
{
	data = c;
	weight = d;
}

HTNode::HTNode(double d)
{
	HTNode(NULL, d);
}

HTNode::~HTNode()
{
}
