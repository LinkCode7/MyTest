#include "stdafx.h"



using namespace std;

class Shape
{
public:
	virtual void Draw() const = 0; // ���麯����������ֻ�̳к����ӿ�

	virtual void Error() {}; // �麯����������̳нӿں�ȱʡʵ��

	int QueryObjectId()const {} // ������̳нӿڣ���һ��ǿ����ʵ��
};

class Rectangle :public Shape
{
public:
	void Draw()
	{
		cout << "����" << endl;
	}
};

class Ellipes :public Shape
{
public:
	void Draw()
	{
		cout << "��Բ" << endl;
	}

	void Error()
	{
		cout << "�޷�������Բ" << endl;
	}
};


///////////////////////////////////////////////////////////////////////////////////
// �ӿڼ̳С�ʵ�ּ̳�
void testVirtual()
{
	
}


// 1 ��Ҫ�����к���������Ϊnon-virtual������class������������Ϊһ������
// 2 ��Ҫ�����з�������Ϊvirtual��������interface class