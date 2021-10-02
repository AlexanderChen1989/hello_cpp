#include <iostream>
#include "lib.h"

void printObj(int obj[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << obj[i] << " ";

	std::cout << std::endl;
}

// 引用调用
void printHello(Hello &h)
{
	std::cout << &(h.v) << std::endl;
}

// 类似新建，Copy
void sayHello(Hello h)
{
	h.sayHello();
}

int main() {
	Hello h;

	printHello(h);
	sayHello(h);
}

int test()
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
