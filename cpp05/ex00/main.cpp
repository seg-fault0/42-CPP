#include "Bureaucrat.hpp"

int main()
{
	//grade too hight constructor
	try
	{
		Bureaucrat b("walid", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//grade too high increment
	try
	{
		Bureaucrat b("walid", 1);
		b.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//grade too low constructor
	try
	{
		Bureaucrat b("walid", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//grade too low decrement
	try
	{
		Bureaucrat b("walid", 150);
		b.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//works
	try
	{
		Bureaucrat b("walid", 100);
		std::cout << b << std::endl;
		b.decrement();
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}