#include "stdafx.h"
#include "std_bind.h"






void stl_move()
{

}


// ��֪A��˾��ͼ�ο�����һ�����������£���ʵ���˿��ߵ�Get/Set������������������˼�����λش��������⣬����ʹ�÷�װ���̳С���̬���ӿڵȣ���ʽ���ޣ��������ܣ�
// 1.��дһ����������(Square)��ͬ��ʵ������ߵ�Get/Set������������������ľ��Σ�
// 2.������Ҫ�����Ρ���������ʾ��������Ϊ��Щ������һ�����Ʒ���(��Ҫ����ʵ�֣�ԭ��Ϊ��void Draw();)
// 3.������Ҫ��A��˾��ͼ�λ�����B��˾���豸�����ϣ���ΪB��˾������Щ��Ļ��Ʒ��������磺void DrawRectangle(const Rectangle& rectangle);
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



// ������Ҫ�����������˼�룬��չ������ӿڱ��˼��
// 1.1 Square�̳�Rectangle������������Ĵ���public�̳���Ӧ�ϸ�����is-a�Ĺ�ϵ
// 1.2 Square����дһ���࣬�Ϻ÷���

// 2.1 Ϊÿ����ʵ��һ��Draw������������ά������չ
// 2.2 ʵ��һ�����ࣨEntity��Geometry��Shape��,�����ṩ�躯��������ʵ���麯��
// 2.3 ʵ�ֽӿ�

// 3.1 ���ʵ�֣�void DrawRectangle(const Rectangle& rectangle); void DrawSquare(const Square& square); �޷���չҵ�񣬲���ʵ��ʵ��
// 3.2 void DrawShape(const Shape& shape) { shape.Draw(); }
// 3.3 ʵ�ֽӿ