#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("undefined")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyForm) : target(robotomyForm.target)
{
	*this = robotomyForm;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyForm)
{
	(void)robotomyForm;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	int	robotomized;

	this->AForm::validateExec(bureaucrat);
	std::cout << "*rashrahstash* ";
	std::srand((unsigned int)time(NULL));
	robotomized = rand() % 2;
	if (robotomized)
		std::cout << target << " was robotomized" << std::endl;
	else
		std::cout << target << " was not robotomized" << std::endl;
}
