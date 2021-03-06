#include <iostream>
#include <cstdlib>
#include <assert.h>

/*

大家好，我将开始一个讲c++编程的系列
讲解c++中，容易让人困惑的一些知识点




这是第一讲，拷贝构造，拷贝赋值

*/


/*

steps:
1. Hello with v, Hello, ~Hello, sayHello

2. run main, copy construct
4. copy assign

5. move construct
6. move assign

keypoints:
* construct == create new instance, assign == `=`
* move with caution
*/

class Hello
{
public:
	Hello()
	{
		std::cout
			<< "Construct"
			<< std::endl;
		this->v = (int *)malloc(sizeof(int));
		*this->v = 10;
	}

	Hello(const Hello &other)
	{
		std::cout
			<< "Copy Construct "
			<< std::endl;

		assert(this->v == nullptr);
		this->v = (int *)malloc(sizeof(int));
		*(this->v) = *(other.v) + 100;
	}

	Hello(Hello &&other)
	{
		std::cout
			<< "Move Construct "
			<< std::endl;

		assert(this->v == nullptr);
		this->v = other.v;
		other.v = nullptr;
	}

	~Hello()
	{
		if (!this->v)
			return;
		std::cout
			<< "Free "
			<< this->v
			<< std::endl;
		free(this->v);
	}

	Hello &operator=(const Hello &other)
	{

		std::cout
			<< "Copy Assign "
			<< this->v
			<< " "
			<< other.v
			<< std::endl;

		*(this->v) = *(other.v);
		return *this;
	}

	Hello &operator=(Hello &&other)
	{
		std::cout
			<< "Move Assign "
			<< std::endl;

		if (this->v)
		{
			std::cout
				<< "Free "
				<< this->v
				<< " Move "
				<< other.v
				<< std::endl;
			free(this->v);
		}
		this->v = other.v;
		other.v = nullptr;
		return *this;
	}

	void sayHello()
	{
		std::cout
			<< "Hello from "
			<< this->v
			<< " "
			<< *(this->v)
			<< std::endl;
	}

private:
	int *v;
};

int main()
{

	{
		std::cout
			<< "====== copy construct ========="
			<< std::endl;
		Hello h;
		h.sayHello();

		// copy construct
		Hello h1 = h;
		h1.sayHello();
		Hello h2(h);
		h2.sayHello();
		Hello h3{h};
		h3.sayHello();
	}

	// copy assign
	{
		std::cout
			<< "====== copy assign ========="
			<< std::endl;

		Hello h;
		h.sayHello();
		Hello h1;
		Hello h2;
		h2 = h1 = h;
		h1.sayHello();
	}

	// move construct
	{
		std::cout
			<< "====== move construct ========="
			<< std::endl;

		Hello h;
		h.sayHello();
		Hello h1 = std::move(h);
		h1.sayHello();
		Hello h2(std::move(h1));
		h2.sayHello();
		Hello h3{std::move(h2)};
		h3.sayHello();
	}

	// move assign
	{
		std::cout
			<< "====== move assign ========="
			<< std::endl;
		Hello h, h2, h3;
		h = std::move(h2 = std::move(h3));
	}

	return 0;
}