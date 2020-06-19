#include "stdafx.h"
#include "ReadRegistry.h"

#define REGPATH_IPC _T("Software\\INCREMENT P CORPORATION\\")
#define REGPATH_SINDY_E_TOOLS  REGPATH_IPC _T("SiNDY-e\\Tools\\")
#define REGPATH_SINDY_E_COMMON REGPATH_SINDY_E_TOOLS _T("COMMON\\")
#define REGPATH_SINDY_E_CHILDDLG REGPATH_SINDY_E_TOOLS _T("AttributeTool\\")
#define REGPATH_SINDY_K REGPATH_IPC _T("SiNDY-k\\")
#define REGPATH_SINDY_M REGPATH_IPC _T("SiNDY-m\\")
#define REGPATH_SINDY_U REGPATH_IPC _T("SiNDY-u\\")
#define REGPATH_SINDY_GL REGPATH_IPC _T("SiNDY-global\\")

void readRegister()
{
	//std::string tabName = uh::reg_util::read(_T("LastTabName"), REGPATH_SINDY_K, _T("tabPage_Kihon"));

	// Write
	//uh::reg_util::write(tabName, L"LastTabName", L"Software\\INCREMENT P CORPORATION\\SiNDY-k");

}