#pragma once



// “∆∂Ø”Ô“Â£∫https://www.cnblogs.com/5iedu/p/11318729.html


class SimpleObject
{
public:
	int m_i;
	SimpleObject()
	{
		m_i = 100;
		std::cout << "SimpleObject()" << std::endl;
	}
	SimpleObject(int i)
	{
		m_i = i;
		std::cout << "SimpleObject(int i)" << std::endl;
	}
	SimpleObject(const SimpleObject& oth)
	{
		m_i = oth.m_i;
		std::cout << "SimpleObject(const SimpleObject& oth)" << std::endl;
	}

	~SimpleObject()
	{
		std::cout << "~SimpleObject()" << std::endl;
	}
};
typedef std::shared_ptr<SimpleObject> SimpleObjectPtr;