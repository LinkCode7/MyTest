#include "stdafx.h"
#include "suspicious.h"

#include<stdio.h>


#pragma warning(disable : 4996)

void keke();
void test20200409();

void test1024();







bool _Main()
{
	//test20200409();
	return true;
}












void test1024()
{
	time_t t;
	struct tm *p;
	t = 1540350000;
	p = gmtime(&t);
	char s[80];
	strftime(s, 80, "%Y-%m-%d %H:%M:%S::%Z", p);
	printf("%d: %s\n", (int)t, s);

	std::string str = "\u0042\u5e62\u0043\u5ea7\u4f1a\u8bae\u5ba4\u0032";
}

void test20200409()
{
	// ����һ���ַ���������дת��Сд��Сдת�ɴ�д����ͳ�����ָ���

	char ch[50];
	scanf("%s", ch);

	int iDigitCount = 0;

	int i = 0;
	while (ch[i] != '\0')
	{
		if (ch[i] >= 'a'&& ch[i] <= 'z')
		{
			ch[i] = ch[i] - 'a' + 'A'; // Сдת��д
		}
		else if (ch[i] >= 'A' && ch[i] <= 'Z')
		{
			ch[i] = ch[i] - 'A' + 'a'; // ��дתСд
		}
		else if (ch[i] >= '0' && ch[i] <= '9')
		{
			++iDigitCount;
		}

		++i;
	}

	printf("Digit:%d\n%s", iDigitCount, ch);
	//puts(ch);
}

void keke()
{
	/*char a[20];
	gets(a);

	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
	if (a[i] >= 'a'&&a[i] <= 'z')
	a[i] += 32;
	else if (a[i] >= 'A'&&a[i] <= 'Z')
	a[i] -= 32;
	puts(a);
	}*/



	/*char a[20];
	int i, digit = 0;
	gets(a);
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] >= 'a'&&a[i] <= 'z')
			a[i] = a[i] - 'a' + 'A';
		else if (a[i] >= 'A'&&a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
		else if (a[i] >= 1 && a[i] <= 9) digit++;
	}
	printf("digit=%d,", digit);
	puts(a);*/
}