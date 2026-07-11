#pragma once

//libraries
#include <iostream>
#include "Bureaucrat.hpp"

//macros
# define Default_AForm_Name "AForm"
# define Default_AForm_Grade Default_Bureaucrat_Grade

//forward declaration
class Bureaucrat;

//class
class AForm
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_isSigned;
		virtual void		performAction(void) const = 0;
	
	public:
	//orthodox
		AForm();
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
	
	//other constructors
		AForm(const std::string& name, int signGrade, int executeGrade);
	
	//geters
		std::string	getName(void) const;
		bool		isSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;

	//methods
		void	beSigned(const Bureaucrat& bureaucrat);
		void	execute(const Bureaucrat& executor) const;
	
	//exeption class
		class GradeTooHighException : public std::exception
		{
			const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char * what() const throw();
		};
		
		class AFormAlreadySigned : public std::exception
		{
			const char * what() const throw();
		};

		class AFormNotSigned : public std::exception
		{
			const char * what() const throw();
		}; 
};

std::ostream& operator<<(std::ostream& os, const AForm& f);