#pragma once

//includes
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

//macros
# define Default_Bureaucrat_Name "Bureaucrat"
# define Default_Bureaucrat_Grade 100
# define MIN_GRADE 150
# define MAX_GRADE 1

//forward declaration
class AForm;

//class
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
	//orthodox
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

	//other constructors
		Bureaucrat(const std::string& name, int grade);

	//geters
		std::string	getName(void) const;
		int			getGrade(void) const;

	//--grade++
		void	increment(void);
		void	decrement(void);
	
	//methodes
		void	signForm(AForm& form);
		void	executeForm(AForm const& form) const;

	//exeption
		class GradeTooHighException : public std::exception
		{
			const char * what() const throw();
		};
	
		class GradeTooLowException : public std::exception
		{
			const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);