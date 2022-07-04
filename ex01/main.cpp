#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl << std::endl;

	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	std::cout << std::endl << std::endl;

	for(int k = 0; k < 5; k++)
	{
		dog->printIdea(k);
		cat->printIdea(k);
	}

	std::cout << std::endl << std::endl;

	Dog dogCopy;

	for(int k = 0; k < 5; k++)
	{
		dog->printIdea(k);
		dogCopy.printIdea(k);
	}

	std::cout << std::endl << std::endl;

	dogCopy = *dog;

	for(int k = 0; k < 5; k++)
	{
		dog->printIdea(k);
		dogCopy.printIdea(k);
	}

	std::cout << std::endl << std::endl;

	delete dog;

	for(int k = 0; k < 5; k++)
		dogCopy.printIdea(k);

	std::cout << std::endl << std::endl;

	const Dog* dogAssing = new Dog(dogCopy);
	const Dog* dogAssing2 = new Dog(*dogAssing);

	for(int k = 0; k < 5; k++)
	{
		dogCopy.printIdea(k);
		dogAssing->printIdea(k);
		dogAssing2->printIdea(k);
	}

	delete dogAssing;

	std::cout << std::endl << std::endl;

	for(int k = 0; k < 5; k++)
	{
		dogCopy.printIdea(k);
		dogAssing2->printIdea(k);
	}

	delete dogAssing2;
	delete cat;
	return 0;
}
