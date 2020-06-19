#include "stdafx.h"
#include "SinglePattern.h"


using namespace std;

SinglePattern1& SinglePattern1::Instance() // 属于类的全局对象
{
	static SinglePattern1 opr;
	return opr;
}






//////////////////////////////////////////////////////////////////////

void testSinglePattern()
{
	cout << "默认构造Id " << SingleOpr.GetId() << endl; // Instance1

	SingleOpr.SetId(2); // Instance2
	cout << "SingleOpr.SetId(2)" << endl;

	cout << "SingleOpr.GetId() " << SingleOpr.GetId() << endl; // Instance3

	SinglePattern1 opr = SinglePattern1::Instance(); // Instance4
	cout << " SinglePattern1::Instance()  GetId() " << opr.GetId() << endl;

	SinglePattern1 opr2 = SinglePattern1::Instance(); // Instance5
	cout << " SinglePattern1::Instance()  GetId() " << opr2.GetId() << endl;
}