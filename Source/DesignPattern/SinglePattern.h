#pragma once


class SinglePattern1
{
	int m_id;
public:

	SinglePattern1()
	{
		//...
		m_id = 1001;
	}

	static SinglePattern1& Instance();

	int GetId()
	{
		return m_id;
	}

	void SetId(int id)
	{
		m_id = id;
	}
};

#define SingleOpr SinglePattern1::Instance()