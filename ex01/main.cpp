#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data *human = new Data();
	std::cout << human->getFirstName() << " " << human->getLastName() << " " << human->getProfession() << std::endl;
	uintptr_t ptr = Serializer::serialize(human);

	std::cout << ptr << std::endl;

	Data *human2 = Serializer::deserialize(ptr);
	std::cout << human2->getFirstName() << " " << human2->getLastName() << " " << human2->getProfession() << std::endl;

	delete human2;
}
