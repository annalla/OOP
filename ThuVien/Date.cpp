#include "Date.h"



Date::Date()
{
	_d = _m = _y = 0;
}
Date::Date(int day, int month, int year)
{
	if (year > 0)
		_y = year;
	if (month >= 1 && month <= 12)
		_m = month;
	if ((LEAP_YEAR(year) && day >= 1 && day <= max_day_leap_year[month])||(day >= 1 && day <= max_day[month]))
		_d = day;
}
Date::Date(const Date &a)
{
	_d = a._d;
	_m = a._m;
	_y = a._y;
}

void Date::setDay(int day)
{
		_d = day;
}
void Date::setMonth(int month)
{
	if (month >= 1 && month <= 12)
		_m = month;
}
void Date::setYear(int year)
{
	if (year > 0)
		_y = year;
}

bool Date::validDate()
{
	if (_d <= 0 || _y <= 0 || _m <= 0 || _m > 12)
		return false;
	if (LEAP_YEAR(_y) && _d > max_day_leap_year[_m]|| _d > max_day[_m])
		return false;
	return true;
}

Date& Date::operator=(const Date &a)
{
	_d = a._d;
	_m = a._m;
	_y = a._y;
	return *this;
}

Date& Date::operator++()
{
	if (_m == 12 && _d == 31)
	{
		_d = 1;
		_m = 1;
		_y++;
	}
	else if (LEAP_YEAR(_y) && _d == max_day_leap_year[_m] || _d == max_day[_m])
	{
		_d = 1;
		_m++;
	}
	else
		_d++;
	return *this;
}
Date Date::operator++(int)
{
	Date temp = *this;
	++(*this);
	return temp;
}
Date& Date::operator--()//Tien to
{
	if (_m == 1 && _d == 1)
	{
		_d = 31;
		_m = 12;
		_y--;
	}
	else if (LEAP_YEAR(_y) && _d == 1)
	{
		_d = max_day_leap_year[--_m];
	}
	else if(_d==1)
		_d = max_day[--_m];
	else
		_d--;
	return *this;
}
Date Date::operator--(int)//Hau to
{
	Date temp = *this;
	--(*this);
	return temp;
}

