#include "stdafx.h"
#include "main.h"



#include <stdio.h>
#pragma warning(disable : 4996)

#include <bitset>
using namespace std;


void keke2();
void keke3();



// ����ÿ���ֲ��Գ���ķ����
int main(int argc, char*argv[]) // �����в������ڲ���program_options
{
	//keke2();

	_Main();
	
	//boost_program_options(argc, argv);

	//BcJs();

	// LintCode
	testt();
	serialize(1);

	//
	TestString();

	// STL
	List_Iterator();
	testAdvance();
	testTemplateBaseClass();
	TestPairCompare();
	TestList();
	system("cls");
	LFUCacheEntry();

	// C++
	system("cls");
	testIterator();
	testSmartPoint(); // Ptr
	TestSmartPoint20200811();
	testBase();
	testOperator1();
	testOperator2();
	readRegister();
	TestCppInherit();
	TestCppClass();

	testCpp11();

	exception_cpp();

	testMath();

	//testFunctionObject();
	testDelete();

	// C++11
	testWidget();
	stl_bind();
	stl_move();

	// C++ Mechanism
	system("cls");
	test_vtbl();



	system("cls");
	std_filesystem();

	// Design pattern
	system("cls");
	testDemeter();
	system("cls");
	testSinglePattern();
	testTemplateMethod();
	testVirtual();

	// c
	system("cls");
	testPoint();
	system("cls");
	interview();
	system("cls");
	oneWayLinkedList();
	system("cls");
	size_of();

	// sort
	testSort();

	// boost
	boost_string();
	boost_split();
	boost_tuple();
	system("cls");
	boost_variant();
	system("cls");
	boost_property_tree();
	system("cls");
	boost_graph();
	
	
	system("cls");
	regex_match();
	regex_replace();
	system("cls");
	std_regex();

	system("cls");
	boost_filesystem();
	system("cls");
	FileSystemSearchDirectory();

	system("cls");
	boost_random();

	system("cls");
	boost_date_time();


	// 
	system("cls");
	DoMemoryUtil();

	// 
	system("cls");
	TestSQLite();

    return 0;
}

void show()
{
	std::bitset<68> bits(1);
	std::cout << bits.to_string() << std::endl;
}





int add();
int sub();
int mul();
int div();

void keke2()
{
	int i, a, f, m = 0, n = 0;
	char y = 'y';
	printf("\n\t\t\t��ӭʹ��Сѧ��������ϵͳ��\n\n");
	printf("\t������ϵͳ���������У��ӷ��⡢�����⡢�˷���ͳ�����\n");
	printf("\n\t\t���β�����Ϊ10�⣬�밴�س�����ʼ���⣡");
	getchar();
	srand(time(0));
	for (i = 1; i <= 10; i++)
	{
		a = rand() % 4 + 1;
		switch (a)
		{
		case 1:
			printf("\t\n��%2d��:�ӷ��⣡\n", i);
			f = add();
			break;
		case 2:
			printf("\t\n��%2d��:�����⣡\n", i);
			f = sub();
			break;
		case 3:
			printf("\t\n��%2d��:�˷��⣡\n", i);
			f = mul();
			break;
		case 4:
			printf("\t\n��%2d��:�����⣡\n", i);
			f = div();
			break;
		}

		if (f == 1)
		{
			printf("�����ˣ��ٽ�������");
			m++;
		}
		else
		{
			printf("�����ˣ��ӱ�Ŭ����");
			n++;
		}
	}
	printf("\n\n���β��Խ������㹲������%d���������%d���������%d��\n", i - 1, m, n);
	printf("��ĳɼ�Ϊ��%d�֣���ӭ�´��ٴβ��ԣ���\n", m * 10);
}
int add()
{
	int a, b, r;
	a = rand() % 30;
	b = rand() % 30;
	printf("%d+%d=", a, b);
	scanf("%d", &r);
	if (r == a + b) return(1);
	else return(0);
}
int sub()
{
	int a, b, r;
	a = rand() % 30;
	b = rand() % 30;
	if (a>b)
	{
		printf("%d-%d=", a, b);
		scanf("%d", &r);
		if (a - b == r) return(1);
		else return(0);
	}
	else sub();

	return -1; //
}
int mul()
{
	int a, b, r;
	a = rand() % 30;
	b = rand() % 30;
	printf("%d*%d=", a, b);
	scanf("%d", &r);
	if (a*b == r) return(1);
	else return(0);
}
int div()
{
	int r = 0;
	int a = rand() % 30;
	int b = rand() % 30;
	
	if (b == 0)
	{
		return div();
	}

	if (a % b == 0)
	{
		printf("%d/%d=", a, b);
		scanf("%d", &r);
		if (a / b == r) return(1);
		else return(0);
	}
	else
	{
		return div();
	}
}



#include <stdio.h>
#include <stdlib.h>

struct Student
{
	char name[100];
	char class_name[100];
	char grade[100];
};

void keke3()
{
	// д��ɼ�
	// wb,a
	char file_path[] = "C:\\Users\\siyuj\\Desktop\\data.txt";
	FILE *fp = fopen(file_path, "a");
	if (fp == NULL)
	{
		exit(1);
	}

	Student student;
	printf("����������ѧ�����������༶��������\n");
	scanf("%s%s%s", &student.name, &student.class_name, &student.grade);

	//fputs("���� 3�� 80��", fp);

	// ��׷�ӵķ�ʽд��һ���˵İ༶���ɼ�
	fprintf(fp, "%s\t%s\t%s\n", student.name, student.class_name, student.grade);
	fclose(fp);




	// �����ɼ�
	//rewind(fp);
	fp = fopen(file_path, "r");

	Student s2;
	while (fscanf(fp, "%s\t%s\t%s\n", s2.name, s2.class_name, s2.grade) != -1)
	{
		// ����õ��ľ���һ��������
	}

	fclose(fp);
}