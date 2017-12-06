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
	newNode->pred = nullptr;
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
		newNode->pred = iter;
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
	int counter = 0;

	assert(idx <= size());
	//iterate to our idx
	while (iter->next!=nullptr&&counter !=idx)
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

void intLnkedlist::clear()
{

	intLinkedListNode*iter = head;
	while (iter !=nullptr)
	{
		intLinkedListNode* next = iter->next;
		delete iter;
		iter = next;
	}
	head = nullptr;
	
}

int intLnkedlist::count(int value)
{
	int counter = 0;
	intLinkedListNode*iter = head;
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

void intLnkedlist::insert(size_t idx, int value)
{
	//prev
	//iter
	intLinkedListNode*iter = head;
	
	int counter = 0;

	//New node = new Linkedlistnode
	intLinkedListNode*newNode = new intLinkedListNode;
	//newNode->value = value
	newNode->value = value;
	//iteratoe through our linked list to find the index we want
	while (iter->next != nullptr &&counter!= idx ) 
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


