#include "stdafx.h"



using namespace std;
class TestQuestion // 试卷类
{
private:
	void Question1() // 考题1
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
		cout << "第N次考试" << endl;

		Question1();
		answer1(); // 代码上看在父类中，运行时调用的是子类

		Question2();
		answer2();

		cout << "总得分..." << endl;
	}

};

class Student:public TestQuestion // 学生类
{
	string m_name;

public:
	Student(const string& name)
	{
		m_name = name;
	}

private:
	void answer1() // 考题1答案
	{
		cout << "	" << m_name << " Question1 answer: ..." << endl;
	}

	void answer2()
	{
		cout << "	" << m_name << " Question2 answer: ..." << endl;
	}

};









///////////////////////////////////////////////////////////////////////////////////
// 模板方法模式
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