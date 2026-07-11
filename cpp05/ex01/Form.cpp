#include "Form.hpp"

/******************************************/
/*************   ORTHODOX  ****************/
/******************************************/

Form::Form() : _name(Default_Form_Name), _signGrade(Default_Form_Grade), _executeGrade(Default_Form_Grade)
{
	_isSigned = false;
}

Form::~Form() {}

Form::Form(const Form& other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

/******************************************/
/*********   OTHER CONSTRUCTORS ***********/
/******************************************/

Form::Form(const std::string& name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw(GradeTooHighException());
	else if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw(GradeTooLowException());

	_isSigned = false;
}

/******************************************/
/*************    GETERS   ****************/
/******************************************/

std::string	Form::getName(void) const { return (_name); }

bool		Form::isSigned(void) const { return (_isSigned); }

int			Form::getSignGrade(void) const { return (_signGrade); }

int			Form::getExecuteGrade(void) const { return (_executeGrade); }

/******************************************/
/*************    METHODES   **************/
/******************************************/

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_signGrade < bureaucrat.getGrade())
		throw (GradeTooHighException());
	else if (_isSigned == true)
		throw (FormAlreadySigned());
	_isSigned = true;
}

/******************************************/
/************    EXEPRTION   **************/
/******************************************/

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

const char * Form::FormAlreadySigned::what() const throw()
{
	return ("Form already signed");
}


/******************************************/
/**********    OVERLOAD COUT   ************/
/******************************************/

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form { name : " << f.getName()
		<< ", signGrade : " << f.getSignGrade()
		<< ", executeGrade : " << f.getExecuteGrade()
		<< ", isSigned : " << f.isSigned()
		<< " }";
	return (os);
}