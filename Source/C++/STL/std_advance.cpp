#include "stdafx.h"
#include "std_advance.h"

using namespace std;

template<class InputIterator, class Distance>
void advance_II(InputIterator it, Distance n)
{
	// ������һǰ��
	while (n--) ++i;
}

template<class BidIrectionalIterator, class Distance>
void advance_BI(BidIrectionalIterator it, Distance n)
{
	// ˫����һǰ��
	if (n >= 0)
		while (n--) ++i;
	else
		while (n++) --i;	
}

template<class RandomAccessIterator, class Distance>
void advance_RAI(RandomAccessIterator it, Distance n)
{
	// ˫����Ծǰ��
	i += n;
}

////////////////////////////////////////////////////////////////////
// ѡ��ͬЧ�ʵİ汾��

// �����ڼ�ѡ��
template<class InputIterator, class Distance>
void Advance(InputIterator i, Distance n)
{
	//if (isRandomAccessIterator(i)) // ��ʵ��
	//	advance_RAI(i,n);
	//else if(isBidIrectionalIterator(i)) // ��ʵ��
	//	advance_BI(i, n);
	//else
	//	advance_II(i, n);
}

// ��Ч�ʵķ�ʽ��������ѡ�񣨺������أ�
// void advance(InputIterator i, Distance n��ClassType)








void testAdvance()
{
	////vector<int> vec = {1,2,3};
	//int p[] = {1,2,3};
	//auto itr = p;

	//MyAdvance(itr,1);
}