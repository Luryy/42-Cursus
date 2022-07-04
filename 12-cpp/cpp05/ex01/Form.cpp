#include <Form.hpp>

Form::Form(void) : name("undefined form"), signGrade(1), execGrade(1), isSigned(false) {}

Form::Form(const std::string name, int gradeSign, int gradeExec) : name(name), signGrade(gradeSign), execGrade(gradeExec), isSigned(false)
{
	this->validateGrade(gradeSign, gradeExec);
}

Form::Form(const Form &form) : name(form.name), signGrade(form.signGrade), execGrade(form.execGrade)
{
	*this = form;
}

Form::~Form() {}

Form	&Form::operator=(const Form &form)
{
	if (this != &form)
		isSigned = form.isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	o << "Form name: " << form.getName() << std::endl
	<< "Form sign grade: " << form.getSignGrade() << std::endl
	<< "Form execution grade: " << form.getExecGrade() << std::endl
	<< "Form is signed: " << form.getIsSigned() << std::endl;
	return (o);
}

const std::string	Form::getName(void) const
{
	return (name);
}

int	Form::getSignGrade(void) const
{
	return (signGrade);
}

int	Form::getExecGrade(void) const
{
	return (execGrade);
}

bool	Form::getIsSigned(void) const
{
	return (isSigned);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}


void	Form::validateGrade(int validate_grade_exec, int validate_grade_sign)
{
	if (validate_grade_sign > 150 || validate_grade_exec > 150)
		throw GradeTooLowException();
	if (validate_grade_sign < 1 || validate_grade_exec < 1)
		throw GradeTooHighException();
}
