#include <Bureaucrat.hpp>

int main(void)
{
	Bureaucrat bureaucrat("Lury", 10);

	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat.getName() << std::endl;


	bureaucrat.downgrade();
	std::cout << bureaucrat.getGrade() << std::endl;

	bureaucrat.upgrade();
	std::cout << bureaucrat.getGrade() << std::endl;

	for (int i = 0; i < 9; i++)
		bureaucrat.upgrade();
	std::cout << bureaucrat.getGrade() << std::endl;

	try {
		bureaucrat.upgrade();
	}
	catch (std::exception & e) {
		std::cerr << "Catched error when upgrading: " << e.what() << std::endl;
	}

	Bureaucrat bureaucratCopy(bureaucrat);


	for (int i = 0; i < 149; i++)
		bureaucratCopy.downgrade();
	std::cout << bureaucratCopy.getGrade() << std::endl;

	try {
		bureaucratCopy.downgrade();
	}
	catch (std::exception & e) {
		std::cerr << "Catched error when downgrading: " << e.what() << std::endl;
	}

	bureaucrat.downgrade();
	std::cout << bureaucrat.getGrade() << std::endl;

	try {
		Bureaucrat bureaucratLow("Lury", 0);
	}
	catch (std::exception & e) {
		std::cerr << "Catched error instanciate: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucratHigh("Lury", 151);
	}
	catch (std::exception & e) {
		std::cerr << "Catched error instanciate: " << e.what() << std::endl;
	}

	return 0;
}
