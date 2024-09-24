#include "ScalarConverter.hpp"
#include <cmath>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <iomanip>

static int string_to_int(const std::string &str) throw (ScalarConverter::ConvertionException)
{
	char *end_ptr;
	size_t pointPosition = str.find('.');
	bool containsPoint = pointPosition != std::string::npos;
	double doubleValue = std::strtod(str.c_str(), &end_ptr);
	if (!containsPoint && end_ptr != &str.c_str()[str.length()])
		throw ScalarConverter::ConvertionException();
	return static_cast<int>(doubleValue);
}

static double string_to_double(const std::string &str) throw (ScalarConverter::ConvertionException)
{
	char *end_ptr;

	double value = std::strtod(str.c_str(), &end_ptr);
	if (end_ptr == str.c_str())
		throw ScalarConverter::ConvertionException();
	return value;
}

static float string_to_float(const std::string &str) throw (ScalarConverter::ConvertionException)
{
	return static_cast<float>(string_to_double(str));
}

static char string_to_char(
	const std::string &str) throw (ScalarConverter::DisplayableConvertionException, ScalarConverter::ConvertionException
)
{
	int value = string_to_int(str);
	char cValue = static_cast<char>(value);
	if (!std::isprint(cValue))
		throw ScalarConverter::DisplayableConvertionException();
	return cValue;
}

static void format_dec(double value, bool isFloat)
{
	isFloat ? std::cout << "float: " :  std::cout << "double: ";
	if (value > 999999 && !std::isinf(value))
		std::cout << "Impossible" << std::endl;
	else if ((value - static_cast<long>(value)) == 0)
	{
		isFloat ? std::cout << static_cast<float>(value) << ".0f" : std::cout << value << ".0";
		std::cout << std::endl;
	}
	else
	{
		isFloat ? std::cout << static_cast<float>(value) << "f" : std::cout << value;
		std::cout << std::endl;
	}
}

static void print_convertions(const std::string &input)
{
	try
	{
		std::cout << " " << std::endl;
		std::cout << "char: " << string_to_char(input) << std::endl;
	}
	catch (ScalarConverter::DisplayableConvertionException)
	{
		std::cout << "Non Displayable" << std::endl;
	}
	catch (ScalarConverter::ConvertionException)
	{
		std::cout << "Impossible" << std::endl;
	}
	try
	{
		std::cout << "int: " << string_to_int(input) << std::endl;
	}
	catch (ScalarConverter::ConvertionException)
	{
		std::cout << "Impossible" << std::endl;
	}

	try
	{
		float floatResult = string_to_float(input);
		format_dec(floatResult, true);
	}
	catch (ScalarConverter::ConvertionException)
	{
		std::cout << "Impossible" << std::endl;
	}

	try
	{
		double doubleResult = string_to_double(input);
		format_dec(doubleResult, false);
	}
	catch (ScalarConverter::ConvertionException)
	{
		std::cout << "Impossible" << std::endl;
	}
}

int main()
{
	print_convertions("9999999");
	print_convertions("0.0");
	print_convertions("4.005");
	print_convertions("42.00050000");

	print_convertions("nan");
	print_convertions("-inf");
	print_convertions("+inf");
	return 1;
}
