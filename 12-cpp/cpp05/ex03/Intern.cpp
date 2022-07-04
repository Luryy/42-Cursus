#include <Intern.hpp>

Intern::Intern(void) {}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

static AForm	*makeShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentialForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string formName, const std::string target) const
{
	std::string		formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *((*formMakers[3])(const std::string)) =
		{
			&makeShrubberyForm,
			&makeRobotomyForm,
			&makePresidentialForm
		};
	std::string	formLowerName;
	AForm			*form = NULL;

	for (unsigned int i = 0; i < formName.size(); i++)
		formLowerName += tolower(formName[i]);

	for (unsigned int i = 0; i < 3; i++)
		if (formLowerName == formNames[i])
		{
			form = (*(formMakers[i]))(target);
			break;
		};

	if (form)
		std::cout << "Intern creates " << form->getName() << std::endl;
	else
		std::cout << "Intern can`t create " << formName << std::endl;
	return (form);
}
