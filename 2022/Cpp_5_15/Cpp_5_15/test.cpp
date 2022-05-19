#include<iostream>
using namespace std;

int MonthDay[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

bool IsLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}

class Date
{
public:
	int GetDay(int year, int month)
	{
		if (IsLeapYear(year) && month == 2)
			return 29;
		else
			return MonthDay[month];
	}
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{
		if (year <= 0 || (month < 0 || month >= 13) || day > GetDay(year, month))
		{
			cout << "ÈÕÆÚ´íÎó" << endl;
			cout << year << "-" << month << "-" << day << endl;
			exit(-1);
		}
	}
	Date(const Date& d)
		:_year(d._year), _month(d._month), _day(d._day)
	{}
	~Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}
	void swap(Date& d)
	{
		::swap(_year, d._year);
		::swap(_month, d._month);
		::swap(_day, d._day);
	}
	Date& operator =(const Date& d)
	{
		Date tmp(d);
		this->swap(tmp);
		return *this;
	}
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetDay(_year, _month))
		{
			_day -= GetDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	Date operator+(int day)
	{
		return Date(*this) += day;
	}

	/*Date& operator-=(int day)
	{
		while (day--)
		{
			_day--;
			if (_day < 1)
			{
				_month--;
				if (_month < 1)
				{
					_year--;
					_month = 12;
				}
				_day = GetDay(_year, _month);
			}
		}
		return *this;
	}*/
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day < 1)
		{
			_month--;
			if (_month < 1)
			{
				_year--;
				_month = 12;
			}
			_day += GetDay(_year, _month);
		}
		return *this;
	}

	Date operator-(int day)
	{
		return Date(*this) -= day;
	}

	bool operator>(const Date& d)
	{
		if (_year > d._year || _year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;
	}
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	int operator-(const Date& d)
	{
		Date d1(*this);
		Date d2(d);
		int ret = 0;
		int num1 = 0;
		int num2 = 0;
		if (d1 > d2)
		{
			d1.swap(d2);
		}
		for (int i = 1; i < d1._month; i++)
		{
			num1 += GetDay(d1._year, i);
		}
		num1 += d1._day;
		for (int i = 1; i < d2._month; i++)
		{
			num2 += GetDay(d2._year, i);
		}
		num2 += d2._day;
		for (int i = d1._year; i < d2._year; i++)
		{
			ret += 365;
			if (IsLeapYear(i))
				ret++;
		}
		ret = ret + num2 - num1;
		if (*this > d)
			return ret;
		else
			return -ret;
	}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{

	return 0;
}