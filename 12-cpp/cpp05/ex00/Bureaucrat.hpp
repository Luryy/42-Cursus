#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	private:
		const std::string	name;
		int			grade;

		void	validateGrade(int validate_grade);

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &bureaucrat);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &bureaucrat);

		const std::string getName() const;
		int getGrade() const;
		void upgrade();
		void downgrade();

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

std::ostream    &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
