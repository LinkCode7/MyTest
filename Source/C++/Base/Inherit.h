#pragma once




class ILineData
{
	ILineData() {} // ��ֹʵ������ռ�ռ�

	void LineFunction()
	{
		//std::cout << this->m_i << std::endl;
	}
};


class LineData:public ILineData
{
public:
	int m_i;
};