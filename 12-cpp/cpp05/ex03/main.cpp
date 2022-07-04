#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <Intern.hpp>

int main(void)
{
	Intern intern;

	Bureaucrat god("God", 1);
	Bureaucrat ceo("CEO", 10);
	Bureaucrat chief("Chief", 50);
	Bureaucrat worker("Worker", 150);

	AForm *shrubber = intern.makeForm("Shrubbery Creation", "home");
	AForm *robotomy = intern.makeForm("Robotomy Request", "seller");
	AForm *presidential = intern.makeForm("Presidential Pardon", "killer");
	intern.makeForm("Unexistent Pardon", "killer");

	std::cout << std::endl << "ShrubberyCreationForm" << std::endl;
	worker.executeForm(*shrubber);
	god.signForm(*shrubber);
	worker.executeForm(*shrubber);
	chief.executeForm(*shrubber);

	std::cout << std::endl << "RobotomyRequestForm" << std::endl;
	chief.executeForm(*robotomy);
	ceo.signForm(*robotomy);
	chief.executeForm(*robotomy);
	ceo.executeForm(*robotomy);

	std::cout << std::endl << "PresidentialPardonForm" << std::endl;
	ceo.executeForm(*presidential);
	ceo.signForm(*presidential);
	ceo.executeForm(*presidential);
	god.executeForm(*presidential);
	god.executeForm(*shrubber);

	delete shrubber;
	delete robotomy;
	delete presidential;
	return 0;
}
