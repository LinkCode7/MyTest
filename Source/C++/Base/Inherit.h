#pragma once




class ILineData
{
	ILineData() {} // 禁止实例，不占空间

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