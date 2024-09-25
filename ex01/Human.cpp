#include "Human.hpp"

#include <iostream>

Human::Human(const std::string &first_name, const std::string &last_name, const std::string &profession)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->profession = profession;
	std::cout << "Human Constructor Called" << std::endl;
}

Human::Human(const Human &other)
{
	*this = other;
}

Human &Human::operator=(const Human &other)
{
	if (&other == this)
		return *this;
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->profession = other.profession;
	return *this;
}

Human::~Human()
{
	std::cout << "Human Destructor Called" << std::endl;
}


std::string Human::getFirstName()
{
	return this->first_name;
}

std::string Human::getLastName()
{
	return this->last_name;
}

std::string Human::getProfession()
{
	return this->profession;
}




