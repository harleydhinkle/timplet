#pragma once
#include <cassert>
#include <cstring>
template<typename t>
class tVector 
{
	t*data;
	size_t capacity;
	size_t size;
public:
	tVector() 
	{
		capacity = 2;
		data = new t[capacity];
		size = 0;
	}
	~tVector() 
	{
		delete[]data;
	}
	t& at(size_t idx) 
	{
		assert(idx >= 0);
		assert(idx < size);

		return data[idx];
	}
	t& append(t val) 
	{
		if (size == capacity) {
			bool didGrow = grow(size + 1);
			assert(didGrow);
		}
		data[size] = val;
		++size;
		return data[size - 1];
	}
	t* c_ptr() const 
	{
		return data;
	}
	size_t getCapacity() const 
	{
		return capacity;
	}
	size_t getSize() const 
	{
		return size;
	}
	bool empty() const
	{
		return size == 0;
	}
	t front() const 
	{
		return data[0];
	}
	t back() const 
	{
		return data[size - 1];
	}
	void erases(size_t idx) 
	{
		for (int i = idx; i < size; i++)
		{
			t temp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp;
		}
		size--;
	}

};
