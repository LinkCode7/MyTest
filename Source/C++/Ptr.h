#pragma once

#pragma warning(disable:4996)
//...
template <typename T>
class Ptr
{
	T *_ptr;
	size_t *_reference_count;


	void releaseCount()
	{
		if (_ptr)
		{
			(*_reference_count)--;
			if ((*_reference_count) == 0)
			{
				delete _ptr;
				delete _reference_count;
			}
		}
	}
public:
	//构造函数  
	Ptr(T* p = 0) : _ptr(p), _reference_count(new size_t)
	{
		if (p)
			*_reference_count = 1;
		else
			*_reference_count = 0;
	}
	//拷贝构造函数  
	Ptr(const Ptr& src)
	{
		if (this != &src)
		{
			_ptr = src._ptr;
			_reference_count = src._reference_count;
			(*_reference_count)++;
		}
	}
	//重载赋值操作符  
	Ptr& operator=(const Ptr& src)
	{
		if (_ptr == src._ptr)
			return *this;

		releaseCount();
		_ptr = src._ptr;
		_reference_count = src._reference_count;
		(*_reference_count)++;
		return *this;
	}

	//重载操作符
	T& operator*()
	{
		if (ptr)
			return *_ptr;

		//throw exception  
	}
	//重载操作符
	T* operator->()
	{
		if (ptr)
			return _ptr;

		//throw exception  
	}
	//析构函数
	~Ptr()
	{
		if (--(*_reference_count) == 0)
		{
			delete _ptr;
			delete _reference_count;
		}
	}
	
};

// Test class
class Table
{
	char* name;

public:
	Table(const char* na)
	{
		if (!na) return;
		name = new char(strlen(na) + 1); //zh
		strcpy(name, na);
	}
	Table& operator=(const Table table)
	{
		if (!table.name) return *this;
		name = new char[strlen(table.name) + 1];
		strcpy(name, table.name);
	}

	~Table()
	{

	}
};


//typedef _com_ptr_t<_com_IIID<IFeatureClass, &__uuidof(IFeatureClass)>> IFeatureClassPtr;
typedef Ptr<Table> TablePtr;