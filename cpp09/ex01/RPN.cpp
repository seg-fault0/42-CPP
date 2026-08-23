#include "RPN.hpp"

/******************************************/
/***********      HELPER     **************/
/******************************************/

static bool	isop(int c)
{
	if (c == '*'
		|| c == '/'
		|| c == '+'
		|| c == '-')
		return (true);
	return (false);
}

static bool	isop(const std::string& c)
{
	if (c == "*"
		|| c == "/"
		|| c == "+"
		|| c == "-")
		return (true);
	return (false);
}

static int ft_atoi(const std::string& str)
{
	std::stringstream ss(str);
	int ret;

	ss >> ret;
	return (ret);
}

static int popVal(std::stack<int>& s)
{
	if (s.empty())
		throw (RPN::ERROR());
	
	int val = s.top();
	
	s.pop();
	return (val);
}

/******************************************/
/***********     ORTHODOX    **************/
/******************************************/

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) { *this = other; }

RPN& RPN::operator=(const RPN& other) 
{
	(void) other;
	return (*this);
}

/******************************************/
/***********      METHODS    **************/
/******************************************/

void RPN::init(const std::string& arg)
{
	if (arg.empty())
		throw ERROR();

	std::stringstream ss(arg);
	std::string token;

	while (ss >> token)
	{
		if (token.length() != 1)
			throw ERROR();

		if (!std::isdigit(static_cast<unsigned char>(token[0])) && !isop(token[0]))
			throw ERROR();

		_expression << token[0] << " ";
	}
}

void	RPN::lunch(void)
{
	std::string	line;
	int			a, b;
	long long		result;

	while (std::getline(_expression, line, ' '))
	{
		if (!isop(line))
			_stack.push(ft_atoi(line));
		else
		{
			a = popVal(_stack);
			b = popVal(_stack);
			result = 0;

			if (line == "+")
				result = static_cast<long long>(b) + a;
			else if (line == "-")
				result = static_cast<long long>(b) - a;
			else if (line == "*")
				result = static_cast<long long>(b) * a;
			else if (line == "/")
			{
				if (a == 0)
					throw (ERROR());
				result = static_cast<long long>(b) / a;
			}
			if (result < INT_MIN || result > INT_MAX)
				throw ERROR();
			_stack.push(static_cast<int> (result));
		}
	}

	if (_stack.size() > 1)
		throw(ERROR());
	std::cout << _stack.top() << std::endl;
}

/******************************************/
/***********      EXCEPTION    ************/
/******************************************/

const char* RPN::ERROR::what() const throw()
{
	return ("ERROR");
}