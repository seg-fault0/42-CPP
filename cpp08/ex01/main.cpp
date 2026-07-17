#include "Span.hpp"
#include <iostream>

void foo1(void)
{
	Span s(5);
	
	for(int i = 0; i < 5; i++)
		s.addNumber(i + 1);
	
	std::cout << "shortestSpan = " <<  s.shortestSpan() << std::endl;
	std::cout << "longestSpan = " <<  s.longestSpan() << std::endl;
}

int main()
{
	try
	{
		foo1();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}