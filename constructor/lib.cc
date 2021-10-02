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

Hello::Hello(const Hello &&other)
{
	std::cout << "Move Construct" << std::endl;
	*this = other;
}

Hello &Hello::operator=(const Hello &other)
{
	std::cout << "Assign" << std::endl;
	Hello h;
	h.v = other.v + 1000;
	return h;
}

Hello &Hello::operator=(const Hello &&other)
{
	std::cout << "Move Assign" << std::endl;
	*this = other;
	return *this;
}

void Hello::sayHello()
{
	std::cout << "Hello from " << this->v << std::endl;
}

Hello::~Hello()
{
	std::cout << "Drop Hello" << std::endl;
}