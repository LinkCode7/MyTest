#include "stdafx.h"
#include <iostream>

using namespace std;
// �ж�һ����ʱ��Ϊ������(121,12321,35653) 
//unsigned char Symmetry(long n)
bool Symmetry(long n)
{
	long i, temp, cout(0);
	i = n; temp = 0;
	//cout << "begin:		i: " << i << endl;
	//cout << "        temp: " << temp << endl;

	//while (i) //���ó��ֳ�������,�������ߵ�λ����
	//{
	//	temp = temp * 10 + i % 10;
	//	i /= 10;

	//	cout << "count:" << cout++  << "i:" << i << endl;
	//	cout << "      " << "temp:" << temp << endl;
	//}

	//cout << "end:		i: " << i << endl;
	//cout << "        temp: " << temp << endl;
	return(temp == n);
}

void algorithm()
{
	Symmetry(12321);
}
