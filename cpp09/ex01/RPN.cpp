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

void	RPN::init(const std::string& arg)
{
	bool	lock = false;

	for(size_t i = 0; i < arg.length(); i++)
	{
		if (!lock && (std::isdigit(arg[i]) || isop(arg[i])))
			lock = true;
		else if (lock && arg[i] == ' ')
			lock = false;
		else
			throw (ERROR());
	}
	_expretion << arg;
}

void	RPN::lunch(void)
{
	std::string	line;
	int			a, b;

	while (std::getline(_expretion, line, ' '))
	{
		if (!isop(line))
			_stack.push(ft_atoi(line));
		else
		{
			a = popVal(_stack);
			b = popVal(_stack);

			if (line == "+")
				_stack.push(b + a);
			else if (line == "-")
				_stack.push(b - a);
			else if (line == "/")
				_stack.push(b / a);
			else if (line == "*")
				_stack.push(b * a);
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