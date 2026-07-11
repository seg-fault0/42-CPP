#include "Bureaucrat.hpp"

/******************************************/
/*************   ORTHODOX  ****************/
/******************************************/

Bureaucrat::Bureaucrat() : _name(Default_Bureaucrat_Name), _grade(Default_Bureaucrat_Grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

/******************************************/
/*********   OTHER CONSTRUCTORS ***********/
/******************************************/

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	else if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	_grade = grade;
}

/******************************************/
/*************    GETERS   ****************/
/******************************************/

std::string	Bureaucrat::getName(void) const { return (_name); }

int			Bureaucrat::getGrade(void) const { return (_grade); }

/******************************************/
/***********    -- GRADE ++   *************/
/******************************************/

void	Bureaucrat::increment(void)
{
	if (_grade - 1 < MAX_GRADE)
		throw (GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decrement(void)
{
	if (_grade + 1 > MIN_GRADE)
		throw (GradeTooLowException());
	_grade++;
}

/******************************************/
/*************    METHODES   **************/
/******************************************/

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() 
		<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

/******************************************/
/************    EXEPRTION   **************/
/******************************************/

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low");
}

/******************************************/
/**********    OVERLOAD COUT   ************/
/******************************************/

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}