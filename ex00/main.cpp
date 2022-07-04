#include <iostream>
#include <limits.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>

static void printChar(char c, double d)
{
	std::cout << "char: ";
	if (d < 0 || d > CHAR_MAX || std::isnan(d))
		std::cout << "impossible";
	else if (c < 32 && c >= 0)
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

static void printInt(int i, double d)
{
	std::cout << "int: ";
	if (d > INT_MAX || d < INT_MIN || std::isnan(d))
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;
}

static void printFloat(float f)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double d)
{
	std::cout << "double: " << d << std::endl;
}

static bool isChar(char *pEnd, char *arg)
{
	if (pEnd == arg && std::char_traits<char>::length(arg) == 1)
		return true;
	return false;
}

static bool hasString(char *pEnd)
{
	if (((pEnd[0] && pEnd[0] != 'f') || std::char_traits<char>::length(pEnd) > 1))
		return true;
	return false;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}

	char *pEnd;
	double	d = std::strtod(argv[1], &pEnd);

	if (isChar(pEnd, argv[1]))
		d = static_cast<int>(argv[1][0]);
	else if (hasString(pEnd))
		d = static_cast<double>(NAN);

	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	printChar(c, d);
	printInt(i, d);
	printFloat(f);
	printDouble(d);
	return 0;
}
