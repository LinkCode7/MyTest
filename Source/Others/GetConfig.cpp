#include "stdafx.h"
#include "GetConfig.h"
using namespace std;


#include <fstream>
//void getCommandLine(int argc, TCHAR** argv)
//{//-c user@server -i configFilePath
// //-c DEVPRODENG1@biela -i C:\Users\sindy_dev\Desktop\test\config.txt
//	//if (argc <= 1)
//	//	return outMessage( "Command line error:argc<=1" );
//	//ConnectionInfo connectInfo;
//
//	//while (--argc)
//	//{
//	//	_TCHAR *s = *++argv;
//	//	switch (*s)
//	//	{
//	//	case '-':
//	//		switch (*++s)
//	//		{
//	//		case 'c'://zh
//	//			connectInfo.connectLink = *++argv;
//	//			--argc;
//	//			break;
//	//		case 'i':
//	//		{
//	//			std::ifstream file(*++argv); --argc;
//	//			if (!file.is_open())
//	//			{
//	//				//std::cerr << "���e���ID���X�g���J���܂���\n" << std::endl;
//	//				return outMessage("���e���ID���X�g���J���܂���\n");
//	//			}
//	//			while (file.good())
//	//			{
//	//				char szBuffer[128] = "";
//	//				file.getline(szBuffer, 127);
//	//				std::string strID = szBuffer;
//	//				if (!strID.IsEmpty())
//	//				{
//	//					long nTabPos = strID.Find(_T("\t"));
//	//					std::string strOID = strID.Left(nTabPos);
//	//					std::string strRev = strID.Right(strID.GetLength() - nTabPos - 1);
//	//					connectInfo.m_listInfoID.push_back(_ttol(strOID));
//	//					connectInfo.m_mapInfoID[_ttol(strOID)] = _ttol(strRev);
//	//				}
//	//			}
//	//		}
//	//		break;
//	//		default:
//	//			return outMessage("default option");
//	//		}
//	//		break;
//	//	default:
//	//		break;
//	//	}
//	//}
//}
//
//
//
///*
//// configuration file:
//#connection
//SERVER	onyx.mr.ipc.pioneer.co.jp
//INSTANCE	5151
//USER	FIX200705
//PASSWORD	FIX200705
//VERSION	SDE.DEFAULT
//#out put
//OUTPUT	.
//*/
//void getConfigFile(const char* strConfigFile)
//{
//	////zh+,config file rule:CONNECTION/tserverValue/tINSTANCE/tinstanceValue/t......
//	//FILE *fp;
//	//ConnectionInfo connectInfo;
//	////if ((fp = fopen(strConfigFile, "r"))) // Origin
//	//if ( fopen_s( &fp, strConfigFile, "r") )
//	//{
//	//	char    aStr[256];
//	//	while (fgets(aStr, 256, fp) != NULL)
//	//	{
//	//		if (aStr[strlen(aStr) - 1] == '\n')
//	//			aStr[strlen(aStr) - 1] = '\0';
//
//	//		if (aStr[0] == '#')	continue;
//	//		int		i = 0;
//	//		char	*s;
//	//		char	aWork[256], aVal[256], aInBuff[1024];
//	//		strcpy_s(aInBuff, aStr);
//	//		for (s = strtok(aInBuff, "\t"); s != NULL; s = strtok(NULL, "\t"))//zh:strtok
//	//		{
//	//			if (!s) continue;
//	//			strcpy(aWork, s);
//	//			s = strtok(NULL, "\t");//zh:Get next
//	//			if (s) strcpy(aVal, s);
//
//
//	//			if ((!strcmp("CONNECTION", aWork)) && (strlen(aVal))) {
//	//				connectInfo.connectLink = aVal;
//	//			}
//	//			else if ((!strcmp("USER", aWork)) && (strlen(aVal))) {
//	//				connectInfo.strUser = aVal;
//	//			}
//	//			else if ((!strcmp("PASSWORD", aWork)) && (strlen(aVal))) {
//	//				connectInfo.strPassword = aVal;
//	//			}
//	//			else if ((!strcmp("VERSION", aWork)) && (strlen(aVal))) {
//	//				connectInfo.strVersion = aVal;
//	//			}
//	//			else if ((!strcmp("OUTPUT", aWork)) && (strlen(aVal))) {
//	//				connectInfo.m_strLogFileName = aVal;
//	//			}
//	//		}
//	//	}// while()
//	//	(void)fclose(fp);
//	//}
//	//else {
//	//	//cerr << "Read config file error:\t" << strConfigFile;
//	//	return outMessage( _T("Read config file error:\t") );
//	//}
//}
//
//
//
//
//
//#define	FILE_LEN	4096
//// FIX201101	./addLayerRoadFile.ini
//CONNECTIONINFO getIniFile( LPCTSTR section, LPCTSTR lpcszIniPath )
//{
//	//std::string strTemp, strConnection, strDataset, strLayer, strGroupName, strAddMode;
//	CONNECTIONINFO sConnectionInfo;
//
//	//// addmode�̃f�t�H���g�l��ݒ�
//	//::GetPrivateProfileString(_T("loadSDEFile"), _T("addmode"), _T("0000"), strAddMode.GetBuffer(FILE_LEN), FILE_LEN, lpcszIniPath);
//	//strAddMode.ReleaseBuffer();
//	//sConnectionInfo.strAddMode = strAddMode;
//	//strAddMode.Empty();
//
//	//// �ڑ�������ݒ�t�@�C�����擾
//	//std::vector<TCHAR> vecResult;
//	//if (!GetPrivateProfileSectionTCharArray(section, lpcszIniPath, vecResult))
//	//{
//	//	outMessage( "GetPrivateProfileSectionTCharArray error" );
//	//	return CONNECTIONINFO();
//	//}
//	//TCHAR *token = &vecResult.at(0);
//
//	//while (*token != '\0')
//	//{
//	//	strTemp = token;
//	//	if (_T("connection") == strTemp.Left(strTemp.Find('=')))
//	//		strConnection = strTemp.Right(strTemp.GetLength() - strTemp.Find('=') - 1);
//	//	else if (_T("dataset") == strTemp.Left(strTemp.Find('=')))
//	//		strDataset = strTemp.Right(strTemp.GetLength() - strTemp.Find('=') - 1);
//	//	else if (_T("layer") == strTemp.Left(strTemp.Find('=')))
//	//		strLayer = strTemp.Right(strTemp.GetLength() - strTemp.Find('=') - 1);
//	//	else if (_T("groupname") == strTemp.Left(strTemp.Find('=')))
//	//		strGroupName = strTemp.Right(strTemp.GetLength() - strTemp.Find('=') - 1);
//	//	else if (_T("addmode") == strTemp.Left(strTemp.Find('=')))
//	//		strAddMode = strTemp.Right(strTemp.GetLength() - strTemp.Find('=') - 1);
//	//	while (*token != '\0')
//	//		++token;
//	//	++token;
//	//}
//	//sConnectionInfo.strDataset = strDataset;
//	//sConnectionInfo.strConnectionName = section;
//	//sConnectionInfo.strGroupName = strGroupName;
//	//if (!strAddMode.IsEmpty())
//	//	sConnectionInfo.strAddMode = strAddMode;
//	//int iPos = -1;
//	//// Rule: "strPasswd|strUser|strVersion|strInstance|strServer" or "strPasswd|strUser||strInstance|strServer"
//	//// �p�X���[�h�擾
//	//iPos = strConnection.Find(_T("|"));
//	//if (iPos > 0)
//	//	sConnectionInfo.strPasswd = strConnection.Left(iPos);
//	//strConnection = strConnection.Right(strConnection.GetLength() - (iPos + 1));
//	//// ���[�U���擾
//	//iPos = strConnection.Find(_T("|"));
//	//if (iPos > 0)
//	//	sConnectionInfo.strUser = strConnection.Left(iPos);
//	//strConnection = strConnection.Right(strConnection.GetLength() - (iPos + 1));
//	//// �o�[�W�����擾
//	//iPos = strConnection.Find(_T("|"));
//	//if (iPos > 0)
//	//	sConnectionInfo.strVersion = strConnection.Left(iPos);
//	//else
//	//	sConnectionInfo.strVersion = _T("SDE.DEFAULT");
//	//strConnection = strConnection.Right(strConnection.GetLength() - (iPos + 1));
//	//// �C���X�^���X�擾
//	//iPos = strConnection.Find(_T("|"));
//	//if (iPos > 0)
//	//	sConnectionInfo.strInstance = strConnection.Left(iPos);
//	//strConnection = strConnection.Right(strConnection.GetLength() - (iPos + 1));
//	//// �T�[�o���擾
//	//sConnectionInfo.strServer = strConnection;
//
//	////...
//	return sConnectionInfo;
//}
//
//bool GetPrivateProfileSectionTCharArray(LPCTSTR lpAppName, LPCTSTR lpFileName, std::vector<TCHAR>& vecResult)
//{
//	//static const int INITIAL_SIZE = 4096;	//!< �o�b�t�@�m�ۂ̏����l
//	//static const int LIMIT_SIZE = 32767;	//!< ����̖������[�v��h���ׂ̃o�b�t�@�m�ۂ̍ő�l
//
//	//DWORD dwSize = INITIAL_SIZE;
//	//while (dwSize < LIMIT_SIZE)
//	//{
//	//	vecResult.resize(dwSize);
//	//	DWORD dwRet = ::GetPrivateProfileSection(lpAppName, &vecResult.at(0), dwSize, lpFileName);
//	//	if (dwRet == 0)
//	//	{
//	//		// �f�[�^�������Ȃ�����
//	//		vecResult.resize(0);
//	//		return false;
//	//	}
//	//	if (dwRet < dwSize - 2)
//	//	{
//	//		// �S�Ẵf�[�^������ꂽ�Ƃ��́A
//	//		// �I�[��2��NULL�������i�[�����傫����resize���ĕԂ�
//	//		vecResult.resize(dwRet + 1);
//	//		return true;
//	//	}
//
//	//	// �S�Ẵf�[�^�������Ȃ������Ƃ��́A�o�b�t�@���Q�{�ɂ��čĎ��s
//	//	dwSize *= 2;
//	//}
//	//// �o�b�t�@�m�ۂ̍ő�l�𒴂���
//	return false;
//}



