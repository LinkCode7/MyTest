#include "stdafx.h"
#include "TestVector.h"




using namespace std;





void PrintVectorLength(const std::vector<Point>& vec);
void TestVectorPush();
void TestMemoryGrowth();
void TestMoveSemantic();

void TestVector()
{
	//TestVectorPush();
	//TestMemoryGrowth();

	TestMoveSemantic();
}






void PrintVectorLength(const std::vector<Point>& vec)
{
	cout << "-------------------------------- size = " << vec.size() << endl;
	cout << "-------------------------------- capacity = " << vec.capacity() << endl;
}

void TestVectorPush()
{
	std::vector<Point> vecPt;

	PrintVectorLength(vecPt);
	cout << endl << endl << endl;

	int iCount = 100;
	for (size_t i = 0; i < iCount; ++i)
	{
		vecPt.push_back(Point());
		PrintVectorLength(vecPt);
		cout << endl;
	}

	std::vector<Point>::iterator iter = vecPt.begin();
	for (; iter != vecPt.end(); ++iter)
	{
		Point pt = *iter;
		//const Point& pt = *iter;
	}

	cout << endl << endl << endl;

	cout << "g_iConstructCount = " << g_iConstructCount << endl;
	cout << "g_iDestructCount = " << g_iDestructCount << endl;
}

void TestMemoryGrowth()
{
	// �ڴ�������ʽ��new = old * 1.5
	// 1,2,3,4,6,9,13,19,28,42,63,94,141,211,316,474,711,1066
	vector<int> vec;

	unsigned int iLastCapacity = vec.capacity();

	for (auto i = 0; i < 1000; ++i)
	{
		vec.push_back(1);

		// ���������ı�ʱ���
		if (vec.capacity() != iLastCapacity)
		{
			iLastCapacity = vec.capacity();
			cout << vec.capacity() << endl;
		}
	}
}

Point GetPointObject()
{
	return Point();
}

void _PrintPoint(const Point& pt)
{
	cout << "PrintPoint(const Point& pt)" << endl;
}

void _PrintPoint(Point&& pt)
{
	cout << "PrintPoint(Point&& pt)" << endl;
}

void PrintPoint(Point&& pt)
{
	_PrintPoint(pt);

	// �������ǰ󶨵�һ����ֵʱ���ͽ�����ת����һ����ֵ
	_PrintPoint(std::forward<Point>(pt));
}

void TestMoveSemantic()
{
	Point pt = GetPointObject();

	Point pt1 = std::move(pt);

	PrintPoint(std::move(pt1));
}