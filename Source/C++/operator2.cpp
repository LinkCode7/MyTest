#include "stdafx.h"


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


void testOperator2()
{
	std::string strResult = read();
	long result = read();
	bool isTrue = read();
}
