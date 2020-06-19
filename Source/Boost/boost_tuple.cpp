#include "stdafx.h"
#include <iostream>
#include <map>
#include <boost/tuple/tuple.hpp>


using namespace std;
void boost_tuple()
{// boost::tuple
	map<long, boost::tuple<bool, std::string, long>> mapItems;
	mapItems[0] = boost::make_tuple(true, "ABC", 10);
	mapItems[1] = boost::make_tuple(false, "XXX", 70);
	mapItems[2] = boost::make_tuple(true, "CBA", 60);

	// Access 2
	bool isTrue = mapItems[0].get<0>();
	for (const auto& item: mapItems)
	{
		bool isTrue1 = item.second.get<0>();
	}


	boost::tuple<int, int, bool> tu = boost::make_tuple(1, 1, false);

	int i1 = tu.get<0>();

	tu.get<0>() = 2;

	i1 = tu.get<0>();
}