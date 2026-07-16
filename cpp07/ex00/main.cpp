#include "whatever.hpp"
#include <iostream>

int main()
{
	int i1 = 11, i2 = 10;
	float f1 = 11.1, f2 = 11.2;
	std::string s1("brb"), s2("be right back");

// max and min
	std::cout << ::max(i1, i2) << " is bigger than " << ::min(i1, i2) << std::endl;
	std::cout << ::min(s1, s2) << " stands for " << ::max(s1, s2) << std::endl;
	
// swap
	std::cout << "before swap : f1 = " << f1 << " | f2 = " << f2 << std::endl;
	::swap(f1, f2);
	std::cout << "after swap : f1 = " << f1 << " | f2 = " << f2 << std::endl;
}