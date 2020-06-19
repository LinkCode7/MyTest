#include "stdafx.h"
#include "NoCaseWString.h"





using namespace std;



///////////////////////////////////////////////////////////////////////
// ExceptionC++ ����2-3 �����ִ�Сд��string

///////////////////////////////////////////////////////////////////////

struct my_char_traits :public char_traits<char>
{
	static bool eq(char c1, char c2)
	{
		return toupper(c1) == toupper(c2);
	}
	static bool ne(char c1, char c2)
	{
		return toupper(c1) != toupper(c2);
	}
	static bool lt(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}
	static int compare(const char* s1, const char* s2, size_t n)
	{
		return _memicmp(s1, s2, n);
	}

	static const char* find(const char* s, int n, char a)
	{
		while (n-- > 0 && toupper(*s) != toupper(a))
		{
			++s;
		}
		return s;
	}

};

typedef basic_string<char, my_char_traits> my_string;

void testException()
{
	map<std::string, int> data = { { "a",1 },{ "CC",3 } };

	if (data.find("A") != data.end())
	{
		cout << "OK" << endl;
	}
}

//////////////////////////////////////////////////////
void exception_cpp()
{
	testException();

	// ����2-3 �����ִ�Сд��string
	string str = "a";
	if (str == "A")
		cout << "stringIs equal" << endl;

	my_string myStr = "a";
	if (myStr == "A")
		cout << "my_string Is equal" << endl;


}