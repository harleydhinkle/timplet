#pragma once
class intLnkedlist
{
public:
	struct intLinkedListNode
	{
		int value;
		intLinkedListNode*next;
		intLinkedListNode*pred;
	};
	intLnkedlist();
	~intLnkedlist();
	void append(int val);
	int at(int index);
	size_t size() const;
	bool empty() const;
	int front() const;
	int back() const;
	void erase(size_t idx);
	void clear();
	int count(int value);
	void insert(size_t idx, int value);

private:
	intLinkedListNode*head;
};