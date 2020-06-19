#include "stdafx.h"
#include "std_bind.h"






void stl_move()
{

}


// 已知A公司的图形库中有一个矩形类如下，它实现了宽、高的Get/Set方法，请用面向对象的思想依次回答如下问题，考虑使用封装、继承、多态、接口等，形式不限，尽你所能！
// 1.请写一个正方形类(Square)，同样实现其宽、高的Get/Set方法（正方形是特殊的矩形）
// 2.现在需要将矩形、正方形显示出来：请为这些类声明一个绘制方法(不要纠结实现，原型为：void Draw();)
// 3.现在需要将A公司的图形绘制在B公司的设备环境上，请为B公司申明这些类的绘制方法，比如：void DrawRectangle(const Rectangle& rectangle);
class Rectangle
{
public:
	virtual void SetHeight(int iHeight) { m_iHeight = iHeight; }
	virtual void SetWidth(int iWidth) { m_iWidth = iWidth; }

	virtual int GetHeight() { return m_iHeight; }
	virtual int GetWidth() { return m_iWidth; }


private:
	int m_iHeight;
	int m_iWidth;
};



// 本题主要考察面向对象思想，扩展：面向接口编程思想
// 1.1 Square继承Rectangle，这种是最常见的错误：public继承中应严格遵守is-a的关系
// 1.2 Square单独写一个类，较好方法

// 2.1 为每个类实现一个Draw函数，不利于维护、扩展
// 2.2 实现一个基类（Entity或Geometry或Shape）,基类提供需函数，子类实现虚函数
// 2.3 实现接口

// 3.1 逐个实现：void DrawRectangle(const Rectangle& rectangle); void DrawSquare(const Square& square); 无法扩展业务，不现实的实现
// 3.2 void DrawShape(const Shape& shape) { shape.Draw(); }
// 3.3 实现接口