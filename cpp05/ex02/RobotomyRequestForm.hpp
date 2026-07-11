#pragma once

//libraries
# include "AForm.hpp"
# include <time.h>
# include <stdlib.h>

//macros
# define RRF_SGrade 72
# define RRF_EGrade 45
# define RRF_Name "RobotomyRequestForm"
# define Default_RRF_Target "DefaultRRFTarget"

//class
class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
		void		performAction(void) const;

	public:
	//orthodox
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	
	//other constructors
		RobotomyRequestForm(const std::string& target);
	
	//exeption
		class RobotizationFailed : public std::exception
		{
			const char * what() const throw();
		};
};