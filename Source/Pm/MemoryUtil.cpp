#include "stdafx.h"
#include "MemoryUtil.h"

#include <fstream>
#include <ostream>
#include <regex>



using namespace std;



// 内存泄漏log文件处理
void DoMemoryUtil()
{
	MemoryUtil::Run object;

	string strTest("C:\\Users\\Administrator\\Desktop\\PMtestMemory3.log");
	std::ifstream ifs("C:\\Users\\Administrator\\Desktop\\PMtestMemory3.log");

	const int iLength = 3000;

	return;

	string strValue;
	char str[iLength];

	bool isNeedAdd = false;

	int iLineCount = 0;
	while (ifs.getline(str, iLength))
	{
		++iLineCount;
		if ( !isNeedAdd )
		{
			if(string(str).find("开始打印泄露地址") != string::npos)
				isNeedAdd = true;
		}
		else
		{
			object.AddLine(str);
		}
	}

	object.Output("C:\\Users\\Administrator\\Desktop\\PMtestMemory3_New.log");

	cout << "共处理：" << iLineCount << "行" << endl;

	string s;
	s.c_str();
}




namespace MemoryUtil
{
	void Run::AddLine(const std::string& str)
	{
		regex reg("(.*)(\\(\\d+\\)):(.*)");

		std::smatch what;
		bool isMatch = std::regex_match(str, what, reg);

		if (!isMatch)
			return;
		
		string strFormat(string(what[1]) + string(what[2]));

		std::map<std::string, Record*>::iterator iter = m_map.find(strFormat);

		if (iter == m_map.end())
		{
			Run::Record* pRecord = new Record(what[0]);
			m_map[strFormat] = pRecord;
		}
		else
		{
			iter->second->m_iCount++;
		}
	}

	void Run::Output(const std::string& strNewLog)
	{
		ofstream ofs;
		ofs.open(strNewLog);

		std::map<std::string, Record*>::reverse_iterator iter = m_map.rbegin();

		for (; iter != m_map.rend(); ++iter)
		{
			Run::Record* pRecord = iter->second;

			ofs << iter->first << "   ->Count = " << pRecord->m_iCount << "\n";
		}
	}

} // namespace MemoryUtil