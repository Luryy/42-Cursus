#include <Array.hpp>

#include <ctime>
#include <cstdlib>

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

int my_tests( void ) {
	Array<int> my_array(20);
	Array<int> empty_array;

	std::cout << std::endl << std::endl;

	std::cout << "My array size: " << my_array.size() << std::endl;
	std::cout << "Empty array size: " << empty_array.size() << std::endl << std::endl;

	std::cout << "Population array:" << std::endl;
    srand(time(NULL));
	for (int i = 0; i < 20; i++)
    {
		const int value = rand();
		my_array[i] = value;
		std::cout << "my_array[" << i << "] = " << my_array[i] << std::endl;
    }



	{
		std::cout << "Testing assignments" << std::endl;
		Array<int> scope_array_equal = my_array;
        Array<int> scope_array_constructor(scope_array_equal);

		std::cout << "My scope_array_equal size: " << scope_array_equal.size() << std::endl;
		std::cout << "My scope_array_constructor size: " << scope_array_constructor.size() << std::endl;
		std::cout << "my_array[10] = " << my_array[10] << std::endl;
		std::cout << "scope_array_equal[10] = " << scope_array_equal[10] << std::endl;
		std::cout << "scope_array_constructor[10] = " << scope_array_constructor[10] << std::endl;

    }

	std::cout << "Deep copy prove:" << std::endl;
	std::cout << "my_array[10] = " << my_array[10] << std::endl  << std::endl;


	try {
		std::cout << "Try to access unexistent index 100:" << std::endl;
		my_array[100];
	} catch(const std::exception &e) {
		std::cout << "Catched error at access unexistent index:" << std::endl;
		std::cerr << "Inexistent index access" << std::endl;
	}

	try {
		std::cout << "Try to access unexistent index -1:" << std::endl;
		my_array[-1];
	} catch(const std::exception &e) {
		std::cout << "Catched error at access unexistent index:" << std::endl;
		std::cerr << "Inexistent index access" << std::endl;
	}

	return 0;
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

	my_tests();
    return 0;
}

