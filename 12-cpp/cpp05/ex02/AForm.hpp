#ifndef AFORM_HPP
# define AFORM_HPP

#include <Bureaucrat.hpp>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int		signGrade;
		const int		execGrade;
		bool		isSigned;


	public:
		AForm(void);
		AForm(const std::string name, int gradeSign, int gradeExec);
		AForm(AForm const &form);
		virtual ~AForm(void);

		void	validateGrade(int validate_grade_exec, int validate_grade_sign);

		AForm &operator=(AForm const &form);

		const std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		void	validateExec(const Bureaucrat &bureaucrat) const;
		virtual void		execute(const Bureaucrat &bureaucrat) const = 0;

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

		class FormUnsignedException : public std::exception
		{
			public:
				const char* what() const throw(){
					return "Form isn`t signed";
				};
		};

};

std::ostream    &operator<<(std::ostream &out, AForm const &form);

#endif
