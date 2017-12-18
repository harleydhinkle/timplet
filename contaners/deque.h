#pragma once
#include "tlinkedlist.h"
#include "iterator.h"
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
		return mylinckedlist.at(index);
	}
	void assign(size_t idx, const T vel)
	{
		for (int i = 0; i < size; i++) 
		{
			idx;
		}
	}
	void erese() 
	{
		return mylinckedlist.erase();
	}
	void clear() 
	{
		return mylinckedlist.clear();
	}
	bool empty() 
	{
		return mylinckedlist.empty();
	}
	size_t size() const 
	{
		return mylinckedlist.size();
	}

	Deque() 
	{
		return mylinckedlist.tLnkedlist();
	}
	~Deque()
	{
		return mylinckedlist.~tLnkedlist();
	}
	void swap(T& x) 
	{

	}
	size_t max_size() const  noexcept
	{
		return mylinckedlist.size();
	}
	void resize(size_t idx,const T& val) 
	{

	}
private:
	tlinkedlist<T> mylinckedlist;
};

