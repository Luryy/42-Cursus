#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <AForm.hpp>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &form);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &form);

		void		execute(const Bureaucrat &bureaucrat) const;
};

#endif
