#pragma once




class MyObject
{
public:
	MyObject()
	{
		m_i = 0;
		std::cout << "MyObject()" << std::endl;
	}
	~MyObject()
	{
		std::cout << "~MyObject()" << std::endl;
	}

	void Show()
	{
		std::cout << "Show()" << std::endl;
	}

private:
	int m_i;
};


template<typename T>
class SharedPtr
{
public:
	SharedPtr() :m_p(nullptr), m_pUseCount(nullptr) {}

	SharedPtr& operator=(const SharedPtr& oth)
	{
		if (this == &oth)
			return *this;

		if ((m_p && m_pUseCount) && (--(*this->m_pUseCount) == 0))
		{
			delete m_p;
			delete m_pUseCount;
		}

		m_p = oth.m_p;
		m_pUseCount = &(++(*oth.m_pUseCount));
		return *this;
	}

	T& operator*()
	{
		return *m_p;
	}
	T* operator->()
	{
		return m_p;
	}

	SharedPtr(T* p)
	{
		m_p = p;
		m_pUseCount = new int(1);
	}

	SharedPtr(const SharedPtr& oth)
	{
		m_p = oth.m_p;
		m_pUseCount = &(++(*oth.m_pUseCount));
	}

	~SharedPtr()
	{
		if (m_p && --(*m_pUseCount) == 0)
		{
			delete m_p;
			delete m_pUseCount;
		}
	}

public:

	T* get() { return m_p; }
	int use_count() { return *m_pUseCount; }

private:
	T* m_p;
	int* m_pUseCount;
};











class B;
class A
{
public:
	~A()
	{
		std::cout << "~A()" << std::endl;
	}

	SharedPtr<B> pb_;
};
class B
{
public:
	~B()
	{
		std::cout << "~B()" << std::endl;
	}

	SharedPtr<A> pa_;
};
