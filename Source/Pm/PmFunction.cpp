#include "stdafx.h"
#include "PmFunction.h"


namespace PmFunction
{
	

	bool Pow(double value, int num, double & result)
	{
		if (num < 0)
			return false;
		else if (num == 0)
		{
			if (value != 0)
				result = 1;
			else
				result = 0;
			return true;
		}
		else
		{
			result = value;
			for (int i = 1; i < num; i++)
			{
				result *= value;
			}

			//
			return true;
		}
	}


	template<class T>
	std::string CStrCut0(const T& value)
	{
		std::string strValue = PmFunction::CStr(value);

		int position = strValue.Find(_T("."));
		if (position >= 0)
		{
			// ȥ�������ַ����ұ���Ч��0��SC20.0100 -> SC20.01
			int length = strValue.GetLength();
			for (int i = 0; i < length - position; ++i)
			{
				// ���ұ߿�ʼȡ�ַ������ǲ��� 0 �� . 
				std::string strTemp = strValue.Right(i + 1);

				// ȡ��ߵ�һ������ΪstrTemp�ұߵ��Ѿ��ȽϹ���
				if (strTemp.Left(1) != _T("0"))
				{
					strValue = strValue.Left(length - i);
					break;
				}
			}

			if (strValue.Right(1) == _T("."))
				strValue = strValue.Left(strValue.GetLength() - 1);
		}

		return strValue;
	}



}
