#include "stdafx.h"
#include "VirtualFunction.h"


using namespace std;
class A
{
	char a_val;
public:

	virtual void show(){ cout << "class A:show()" << endl; }
	virtual void say() { cout << "class A:say()" << endl; }

	inline void setA_Val(char val) { a_val = val; }
	inline char getA_Val()const { return a_val; }
};
class B : public A
{
	int b_val;
public:

	void say() { cout << "class B: say()" << endl; }

	virtual void PrintHello() { cout << "class B:hello" << endl; }
	virtual void print1() { cout << "class B: print1" << endl; }

	inline void setB_Val(int val) { b_val = val; }
	inline int getB_Val()const { return b_val; }
};

void virtualFunction()
{
	B b;
	b.setB_Val(123);
	b.setA_Val('A');

	int *vfptr = new int;
	int *pf = new int;
	memcpy(vfptr, &b, 4);// B类型的指针赋给vfptr
	memcpy(pf, reinterpret_cast<int *>(*vfptr) + 2, 4);// 取B中的第2个函数

	void(*pfun)() = reinterpret_cast<void(*)()>(*pf);// 构造函数指针
	pfun();// "class B hello"


	char *pa_val = new char;
	int *pb_val = new int;
	memcpy(pa_val, reinterpret_cast<int *>(&b) + 1, sizeof(char));
	memcpy(pb_val, reinterpret_cast<int *>(&b) + 2, sizeof(int));
	cout << *pa_val << endl;// A
	cout << *pb_val << endl;// 123
	cout << "<<<<<<<<<<<<<<" << endl;


	*pa_val = 'B';
	*pb_val = 999;
	memcpy(reinterpret_cast<int *>(&b) + 1, pa_val, sizeof(char));
	memcpy(reinterpret_cast<int *>(&b) + 2, pb_val, 4);
	cout << b.getA_Val() << endl;// B
	cout << b.getB_Val() << endl;// 999
}