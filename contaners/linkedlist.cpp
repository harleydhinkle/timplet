#include "linkedlist.h"
#include <cassert>
#include <cstring>
intLnkedlist::intLnkedlist():head(nullptr)
{

}

intLnkedlist::~intLnkedlist()
{
	intLinkedListNode* iter = head;
	while (iter != nullptr) 
	{
		intLinkedListNode*next = iter -> next;
		delete iter;
		iter = iter->next;
	}
}

void intLnkedlist::append(int val)
{
	intLinkedListNode*newNode = new intLinkedListNode;
	newNode->value = val;
	newNode->next = nullptr;
	if (head == nullptr) 
	{
		head = newNode;
	}
	else 
	{
		intLinkedListNode *iter = head;
		while (iter->next  !=nullptr)
		{
			iter = iter->next;
		}
		iter->next = newNode;
	}
}

int intLnkedlist::at(int index)
{
	intLinkedListNode*iter = head;
	int iterationCount = 0;
	while (iterationCount!=index &&iter!=nullptr)
	{
		iterationCount++;
		iter = iter->next;
	}
	assert(iter != nullptr);

	return iter->value;
}


size_t intLnkedlist::size() const
{
	int counter= 0;
	intLinkedListNode*iter = head;
	while (iter != nullptr) 
	{
		counter++;
		iter = iter->next;
	}
	return counter;
}

bool intLnkedlist::empty() const
{

	return head == nullptr;
}

int intLnkedlist::front() const
{
	assert(!empty());
	return head->value;
}

int intLnkedlist::back() const
{
	assert(!empty());
	intLinkedListNode*iter = head;
	while (iter->next !=nullptr)
	{
		iter = iter->next;
	}
	return iter->value;
}



void intLnkedlist::erase(size_t idx)
{
	intLinkedListNode*iter = head;
	intLinkedListNode*pred = iter;
	
	//iterate to our idx
	while (iter = pred)
	{
		iter->value = idx;
		delete iter;
	}

	//set out previous idx equal to our iterators->next
	pred = iter->next;

}

void intLnkedlist::clear()
{

	intLinkedListNode*iter = head;
	intLinkedListNode*store = iter;
	while (iter !=nullptr)
	{
		iter->next = store;
		delete iter;
	}
	iter->value;
}

int intLnkedlist::count(int value)
{
	int counter = 0;
	intLinkedListNode*iter = head;
	intLinkedListNode*pred = iter;
	while (iter = nullptr) 
	{
		if (iter->value = pred->value) 
		{
			counter++; 
		}
	}
	return counter;
}

void intLnkedlist::insert(size_t idx, int value)
{

}


