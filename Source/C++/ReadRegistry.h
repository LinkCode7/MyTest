#pragma once
//#include <atlbase.h>
//#include "TDC\useful_headers\str_util.h"

// 主要なレジストリパスの宣言
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
//			//レジストリキーがなければ失敗
//			return (ERROR_SUCCESS == reg.Open(hkey, path));
//		}
//
//		inline bool create(HKEY hkey, const std::string& path, CRegKey& reg)
//		{
//			return (ERROR_SUCCESS == reg.Create(hkey, path));
//		}
//
//		/// REG_SZの値を書き込む
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
//		/// REG_DWORDの値を書き込む
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
//		/// キーを削除する
//		inline bool deletekey(const std::string& key, const std::string& path, HKEY hkey = HKEY_CURRENT_USER)
//		{
//			CRegKey reg;
//			if (!open(hkey, path, reg))
//				return false;
//
//			return (ERROR_SUCCESS == reg.DeleteValue(key));
//		}
//
//		/// 存在確認
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
//		/// 同じ引数で異なる型の戻り値を返すオーバーロード関数もどきを実現するための小細工クラス
//		class read
//		{
//		public:
//			/**
//			* @brief コンストラクタ
//			* @breaf 実質的な関数
//			* @param[in]          _key レジストリのキー
//			* @param[in] _path	_hkeyを除いたレジストリキーまでのパス
//			* @param[in,optional] _default キーが無かった場合に返す値
//			* @param[in,optional] createDefaultKey キーが無かった場合に作成する（デフォルト：false）
//			* @param[in,optional] _hkey	HKEY_XXXのキー（デフォルト：HKEY_CURRENT_USER）
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
//			/// REG_DWORDの値を返す
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
//					// デフォルト指定なし（VT_EMPTY）なら0
//					lVal = va_default.lVal;
//
//					if (m_createDefaultKey)
//						write(lVal, key, path, hkey);
//				}
//
//				return (long)lVal;
//			}
//
//			/// REG_DWORDが0またはキーが無ければfalse。そうでなければtrue
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
//					// デフォルト指定なし（VT_EMPTY）なら0
//					lVal = va_default.boolVal ? 1 : 0;
//
//					if (m_createDefaultKey)
//						write(lVal, key, path, hkey);
//				}
//
//				return (lVal != 0);
//			}
//
//			/// REG_SZの値を返す
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
//				// キーがない場合
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
//			HKEY hkey;              //!< オープンするHKEY
//			std::string path;           //!< オープンするサブキー
//			std::string key;            //!< オープンするキー名
//			CComVariant va_default; //!< キーがなかった場合に返す値
//			CRegKey reg;            //!< レジストリ操作用
//			bool m_createDefaultKey; //!< キーがなかったら作る
//		};
//
//		/**
//		* @brief RGB値として読み込む
//		* @breaf REG_SZ で R,G,B で書かれた値をRGB値として取得する
//		* @param[in]          key レジストリのキー
//		* @param[in]          path	hkeyを除いたレジストリキーまでのパス
//		* @param[in,optional] defColor キーが無かった場合に返す値
//		* @param[in,optional] createDefaultKey	キーがなかった場合はデフォルト値で作成する（デフォルト：false）
//		* @param[in,optional] hkey	HKEY_XXXのキー（デフォルト：HKEY_CURRENT_USER）
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
//			// r,g,b で書かれている想定
//			std::string strRGB = read(key, path, CComVariant(defRGB), createDefaultKey);
//			std::vector<std::string> rgbLst = str_util::split(strRGB, _T(","));
//
//			// 書式だけ確認
//			if (rgbLst.size() != 3)
//				return defColor;
//
//			// あとは _tstol() 任せ。ちゃんと変換できなくても知らない。
//			return RGB(_tstol(rgbLst[0]), _tstol(rgbLst[1]), _tstol(rgbLst[2]));
//		}
//
//	} // reg_util 
//} // uh
