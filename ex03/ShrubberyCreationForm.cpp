#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("undefined")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm) : target(shrubberyForm.target)
{
	*this = shrubberyForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyForm)
{
	(void)shrubberyForm;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	std::ofstream	file;

	this->AForm::validateExec(bureaucrat);
	file.open((target + "_shrubbery").c_str());
	file << "            _-_            " << std::endl;
	file << "         /~~   ~~\\         " << std::endl;
	file << "      /~~         ~~\\      " << std::endl;
	file << "     {               }     " << std::endl;
	file << "      \\  _-     -_  /      " << std::endl;
	file << "        ~  \\\\ //  ~        " << std::endl;
	file << "     _- -   | | _- _       " << std::endl;
	file << "       _ -  | |   -_       " << std::endl;
	file << "           // \\\\           " << std::endl;
	file.close();
}
