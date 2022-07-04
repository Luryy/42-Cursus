#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &form);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &form);

		void		execute(const Bureaucrat &bureaucrat) const;
};

#endif
