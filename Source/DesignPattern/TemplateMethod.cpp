#include "stdafx.h"



using namespace std;
class TestQuestion // �Ծ���
{
private:
	void Question1() // ����1
	{
		cout << "Question1..." << endl;
	}

	void Question2()
	{
		cout << "Question2..." << endl;
	}

	virtual void answer1() = 0;
	virtual void answer2() = 0;


public:
	void TestAnswer()
	{
		cout << "��N�ο���" << endl;

		Question1();
		answer1(); // �����Ͽ��ڸ����У�����ʱ���õ�������

		Question2();
		answer2();

		cout << "�ܵ÷�..." << endl;
	}

};

class Student:public TestQuestion // ѧ����
{
	string m_name;

public:
	Student(const string& name)
	{
		m_name = name;
	}

private:
	void answer1() // ����1��
	{
		cout << "	" << m_name << " Question1 answer: ..." << endl;
	}

	void answer2()
	{
		cout << "	" << m_name << " Question2 answer: ..." << endl;
	}

};









///////////////////////////////////////////////////////////////////////////////////
// ģ�巽��ģʽ
void testTemplateMethod()
{
	TestQuestion* pStudent1 = new Student("student1");
	TestQuestion* pStudent2 = new Student("student2");

	pStudent1->TestAnswer();
	cout << endl << "---------------------------------------" << endl << endl;
	pStudent2->TestAnswer();

	delete pStudent1;
	delete pStudent2;
}