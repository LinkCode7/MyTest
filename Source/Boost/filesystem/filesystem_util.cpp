#include "stdafx.h"
#include "filesystem_util.h"

#include <boost/filesystem.hpp>

#include <boost/regex.hpp>
#include <boost/progress.hpp>


using namespace std;
using namespace boost;



void FileSystemSearchDirectory()
{
	return;

	boost::filesystem::path path("C:\\Users\\Administrator\\Desktop\\7");

	auto strDir = FindFile(path.string(), "��С��.doc");

	// filesystem�׳��쳣������������ϵͳ��������ʵ��ļ���std::filesystem���Ժ����쳣
	// https://stackoverflow.com/questions/52318249/the-stdfilesystemrecursive-directory-iterator-exception
	//for (auto& el : std::filesystem::recursive_directory_iterator(dir, std::filesystem::directory_options::skip_permission_denied))
	//{
	//	std::cout << el.path() << '\n';
	//}

	std::map<std::string, std::vector<std::string>> mapPath2Files;
	{
		::system("cls");
		boost::progress_timer t;
		FindFileRegex("C:\\Users\\Administrator\\Desktop\\�½��ļ���", ".*\\.txt$", mapPath2Files);
	}
}






std::string FindFile(const std::string& strDir, const std::string& strFile)
{
	namespace bf = boost::filesystem;

	if (!bf::exists(strDir) || !bf::is_directory(strDir))
		return false;

	typedef bf::recursive_directory_iterator fd_iterator;

	fd_iterator end;

	// ����Ŀ¼�µ��ļ�
	for (fd_iterator pos(strDir); pos != end; ++pos)
	{
		cout << pos->path() << endl;
		if( !bf::is_directory(*pos) && strFile == pos->path().filename())
		{
			return pos->path().parent_path().string();
		}
	}

	return std::string();
}

bool FindFileRegex(const std::string& strDir, const std::string& strRegex, std::map<std::string,std::vector<std::string>>& mapPath2Files)
{
	namespace bf = boost::filesystem;

	if (!bf::exists(strDir) || !bf::is_directory(strDir))
		return false;

	typedef bf::recursive_directory_iterator fd_iterator;

	fd_iterator end;

	boost::smatch what;
	boost::regex reg(strRegex);

	// ����Ŀ¼�µ��ļ�
	//for (auto& el : std::filesystem::recursive_directory_iterator(dir, std::filesystem::directory_options::skip_permission_denied))

	for (fd_iterator pos(strDir, bf::symlink_option::_detail_no_push); pos != end; ++pos)
	{
		if (!bf::is_directory(*pos))
		{
			bf::path pa = pos->path();

			//if (boost::regex_match(pa.filename().string(), what, reg))
			if(pa.filename().string().find(".txt") != std::string::npos)
			{
				string strPath(pa.parent_path().string());

				auto iter = mapPath2Files.find(strPath);
				if (iter == mapPath2Files.end())
				{
					std::vector<string> vec{ pa.filename().string() };
					mapPath2Files[strPath] = vec;
				}
				else
				{
					iter->second.push_back(pa.filename().string());
				}

				cout << strPath << endl;
			}
		}
	}

	return !mapPath2Files.empty();
}

std::string FindFileOnePath(const std::string& strDir, const std::string& strFile)
{
	namespace bf = boost::filesystem;

	if (!bf::exists(strDir) || !bf::is_directory(strDir))
		return false;

	typedef bf::recursive_directory_iterator fd_iterator;

	fd_iterator end;

	// ����Ŀ¼�µ��ļ�
	for (fd_iterator pos(strDir); pos != end; ++pos)
	{
		cout << pos->path() << endl;
		if (bf::is_directory(*pos))
		{
			// ����������Ŀ¼
			pos.no_push();
		}

		if (strFile == pos->path().filename())
		{
			return pos->path().parent_path().string();
		}
	}

	return std::string();
}