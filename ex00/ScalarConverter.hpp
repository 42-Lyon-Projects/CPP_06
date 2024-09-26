#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &other);
		virtual ~ScalarConverter();

	public:
		static void convert (const std::string &input);
};



#endif
