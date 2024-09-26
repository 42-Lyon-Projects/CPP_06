#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

class Data {

	private:
		std::string first_name;
		std::string last_name;
		std::string profession;
	public:
		explicit Data(const std::string &first_name = "John", const std::string &last_name = "Lennon", const std::string &profession = "Musician");
		Data(const Data &other);
		Data&operator=(const Data &other);
		~Data();
	public:
		std::string getFirstName();
		std::string getLastName();
		std::string getProfession();
};

#endif //HUMAN_HPP
