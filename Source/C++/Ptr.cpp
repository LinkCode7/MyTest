#include "stdafx.h"
#include <boost/smart_ptr.hpp>
#include <memory>
#include "Ptr.h"

using namespace std;



void test(shared_ptr<int> p)
{
	cout << *(p.get()) << endl;
}

void testSmartPoint()
{
	/*Ptr<char> cp1(new char('a'));
	Ptr<char> cp2(cp1);
	Ptr<char> cp3;
	cp3 = cp2;
	cp3 = cp1;
	cp3 = cp3;
	Ptr<char> cp4(new char('b'));
	cp3 = cp4;*/

	int count(0);
	shared_ptr<int> p1(new int(4));
	count = p1.use_count();

	test(p1);
	//shared_ptr<int> p2 = p1;
	count = p1.use_count();
	//count = p2.use_count();

}