#include "Data.hpp"
#include <iostream>

Data::Data(const std::string &first_name, const std::string &last_name, const std::string &profession)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->profession = profession;
	std::cout << "Human Constructor Called" << std::endl;
}

Data::Data(const Data &other)
{
	*this = other;
}

Data &Data::operator=(const Data &other)
{
	if (&other == this)
		return *this;
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->profession = other.profession;
	return *this;
}

Data::~Data()
{
	std::cout << "Human Destructor Called" << std::endl;
}


std::string Data::getFirstName()
{
	return this->first_name;
}

std::string Data::getLastName()
{
	return this->last_name;
}

std::string Data::getProfession()
{
	return this->profession;
}




