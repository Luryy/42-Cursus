#include <Span.hpp>

#include <vector>
#include <list>

int main()
{
	{
		std::cout << "Fill range interator with large of data:" << std::endl;
		std::vector<int> vec;
		Span my_span = Span(300000);

		for(int i = 0; i < 300000; i++)
			vec.push_back(i);
		my_span.fill(vec.begin(), vec.end());
		std::cout << my_span.shortestSpan() << std::endl;
		std::cout << my_span.longestSpan() << std::endl;
		try {
			my_span.addNumber(100);
		}
		catch(const std::exception& e) {
			std::cerr << "Catched error > Span is full" << std::endl;
		}
	}

	{
		std::cout << "Throws:" << std::endl;
		Span my_span = Span(1);
		my_span.addNumber(100);

		try {
			my_span.addNumber(1000);
		}
		catch(const std::exception& e) {
			std::cerr << "Catched error > Span is full" << std::endl;
		}
		try {
			my_span.shortestSpan();
		}
		catch(const std::exception& e) {
			std::cerr << "Catched error > Span without enough arguments" << std::endl;
		}
		try {
			my_span.longestSpan();
		}
		catch(const std::exception& e) {
			std::cerr << "Catched error > Span without enough arguments" << std::endl;
		}
	}

	{
		std::cout << "Shortest and longest:" << std::endl;
		Span my_span = Span(10);
		my_span.addNumber(100);
		my_span.addNumber(1000);
		my_span.addNumber(-1000);
		my_span.addNumber(-700);
		my_span.addNumber(-7001);
		my_span.addNumber(-701);


		std::cout << my_span.shortestSpan() << std::endl;
		std::cout << my_span.longestSpan() << std::endl;

		my_span.addNumber(9000);
		my_span.addNumber(9700);
		my_span.addNumber(1001);
		my_span.addNumber(101);

		std::cout << my_span.shortestSpan() << std::endl;
		std::cout << my_span.longestSpan() << std::endl;
	}


	std::cout << "Subject:" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
