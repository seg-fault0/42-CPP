#include "PresidentialPardonForm.hpp"

/******************************************/
/*************   ORTHODOX  ****************/
/******************************************/

PresidentialPardonForm::PresidentialPardonForm() : AForm(PPF_Name, PPF_SGrade, PPF_EGrade)
{
	_target = PPF_Default_Target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade())
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
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

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(PPF_Name, PPF_SGrade, PPF_EGrade)
{
	_target = target;
}

/******************************************/
/*************   OVERRIDE  ****************/
/******************************************/

void PresidentialPardonForm::performAction(void) const
{
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;		
}