#ifndef FORM_HPP
# define FORM_HPP

#include <Bureaucrat.hpp>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int		signGrade;
		const int		execGrade;
		bool		isSigned;

		void	validateGrade(int validate_grade_exec, int validate_grade_sign);

	public:
		Form(void);
		Form(const std::string name, int gradeSign, int gradeExec);
		Form(Form const &form);
		~Form(void);

		Form &operator=(Form const &form);

		const std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;
		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw(){
					return "Grade is too hight";
				};
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw(){
					return "Grade is too low";
				};
		};

};

std::ostream    &operator<<(std::ostream &out, Form const &form);

#endif
