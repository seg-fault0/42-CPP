#pragma once

//libraries
# include "AForm.hpp"
# include <fstream>

//macros
# define SCF_SGrade 145
# define SCF_EGrade 137
# define SCF_Name "ShrubberyCreationForm"
# define Default_SCF_Target "DefaultSCFTarget"

//class 
class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

		void		performAction(void) const;

	public:
	//orthodox
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	
	//other constructor
		ShrubberyCreationForm(const std::string& target);

	//exeption
		class OpenFileExeption : public std::exception
		{
			const char * what() const throw();
		};
};