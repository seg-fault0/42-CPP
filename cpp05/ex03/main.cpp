#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* form;

	Bureaucrat boss("Boss", 1);

	try
	{
		form = someRandomIntern.makeForm("heuw", "home");
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
