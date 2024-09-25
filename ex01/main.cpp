#include "ScalarConverter.hpp"

static bool isNum(const std::string &line)
{
	char* errorPtr;
	std::strtod(line.c_str(), &errorPtr);
	return errorPtr != line.c_str();
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::cout << isNum(argv[1]) << std::endl;
	if (!isNum(argv[1]))
		return 1;
	ScalarConverter::convert(argv[1]);
	return 0;
}