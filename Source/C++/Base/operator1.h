#pragma once

void testCppOperator();

class MyObject
{
public:
	MyObject() : value_(10001) { std::cout << "MyObject()" << std::endl; }
	explicit MyObject(int value) : value_(value) { std::cout << "explicit MyObject(int value)" << std::endl; }
	MyObject(double value) : value_(value) { std::cout << "explicit MyObject(double value)" << std::endl; }

	MyObject(const MyObject& other)
	{
		std::cout << "MyObject(const MyObject& other)" << std::endl;
		value_ = other.value_;
	}

	MyObject& operator=(const MyObject& rhs)
	{
		std::cout << "MyObject& operator=(const MyObject& rhs)" << std::endl;
		if (this == &rhs) return *this;

		this->value_ = rhs.value_;
		return *this;
	}

	int value_;
};