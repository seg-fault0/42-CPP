#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//grade to high form
	try
	{
		Bureaucrat	b("walid", 12);
		Form		f("contract", 2, 0);

		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//grade to low form
	try
	{
		Bureaucrat	b("walid", 12);
		Form		f("contract", 151, 2);

		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//couldn't sign
	try
	{
		Bureaucrat	b("walid", 11);
		Form		f("contract", 10, 10);

		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//works
	try
	{
		Bureaucrat	b("walid", 9);
		Form		f("contract", 10, 10);

		b.signForm(f);
		b.signForm(f);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}