#include "stdafx.h"



using namespace std;

class Shape
{
public:
	virtual void Draw() const = 0; // 纯虚函数：让子类只继承函数接口

	virtual void Error() {}; // 虚函数：让子类继承接口和缺省实现

	int QueryObjectId()const {} // 让子类继承接口，及一份强制性实现
};

class Rectangle :public Shape
{
public:
	void Draw()
	{
		cout << "矩形" << endl;
	}
};

class Ellipes :public Shape
{
public:
	void Draw()
	{
		cout << "椭圆" << endl;
	}

	void Error()
	{
		cout << "无法构造椭圆" << endl;
	}
};


///////////////////////////////////////////////////////////////////////////////////
// 接口继承、实现继承
void testVirtual()
{
	
}


// 1 不要将所有函数都声明为non-virtual，除非class根本不打算作为一个基类
// 2 不要将所有方法声明为virtual，除非是interface class