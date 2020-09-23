#pragma once





int g_iConstructCount = 0;
int g_iDestructCount = 0;

class Point
{
public:
	Point::Point()
	{
		m_i = 0;
		++g_iConstructCount;
		std::cout << "Point()" << std::endl;
	}

	Point::Point(const Point& oth)
	{
		m_i = oth.m_i;
		std::cout << "Point(const Point& oth)" << std::endl;
	}

	Point::Point(Point&& oth)noexcept
	{
		m_i = oth.m_i;
		//oth.m_i = nullptr;
		std::cout << "Point(const Point&& oth)" << std::endl;
	}

	Point& Point::operator=(const Point& oth)
	{
		m_i = oth.m_i;
		std::cout << "Point::operator=(const Point& oth)" << std::endl;
		return *this;
	}

	Point& Point::operator=(Point&& oth)noexcept
	{
		m_i = oth.m_i;
		//oth.m_i = nullptr;
		std::cout << "Point::operator=(const Point&& oth)" << std::endl;
		return *this;
	}

	Point::~Point()
	{
		++g_iDestructCount;
		std::cout << "~Point()" << std::endl;
	}

private:
	int m_i;
};