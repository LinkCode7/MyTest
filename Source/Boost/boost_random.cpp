#include "stdafx.h"
#include "boost_random.h"

#include <boost/random.hpp>


using namespace std;
using namespace boost;







//////////////////////////////////////////////////////////////////////////////////
void boost_random()
{
	random_generator();
	random_distribution();
}



void random_generator()
{
	// �趨��Χ
	mt19937 rng(500);

	cout << mt19937::min() << "<->" << mt19937::max() << endl;

	// ����100�������
	for (int i = 0; i < 100; ++i)
	{
		cout << rng() << endl;
	}

	// ȥ��5��
	rng.discard(5);

	// �������
	vector<int> vec(10);
	rng.generate(vec.begin(), vec.end());
}

void random_distribution()
{
	mt19937 rng(time(0));

	cout << endl << "--------------uniform_int_distribution--------------" << endl;
	random::uniform_int_distribution<> ui(0, 255);

	for (int i = 0; i < 10; ++i)
	{
		cout << ui(rng) << ",";
	}
	assert(ui.a() == 0 && ui.b() == 255);


	cout << endl << "--------------uniform_01--------------" << endl;
	uniform_01<> u01;
	for (int j = 0; j < 10; ++j)
	{
		cout << u01(rng) << ",";
	}


	cout << endl << "--------------normal_distribution--------------" << endl;
	normal_distribution<> nd(1, 2);

	int iCount = 0;
	for (int k = 0; k < 10000; ++k)
	{
		if (abs(nd(rng) - 1) <= 2.0)
			++iCount;
	}

	cout << endl << endl;
	cout << 1.0 * iCount / 10000 << endl;
}