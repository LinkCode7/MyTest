#pragma once

//#define _CRT_SECURE_NO_DEPRECATE//预处理器中添加此宏
#pragma warning(disable:4996)// Use c types character

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <sstream>

#include <array>
#include <functional>

#include <time.h>


//#include <atlbase.h>
//#include <atlcom.h>
//#include <atlctl.h>
//#include <atlstr.h>// std::string
//using namespace ATL;



//#define _AFXDLL
//#include <afxwin.h>
// #include <windows.h> //这个可以不包含，在VS2015下测试不包含通过，别的VS就不知道了.
//#include <std::string>


#ifdef _UNICODE
typedef std::wstring tstring;
#else
typedef std::string	tstring;
#endif


#define DESKTOP_FILE_TXT "C:\\Users\\Administrator\\Desktop\\Test.txt"
#define DESKTOP_FILE_XML "C:\\Users\\Administrator\\Desktop\\Test.xml"

#define PRINT() std::cout << "True " << __LINE__ << std::endl;


#define PmDelete(TYPE) {delete TYPE;(TYPE)=NULL;}


class TestOperator
{
	bool m_isTestRand;

public:
	static TestOperator& instance()
	{
		static TestOperator opr;
		return opr;
	}

	bool TestRand()
	{
		return false;
	}
};

#define TestOpr TestOperator::instance()


// GDAL库只编译了VS2015版本
#define _VERSION_VS2015_ 1900