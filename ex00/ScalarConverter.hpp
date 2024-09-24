#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>

class ScalarConverter {
	public:
		static void convert (const std::string &input);


	class ConvertionException: public std::exception {};
	class DisplayableConvertionException: public std::exception {};

};



#endif
