#include <iter.hpp>

int main( void ) {
	char str[] = "Only a string";
    std::string strArray[] = {"Array", "of", "strings" };
	const char	*constStrArray[4] = {"Const", "Array", "of", "strings"};
    int integers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    iter(str, 13, print);
    iter(strArray, 3, print);
    iter(constStrArray, 4, print);
    iter(integers, 10, print);
	return 0;
}
