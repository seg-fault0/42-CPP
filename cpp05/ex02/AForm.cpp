#include "AForm.hpp"

/******************************************/
/*************   ORTHODOX  ****************/
/******************************************/

AForm::AForm() : _name(Default_AForm_Name), _signGrade(Default_AForm_Grade), _executeGrade(Default_AForm_Grade)
{
	_isSigned = false;
}

AForm::~AForm() {}

AForm::AForm(const AForm& other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
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

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
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

std::string	AForm::getName(void) const { return (_name); }

bool		AForm::isSigned(void) const { return (_isSigned); }

int			AForm::getSignGrade(void) const { return (_signGrade); }

int			AForm::getExecuteGrade(void) const { return (_executeGrade); }

/******************************************/
/*************    METHODES   **************/
/******************************************/

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_signGrade < bureaucrat.getGrade())
		throw (GradeTooHighException());
	else if (_isSigned == true)
		throw (AFormAlreadySigned());
	_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (_isSigned == false)
		throw (AFormNotSigned());
	if (executor.getGrade() > _executeGrade)
		throw(GradeTooLowException());
	performAction();
}

/******************************************/
/************    EXEPRTION   **************/
/******************************************/

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade too low");
}

const char * AForm::AFormAlreadySigned::what() const throw()
{
	return ("AForm already signed");
}

const char * AForm::AFormNotSigned::what() const throw()
{
	return ("AForm not signed yet");
}

/******************************************/
/**********    OVERLOAD COUT   ************/
/******************************************/

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm { name : " << f.getName()
		<< ", signGrade : " << f.getSignGrade()
		<< ", executeGrade : " << f.getExecuteGrade()
		<< ", isSigned : " << f.isSigned()
		<< " }";
	return (os);
}