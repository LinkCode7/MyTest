#include "stdafx.h"
#include "construct.h"



void TestCppClass()
{
	SimpleObject s;

	// error C2248 : ��SimpleObject::operator new�� : �޷����� private ��Ա
	//SimpleObject* pSimpleObject = new SimpleObject;
}