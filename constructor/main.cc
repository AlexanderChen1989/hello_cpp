#include <iostream>
#include "lib.h"

void printObj(int obj[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << obj[i] << " ";

	std::cout << std::endl;
}

void printHello(Hello &h)
{
	std::cout << &(h.v) << std::endl;
}

void printHello2(Hello h)
{
	h.sayHello();
}

int main()
{
	// 默认
	Hello h;
	h.sayHello();

	// 新建，Copy
	Hello h2 = h;
	h2.sayHello();


	// 新建，Copy
	Hello h3(h);
	h3.sayHello();

	Hello h4;
	// 赋值，Assign
	h4 = h;
	h4.sayHello();


	return 0;
}
