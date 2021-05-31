#include "stdafx.h"
#include "sizeof.h"


using namespace std;


void size_of()
{
	using namespace TestSizeOf;

	VirtualFunctionTest::Test();

	ByteAlignmentTest::Test();

	Char_CharArray();

	VPtrTest::Test();


	TestSizeOf::Unexpected();
}


void TestSizeOf::VirtualFunctionTest::Test()
{
	A aValue;
	B bValue;
	C cValue;

	int iAsize = sizeof(aValue);
	int iBsize = sizeof(bValue);
	int iCsize = sizeof(cValue);

	int iCount = iAsize + iBsize;
}

void TestSizeOf::ByteAlignmentTest::Test()
{
	test1 t1;

	cout << "test1 = " << sizeof(test1) << endl;
	cout << "test2 = " << sizeof(test2) << endl;
	cout << "test3 = " << sizeof(test3) << endl;
	cout << "test4 = " << sizeof(test4) << endl;
	cout << "test5 = " << sizeof(test5) << endl;
}

void Char_CharArray()
{
	string str = "hello";
	char* ch1 = "hello";
	char ch2[] = "hello";
	char ch3[100];
	char ch4[10] = "hello";
	

	char* pChar = (char*)malloc(100);
	void* pVoid = (void*)malloc(100);

	cout << endl << "Char_CharArray" << endl;
	cout << sizeof(str) << endl;

	// ��ָ�룬���ֽ�
	cout << sizeof(ch1) << endl;
	// �����飬������һ���ַ������ַ���ĩβ������һ�������������Գ���Ϊ5 + 1 = 6
	cout << sizeof(ch2) << endl;
	// �����飬�ڱ����ڷ�����100*1 = 100Byte
	cout << sizeof(ch3) << endl;

	cout << sizeof(ch4) << endl; // 10

	cout << sizeof(pChar) << endl; // 4
	cout << sizeof(pVoid) << endl;  // 4

	free(pChar);
	free(pVoid);


	// int
	int a = 100;
	int* pA = &a;
	int pA2[3] = {1, 2};

	cout << endl << endl;
	cout << sizeof(pA) << endl; // 4
	cout << sizeof(pA2) << endl; // 4*3=12
}

void TestSizeOf::VPtrTest::TestNotAboutSizeOf()
{
	return;

	NoVirtual* pBase = new HaveVirtual();

	pBase->fun();

	HaveVirtual* pSubClass = static_cast<HaveVirtual*>(pBase);
	pSubClass->fun();

	delete pBase; //zh,???
}

void TestSizeOf::VPtrTest::Test()
{
	cout << endl << "-------------------------------------" << endl;
	cout << "sizeof(NoVirtual)" << sizeof(NoVirtual) << endl;
	cout << "sizeof(HaveVirtual)" << sizeof(HaveVirtual) << endl << endl;

	NoVirtual nv1, nv2;
	HaveVirtual hv1, hv2;

	unsigned long* p = nullptr;
	p = reinterpret_cast<unsigned long*>(&nv1);
	cout << "first 4bytes of nv1:" << p[0] << endl;

	p = reinterpret_cast<unsigned long*>(&nv2);
	cout << "first 4bytes of nv2:" << p[0] << endl << endl;


	// VS2015:ǰ�ĸ��ֽڵĵ�ַ����ͬ�ģ�vptr������class�ڴ������ͷ��
	p = reinterpret_cast<unsigned long*>(&hv1);
	cout << "first 4bytes of hv1: 0x" << hex << p[0] << endl;

	p = reinterpret_cast<unsigned long*>(&hv2);
	cout << "first 4bytes of hv2: 0x" << hex << p[0] << endl;


	// 
	TestNotAboutSizeOf();
}

void TestSizeOf::Unexpected()
{
	system("cls");
	cout << sizeof(void*) << endl;
	cout << sizeof(int) << endl;

	cout << sizeof(nullptr) << endl;
	cout << sizeof(NULL) << endl;
	cout << sizeof(0) << endl;
}