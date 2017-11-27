#include <iostream>
#include "test.h"
int add(int a, int b) 
{
	return a + b;
}
float add(float a, float b) 
{
	return a + b;
}
template<typename T>
T sub(T a, T b) 
{
	return a - b;
}
template<typename T>
T print(T a) 
{
	return a;
}
template<typename T>
T min(T a, T b) 
{
	if (a < b) 
	{
		return a;
	}
	if (b < a) 
	{
		return b;
	}
}
template<typename T>
T max(T a, T b)
{
	if (a > b)
	{
		return a;
	}
	if (b > a)
	{
		return b;
	}
}
template<typename T>
T clamp(T a, T b,T c)
{
	if (a < b) {
		return b;
	}
	else if (a) {

	}
}
class Person 
{
public:
	std::string name;
	int age;
	float heigth;
};
template<typename T>
void swap(T& a, T& b) 
{
	T temp = a;
	a = b; 
	b = temp;
}

int main() 
{
	assert<true>(5 == 5);

	int think = 5;
	int fwoob = 7;
	swap(think, fwoob);
	int v1 = add(5, 2);
	float v2 = add(2.1f, 3.2f);
	int s1 = sub(1, 1);
	float s2 = sub(2.5f, 1.1f);
	int s3 = sub<int>(1, 2.0f);
	int r1 = print(1);
	float r2 = print(1.2f);
	bool r3 = print(true);
	int m1 = min(2, 3);
	int m2 = min(3, 2);
	int b1 = max(4, 1);
	int b2 = max(1, 5);
	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
	std::cout << r3 << std::endl;
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	return 0;

}