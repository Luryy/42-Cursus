#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <AForm.hpp>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &form);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);

		void		execute(const Bureaucrat &bureaucrat) const;
};

#endif
