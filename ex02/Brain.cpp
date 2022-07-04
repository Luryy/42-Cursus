#include <Brain.hpp>

static std::string get_random_idea(const int len) {
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[std::rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

Brain::Brain(void)
{
	std::cout << "Brain default contructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = get_random_idea(10);
};

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
};

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy contructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
};

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &brain)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	return (*this);
};

std::string Brain::getIdea(int i) const
{
	return ideas[i];
};
