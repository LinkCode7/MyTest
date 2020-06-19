#pragma once
#include <list>
#include <map>
#include <vector>

#define		CONFIGFILE	"config.txt"
typedef	std::vector<std::string> stringArray;

//void outMessage(const char* message)
//{
//	std::cout << std::endl << message << "line:" << __LINE__ << std::endl;
//}

struct ConnectionInfo
{
	std::string connectLink;

	std::string strUser;
	std::string strPassword;
	std::string strVersion;
	std::string strServer;

	std::string configFile1;
	std::string configFile2;
	std::string strReseave;

	std::string m_strLogFileName;

	std::list<long> m_listInfoID;
	std::map<long, long> m_mapInfoID;
};




/// �ǂݍ��݃^�C�v
enum LOADTYPE
{
	TYPE_PGDB,
	TYPE_ROAD,
	TYPE_MAP,
	TYPE_RASTER,
	TYPE_PATTERN,
};
/// ���C�����
struct LAYERINFO {
	std::string					strLayerName;		//!< �ݒ�t�@�C����layers�A�܂���dataset���ɂ��郌�C��
	std::string					strAliasName;		//!< �ݒ�t�@�C����layers�A�܂���dataset���ɂ��郌�C��(�G�C���A�X��)
	std::string					strSymbolName;		//!< ���C���̃V���{��
	std::string					strCheck;			//!< �`�F�b�N�{�b�N�X 0:�Ȃ�,1:�`�F�b�N
	LOADTYPE				lLoadType;			//!< 0:PGDB,1:���H,2:�n�},3:���X�^
	std::string					strPurpose;			//!< ��ƖړI
};
/// SDE�ڑ����
struct CONNECTIONINFO {
	std::string					strConnectionName;	//!< �ڑ����R���{�{�b�N�X

	std::string					strServer;
	std::string					strInstance;
	std::string					strUser;
	std::string					strPasswd;
	std::string					strVersion;

	std::string					strDataset;			//!< �ݒ�t�@�C����dataset
	std::string					strAddMode;			//!< �ݒ�t�@�C����AddMode(�Z�N�V�������ɂ���ꍇ�̓Z�N�V�������̋L�q���D�悳���)
	std::string					strGroupName;		//!< �ݒ�t�@�C����groupname
	std::list<LAYERINFO>	listLayerInfo;		//!< �ݒ�t�@�C����layers
	bool					bGroupLayerSDE;		//!< SDE�Ǎ��ݎ��O���[�v���C���ɒǉ����邩
	bool					bGroupLayer;		//!< �O���[�v���C���\���t���O
};

//bool GetPrivateProfileSectionTCharArray(LPCTSTR lpAppName, LPCTSTR lpFileName, std::vector<TCHAR>& vecResult);