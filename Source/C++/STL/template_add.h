#pragma once
template<bool T, class T1, class T2>
class BoolTrait;

template<typename T1, typename T2>
class BoolTrait<true, T1, T2>
{
public:
	typedef T1 ResultT;
};

template<typename T1, typename T2>
class BoolTrait<false, T1, T2>
{
public:
	typedef T2 ResultT;
};

////////////////////////////////////////////////////////////

template<typename bigSize, typename smallSize>
class ReturnValue
{
public:
	// ͨ���ֽڳ����жϾ���
	typedef typename BoolTrait<(sizeof(bigSize) > sizeof(smallSize)), bigSize, smallSize>::ResultT ResultT;
};

//��Ϊint��float������ռ���ֽ���ͬ�������޷�ͨ���Ƚϴ�С���ж����͵ľ��ȣ���Ҫƫ�ػ�  
template<>
class ReturnValue<float, int>
{
public:
	typedef float ResultT;
};
template<>
class ReturnValue<int, float>
{
public:
	typedef float ResultT;
};

// Add
template<typename t1, typename t2>
typename ReturnValue<t1, t2>::ResultT Add(T1 lhs, T2 rhs)
{
	return lhs + rhs;
}