#include "nice.h"
#include <iostream>

namespace nice
{
	Nice::Nice(int c) : counter(c)
	{
		std::cout << other.get() << std::endl;
		other.reset(this);
	}

	Nice::~Nice()
	{
		other.reset(nullptr);
		std::cout << "Nice from " << counter << std::endl;
	}

	void Nice::sayHello()
	{
		std::cout << "Hello from " << counter << std::endl;
	}
}