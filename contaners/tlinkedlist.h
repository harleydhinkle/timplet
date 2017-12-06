#pragma once
#include <cassert>
#include <cstring>
template<typename T>
class tlinkedlist 
{
public:
	struct tLinkedListNode
	{
		T value;
		tLinkedListNode*next;
		tLinkedListNode*pred;
	};
	tLnkedlist() 
	{

	}
	~tLnkedlist() 
	{
		tLinkedListNode* iter = head;
		while (iter != nullptr)
		{
			tLinkedListNode*next = iter->next;
			delete iter;
			iter = iter->next;
		}
	}
	void append(T val) 
	{
		tLinkedListNode*newNode = new tLinkedListNode;
		newNode->value = val;
		newNode->next = nullptr;
		newNode->pred = nullptr;
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			tLinkedListNode *iter = head;
			while (iter->next != nullptr)
			{
				iter = iter->next;
			}
			newNode->pred = iter;
			iter->next = newNode;
		}
	}
	T at(T index) 
	{
		tLinkedListNode*iter = head;
		T iterationCount = 0;
		while (iterationCount != index &&iter != nullptr)
		{
			iterationCount++;
			iter = iter->next;
		}
		assert(iter != nullptr);

		return iter->value;
	}
	size_t size() const 
	{
		t counter;
		tLinkedListNode*iter = head;
		while (iter != nullptr)
		{
			counter++;
			iter = iter->next;
		}
		return counter;
	}
	T empty() const 
	{
		return head == nullptr;
	}
	T front() const 
	{
		assert(!empty());
		return head->value;
	}
	T back() const 
	{
		assert(!empty());
		tLinkedListNode*iter = head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		return iter->value;
	}
	void erase(size_t idx) 
	{
		tLinkedListNode*iter = head;
		T counter = 0;

		assert(idx <= size());
		//iterate to our idx
		while (iter->next != nullptr&&counter != idx)
		{

			iter = iter->next;
			counter++;
		}

		//set out previous idx equal to our iterators->next
		//assert(counter == idx);
		iter->pred->next = iter->next;
		if (idx == 0)
		{
			head = iter->next;
		}

		delete iter;
	}
	void clear() 
	{

		tLinkedListNode*iter = head;
		while (iter != nullptr)
		{
			tLinkedListNode* next = iter->next;
			delete iter;
			iter = next;
		}
		head = nullptr;

	}
	T count(T value) 
	{
		T counter = 0;
		tLinkedListNode*iter = head;
		//intLinkedListNode*pred = iter;
		while (iter->next != nullptr)
		{

			if (iter->value = value)
			{
				counter++;
			}
			iter = iter->next;
		}
		return counter;
	}
	void insert(size_t idx, T value) 
	{
		//prev
		//iter
		tLinkedListNode*iter = head;

		T counter = 0;

		//New node = new Linkedlistnode
		tLinkedListNode*newNode = new intLinkedListNode;
		//newNode->value = value
		newNode->value = value;
		//iteratoe through our linked list to find the index we want
		while (iter->next != nullptr &&counter != idx)
		{

			iter = iter->next;
			counter++;
		}
		//find the previos node and find the next the node
		//prev->next = newNode
		iter->pred->next = newNode;
		//newNode->next = iter
		newNode->next = iter;
		newNode->pred = iter->pred;
	}
};