#include "stdafx.h"
#include "std_bind.h"


#include <array>
#include <functional>



using namespace std;

void stl_bind()
{
	TestReplace();
}





void TestReplace()
{
	std::array<int, 10> s{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

	std::replace(s.begin(), s.end(), 8, 88);

	for (int a : s)
	{
		std::cout << a << " ";
	}
	std::cout << '\n';

	// 将所有小于5的数替换为55
	std::replace_if(s.begin(), s.end(), std::bind(std::less<int>(), std::placeholders::_1, 5), 55);

	for (int a : s)
	{
		std::cout << a << " ";
	}
	std::cout << '\n';
}