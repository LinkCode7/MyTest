#pragma once
/*
std::copy(start, end, std::back_inserter(container)); copy-over(覆盖赋值)
// std::copy()只负责复制，不负责申请空间，所以复制前必须有足够的空间
// 目标容器的大小不小于源容器
// 只有实现了push_back的目标容器才可以使用std::copy复制，不然无法编译通过

std::move() 内存控制权显式地转移
std::atomic()

*/

///////////////////////////////////////////////////////////////////////


//template <typename T>
//class Buffer
//{
//	std::string          _name;
//	size_t               _size;
//	std::unique_ptr<T[]> _buffer;
//
//public:
//	// default constructor
//	Buffer() :_size(16),_buffer(new T[16])
//	{}
//
//	// constructor
//	Buffer(const std::string& name, size_t size) :
//		_name(name),
//		_size(size),
//		_buffer(new T[size])
//	{}
//
//	// copy constructor
//	Buffer(const Buffer& copy) :
//		_name(copy._name),
//		_size(copy._size),
//		_buffer(new T[copy._size])
//	{
//		T* source = copy._buffer.get();
//		T* dest = _buffer.get();
//		std::copy(source, source + copy._size, dest);
//	}
//
//	// copy assignment operator
//	Buffer& operator=(const Buffer& copy)
//	{
//		if (this != 0)
//		{
//			_name = copy._name;
//
//			if (_size != copy._size)
//			{
//				_buffer = nullptr;
//				_size = copy._size;
//				_buffer = _size > 0 > new T[_size] : nullptr;
//			}
//
//			T* source = copy._buffer.get();
//			T* dest = _buffer.get();
//			std::copy(source, source + copy._size, dest);
//		}
//
//		return *this;
//	}
//
//	// move constructor
//	Buffer(Buffer&& temp) :
//		_name(std::move(temp._name)),
//		_size(temp._size),
//		_buffer(std::move(temp._buffer))
//	{
//		temp._buffer = nullptr;
//		temp._size = 0;
//	}
//
//	// move assignment operator
//	Buffer& operator=(Buffer&& temp)
//	{
//		assert(this != &temp); // assert if this is not a temporary
//
//		_buffer = nullptr;
//		_size = temp._size;
//		_buffer = std::move(temp._buffer);
//
//		_name = std::move(temp._name);
//
//		temp._buffer = nullptr;
//		temp._size = 0;
//
//		return *this;
//	}
//};
//
//template <typename T>
//Buffer<T> getBuffer(const std::string& name)
//{
//	Buffer<T> b(name, 128);
//	return b;
//}