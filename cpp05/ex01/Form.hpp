#pragma once

//libraries
#include <iostream>
#include "Bureaucrat.hpp"

//macros
# define Default_Form_Name "Form"
# define Default_Form_Grade Default_Bureaucrat_Grade

//forward declaration
class Bureaucrat;

//class
class Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_isSigned;
	
	public:
	//orthodox
		Form();
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
	
	//other constructors
		Form(const std::string& name, int signGrade, int executeGrade);
	
	//geters
		std::string	getName(void) const;
		bool		isSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;

	//methods
		void	beSigned(const Bureaucrat& bureaucrat);
	
	//exeption class
		class GradeTooHighException : public std::exception
		{
			const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char * what() const throw();
		};
		
		class FormAlreadySigned : public std::exception
		{
			const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);