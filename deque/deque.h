#pragma once
#include <cassert>
#include <cstring>
#include "t"
template<typename T>
class  deque
{
public:
	struct dequenode
	{
		T *value;
		T size;
		dequenode* next;
		dequenode* pred;
		T data
	};
	tdeque():head(nullptr)
	{

	}
	~tdeque() 
	{
		dequenode* iter = head;
		while (iter != nullptr)
		{
			dequenode * next = iter->next;
			delete iter;
			iter = iter->next;
		}
	}
	

private:

};





template <typename T>
class Deque
{
private:
	//TlinkedList myList



	//




};
