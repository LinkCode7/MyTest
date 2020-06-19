#include "stdafx.h"
#include <set>
#include <algorithm>

using namespace std;

void bubble_sort(int num[], int size)
{
	int flag = 0;
	int i, j, min;
	for (i = 0; i<size -1; ++i)
	{
		flag = 0;//����н���flag=1
		///////////////////////////////////////////////////////////////
		// ����ڲ�forѭ�����룬�ݳ�Ϊ������X��
		// ����Xִ��һ�鼴�����forѭ����һ�Σ��ڲ�forѭ����size - i - 1��
		for (j = 0; j<size - i - 1; ++j)
		{
			// ��һ�Σ�1��Ԫ�غ�2��Ԫ�رȽϣ�����Ľ������ұ�
			// �ڶ��Σ�2��3�Ƚϣ�����ķŵ��ұ�
			// �����Σ�3��4�Ƚϣ�����ķŵ��ұ�
			// ������"����X" ��N�ν�����ִ����ϣ�
			// ���������N�����Ѿ�����
			if (num[j] > num[j + 1])
			{
				min = num[j + 1];
				num[j + 1] = num[j];
				num[j] = min;
				flag = 1;
			}
		}
		///////////////////////////////////////////////////////////////
		if (flag == 0)
		{
			// �Ѿ�����
			break;
		}
	}
}

void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void quick_sort(int vec[], int leftIndex, int rightIndex)
{
	int last = 0;

	const int high = rightIndex;
	const int low = leftIndex;
	if (leftIndex >= rightIndex)// ����
		return;
	while (leftIndex<rightIndex)
	{
		if (vec[leftIndex]>vec[rightIndex])
		{
			swap(vec, leftIndex, rightIndex);

			last = ~last;

		}
		if (last == 0)
			rightIndex--;
		else
			leftIndex++;
	}
	quick_sort(vec, low, leftIndex - 1);
	quick_sort(vec, leftIndex + 1, high);
}

////////////////////////////////////////////////////////////////////
constexpr auto BUBBLE_MAX = 10;
constexpr auto QUICK_MAX = 10000000;

void testSort()
{
	if(!TestOpr.TestRand())
		return;

	// 1
	int array1[BUBBLE_MAX];
	for (int j = 0; j<BUBBLE_MAX; ++j)
	{
		array1[j] = rand() % BUBBLE_MAX;
	}
	bubble_sort(array1, BUBBLE_MAX);

	// 2
	int* array2 = (int*)malloc(sizeof(int) * QUICK_MAX);
	for (int j = 0; j<QUICK_MAX; ++j)
	{
		array2[j] = rand() % QUICK_MAX;
	}
	quick_sort(array2, 0, QUICK_MAX - 1);
	
	free(array2);
}







void ContainerSort()
{
	set<std::string> set{ "DN15", "DN10", "DN100", "DN110", "DN150" };

	vector<std::string> vec = { "B", "BYJ", "BY", "WD", "WDZ" }; // _T(""),

	//// �Ӵ�Сgreater��BYJ������BYǰ��
	//std::sort(vec.begin(), vec.end(), std::greater<std::string>());



	//std::map<std::string, std::string, std::greater<std::string>> mapValue = { {_T("a"),_T("1")},{_T("b"),_T("2")} };
}