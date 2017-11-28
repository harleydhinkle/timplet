#pragma once
class intvector 
{
	int * data;
	size_t capacity;
	size_t size;
public:
	intvector();
	~intvector();
	int& at(size_t idx);
	int* datapont() const;
	int& append(int val);
	size_t capacitytotal () const;
	size_t sizearra() const;
	bool empty() const;
	int front() const;
	int back() const;
	int& sub(size_t vel);
private:
	bool grow(size_t minSize);
};