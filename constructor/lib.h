#pragma once

class Hello
{
public:
	Hello();
	Hello(const Hello &other);
	Hello &operator=(const Hello &other);

	void sayHello();

	~Hello();

	int v;
};
