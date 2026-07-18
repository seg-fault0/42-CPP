#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage : ./btc <inputFile.txt>\n";
		return(1);
	}

	try
	{
		BitcoinExchange btc;

		btc.init(av[1]);
		btc.lunch();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}