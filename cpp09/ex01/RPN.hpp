#pragma once

//libraries
# include <iostream>
# include <stdexcept>
# include <cctype>
# include <stack>
# include <sstream>
# include <string>

//macros
# define ull_t unsigned long long

//class
class RPN
{
	private:
		std::stringstream	_expression;
		std::stack<int>		_stack;

	public:
	//orthodox
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

	//methods
		void	init(const std::string& arg);
		void	lunch(void);
	
	//exception
		class ERROR : public std::exception
		{
			const char* what() const throw();
		};
};