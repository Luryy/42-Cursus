#include <easyfind.hpp>

#include <vector>
#include <list>

int main()
{
    std::vector<int>    vector_int;
    std::list<int>      list_int;

    for (int d = 0; d < 21; d++)
    {
        vector_int.push_back(d);
        list_int.push_back(d);
    }

    try
    {
        easyfind(vector_int, 1);
        std::cout << "found 1" << std::endl;
        easyfind(vector_int, 2);
        std::cout << "found 2" << std::endl;
        easyfind(vector_int, -1);
        std::cout << "found -1" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error when easyfiding" << std::endl;
    }

    try
    {
        easyfind(list_int, 0);
        std::cout << "found 0" << std::endl;
        easyfind(list_int, 20);
        std::cout << "found 20" << std::endl;
        easyfind(list_int, -1);
        std::cout << "found -1" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error when easyfiding" << std::endl;
    }
}
