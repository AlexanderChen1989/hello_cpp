#include "lib.h"
#include <iostream>

Hello::Hello()
{
	this->v = 10;
}

Hello::Hello(const Hello &other)
{
	std::cout << "Copy" << std::endl;
	this->v = other.v + 100;
}

Hello &Hello::operator=(const Hello &other)
{
	std::cout << "Assign" << std::endl;
	Hello h;
	h.v = other.v + 1000;
	return h;
}

void Hello::sayHello()
{
	std::cout << "Hello from " << this->v << std::endl;
}

Hello::~Hello()
{
	std::cout << "Drop Hello" << std::endl;
}