Date& Date::operator+=(int days)
{
	Date kq(*this);
	while (days >= 365)
	{
		if (kq._m <= 2)
		{
			if (LEAP_YEAR(kq._y))
			{
				kq._y++;
				kq--;
			}
			else
			{
				kq._y++;
			}
			days -= 365;
		}
		else
		{
			if (LEAP_YEAR(kq._y + 1))
			{
				kq._y++;
				kq--;
			}
			else
			{
				kq._y++;
			}
			days -= 365;
		}
	}

	while (days > 0)
	{
		
			if (LEAP_YEAR(kq._y))
			{
				while (days > max_day_leap_year[kq._m % 12])
				{
					days -= max_day_leap_year[kq._m % 12];
					kq._m++;
				}
				if (kq._m > 12)
				{
					kq._m = kq._m % 12;
					kq._y++;
				}
				kq._d += days;
				if (kq._d > max_day_leap_year[kq._m])
				{
					kq._d = kq._d%max_day_leap_year[kq._m];
					kq._m++;
				}
				days = 0;
			}
			else
			{
				while (days > max_day[kq._m % 12])
				{
					days -= max_day[kq._m % 12];
					kq._m++;

				}
				if (kq._m > 12)
				{
					kq._m = kq._m % 12;
					kq._y++;
				}
				kq._d += days;
				if (kq._d > max_day[kq._m])
				{
					kq._d = kq._d%max_day[kq._m];
					kq._m++;
				}
				days = 0;
			}
		
	}
	
	
	*this=kq;
	return *this;
}
Date& Date::operator-=(int days)
{
	while (days >= 365)
	{
		if (_m <= 2)
		{
			if (LEAP_YEAR(_y - 1))
			{
				_y--;
				(*this)++;
			}
			else
			{
				_y--;
			}
			days -= 365;
		}
		else
		{
			if (LEAP_YEAR(_y))
			{
				_y--;
				(*this)++;
			}
			else
			{
				_y--;
			}
			days -= 365;
		}
	}
	while (days > 0)
	{
		if (LEAP_YEAR(_y))
		{
			while (days > max_day_leap_year[abs(_m) % 12])
			{
				_m--;
				days -= max_day_leap_year[abs(_m) % 12];

			}
			if (_m <= 0)
			{
				if (_m == 0)
					_m = 12;
				else
					_m = abs(_m) % 12;
				_y--;
			}
			_d -= days;
			if (_d <= 0)
			{
				_m--;
				if (_d == 0) _d = max_day_leap_year[_m];
				else _d = max_day_leap_year[_m] - abs(_d) % max_day_leap_year[_m];

			}
			days = 0;
		}
		else
		{
			while (days > max_day[abs(_m) % 12])
			{
				_m--;
				days -= max_day[abs(_m) % 12];

			}
			if (_m <= 0)
			{
				if (_m == 0)
					_m = 12;
				else
					_m = abs(_m) % 12;
				_y--;
			}
			_d -= days;
			if (_d <= 0)
			{
				_m--;
				if (_d == 0) _d = max_day[_m];
				else _d = max_day[_m] - abs(_d) % max_day[_m];

			}
			days = 0;
		}
	}
	
	return *this;
}
int Date::operator-(const Date &a)
{
	int day1=0,day2=0;

	if (LEAP_YEAR(_y))
	{
		for (int i = 1; i < _m; i++)
			day1 += max_day_leap_year[i];
		day1 += _d;
	}
	else
	{
		for (int i = 1; i < _m; i++)
			day1 += max_day[i];
		day1+= _d;
	}
	if (LEAP_YEAR(a._y))
	{
		for (int i = 1; i < a._m; i++)
			day2 += max_day_leap_year[i];
		day2 += a._d;
	}
	else
	{
		for (int i = 1; i < a._m; i++)
			day2 += max_day[i];
		day2 += a._d;
	}
	if (_y == a._y)
	{
		return (day1 - day2);
	}
	else
	{
		int n = _y - a._y;
		if (n == 1)
		{
			if (LEAP_YEAR(a._y))
				return (366 - day2 + day1);
			else
				return (365 - day2 + day1);
		}
		int y = a._y;
		for (int i = 0; i < n; i++)
		{
			if (LEAP_YEAR(y))
				day1 += 366;
			else
				day1 += 365;
			y++;
		}
		return day1 - day2;
	}
}
bool Date::operator<(const Date &a)
{
	if (_y > a._y)
		return false;
	if (_y == a._y && _m > a._m)
		return false;
	if (_y == a._y && _m == a._m &&  _d > a._d)
		return false;
	return true;
}
bool Date::operator<=(const Date &a)
{
	if (_y > a._y)
		return false;
	if (_y == a._y && _m > a._m)
		return false;
	if (_y == a._y && _m == a._m &&  _d >= a._d)
		return false;
	return true;
}
bool Date::operator>(const Date &a)
{
	if (_y > a._y)
		return true;
	if (_y == a._y && _m > a._m)
		return true;
	if (_y == a._y && _m == a._m &&  _d > a._d)
		return true;
	return false;
}
bool Date::operator>=(const Date &a)
{
	if (_y > a._y)
		return true;
	if (_y == a._y && _m > a._m)
		return true;
	if (_y == a._y && _m == a._m &&  _d >= a._d)
		return true;
	return false;
}

ostream& operator<<(ostream &out, const Date &a)
{
	if (a._d < 10)
		out << "0" << a._d;
	else
		out << a._d;
	out << "/";
	if (a._m < 10)
		out << "0" << a._m;
	else out << a._m;
	out << "/" << a._y << "";
	return out;
}
istream& operator>>(istream &in, Date &a)
{
	string str;
	in >> str;
	int i = 0,so=0;
	while (str[i] != NULL)
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			so = (str[i] - '0') + so * 10;
			i++;
		}
		if (str[i] == '/')
		{
			i++;
			a.setDay(so);
			so = 0;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			so = (str[i] - '0') + so * 10;
			i++;
		}
		if (str[i] == '/')
		{
			i++;
			a.setMonth(so);
			so = 0;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			so = (str[i] - '0') + so * 10;
			i++;
		}
		a.setYear(so);
	}
	return in;
}
Date::~Date()
{
}
