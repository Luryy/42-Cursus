#ifndef TESTER_UTILS_HPP
# define TESTER_UTILS_HPP

template <typename T>
void	print_vector(T& vector_to_print)
{
	int i;

	std::cout << "-----------------------------------------" << std::endl;
	for (i = 0; i < (int) vector_to_print.size(); i++)
	{
		std::cout << "|" << vector_to_print[i];
	}
	std::cout << "|";
	std::cout << std::endl;
	std::cout << "size: " << vector_to_print.size();
	std::cout << "\t\t";
	std::cout << "capacity: " << vector_to_print.capacity() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
};

template <typename P>
void print_pair(P &p)
{
		std::cout << "f: " << p.first << "\t\t s: " << p.second << std::endl;
};

template <typename N>
void print_node(N &node)
{
	N *tmp;
	tmp = &node;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	std::cout << "parent:\t" << node.parent << std::endl;
	std::cout << "node:  \t" << &node << std::endl;
//	std::cout << "Content:\t"; print_pair(*(node.content));
	if (tmp->content  == NULL)
		std::cout << "Content:\t (null)\n";
	else
	{
		std::cout << "Content:\t"; print_pair(*(node.content));
	};
	std::cout << "color:\t\t" << node.color << std::endl;
	std::cout << "left:\t\t" << node.left << "\tright:\t" << node.right << std::endl;

	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
};

template<typename K,typename Val>
void print_map(ft::map<K,Val> &m)
{
	if (m.empty())
	{
		std::cout << "(empy map)\n";
		return;
	};
	typename ft::map<K,Val>::iterator i;
	i = m.begin();
	while (i != m.end())
	{
		std::cout << "(" << i->first << "," << i->second << ")\n";
		i++;
	};
	std::cout << std::endl;
};

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

template <typename T>
void	time_tracker(std::string message, T (*f)(void))
{
	clock_t ini, fin;
	double elapsed_time;

	ini = clock();

	f();

	fin = clock();
	elapsed_time = 1000 * ((double) fin - (double) ini) / (double) (CLOCKS_PER_SEC);
	std::cout << bold_on << message << " Elapsed time: " << elapsed_time << "ms" << std::endl;
};

#endif
