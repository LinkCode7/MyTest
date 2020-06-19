#include "stdafx.h"
#include "boost_filesystem.h"


#include <boost/ratio.hpp>

using namespace std;
using namespace boost;



void Testtttt()
{

	if (ispunct('•'))
	{
		cout << endl;
	}
	if (!filesystem::windows_name("a•w"))
	{
		cout << endl;
	}
}

void boost_filesystem()
{
	Testtttt();
	return;

	// 判断文件是否存在: "\\" is must
	filesystem::path pathDir("C:\\Users\\Administrator\\Desktop\\7");
	filesystem::path pathFile("C:\\Users\\Administrator\\Desktop\\Test.ini");

	if (!check(pathDir, pathFile))
		return;

	info(pathDir, pathFile);

	change(pathDir, pathFile);
	
	FileStatus(pathDir, pathFile);

	property(pathDir, pathFile);

	file_operator();

	// Windows:		Shlwapi.h: PathIsDirectory(path)
}

bool check(const filesystem::path& pathDir, const filesystem::path& pathFile)
{
	// 是不是目录
	if (!filesystem::is_directory(pathDir))
		return false;

	// 是不是普通文件
	if (!filesystem::is_regular_file(pathFile))
		return false;

	// 是否存在
	if (!filesystem::exists(pathDir))
		return false;

	if (!filesystem::exists(pathFile))
		return false;

	// 判断文件名是否符合Windows规范，不允许"<>?:|/\"
	if (!filesystem::windows_name(pathFile.filename().string()))
		return false;

	return true;
}

void info(const filesystem::path& pathDir, const filesystem::path& pathFile)
{
	cout << pathDir.string() << endl;
	cout << pathFile.c_str() << endl;

	// 返回path对象
	cout << pathDir.parent_path() << endl;
	cout << pathFile.stem() << endl; // 不含扩展名的文件名
	cout << pathDir.stem() << endl; // 最里层的目录名

	cout << pathDir.has_filename() << endl; // true?
	cout << pathFile.has_filename() << endl;

	cout << pathFile.has_parent_path() << endl;
	cout << pathFile.filename() << endl; // 带后缀的文件名

	cout << pathFile.extension() << endl; // 后缀名
	cout << pathDir.extension() << endl;

	cout << pathDir.root_name() << endl; // C:
	cout << pathDir.root_directory() << endl;
	cout << pathDir.root_path() << endl; // 根目录的路径 C:\

	// 相对路径
	cout << pathDir.relative_path() << endl;

	bool isAbsolute = system_complete(pathDir).is_absolute();
}

void change(filesystem::path& pathDir, filesystem::path& pathFile)
{
	filesystem::path path("C:\\Users\\Administrator\\Desktop");
	path.append("7\\Test.ini"); // path /= "7";

	path.replace_extension(".txt");
	path.remove_filename();
	//boost::system_complete();
}

void FileStatus(const filesystem::path& pathDir, const filesystem::path& pathFile)
{
	using namespace filesystem;

	// 验证文件权限
	assert((status("C:\\Users\\Administrator\\Desktop").permissions() & owner_exe) != owner_exe);
}

void property(const filesystem::path& pathDir, const filesystem::path& pathFile)
{
	using namespace filesystem;
	cout << endl << "----------property----------" << endl;
	cout << current_path() << endl;
	cout << initial_path() << endl;

	cout << file_size(pathFile) << endl;

	time_t t = last_write_time(pathFile);
	last_write_time(pathFile, time(0));


	// 磁盘空间信息
	space_info si = space(pathDir);
	cout << si.capacity / giga::num << endl; // 使用ratio库的giga单位
	cout << si.available / giga::num << endl;
	cout << si.free / giga::num << endl;
}

void file_operator()
{
	namespace fs = boost::filesystem;

	fs::path pathCur = fs::current_path();
	pathCur.append("\\FileSystemTestDir");

	// 创建目录，若存在该目录则不会创建
	bool isOk = fs::create_directory(pathCur);
	// 创建多级目录，这里是纵向创建
	isOk = fs::create_directories(pathCur / "FileSystemTestDir_sub" / "FileSystemTestDir_sub_sub");

	if (fs::is_empty(pathCur))
	{
		isOk = fs::remove(pathCur); // 注意：remove只能删除空目录或文件
	}
	else
	{
		isOk = fs::remove_all(pathCur); // 删除目录、子目录及文件，All
	}
}