#include "stdafx.h"
#include "boost_date_time.h"

#include <boost/date_time/gregorian/gregorian.hpp> // �������ڵ����
#include <boost/date_time/posix_time/posix_time.hpp> // ����ʱ������

using namespace std;
using namespace boost;




void boost_date_time()
{
	TestDate::test_date();

	TestDate::test_date_duration();

	TestDate::calculate_date();

	TestDate::_date_period();

	TestDate::date_iterator();

	TestDate::static_function();

	TestTimeAndPTime::_time_duration();

	TestTimeAndPTime::_p_time();

	TestTimeAndPTime::_time_period();

	TestTimeAndPTime::_time_iterator();

	TestTimeAndPTime::format_time();
}



namespace TestDate
{
	// ����
	void test_date()
	{
		using namespace boost::gregorian;

		cout << date(neg_infin) << endl;
		cout << date(pos_infin) << endl;

		cout << date(min_date_time) << endl;
		cout << date(max_date_time) << endl;

		date d1(2019, 8, 28);
		date d2(2018, Jan, 1);

		assert(d1 > d2);

		// �����ꡢ�¡���
		assert(d1.year() == 2019);
		assert(d1.month() == 8);
		assert(d1.day() == 28);

		date::ymd_type ymd = d1.year_month_day();

		cout << endl << "---------------------" << endl;
		// date��������(0��ʾ������)
		cout << d1.day_of_week() << endl;
		// ����ڼ���(366)
		cout << d1.day_of_year() << endl;
		// �������һ��
		cout << d1.end_of_month() << endl;

		// �����������ǵ���ĵڼ���(0-53)
		cout << date(2015, 1, 10).week_number() << endl;
		cout << date(2016, 1, 10).week_number() << endl;
		cout << date(2017, 1, 10).week_number() << endl;


		cout << endl;
		// dateת�ַ���
		cout << d1 << endl;
		cout << to_simple_string(d1) << endl;
		cout << to_iso_string(d1) << endl;
		cout << to_iso_extended_string(d1) << endl;

		// ��C���Ի�ת
		{
			date d3(2017, 7, 7);
			tm t = to_tm(d3);

			date d4 = date_from_tm(t);
		}
	}

	// ����ʱ��(��)������
	void test_date_duration()
	{
		using namespace boost::gregorian;

		// date_duration
		days dd1(10), dd2(-100), dd3(255);

		assert(dd1 > dd2 && dd1 < dd3);
		assert(dd3 / 5 == days(51));


		// �ꡢ�¡�����
		years y(2);
		months m(5);
		weeks w(3);

		assert(w.days() == 21);
		months m2 = y + m;

		assert(m2.number_of_months() == 29);
		assert((y * 2).number_of_years() == 4);
	}

	// ��������
	void calculate_date()
	{
		using namespace boost::gregorian;

		date d1(2000, 1, 1), d2(2019, 8, 29);

		cout << endl << "---------------------" << endl;
		cout << d2 - d1 << endl;

		assert(d1 + (d2 - d1) == d2);

		d1 += days(10);
		assert(d1.day() == 11);

		d1 += months(2);
		assert(d1.month() == 3 && d1.day() == 11);

		// (1)�����൱��(7)��
		d1 -= weeks(1);
		assert(d1.day() == 4);

		d2 -= years(10);
		assert(d2.year() == d1.year() + 9);


		// ��������months��years����ʱ�������ʱ�������������ĩ�����һ�죬��ô�Ӽ��¡�
		// ���õ���Ӧ����ĩʱ�䣬�����Ǽ򵥵��·ݻ����+-
		{
			date dd(2017, 3, 30);
			dd -= months(1);
			cout << to_iso_extended_string(dd) << endl; // 2017-2-28

			dd -= months(1);
			cout << to_iso_extended_string(dd) << endl; // 2017-1-31

			dd -= months(1);
			cout << to_iso_extended_string(dd) << endl; // 2016-12-31

			dd += months(2);
			cout << to_iso_extended_string(dd) << endl; // 2017-2-28
		}
	}

	// ��������
	void _date_period()
	{
		using namespace boost::gregorian;

		date_period dp1(date(2019, 1, 1), days(20));
		date_period dp2(date(2019, 1, 1), date(2019, 8, 30));

		date_period dp3(date(2019, 2, 2), days(10));

		assert(dp1.begin().day() == 1);
		assert(dp1.end().day() == 21);
		assert(dp1.last().day() == 20);

		assert(dp1.length().days() == 20);

		cout << endl << "---------------------" << endl;
		cout << dp2 << endl;

		assert(dp1.is_before(date(2050, 1, 1)));
		assert(dp1.is_after(date(1999, 1, 1)));
		assert(dp1.contains(date(2019, 1, 2))); //
		
		assert(dp2.intersects(dp3)); //


		// ƽ����������
		dp1.shift(days(3));
		cout << dp1.begin().day() << endl;
		cout << dp1.length().days() << endl;

		// ��������������������С
		dp1.expand(days(-1));
		cout << dp1.begin().day() << endl;
		cout << dp1.length().days() << endl;
	}

