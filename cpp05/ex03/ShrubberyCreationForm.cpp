#include "ShrubberyCreationForm.hpp"

/******************************************/
/*************   ORTHODOX  ****************/
/******************************************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SCF_Name, SCF_SGrade, SCF_EGrade) 
{
	_target = Default_SCF_Target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm (other.getName(), other.getSignGrade(), other.getExecuteGrade())
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(SCF_Name, SCF_SGrade, SCF_EGrade) 
{
	_target = target;
}

/******************************************/
/*************   OVERRIDE  ****************/
/******************************************/

void	ShrubberyCreationForm::performAction(void) const
{
	std::ofstream outFile((_target+ std::string("_shrubbery")).c_str());

	if (outFile)
	{
		outFile << "    /\\    \n";
		outFile << "   /  \\   \n";
		outFile << "  /    \\  \n";
		outFile << " /      \\ \n";
		outFile << "/________\\\n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";

		outFile.close();
	}
	else
		throw ShrubberyCreationForm::OpenFileExeption();

}

/******************************************/
/************    EXEPRTION   **************/
/******************************************/

const char * ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return ("Failed to open file");
}
