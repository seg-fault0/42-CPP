#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error : usage : ./RPN <Polish mathematical expression>" << std::endl;
		return (1);
	}

	try
	{
		RPN	rpn;

		rpn.init(av[1]);
		rpn.lunch();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}