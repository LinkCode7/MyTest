#include "stdafx.h"
#include "TestSQLite.h"



//#include "..\..\..\Sindy\SINDY.h"
//#pragma comment(lib,"Debug/Sindy.lib")






void TestSQLite()
{
	//tstring strValue, strOther;
	//{
	//	tstring strDbPath(_T("E:\\Code\\export\\ddll\\UserData\\UserData.pmdb"));
	//	GetValueByName(strDbPath, _T("Head"), strValue, strOther);
	//}

	//Sindy::Nothing();
}





//bool GetValueByName(const tstring& strDbPath, const tstring& strKeyName, tstring& strValue, tstring& strOther)
//{
//	using namespace Sindy;
//
//	WorkspaceSqlite dbUserData;
//	dbUserData.Attach(strDbPath, _T("U"));
//
//	tstring strSql(_T("select * from U.pmaz_elec_sys_sett where parmname ='"));
//	strSql += strKeyName;
//	strSql += _T("'");
//
//	SqliteSyntax stmtSel(dbUserData.GetDefaultDb());
//	stmtSel.Prepare(strSql);
//
//	tstring strContent;
//	if (stmtSel.Step() == SQLITE_ROW)
//	{
//		stmtSel.Column_Text(_T("parmvalue"), strValue);
//		stmtSel.Column_Text(_T("parmother"), strOther);
//	}
//
//	stmtSel.Reset();
//
//	dbUserData.Detach(_T("U"));
//
//	return true;
//}