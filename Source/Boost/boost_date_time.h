#pragma once


/*
���ڣ������ա�����
ʱ�䣺
*/

/*
ʱ���ࣺyears,months,days(weeks)


boost::progress_timer�Ǽ�ʱ��
*/



namespace TestDate
{
	// date����Ϊ��λ�����ں�����
	// ʱ���ࣺ�ꡢ�¡���
	// �����ࣺ�������䡢���ڵ�����

	// ����
	void test_date();

	// ����ʱ��������
	void test_date_duration();
	// ��������
	void calculate_date();

	// ��������
	void _date_period();

	// ���ڵ�����
	void date_iterator();

	void static_function();

} // namespace TestDate









namespace TestTimeAndPTime
{
	// ʱ�䳤��
	void _time_duration();


	// ʱ���
	void _p_time();
	// ʱ������
	void _time_period();

	// ʱ�������
	void _time_iterator();

	// ��ʽ��ʱ��
	void format_time();

} // namespace TestTimeAndPTime