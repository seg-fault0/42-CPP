#include "iter.hpp"
#include <iostream>
#include <vector>

template <typename T>
void	increment(T& element)
{
	element++;
}

template <typename T>
void	print_elemt(T& element)
{
	std::cout << "(" << element << ") ";
}

void test1(void)
{
	std::cout << "***** TEST 1 : array of ints ******\n";

	int arr[] = {1, 2, 3, 4, 5};
	int size = 5;
	
	std::cout << "Before : ";
	iter(arr, size, print_elemt<int>);
	std::cout << std::endl;
	
	iter(arr, size, increment<int>);
	
	std::cout << "After : ";
	iter(arr, size, print_elemt<int>);
	std::cout << "\n";
}

void test2(void)
{
	std::cout << "***** TEST 2 : array of floats ******\n";
	
	float arr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
	size_t size = 5;
	
	std::cout << "Before : ";
	iter(arr, size, print_elemt<float>);
	std::cout << std::endl;
	
	iter(arr, size, increment<float>);
	
	std::cout << "After : ";
	iter(arr, size, print_elemt<float>);
	std::cout << "\n";
}

int main()
{
	test1();
	std::cout << "\n";
	test2();
}