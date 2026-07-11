#include "RobotomyRequestForm.hpp"

/******************************************/
/*************   ORTHODOX  ****************/
/******************************************/

RobotomyRequestForm::RobotomyRequestForm() : AForm(RRF_Name, RRF_SGrade, RRF_EGrade)
{
	_target = Default_RRF_Target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade())
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}

/******************************************/
/*********   OTHER CONSTRUCTORS ***********/
/******************************************/

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(RRF_Name, RRF_SGrade, RRF_EGrade)
{
	_target = target;
}

/******************************************/
/*************   OVERRIDE  ****************/
/******************************************/

void	RobotomyRequestForm::performAction(void) const
{
	srand(time(NULL));

	if (rand() % 2 == 0)
		std::cout << "Beeep Be Be Beeeee Beeeeeeeep. " << getName() << " has been robotomized successfully!" << std::endl; 		
	else
		throw RobotizationFailed();

}

/******************************************/
/************    EXEPRTION   **************/
/******************************************/

const char * RobotomyRequestForm::RobotizationFailed::what() const throw()
{
	return ("Unfortunately robotomy failed.");
}
