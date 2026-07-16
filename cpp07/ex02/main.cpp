#include <iostream>
#include "Array.hpp"

#define MAX_SIZE 100

int main(int, char**)
{
	Array<int> numbers(MAX_SIZE);

	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		numbers[i] = rand();
	

	try // out of bound -
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try // out of bound +
	{
		numbers[MAX_SIZE] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << "size = " << numbers.size() << " | MaxSize = " << MAX_SIZE << "\n";
	std::cout << "before : element [10] = " << numbers[10] << "\n";
	numbers[10] = 88;
	std::cout << "after : element [10] = " << numbers[10] << "\n";

	return 0;
}