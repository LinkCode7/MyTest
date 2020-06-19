#include "stdafx.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
//#include "TDC/useful_headers/tstring.h"

//using namespace uh;
//
///**
//* @brief �f�B���N�g�������̃f�B���N�g���Q�𓾂�
//* @note FindFirstFile�̎d�l�Ɉˑ�����ׁAspec�Ɋg���q���w�肵���Ƃ��́A
//*       �g���q�̑O����v�ōi�荞�܂��
//* @param[in]	dir		�f�B���N�g��
//* @param[in]	spec	�f�B���N�g�����t�B���^�B"*.*"�̂悤�Ɏw�肷��B
//* @param[out]	dirs	�o�̓f�B���N�g���Q
//*/
//inline void getDirectoryNames(LPCTSTR dir, LPCTSTR spec, std::vector<tstring>& dirs)
//{
//	assert(dir);
//	assert(spec);
//
//	tstring filespec = tstring(dir) + _T("\\") + spec;
//
//	WIN32_FIND_DATA fd;
//	HANDLE hFind = ::FindFirstFile(filespec.c_str(), &fd);
//	if (hFind == INVALID_HANDLE_VALUE)
//	{
//		// spec�ɓK������t�@�C�����Ȃ��Ƃ��͗�O�ɂ��Ȃ�
//		if (::GetLastError() == ERROR_FILE_NOT_FOUND)
//			return;
//
//		std::string msg = std::string("Fail FindFirstFile: ") + toStr(filespec);
//		throw std::runtime_error(msg);
//	}
//
//	do
//	{
//		tstring filename = fd.cFileName;
//		if ((filename == _T(".")) || (filename == _T("..")))
//			continue;
//
//		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//		{
//			dirs.push_back(filename);
//		}
//	} while (::FindNextFile(hFind, &fd));
//	::FindClose(hFind);
//}