#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Human.hpp"
#include <stdint.h>

class Serializer {

	private:
		Serializer();
		Serializer(const Serializer &other);
		virtual ~Serializer();

	public:
		static uintptr_t serialize(Human* ptr);
		static Human* deserialize(uintptr_t raw);

};


#endif
