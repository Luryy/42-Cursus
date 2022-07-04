#ifndef INTERN_HPP
# define INTERN_HPP

#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &intern);
		virtual ~Intern();

		Intern	&operator=(const Intern &intern);

		AForm	*makeForm(const std::string formName, const std::string target) const;
};

#endif
