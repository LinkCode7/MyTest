#include "stdafx.h"
#include <initializer_list>
#include <array>


using namespace std;

double sum(std::initializer_list<double> il)
{
	double total{ 0 };
	for (auto p = il.begin(); p != il.end(); p++)
	{
		total += *p;
	}
	return total;
}

template<typename T, typename U>
decltype(T*U) useful(T t, U u)
{
	decltype(T*U) re(t*u);
	return re;
}

template<typename T, typename U>
auto eff(T t, U u) -> decltype(T*U)
{
	// ...
}

template<typename T>
using arr12 = std::array<T, 12>; // template for multiple aliases: ���廯ģ��<T, int>


void base2();
void Base()
{
	// 1
	int x = { 5 };
	double y{ 3.14 };
	short quar[5]{ 2,4,6,8 };
	// class A ...

	int* arr = new int[4]{ 2,3,4,5 };

	// {}��������ķ�Χ
	char c1 = 1.57e27;
	char c2 = 459585821;

	char c3{ 66 };
	char c4{ 66 };


	// 2
	vector<int> vec1(10); // 10��δ��ʼ����ֵ
	vector<int> vec2{ 10 }; // ����һ��Ԫ�أ�10
	vector<int> vec{ 1,2,3,4,5 }; // ��ʼ��5��N����Ԫ��


	// 3
	double total = sum({ 2.0,3.1,4 }); // �����߿�����ôд


	//// 4 auto
	//auto maton = 112; // type:int
	//auto pt = &maton; // type:int*
	//double fm(double, int);
	//auto pf = fm; // type: double (*)(double,int)
	//// auto�򻯵���������


	// 5 decltype
	// ����������������Ϊ���ʽָ��������
	decltype(x) yy; // ��yy��������x��ͬ
	double xx;
	int n;
	decltype(xx*n) q; // q same type as x*n,i.e,double
	decltype(&xx) pd; // pd same as &x,i.e,double*

	// decltype�ڶ���ģ��ʱ�ǳ�����
	//useful(char('a'), short(5)); // resultΪint����

	int j = 3;
	int &k = j;
	const int &nn = j;
	decltype(nn) i1 = 5;		// const int&�������ʼ��
	decltype(j) i2;			// int
	decltype((j)) i3 = j;	// int&�������ʼ��
	decltype(k + 1) i4;		// int


	// 6 �����������ͺ����������ں����������ڲ����б��ָ���������ͣ�
	double f1(double, int);			// traditional syntax
	auto f2(double, int) -> double; // return type: double

	//eff(3.14, 5); // ����������eff�����б�ʱ��T��U�������������ڣ����Ҫ�ڲ����б��ʹ��decltype


	// 7 ģ�������using = 
	using itType = std::vector<std::string>::iterator; // �˴�������typedef�����߳�����

	
	//arr12<double> a1; // std::array<double, 12> a1;
	//arr12<std::string> a2; // std::array<std::string, 12> a2;


	// 8 nullptr


	// 9 ����ָ�루��������ָ�붼�����ƶ�����Эͬ������


	// 10 �����쳣�Ĳ���������void fun() throw���쳣�淶�����noexcept�ؼ��֣������������������쳣��


	// 11 ö��
	enum Old1 {yes,no,mabe};
	//enum Old2 {yes,oh}; // error C2365: ��Base::yes��: �ض���

	enum class New1 {never,sometimes,often,always};
	enum class New2 {never,ok};								// ����ͬ��
	enum struct New3 { never, sometimes, often, always };


	base2();
}




class Plebe
{
	Plebe(int);					// automatic int-to-plete conversion
	explicit Plebe(double);		// requires explicit use
};

class Session
{
	int num = 0;
	double pi{ 3.14 }; // ����ʹ��С���ų�ʼ�������ͬ�ڹ���

public:
	Session(int n, double p):num(n), pi(p) {} // ���캯���ĳ�Ա��ʼ���б����Ḳ�����ڳ�ʼ����ֵ
};
void base2()
{
	// 1 ������޸�

	// 1.1 ��ʽת�������
	/*Plebe a, b; //zh
	a = 5;
	b = 0.5;
	b = Plebe(0.5);*/


	// 1.2 ���ڳ�ʼ����Ա����


	// 2 ģ���STL������޸�

	// 2.1 ���ڷ�Χ��forѭ�����������������ʵ��begin()��end()���������STL���������ԣ���
	double prices[5] = { 1,2,3,4,5 };
	for (auto x : prices)		// ֻ����ü�const: for (const auto TypeName : Type)
	{
		std::cout << x << std::endl;
	}

	for(auto& x: prices) // ��Ҫ�޸�
	{
		x = std::rand();
	}


	// 2.2 �µ�STL����

	// ��������
	// forward_list,unordered_map,unordered_multimap,unordered_set,unordered_multiset

	std::array<int,10> arr;


	// 2.3 �µ�STL����

	// cbegin(),cend(),		crbegin()��crend()��rbegin()��rend()��const�汾


	// 2.4 valarray����������C++11�������������begin()��end()����valarray��������ʹvalarray�����û��ڷ�Χ��forѭ����


	// 2.5 ���� export�ؼ���


	// 2.6 �����ţ�����Ƕ��ģ��ʱ���Բ��ֿ������� vector<list<int>> data;


	// 3 ��ֵ����

}