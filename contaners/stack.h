#pragma once
#include "tvector.h"
#include "linkedlist.h"
#include <cassert>
#include <cstring>
template<typename T>
class Stack
{
private:
	tVector<T>vector;
public:
	//top is size - 1
	
	//empty
	bool empty() 
	{
		return vector.empty();
	}

	//size
	T size() 
	{
		return vector.size();
	}
	//return the thing that was popped
	//pop
	T pop() 
	{	
		assert(!empty());
		T t = vector(size());
		size -= 1;
		return t;
	}
	//push
	T push() 
	{
		
	}
	//add element to top the top of the stack
	//top
	T top()
	{

	}
	//access top of the stack

};
