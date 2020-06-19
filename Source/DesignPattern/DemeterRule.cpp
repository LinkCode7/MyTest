#include "stdafx.h"
using namespace std;

// �����ط�������ֻ��ԭ��
// ������Ӧ�������ٵط���ֱ�ӵ��໥���ã�����ϣ�����һ����Ҫ����һ����ķ�������ͨ��������ת���������
// ������֮����໥����Խ������϶ȵͣ���һ����ı�ʱ���Შ�������࣬�����ڸ���


// ����С�˵���ְ���������˾��һ�죬������ -> �������� -> ����԰�װ����
// ǡ�ɲ������ܳ�������ҵ����ŵ�С�ţ�С�����˵�������װ���ӵ��ͻ������绰ȥ���������
// ����С��ֻ�������£����ܲ����������˰�æװһ�£�����Ҳ��æ����С����һ�²��ŵ���һ��ͬ��С��
// С�����ȡ���Եĵ�����д����С�Ű�װ������˵����...


class OfficeManage
{
private:
	virtual void NewEmployeeImp() = 0;

public:
	void NewEmployee()
	{
		// ...
		NewEmployeeImp();
		// ...
	}

	// ...
};

class DevelopOffice:public OfficeManage
{
private:
	string m_headName{"����"};

	void NewEmployeeImp()
	{
		cout << m_headName << " ����������ְ���񣬰�װ����..." << endl;
	}

public:
	void SetHeadName(const string& strName) // ���ò�����������
	{
		m_headName = strName;
	}
};

//////////////////////////////////////////////////////////////////////////////////

void testDemeter()
{
	OfficeManage* pDevelopOffice = new DevelopOffice;
	pDevelopOffice->NewEmployee();

	delete pDevelopOffice;
}