#include <iostream>
#include <cstdlib>
#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base *generate(void)
{
	switch (rand() % 3)
    {
        case 0:
            std::cout << "Generate type A" << std::endl;
            return (new A());
        case 1:
            std::cout << "Generate type B" << std::endl;
            return (new B());
        case 2:
            std::cout << "Generate type C" << std::endl;
            return (new C());
    }
    return (0);
};

void identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Identify pointer: A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Identify pointer: B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Identify pointer: C" << std::endl;
	else
		std::cout << "Undefined type" << std::endl;

};

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Identify reference: A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Identify reference: B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Identify reference: C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
};

int	main(void)
{
	Base	*p;
	srand(time(NULL));

	for (int i = 0; i < 3; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
		delete p;
	}

	return (0);
}
