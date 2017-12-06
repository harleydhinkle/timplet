#pragma once

template<typename T>
class iterator
{
public:
	iterator() = delete;
	iterator(T&container, int initialIndex):owningContainter(&container),currentIndex(initialIndex)
	{

	}
	iterator(const iterator<T>&other) :owningContainter(other.owningContainter),currentIndex(other.currentIndex)
	{

	}
	iterator<T>& operator=(const iterator<T>&other) 
	{
		owningContainter = other.owningContainter;
		currentIndex = other.currentIndex;
	}

	bool operator==(const iterator<T>&other) 
	{
		bool isSamecontaner = owningContainter == other.owningContainter;
		bool isSameIndex = currentIndex == other.currentIndex;
		return isSamecontaner&&isSameIndex;

	}
	bool operator!=(const iterator<T>&other) 
	{
		bool isSamecontaner = owningContainter == other.owningC
		bool isSameIndex = currentIndex == other.currentIndex;
		return !isSamecontaner||isSameIndex;

	}

	auto& operator*() 
	{
		return owningContainter->at(currentIndex);
	}

	iterator<T>& operator++() 
	{
		++currentIndex;
		return *this;
	}
	iterator<T>& operator++(int previousValue)
	{
		iterator<T>tmp(owningContainter, currentIndex);
		operator++();
		return tmp;
	}
private:
	T*owningContainter;
	int currentIndex;

};			  