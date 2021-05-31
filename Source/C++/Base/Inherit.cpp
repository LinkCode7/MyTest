#include "stdafx.h"
#include "Inherit.h"

void TestAbstractVirtualImpl();
void TestMemsetVirtualClass();


void TestCppInherit()
{
	//LineData* pLine = new LineData;
	//pLine->m_i = 1;

	TestAbstractVirtualImpl();

	TestMemsetVirtualClass();
}

void TestAbstractVirtualImpl()
{
	B* pa = new B; //zh
	pa->exec();
	delete pa;
}

void TestMemsetVirtualClass()
{
	return;
	son s;
	::memset(&s, 0, sizeof(s));

	// son对象被置空，程序运行出错
	parent& p = s;
	p.output();
}