#include <AForm.hpp>

AForm::AForm(void) : name("undefined form"), signGrade(1), execGrade(1), isSigned(false) {}

AForm::AForm(const std::string name, int gradeSign, int gradeExec) : name(name), signGrade(gradeSign), execGrade(gradeExec), isSigned(false)
{
	this->validateGrade(gradeSign, gradeExec);
}

AForm::AForm(const AForm &form) : name(form.name), signGrade(form.signGrade), execGrade(form.execGrade)
{
	*this = form;
}

AForm::~AForm() {}

AForm	&AForm::operator=(const AForm &form)
{
	if (this != &form)
		isSigned = form.isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const AForm &form)
{
	o << "AForm name: " << form.getName() << std::endl
	<< "AForm sign grade: " << form.getIsSigned() << std::endl
	<< "AForm execution grade: " << form.getExecGrade() << std::endl
	<< "AForm is signed: " << form.getIsSigned() << std::endl;
	return (o);
}

const std::string	AForm::getName(void) const
{
	return (name);
}

int	AForm::getSignGrade(void) const
{
	return (signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (execGrade);
}

bool	AForm::getIsSigned(void) const
{
	return (isSigned);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

void	AForm::validateExec(const Bureaucrat &bureaucrat) const
{
	if (!isSigned)
		throw FormUnsignedException();
	if (this->getExecGrade() < bureaucrat.getGrade())
		throw GradeTooLowException();
}


void	AForm::validateGrade(int validate_grade_exec, int validate_grade_sign)
{
	if (validate_grade_sign > 150 || validate_grade_exec > 150)
		throw GradeTooLowException();
	if (validate_grade_sign < 1 || validate_grade_exec < 1)
		throw GradeTooHighException();
}
