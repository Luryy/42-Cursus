#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(void) : name("undefined bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int newGrade) : name(name)
{
	this->validateGrade(newGrade);
	grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
		grade = bureaucrat.grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}

const std::string	Bureaucrat::getName(void) const
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::upgrade(void)
{
	this->validateGrade(grade - 1);
	grade--;
}

void	Bureaucrat::downgrade(void)
{
	this->validateGrade(grade + 1);
	grade++;
}

void	Bureaucrat::validateGrade(int validate_grade)
{
	if (validate_grade > 150)
		throw GradeTooLowException();
	if (validate_grade < 1)
		throw GradeTooHighException();
}
