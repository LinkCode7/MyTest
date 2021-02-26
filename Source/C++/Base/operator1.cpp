#include "stdafx.h"
#include "operator1.h"

class read
{
public:

	read(){}

	operator std::string()
	{
		std::string strVal("std::string Case");

		return strVal;
	}
	operator long()
	{
		long valuel(100);

		return valuel;
	}
	operator bool()
	{
		bool isNotEmpty(false);

		return isNotEmpty;
	}

	operator int()
	{
		return 10;
	}
};


void testOperator1()
{
	std::string strResult = read();
	long result = read();
	bool isTrue = read();

	testCppOperator();
}

void testCppOperator()
{
	MyObject object1;
	MyObject object2(10);
	MyObject object3(3.14);

	MyObject object4(object1);
	MyObject object5 = object2;
	object5 = object1; // operator=
	object5 = 0.5; // MyObject(double value),operator=
}