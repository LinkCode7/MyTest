#include "stdafx.h"





using namespace std;

void iteratorInvalid()
{
	// 1.vector
	vector<int>::iterator iter1;
	vector<int> vec = {1,2,3,4,5,6,7};
	
	for (iter1 = vec.begin(); iter1 != vec.end(); iter1++)
	{
		if (*iter1 == 2)
		{
			// erase()�᷵�ص�������һ��λ�ã���ȷд����
			iter1 = vec.erase(iter1);

			//����д����vec.erase(iter); // ��ʱ������iterָ���ֵ�ѱ�ɾ��
			cout << *iter1 << endl;// vec.erase(iter); �����±���
		}
	}

	// 2.map
	map<int, string>::iterator iter2;
	map<int, string> ma = { {1,"a"},{2,"b"},{3,"c"},{4,"d"} };

	for (iter2 = ma.begin(); iter2 != ma.end(); iter2++)
	{
		if (iter2->first == 2)
		{
			// erase()�᷵�ص�������һ��λ�ã���ȷд�����֣�
			iter2 = ma.erase(iter2);
			//ma.erase(iter2++);

			//����д����ma.erase(iter2); // ��ʱ������iterָ���ֵ�ѱ�ɾ��
			cout << iter2->first << endl;// ma.erase(iter2); �����±���
		}
	}

}

/////////////////////////////////////////////////////////////////

void testIterator()
{
	iteratorInvalid();

}