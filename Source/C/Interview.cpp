#include "stdafx.h"
using namespace std;




// �ַ�������
char* reverse(char* p)
{
	int size = strlen(p);
	for (int i = 0; i < size/2; ++i)
	{
		char temp = *(p + i);
		*(p + i) = *(p + size - i - 1);
		*(p + size - i - 1) = temp;
	}
	return p;
}
//void reverseString(char p[])
//{
//	int length = strlen(p);
//	for (int i = 0; i < length / 2; i++)
//	{
//		char tmp = p[i];
//		p[i] = p[length - 1 - i]; //zh: error
//		p[length - 1 - i] = tmp;
//	}
//}



class EmptyClass {};
class A
{
	int a;
	char c;
};
class B
{
	int a;
	char c;
	int aa;
};
class B2
{
	int a;
	char c;
	char cc;
};
void test_byte()
{
	cout << endl;
	// ������ͬ�Ķ��󣬱����в�ͬ�ĵ�ַ��������������һ����СΪ0���ڴ棬��ַ����ͬ��
	cout << sizeof(EmptyClass) << endl; // 1

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl; // 4 + 4 + 4
	cout << sizeof(B2) << endl; // 4 + 4���ڴ����
	
}

void test_char_point()
{
	char* ch1 = "abc";
	char ch2[] = "abc";

	char* p1 = "abc";
	char p2[] = "abc";
	const char* p3 = "abc";
	char* const p4 = "abc";
	const char* const p5 = "abc";

	system("cls");
	// ��Ĭ��int���������==�жϵ��ǵ�ַ�Ƿ���ͬ
	cout << boolalpha << (ch1 == p1) << endl; // 1,true
	cout << (ch1 == p2) << endl; // 0
	cout << (ch1 == p3) << endl; // 1
	cout << (ch1 == p4) << endl; // 1
	cout << (ch1 == p5) << endl; // 1

	cout << (ch2 == p1) << endl; // 0
	cout << (ch2 == p2) << endl; // 0
	cout << (ch2 == p3) << endl; // 0
	cout << (ch2 == p4) << endl; // 0
	cout << (ch2 == p5) << endl; // 0
}

/////////////////////////////////////////////////////////////////////////////

void interview()
{
	// 1.�ַ�������
	char p[] = "abcd";
	//char* p2 = _strrev(p); //zh: char* p = "abcd";  Error
	char* pResult = reverse(p);

	// 2.sizeof �� strlen
	test_byte(); // C++

	// 3.
	test_char_point();

}