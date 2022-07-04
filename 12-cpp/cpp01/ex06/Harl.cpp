#include <Harl.hpp>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain()
{
	void (Harl::*methodptr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	int	level = this->level;

	switch (level)
	{
		case 0:
			(this->*(methodptr[level++]))();
			std::cout << std::endl;
		case 1:
			(this->*(methodptr[level++]))();
			std::cout << std::endl;
		case 2:
			(this->*(methodptr[level++]))();
			std::cout << std::endl;
		case 3:
			(this->*(methodptr[level]))();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

}

void Harl::setLevel(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;

	this->level = i;
	while (++i < 4)
		if (levels[i] == level)
			this->level = i;
};


void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
	<< "I cannot believe adding extra bacon costs more money." << std::endl
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
	<< "I think I deserve to have some extra bacon for free." << std::endl
	<<  "I’ve been coming for years whereas you started working here since last month." << std::endl;;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}
