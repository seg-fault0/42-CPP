#include "ScalarConverter.hpp"

/********************************************************/
/******************       HELPERS      ******************/
/********************************************************/

static long long	ft_atoll(const std::string& str)
{
	std::stringstream ss(str);
	long long ll;

	if (str.length() == 1 && !std::isdigit(str[0]))
		return (static_cast<long long> (str[0]));
	ss >> ll;
	return (ll);
}

static double	ft_atod(const std::string& str)
{
	std::stringstream ss(str);
	double d;

	if (str.length() == 1 && !std::isdigit(str[0]))
		return (static_cast<double> (str[0]));
	ss >> d;
	return (d);
}

/********************************************************/
/*****************       CHECKERS      ******************/
/********************************************************/

static bool	ft_isPseudo(const std::string& arg)
{
	if (arg == "nan" || arg == "+inf" || arg == "+inff"
		|| arg == "nanf" || arg == "-inf" || arg == "-inff")
		return (true);
	return (false);
}

static bool ft_isValidArg(const std::string& arg)
{
	if (arg.length() == 1)
		return (true);

	size_t i = 0;
	bool hasDigit = false;
	bool hasDot = false;
	bool hasF = false;

	if (arg[i] == '+' || arg[i] == '-')
		i++;

	while (i < arg.length())
	{
		if (std::isdigit(arg[i]))
			hasDigit = true;
		else if (arg[i] == '.')
		{
			if (hasDot || hasF)
				return (false);
			hasDot = true;
		}
		else if (arg[i] == 'f')
		{
			if (!hasDot || hasF || i != arg.length() - 1)
				return (false);
			hasF = true;
		}
		else
			return (false);

		i++;
	}
	return (hasDigit);
}

/********************************************************/
/*******************       PRINT      *******************/
/********************************************************/

static void	print_char(const std::string& arg, bool isPseudo, bool isValidArg)
{
	long long	c = 0;

	if (!isValidArg || isPseudo)
		std::cout << "char: impossible\n";
	else if (arg.empty())
		std::cout << "char: Non displayable\n";
	else if (arg.length() == 1 && !std::isdigit(arg[0]))
		std::cout << "char: '" << arg << "'\n";
	else
	{
		c = ft_atoll(arg);
		if (c < 0 || c > 127)
			std::cout << "char: impossible\n";
		else if (!std::isprint(c))
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: '" << static_cast<char>(c) << "'\n";
	}
}

static void	print_int(const std::string& arg, bool isPseudo, bool isValidArg)
{
	long long c = 0;

	if (!isValidArg || isPseudo)
		std::cout << "int: impossible\n";
	else if (arg.empty())
		std::cout << "int: 0\n";
	else
	{
		c = ft_atoll(arg);
		if (c > INT_MAX || c < INT_MIN)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(c) << std::endl;
	}
}

static void	print_float(const std::string& arg, bool isPseudo, bool isValidArg)
{
	double d = ft_atod(arg);

	if (isPseudo)
	{
		if (arg == "nan")
			std::cout << "float: nanf\n";
		else if (arg == "+inf")
			std::cout << "float: +inff\n";
		else if (arg == "-inf")
			std::cout << "float: -inff\n";
		else
			std::cout << "float: " << arg << std::endl;
	}
	else if (arg.empty())
		std::cout << "float: 0.0f\n";
	else if (!isValidArg || d < -FLT_MAX || d > FLT_MAX)
		std::cout << "float: impossible\n";
	else
	{
		if (d == static_cast<int>(d))
			std::cout << "float: " << static_cast<float>(d) << ".0" << "f\n";
		else
			std::cout << "float: " << static_cast<float>(d) << "f\n";
	}
}

static void	print_double(const std::string& arg, bool isPseudo, bool isValidArg)
{
	double d = ft_atod(arg);

	if (isPseudo)
	{
		if (arg == "nanf")
			std::cout << "double: nan\n";
		else if (arg == "+inff")
			std::cout << "double: +inf\n";
		else if (arg == "-inff")
			std::cout << "double: -inf\n";
		else
			std::cout << "double: " << arg << std::endl;
	}
	else if (arg.empty())
		std::cout << "double: 0.0\n";
	else if (!isValidArg || d < -DBL_MAX || d > DBL_MAX)
		std::cout << "double: impossible\n";
	else
	{
		if (d == static_cast<int>(d))
			std::cout << "double: " << d << ".0\n";
		else
			std::cout << "double: " << d << std::endl;
	}
}

/********************************************************/
/*******************     CONVERT     ********************/
/********************************************************/

void	ScalarConverter::convert(const std::string& arg)
{
	bool isPseudo = false;
	bool isValidArg = true;

	if (ft_isPseudo(arg) == true)
		isPseudo = true;
	else if (!ft_isValidArg(arg))
		isValidArg = false;

	print_char(arg, isPseudo, isValidArg);
	print_int(arg, isPseudo, isValidArg);
	print_float(arg, isPseudo, isValidArg);
	print_double(arg, isPseudo, isValidArg);
}
