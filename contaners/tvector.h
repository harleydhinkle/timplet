#pragma once
#include <cassert>
#include <cstring>
#include <iostream>
template<typename t>
class tVector 
{
	t*data;
	size_t capacity;
	size_t size;
	bool grow(size_t minSize)
	{
		assert(minSize <= 64000);
		if (minSize <= capacity)
		{
			return true;
		}

		while (capacity<minSize)
		{
			capacity *= 2;
		}
		t* newData = new t[capacity];
		memcpy(newData, data, sizeof(t) * size);

		delete[]data;

		data = newData;
		return true;
	}
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
		assert(size > 0);
		return data[0];
	}
	t back() const 
	{
		assert(size > 0);
		return data[size - 1];
	}
	void pop() 
	{
		assert(size > 0);
		size -= 1;
	}
	void erases(size_t idx) 
	{
		for (size_t i = idx; i < size; i++)
		{
			t temp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp;
		}
		size--;
	}
	void clear() 
	{

		size = 0;
	}
	t operator[](size_t idx) const 
	{
		assert(idx < size);
		return data[idx];
	}
	t &operator[](size_t idx) 
	{
		assert(idx < size);
		return data[idx];
	}
	size_t count(t value) const
	{
		size_t counter = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (data[i] == value)
			{
				counter++;
			}
		}
		return counter;
	}
	void insert(size_t idx, t value) 
	{
		assert(idx >= 0);
		assert(idx < size);
		append(value);
		if (idx<size - 1)
		{
			for (size_t i = size; i >= idx; i--)
			{
				t temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
			}
		}
	}
	void Reserve(size_t newCapacity) 
	{

		if (newCapacity > capacity)
		{
			t *newData = new t[newCapacity];
			memcpy(newData, data, sizeof(t) * size);
			delete[] data;
			data = newData;
			capacity = newCapacity;
		}
	}
	void Compact() 
	{

		if (capacity > size)
		{
			t *newData = new t[size];
			memcpy(newData, data, sizeof(t) * size);
			delete[] data;
			data = newData;
			capacity = size;
		}
	}

};
