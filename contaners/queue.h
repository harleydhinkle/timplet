#pragma once
#include "tlinkedlist.h"
template<typename T>
class Queue
{
private:
	tlinkedlist<T>tLinkedListNode;
public:
	bool empty()
	{
		return tLinkedListNode.empty();
	}
	T size()
	{
		
	}
};