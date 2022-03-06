#include"Date.h"

inline int GetMonthDay(int year,int month)
{
	//数组存储平年每个月的天数
	static int dayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = dayArray[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}
	return day;
}

Date::Date(int year , int month , int day )
{
	if (year>=0
		&& month > 0 && month < 13
		&& day > 0 && day <= GetMonthDay(year,month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "输入日期非法！" << endl;
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
}

void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

Date& Date::operator += (int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	else
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
	}
	return *this;
}

Date Date::operator + (int day)
{
	Date ret(*this);
	ret += day;
	return ret;
}

Date& Date::operator -= (int day)
{
	if (day < 0)
	{
		*this += -day;
	}
	else
	{
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
	}
	return *this;
}
Date Date::operator - (int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}

Date& Date::operator ++ ()
{
	*this += 1;
	return *this;
}
//int参数不需要给实参，因为没有用，他的作用是为了跟前置++构成函数重载
Date& Date::operator ++ (int )
{
	Date ret(*this);
	*this += 1;
	return ret;
}

Date& Date::operator -- ()
{
	*this -= 1;
	return *this;
}
//int参数不需要给实参，因为没有用，他的作用是为了跟前置--构成函数重载
Date& Date::operator -- (int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}
//d1>d2
bool Date::operator > (const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator == (const Date& d)
{
	return _year == d._year &&
		_month == d._month &&
		_day == d._day;
}
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	Date max(*this);
	Date min(d);
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (max != min)
	{
		++min;
		++n;
	}
	return n * flag;
}
