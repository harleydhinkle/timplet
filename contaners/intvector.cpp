#include "intvector.h"
#include <cassert>
#include <cstring>

intvector::intvector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intvector::~intvector()
{
	delete[] data;
}

int & intvector::at(size_t idx)
{

	assert(idx >= 0);
	assert(idx < size);

	return data[idx];

}

int * intvector::datapont() const
{
	return data;
}

int & intvector::append(int val)
{
	if (size == capacity) {
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}
	data[size] = val;
	++size;
	return data[size - 1];
}
size_t intvector::capacitytotal() const
{
	return capacity;
}
size_t intvector::sizearra() const
{
	return size;
}
bool intvector::empty() const
{
	return size == 0;
}
int intvector::front() const
{
	return data[0];
}
int intvector::back() const
{
	return data[size - 1];
}
int intvector::operator[](size_t idx) const
{
	return data[idx];
}
int & intvector::operator[](size_t idx)
{
	return data[idx];
}
void intvector::clear()
{
	size = 0;
}
void intvector::erase(size_t idx)
{
	for (int i = idx; i < size; i++) 
	{
		int temp = data[i];
		data[i] = data[i + 1];
		data[i + 1] = temp;
	}
	size--;
}
int intvector::count(int value)
{
	int counter = 0;
	for (int i;);
	return counter;
}
void intvector::insert(size_t idx, int value)
{
	assert(idx >= 0);
	assert(idx < size);
	append(value);
	if(idx<size - 1)
	{
		for (int i = size; i >= idx; i--)
		{
			int temp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp;
		}
	}
}
bool intvector::grow(size_t minSize)
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
	int* newData = new int[capacity];
	memcpy(newData, data,sizeof(int) * size);

	delete[]data;

	data = newData;
	return true;
}
