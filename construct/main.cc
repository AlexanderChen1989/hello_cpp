#include <iostream>
#include <cstdlib>
#include <assert.h>

// construct ->
// copy construct ->
// move construct
// copy assign
// move assign

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

	~Hello()
	{
		std::cout
			<< "Drop Hello "
			<< *(this->v)
			<< std::endl;
		free(this->v);
	}

	void sayHello()
	{
		std::cout
			<< "Hello from "
			<< *(this->v)
			<< std::endl;
	}

private:
	int *v;
};

int main()
{
	Hello h;
	h.sayHello();

	// copy construct
	Hello h1 = h;
	h1.sayHello();
	Hello h2(h);
	h2.sayHello();
	Hello h3{h};
	h3.sayHello();

	// copy assign
	

	return 0;
}