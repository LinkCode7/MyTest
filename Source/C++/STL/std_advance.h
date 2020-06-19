#pragma once

// ��������Ӧ�ͱ�֮ iterator_category
/*
�����ƶ�������ʩ�в�������������Ϊ��
// ++
InputIterator��ֻ��
OutputIterator��ֻд
FarwardIterator������д�����㷨��replace���ڴε�����ָ��Ŀռ��϶�д
// ++,--
BidirectionalIterator��˫���ƶ����磺���򿽱�ĳ����Χ�ڵ�Ԫ�أ�
// 
RandomAccessIterator����������ָ������������++,--,p+n,p-n,p[n],p1-p2,p1<p2,p1!=p2,p1==p2��

*/


// 1.��Щ��ֻ�������
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag :public forward_iterator_tag {};
struct random_access_iterator_tag :public bidirectional_iterator_tag {};


// 2.���ز�ͬ�汾�� advance()
template<class InputIterator, class Distance>
void __advance(InputIterator it, Distance n, input_iterator_tag) // ��ָ���βΣ��������������
{
	// ������һǰ��
	while (n--) ++i;
}

template<class BidIrectionalIterator, class Distance>
void __advance(BidIrectionalIterator it, Distance n, forward_iterator_tag)
{
	// ����
	__advance(it, n, input_iterator_tag());
}

template<class BidIrectionalIterator, class Distance>
void advance_BI(BidIrectionalIterator it, Distance n, bidirectional_iterator_tag)
{
	// ˫����һǰ��
	if (n >= 0)
		while (n--) ++i;
	else
		while (n++) --i;
}

template<class RandomAccessIterator, class Distance>
void __advance(RandomAccessIterator it, Distance n, random_access_iterator_tag)
{
	// ˫����Ծǰ��
	it += n;
}


// 3.�ṩһ������ʹ�õĽӿ�
template<class InputIterator, class Distance>
void MyAdvance(InputIterator it, Distance n)
{
	// iterator_category()����һ�����ڵ�����������ʱ����
	__advance(it, n, iterator_trait<InputIterator>::iterator_category());
}


// 4.����trait���һ���ͱ�
template<class I>
struct iterator_trait
{
	typedef typename I::iterator_category iterator_category;
};

// Ϊ��ԭ��ָ�롱��Ƶ�ƫ�ػ�(partial specialization)
template<class T>
struct iterator_trait<T*>
{
	// ��ԭ��ָ�롱����Random Access Iterator,Ӧ������ǿ��Χ��
	typedef random_access_iterator_tag iterator_category;
};

// Ϊ��ԭ��ָ�롱const��(point-to-const)��Ƶ�ƫ�ػ�
template<class T>
struct iterator_trait<const T*>
{
	typedef random_access_iterator_tag iterator_category;
};