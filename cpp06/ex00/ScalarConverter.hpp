#pragma once

//libraries
# include <iostream>
# include <sstream>
# include <limits.h>
# include <cfloat>
# include <cctype>

//class
class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

	public:
		static void	convert(const std::string& arg);
};
