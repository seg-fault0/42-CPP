#include "easyfind.hpp"
#include <vector>
#include <iostream>

void foo1()
{
	std::vector<int> v;

	for(int i = 0; i < 10; i++)
		v.push_back(i + 1);
	
	std::cout << "look for : " << *easyfind(v, 9) << std::endl;
}

void foo2()
{
	std::vector<int> v;

	for(int i = 0; i < 10; i++)
		v.push_back(i + 1);
	
	std::cout << "look for : " << *easyfind(v, 100) << std::endl;
}

int main()
{
	try
	{
		foo1();
		foo2();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}