#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

class Human {

	private:
		std::string first_name;
		std::string last_name;
		std::string profession;
	public:
		explicit Human(const std::string &first_name = "John", const std::string &last_name = "Lennon", const std::string &profession = "Musician");
		Human(const Human &other);
		Human&operator=(const Human &other);
		~Human();
	public:
		std::string getFirstName();
		std::string getLastName();
		std::string getProfession();
};

#endif //HUMAN_HPP
