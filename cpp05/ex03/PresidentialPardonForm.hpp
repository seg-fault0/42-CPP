#pragma once

//libraries
# include "AForm.hpp"

//macros
# define PPF_SGrade 25
# define PPF_EGrade 5
# define PPF_Name "PresidentialPardonForm"
# define PPF_Default_Target "DefaultPPFTarget"

//class
class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
		void		performAction(void) const;
	
	public:
	//orthodox
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	//other constructors
		PresidentialPardonForm(const std::string& target);
};