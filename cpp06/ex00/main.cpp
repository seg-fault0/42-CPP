#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "usage : ./ScalarConverter <int>\n";
		return (1);
	}

	ScalarConverter::convert(av[1]);
}