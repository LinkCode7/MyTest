#include "stdafx.h"
#include "boost_variant.h"

#include <boost/variant.hpp>

using namespace std;
using namespace boost;








// main
void boost_variant()
{
	variant<int, float, string> var;
	var = float(3.14);

	int index = var.which();

	assert(var.type() == typeid(float));
	const boost::typeindex::type_info& type = var.type();
	cout << type.name() << endl;

	float copy = boost::get<float>(var);


	boost_variant2();

	boost_variant_visitor();
}



/////////////////////////////////////////////////////////////////////////

void boost_variant2()
{
	typedef variant<int, double, string> var_t;
	var_t v;
	v = 2.13;

	var_t v2("string type");

	v2 = v;

	try
	{
		cout << boost::get<int>(v2) << endl;
	}
	catch (bad_get&)
	{
		cout << "bad_get" << endl;
	}
}


typedef variant<int, double> variant_t;

// RTTI����variant��variant���ͱ仯��Ҫ�޸ĺ�����C����ʽ��if-else
void __var_print(variant_t& v)
{
	if (v.type() == typeid(int))
	{
		boost::get<int>(v) *= 2;
		cout << v << endl;
	}
	else if (v.type() == typeid(double))
	{
		get<double>(v) *= 2;
		cout << v << endl;
	}
	else
	{
		cout << "don't know type" << endl;
	}
}



// visitorģʽ����variant������ģ������Ƶ�
void boost_variant_visitor()
{
	//__var_print();

	variant_t v(100);
	var_double_print vp;

	// variant�����һ����ʼ���ͣ���Ȼ������ģ��ĵ�һ�����ͳ�ʼ����������apply_visitor�Ƶ�����
	boost::apply_visitor(vp, v);

	v = 3.14;
	boost::apply_visitor(vp, v);

	variant<int, double, vector<int>> vari;
	vari = vector<int>({ 1,2 });
	boost::apply_visitor(vp, vari);
}






void var_double_print::operator()(std::vector<int>& vec) const
{
	/*for (auto& it : vec)
	{
		it *= 2;
		std::cout << it << std::endl;
	}*/

	vec.reserve(vec.size() * 2);
	std::copy(vec.begin(), vec.end(), std::back_inserter(vec));

	for (auto& it : vec)
	{
		std::cout << it << ",";
	}
	cout << std::endl;
}