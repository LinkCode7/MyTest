#include "stdafx.h"





class Object
{
public:
	Object()
	{
		std::cout << "���죺Object()" << std::endl;
	}
	~Object()
	{
		std::cout << "������~Object()" << std::endl;
	}

};

//////////////////////////////////////////////////////////////////////////

void testDelete()
{
	Object* pObject1 = new Object;
	Object* pObject2 = new Object[3];

	delete pObject1;
	delete[] pObject2; // []������������

	// ��Ϊδ֪�Ĵ���������ʽ
	//delete[] pObject1; // ����ѭ��delete
	//delete pObject2; // �쳣
}