	// ���ڵ����������ض�����(X��X��X��) ++date��--date
	// ���ڵ�����������STL����ĵ��������û��difference_type��point��reference���ڲ�����
	void date_iterator()
	{
		using namespace boost::gregorian;

		date d(2007, 9, 28);

		day_iterator d_iter(d);
		assert(d_iter == d);

		++d_iter;
		assert(d_iter == date(2007, 9, 29));

		year_iterator y_iter(*d_iter, 10);
		assert(y_iter == d + days(1));

		--y_iter;
		assert(y_iter->year() == 1997);
	}

	// ���õľ�̬����
	void static_function()
	{
		using namespace boost::gregorian;

		// �ж�����
		cout << gregorian_calendar::is_leap_year(2008) << endl;

		assert(gregorian_calendar::end_of_month_day(2019, 8) == 31);
	}

} // namespace TestDate


















namespace TestTimeAndPTime
{
	// ʱ�䳤��
	void _time_duration()
	{
		using namespace boost::posix_time;

		// 1ʱ-10��-30��-1����(1000΢��)
		time_duration td(1, 10, 30, 1000);

		assert(td.total_seconds() == 1 * 3600 + 10 * 60 + 30); // ������������������΢��
		assert(td.fractional_seconds() == 1000);
		cout << td.total_milliseconds() << endl;

		time_duration tdNegative = td.invert_sign();
		assert(tdNegative.is_negative() == true);

		cout << to_simple_string(td) << endl;
		cout << to_iso_string(td) << endl;

		tm t = to_tm(td);


		// time_duration������
		hours h(1);
		minutes m(10);
		seconds s(61); // 61��
		millisec ms(1);

		time_duration td2 = h + m + s + ms;
		time_duration td3 = duration_from_string("1:10:30:001"); // ���ַ�����ʼ��

	}

	void _p_time()
	{
		using namespace boost::gregorian;
		using namespace boost::posix_time;
		
		ptime p(date(2019, 8, 30), hours(14)); // 2019-08-30-14

		ptime p1 = time_from_string("2017-7-7 01:00:00");
		ptime p2 = from_iso_string("20170707T010000");

		// universal_time()��ȡUTC��ǰʱ��
		ptime pt1 = second_clock::local_time(); // �뾫��
		ptime pt2 = microsec_clock::local_time(); // ΢���


		ptime pt(date(2019, 8, 30), hours(14) + minutes(47));

		date d = pt.date();
		time_duration td = p.time_of_day();
		assert(d.month() == 8 && d.day() == 30);
		assert(td.total_seconds() == 14 * 3600);// +47 * 60);

		ptime ptNew = pt + hours(3);

		ptNew += months(1);

		cout << to_simple_string(ptNew) << endl;
		cout << to_iso_string(ptNew) << endl;
		cout << to_iso_extended_string(ptNew) << endl;

		tm t = to_tm(ptNew);
		assert(ptime_from_tm(t) == ptNew);

		ptime ptt = from_time_t(std::time(0));
	}

	void _time_period()
	{
		using namespace boost::gregorian;
		using namespace boost::posix_time;

		ptime p(date(2017, 1, 1), hours(12));

		time_period tp1(p, hours(8));
		time_period tp2(p+hours(8), hours(1));

		assert(tp1.end() == tp2.begin() && tp1.is_adjacent(tp2));
		
		tp1.shift(hours(1));
		assert(tp1.is_after(p));
		assert(tp1.intersects(tp2));

		tp2.expand(hours(10));
		assert(tp2.contains(p) && tp2.contains(tp1));
	}

	void _time_iterator()
	{
		using namespace boost::gregorian;
		using namespace boost::posix_time;

		ptime p(date(2017, 5, 31), hours(10));

		cout << endl << "---------------------" << endl;
		for (time_iterator t_iter(p, minutes(10)); t_iter < p + hours(1); ++t_iter)
		{
			cout << *t_iter << endl;
		}
	}

	void format_time()
	{
		using namespace boost::gregorian;
		using namespace boost::posix_time;

		date d(2014, 11, 3);
		date_facet* pDFacet = new date_facet("%Y��%m��%d��");

		cout.imbue(locale(cout.getloc(), pDFacet));
		cout << d << endl;

		time_facet* pTFacet = new time_facet("%Y��%m��%d��%H��%M��%S%F��");

		cout.imbue(locale(cout.getloc(), pTFacet));
		cout << ptime(d, hours(21) + minutes(50) + millisec(100)) << endl;

		//PmDelete(pDFacet);
		//PmDelete(pTFacet);
	}

} // namespace TestTimeAndPTime