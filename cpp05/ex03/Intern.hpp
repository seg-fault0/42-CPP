#pragma once

//libraries
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

//macros
# define MAX_FORMS 3

class Intern
{

	public:
		// ORTHODOX
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		// METHODES
		AForm	*makeForm(const std::string form_name, const std::string form_target);

		//EXEPTION
		class FormNotFound : public std::exception
		{
			public:
				const char * what() const throw();
		};
};