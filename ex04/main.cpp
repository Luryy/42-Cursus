#include <iostream>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Error: arguments should be <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string	filename = argv[1];
	std::ifstream	fileread(filename.c_str());

	if (!fileread.is_open())
	{
		std::cout << "Error: file " << filename << " can't be opened" << std::endl;
		return 1;
	}

	std::stringstream	buffer;
	buffer << fileread.rdbuf();
	if (!buffer)
		std::cout << "Error: something was wrong when reading file" << std::endl;
	fileread.close();
	std::string	stringbuffer = buffer.str();

	filename.append(".replace");
	std::ofstream	filewrite(filename.c_str());
	if (!filewrite.is_open())
	{
		std::cout << "Error: file " << filename << " can't be created" << std::endl;
		return 1;
	}

	std::string	filecontent;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::size_t	found = stringbuffer.find(s1);

	while (found != std::string::npos) {
		filecontent.append(stringbuffer.substr(0, found));
		filecontent.append(s2);
		stringbuffer = stringbuffer.substr(found + s1.size(), stringbuffer.size());
		found = stringbuffer.find(s1);
	}
	filecontent.append(stringbuffer);
	filewrite << filecontent;
	filewrite.close();

	return 0;
}
