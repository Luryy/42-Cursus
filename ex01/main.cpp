#include <Bureaucrat.hpp>
#include <Form.hpp>

int main(void)
{
	Bureaucrat bureaucrat("Lury", 31);
	Form form("Contract", 30, 30);

	std::cout << form << std::endl;
	bureaucrat.signForm(form);
	std::cout << "Is signed: " << form.getIsSigned() << std::endl;

	bureaucrat.upgrade();

	bureaucrat.signForm(form);
	std::cout << "Is signed: " << form.getIsSigned() << std::endl;

	try {
		Form form("Hight", 0, 0);
	} catch (std::exception & e) {
		std::cerr << "Catched error instanciate: " << e.what() << std::endl;
	}

	try {
		Form form("Low", 151, 151);
	} catch (std::exception & e) {
		std::cerr << "Catched error instanciate: " << e.what() << std::endl;
	}


	return 0;
}
