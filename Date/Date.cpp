#include"Date.h"
int Date::GetMonthDay(int year, int month)
{
	static const int monthDays[13] = { 0, 31, 28, 31, 30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31 };
	if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return monthDays[month];
	}
}
 Date::Date(int year, int month, int day)
{
	if (year >= 0 && 
		month > 0 && month <13 &&
		day > 0 && day <GetMonthDay(year,month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "Date Invalid" << endl;
	}
}
void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
bool Date::operator>(const Date& d)
{
	return (_year > d._year) ||
		(_year == d._year && _month > d._month) ||
		(_year == d._year && _month == d._month && _day > d._day);
}
bool Date::operator==(const Date& d)
{
	return _year == d._year &&
		_day == d._day &&
		_month == d._month;
}
//¸´ÓÃ
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
// d + 100
Date Date::operator+(int day)
{
	/*Date ret(*this);
	ret._day += day;
	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		ret._day -= GetMonthDay(ret._year, ret._month);
		ret._month++;
		if (ret._month == 13)
		{
			ret._year++;
			ret._month = 1;
		}
	}
	return ret;*/
	Date ret(*this);
	ret += day;
	return ret;

}
Date Date::operator-(int day)
{
	/*Date ret(*this);
	ret._day -= day;
	while (ret._day <= 0)
	{
		ret._month--;
		if (ret._month == 0)
		{
			ret._year--;
			ret._month = 12;
		}
		ret._day += GetMonthDay(ret._year, ret._month);
	}
	return ret;*/
	Date ret(*this);
	ret -= day;
	return ret;
}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
int Date::operator-(const Date& d)
{
	/*int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (min != max)
	{
		++min;
		count++;
	}
	return count * flag;*/

	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (min != max)
	{
		min++;
		count++;
	}
	return flag * count;
}

// ++d d.operator++(&d)
Date Date::operator++()
{
	*this += 1;
	return *this;
}
// d++ d.operator++(&d, 0)
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

// --d d.operator++(&d)
Date Date::operator--()
{
	*this -= 1;
	return *this;
}
// d-- d.operator++(&d, 0)
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
int main()
{
	Date d1(2018,11,14);
	Date d2(2018, 11, 25);
	////d2.Print();
	//(d2 - 100).Print();

	//Date d5(2015, 1, 1);
	//Date ret = d5 - 1;
	//ret.Print();
	cout << d2 - d1 << endl;
	system("pause");
	return 0;
}