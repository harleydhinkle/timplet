#pragma once
#include "tlinkedlist.h"
template <typename T>
class Deque
{
public:
	//add to the front of linkedlish
	//remove from the front of linkedlist
	//add to the back of linkedlist
	//remove from the back of linked list
	int size= 0;
	T front() const
	{
		return mylinckedlist.front();
	}
	T back() const 
	{
		return mylinckedlist.back();
	}

	void addfront(T vel) {
		mylinckedlist.insert(0, vel);
		size +=1;
	}
	void addback(T vel) {
		mylinckedlist.insert(size, vel);
		size +=1
	}
	void removefront(T vel)
	{
		mylinckedlist.erase(0);
		size -= 1
	}
	void removeback(T vel) 
	{
		mylinckedlist.erase(size);
		size -= 1;
	}
	int at(T index) 
	{

	}
		


private:
	tlinkedlist<T> mylinckedlist;
};

