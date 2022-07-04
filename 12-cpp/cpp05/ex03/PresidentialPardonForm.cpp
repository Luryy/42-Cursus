#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), target("undefined")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pardonForm) : target(pardonForm.target)
{
	*this = pardonForm;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &pardonForm)
{
	(void)pardonForm;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	this->AForm::validateExec(bureaucrat);
	std::cout << target << " was forgiven by Zafor Beeblebrox" << std::endl;
}
