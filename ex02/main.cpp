#include "Base.hpp"
#include "ctime"
#include "iostream"
#include "cstdlib"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base* generate()
{
	srand(time(0));
	int random = (rand() % 3);
	Base *base;
	if (random == 0)
		base = new A();
	else if (random == 1)
		base = new B();
	else
		base = new C();
	return base;
}

static void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "Generated Class is an instance of A " << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "Generated Class is an instance of B " << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "Generated Class is an instance of C " << std::endl;
}

static void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Generated Class is an instance of A " << std::endl;
	}
	catch (std::exception ignored)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "Generated Class is an instance of B " << std::endl;
		}
		catch (std::exception ignored)
		{
			try
			{
				C c = dynamic_cast<C&>(p);
				std::cout << "Generated Class is an instance of C " << std::endl;
			}
			catch (std::exception e)
			{
				std::cout << "Unable to find the class " << std::endl;
			}
		}
	}
}

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 1;
}
