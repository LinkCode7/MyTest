#include "stdafx.h"
using namespace std;

// 迪米特法则（最少只是原则）
// 两个类应尽可能少地发生直接的相互作用（松耦合），若一个类要调另一个类的方法，可通过第三者转发这个调用
// 类与类之间的相互关联越弱（耦合度低），一个类改变时不会波及关联类，有利于复用


// 例：小菜第入职软件开发公司第一天，找人事 -> 部门主管 -> 领电脑安装环境
// 恰巧部门主管出差，于是找到部门的小张，小张领了电脑正安装，接到客户紧急电话去处理故障了
// 于是小菜只能找人事，问能不能让其它人帮忙装一下，人事也在忙，让小菜找一下部门的另一个同事小李
// 小李看到领取电脑的单子上写着让小张安装，于是说不管...


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
	string m_headName{"部长"};

	void NewEmployeeImp()
	{
		cout << m_headName << " 处理新人入职事务，安装环境..." << endl;
	}

public:
	void SetHeadName(const string& strName) // 设置部门事务负责人
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