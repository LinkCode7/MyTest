#pragma once
//#include <atlbase.h>
//#include "TDC\useful_headers\str_util.h"

// ��v�ȃ��W�X�g���p�X�̐錾
#define REGPATH_IPC _T("Software\\INCREMENT P CORPORATION\\")
#define REGPATH_SINDY_E_TOOLS  REGPATH_IPC _T("SiNDY-e\\Tools\\")
#define REGPATH_SINDY_E_COMMON REGPATH_SINDY_E_TOOLS _T("COMMON\\")
#define REGPATH_SINDY_E_CHILDDLG REGPATH_SINDY_E_TOOLS _T("AttributeTool\\")
#define REGPATH_SINDY_K REGPATH_IPC _T("SiNDY-k\\")
#define REGPATH_SINDY_M REGPATH_IPC _T("SiNDY-m\\")
#define REGPATH_SINDY_U REGPATH_IPC _T("SiNDY-u\\")
#define REGPATH_SINDY_GL REGPATH_IPC _T("SiNDY-global\\")

//namespace uh {
//	namespace reg_util {
//
//		inline bool open(HKEY hkey, const std::string& path, CRegKey& reg)
//		{
//			//���W�X�g���L�[���Ȃ���Ύ��s
//			return (ERROR_SUCCESS == reg.Open(hkey, path));
//		}
//
//		inline bool create(HKEY hkey, const std::string& path, CRegKey& reg)
//		{
//			return (ERROR_SUCCESS == reg.Create(hkey, path));
//		}
//
//		/// REG_SZ�̒l����������
//		inline bool write(const std::string& val, const std::string& key, const std::string& path, HKEY hkey = HKEY_CURRENT_USER)
//		{
//			CRegKey reg;
//
//			if (!create(hkey, path, reg))
//				return false;
//
//			return (ERROR_SUCCESS == reg.SetStringValue(key, val));
//		}
//
//		/// REG_DWORD�̒l����������
//		inline bool write(long val, const std::string& key, const std::string& path, HKEY hkey = HKEY_CURRENT_USER)
//		{
//			CRegKey reg;
//
//			if (!create(hkey, path, reg))
//				return false;
//
//			return (ERROR_SUCCESS == reg.SetDWORDValue(key, val));
//		}
//
//		/// �L�[���폜����
//		inline bool deletekey(const std::string& key, const std::string& path, HKEY hkey = HKEY_CURRENT_USER)
//		{
//			CRegKey reg;
//			if (!open(hkey, path, reg))
//				return false;
//
//			return (ERROR_SUCCESS == reg.DeleteValue(key));
//		}
//
//		/// ���݊m�F
//		inline bool exist(const std::string& key, const std::string& path, HKEY hkey = HKEY_CURRENT_USER)
//		{
//			CRegKey reg;
//			if (!open(hkey, path, reg))
//				return false;
//
//			DWORD type = 0;
//			return (ERROR_SUCCESS == reg.QueryValue(key, &type, NULL, NULL));
//		}
//
//		/// ���������ňقȂ�^�̖߂�l��Ԃ��I�[�o�[���[�h�֐����ǂ����������邽�߂̏��׍H�N���X
//		class read
//		{
//		public:
//			/**
//			* @brief �R���X�g���N�^
//			* @breaf �����I�Ȋ֐�
//			* @param[in]          _key ���W�X�g���̃L�[
//			* @param[in] _path	_hkey�����������W�X�g���L�[�܂ł̃p�X
//			* @param[in,optional] _default �L�[�����������ꍇ�ɕԂ��l
//			* @param[in,optional] createDefaultKey �L�[�����������ꍇ�ɍ쐬����i�f�t�H���g�Ffalse�j
//			* @param[in,optional] _hkey	HKEY_XXX�̃L�[�i�f�t�H���g�FHKEY_CURRENT_USER�j
//			*/
//			read(LPCTSTR _key, const std::string& _path, const CComVariant& _default = CComVariant(), bool createDefaultKey = false, HKEY _hkey = HKEY_CURRENT_USER) :
//				key(_key),
//				path(_path),
//				hkey(_hkey),
//				va_default(_default),
//				m_createDefaultKey(createDefaultKey)
//			{
//			}
//
//			/// REG_DWORD�̒l��Ԃ�
//			operator long()
//			{
//				DWORD lVal = 0;
//
//				bool ok = false;
//				if (open(hkey, path, reg))
//				{
//					ok = (ERROR_SUCCESS == reg.QueryDWORDValue(key, lVal));
//					reg.Close();
//				}
//
//				if (!ok)
//				{
//					// �f�t�H���g�w��Ȃ��iVT_EMPTY�j�Ȃ�0
//					lVal = va_default.lVal;
//
//					if (m_createDefaultKey)
//						write(lVal, key, path, hkey);
//				}
//
//				return (long)lVal;
//			}
//
//			/// REG_DWORD��0�܂��̓L�[���������false�B�����łȂ����true
//			operator bool()
//			{
//				DWORD lVal = 0;
//
//				bool ok = false;
//				if (open(hkey, path, reg))
//				{
//					ok = (ERROR_SUCCESS == reg.QueryDWORDValue(key, lVal));
//					reg.Close();
//				}
//
//				if (!ok)
//				{
//					// �f�t�H���g�w��Ȃ��iVT_EMPTY�j�Ȃ�0
//					lVal = va_default.boolVal ? 1 : 0;
//
//					if (m_createDefaultKey)
//						write(lVal, key, path, hkey);
//				}
//
//				return (lVal != 0);
//			}
//
//			/// REG_SZ�̒l��Ԃ�
//			operator std::string()
//			{
//				std::string strVal;
//
//				bool ok = false;
//				if (open(hkey, path, reg))
//				{
//					ULONG uLen = 0;
//					if (ERROR_SUCCESS == reg.QueryStringValue(key, NULL, &uLen))
//					{
//						ok = (ERROR_SUCCESS == reg.QueryStringValue(key, strVal.GetBuffer(uLen), &uLen));
//						strVal.ReleaseBuffer();
//					}
//					reg.Close();
//				}
//
//				// �L�[���Ȃ��ꍇ
//				if (!ok)
//				{
//					strVal = va_default;
//
//					if (m_createDefaultKey)
//						write(strVal, key, path, hkey);
//				}
//
//				return strVal;
//			}
//
//		private:
//			HKEY hkey;              //!< �I�[�v������HKEY
//			std::string path;           //!< �I�[�v������T�u�L�[
//			std::string key;            //!< �I�[�v������L�[��
//			CComVariant va_default; //!< �L�[���Ȃ������ꍇ�ɕԂ��l
//			CRegKey reg;            //!< ���W�X�g������p
//			bool m_createDefaultKey; //!< �L�[���Ȃ���������
//		};
//
//		/**
//		* @brief RGB�l�Ƃ��ēǂݍ���
//		* @breaf REG_SZ �� R,G,B �ŏ����ꂽ�l��RGB�l�Ƃ��Ď擾����
//		* @param[in]          key ���W�X�g���̃L�[
//		* @param[in]          path	hkey�����������W�X�g���L�[�܂ł̃p�X
//		* @param[in,optional] defColor �L�[�����������ꍇ�ɕԂ��l
//		* @param[in,optional] createDefaultKey	�L�[���Ȃ������ꍇ�̓f�t�H���g�l�ō쐬����i�f�t�H���g�Ffalse�j
//		* @param[in,optional] hkey	HKEY_XXX�̃L�[�i�f�t�H���g�FHKEY_CURRENT_USER�j
//		*/
//		inline COLORREF readRGB(LPCTSTR key,
//			const std::string& path,
//			const COLORREF& defColor = RGB(0, 0, 0),
//			bool createDefaultKey = false,
//			HKEY hkey = HKEY_CURRENT_USER)
//		{
//			std::string defRGB = str_util::format(_T("%ld,%ld,%ld"),
//				(long)GetRValue(defColor),
//				(long)GetGValue(defColor),
//				(long)GetBValue(defColor));
//
//			// r,g,b �ŏ�����Ă���z��
//			std::string strRGB = read(key, path, CComVariant(defRGB), createDefaultKey);
//			std::vector<std::string> rgbLst = str_util::split(strRGB, _T(","));
//
//			// ���������m�F
//			if (rgbLst.size() != 3)
//				return defColor;
//
//			// ���Ƃ� _tstol() �C���B�����ƕϊ��ł��Ȃ��Ă��m��Ȃ��B
//			return RGB(_tstol(rgbLst[0]), _tstol(rgbLst[1]), _tstol(rgbLst[2]));
//		}
//
//	} // reg_util 
//} // uh