//void list1()
//{
//	char* c_cpDB_Connect_Str;
//	char*		cut_str = "/";
//
//	char*	field[5] = { NULL, NULL, NULL, NULL, NULL };
//
//	char*	a_cpTmpStr = new char[strlen(c_cpDB_Connect_Str) + 1];
//
//	sprintf(a_cpTmpStr, "%s", c_cpDB_Connect_Str);
//
//	field[0] = strtok(a_cpTmpStr, cut_str);		///< ���[�U��
//	field[1] = strtok(NULL, cut_str);			///< �p�X���[�h
//	field[2] = strtok(NULL, cut_str);			///< �o�[�W����	
//	field[3] = strtok(NULL, cut_str);			///< �C���X�^���X
//	field[4] = strtok(NULL, cut_str);			///< �T�[�o��
//
//}


void getenv(void)
{
	//bool bSts = true;
	//FILE *fp;

	//// PostGIS default
	///*m_PostGIS_Param.bAddField_OID = true;
	//m_PostGIS_Param.bIgnoreInsertErr = false;
	//m_PostGIS_Param.bMeshClip = false;*/

	//if ((fp = fopen(CONFIGFILE, "r"))) {
	//	cout << "<<< SiNDYExportPGDB Tool�p�����[�^ >>>" << endl;
	//	char    aStr[256];
	//	while (fgets(aStr, 256, fp) != NULL) {
	//		aStr[strlen(aStr) - 1] = '\0';
	//		if (aStr[0] == '#')	continue;
	//		int		i = 0;
	//		char	*s;
	//		char	aWork[256], aVal[256], aInBuff[1024];
	//		strcpy(aInBuff, aStr);
	//		for (s = strtok(aInBuff, "\t"); s != NULL; s = strtok(NULL, "\t")) {
	//			if (!s) continue;
	//			strcpy(aWork, s);
	//			s = strtok(NULL, "\t");
	//			if (s) strcpy(aVal, s);

	//			//< # �ݒ�t�@�C���ւ̃p�X
	//			if ((!strcmp("CONVERT_PATH", aWork)) && (strlen(aVal))) {
	//				//m_strConvertFilePath = aVal;
	//			}// cout << _T("CONVERT_PATH	= ") << aVal << endl;

	//			 //< # PGDB�t�@�C���ւ̃p�X
	//			else if ((!strcmp("PGDB_PATH", aWork)) && (strlen(aVal))) {
	//				//m_strPGDBFilePath = aVal;
	//			}// cout << _T("PGDB_PATH	= ") << aVal << endl;

	//			 //< # �ϊ��t�B�[���h
	//			else if ((!strcmp("FIELD_PATH", aWork)) && (strlen(aVal))) {
	//				//m_strFieldFilePath = aVal;
	//			}//cout << _T("FIELD_PATH	= ") << aVal << endl;

	//			 //< # �ϊ����b�V�����X�g
	//			else if ((!strcmp("MESHLIST", aWork)) && (strlen(aVal))) {
	//				//m_strMeshFilePath = aVal;
	//			}//cout << _T("MESHLIST	= ") << aVal << endl;

	//			 //< # �ϊ����O�t�@�C��
	//			else if ((!strcmp("CONVERT_LOG", aWork)) && (strlen(aVal))) {
	//				//m_strConvertLogFilePath = aVal;
	//			}//cout << _T("CONVERT_LOG	= ") << aVal << endl;

	//			 //< �����N��֘A�e�[�u���ϊ��H
	//			else if ((!strcmp("CONVERT_NWTBL", aWork)) && (strlen(aVal))) {
	//				//m_cnvNwTbl = atoi(aVal);
	//			}//cout << _T("CONVERT_NWTBL	= ") << aVal << endl;

	//			 //< ���b�V���|���S���ϊ��H
	//			else if ((!strcmp("CONVERT_MESH", aWork)) && (strlen(aVal))) {
	//				//m_cnvMeshPoly = atoi(aVal);
	//			}//cout << _T("CONVERT_MESH	= ") << aVal << endl;

	//			 //< SDE-OBJECT�ϊ��H
	//			else if ((!strcmp("CONVERT_OBJECT", aWork)) && (strlen(aVal))) {
	//				//m_cnvObject = atoi(aVal);
	//			}

	//			//< TIME-REG_TBL�ϊ��H add masuda
	//			else if ((!strcmp("CONVERT_TIME-REG_TBL", aWork)) && (strlen(aVal))) {
	//				//m_cnvTimeTbl = atoi(aVal);
	//			}

	//			//< DRMA���������v�H[Bug 4381]�y�v�]�z�������w�肵���l�� PGDB �ϊ������� Add 2006/6/7
	//			else if ((!strcmp("CONVERT_DRM_ATTR", aWork)) && (strlen(aVal))) {
	//				//m_cnvDRMA_Attr = atoi(aVal);
	//			}

	//			//< # PostGIS�T�[�o�[
	//			else if ((!strcmp("POSTGIS_DB", aWork)) && (strlen(aVal)))
	//			{
	//				vector<std::string> m_strPostGISServer;
	//				std::string strLine;
	//				strLine = aVal;
	//				//std::stringTokenizer strToken(strLine, std::string(_T(",")));
	//				//long count = strToken.CountTokens();
	//				std::stringArray cArray;
	//				//for (long i = 0; i<count; i++) {
	//					//std::string cstr(strToken.GetNextToken());
	//					//cstr.TrimLeft();
	//					//m_strPostGISServer.push_back(cstr);
	//				//}
	//			}
	//			//< # PostGIS�p�ϊ��p�����[�^
	//			else if ((!strcmp("POSTGIS_ADD_FIELD_OID", aWork)) && (strlen(aVal)))
	//			{
	//				/*if (0 == atoi(aVal))
	//					m_PostGIS_Param.bAddField_OID = false;
	//				else
	//					m_PostGIS_Param.bAddField_OID = true;*/
	//			}
	//			//< # PostGIS�p�ϊ��p�����[�^
	//			else if ((!strcmp("POSTGIS_IGNORE_INSERT_ERR", aWork)) && (strlen(aVal)))
	//			{
	//				/*if (0 == atoi(aVal))
	//					m_PostGIS_Param.bIgnoreInsertErr = false;
	//				else
	//					m_PostGIS_Param.bIgnoreInsertErr = true;*/
	//			}
	//			//< # PostGIS�p�ϊ��p�����[�^
	//			else if ((!strcmp("POSTGIS_MESH_CLIP", aWork)) && (strlen(aVal)))
	//			{
	//				/*if (0 == atoi(aVal))
	//					m_PostGIS_Param.bMeshClip = false;
	//				else
	//					m_PostGIS_Param.bMeshClip = true;*/
	//			}
	//		}
	//	}
	//	(void)fclose(fp);
	//}
	//return bSts;
}