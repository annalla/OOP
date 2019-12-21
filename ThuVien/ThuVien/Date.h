#pragma once
#pragma disable(warning:4996)
#ifndef DATE_H_
#define DATE_H_
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

#define LEAP_YEAR(y) (y%400==0||(y%4==0 && y%100!=0))? true :false
class Date
{
	int _d;
	int _m;
	int _y;
public:
	int max_day[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
	int max_day_leap_year[13] = { 31,31,29,31,30,31,30,31,31,30,31,30,31 };

	Date();
	Date(int day,int month,int year);
	Date(const Date &a);

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	bool validDate();

	Date& operator=(const Date &a);

	Date& operator++();//Tien to
	Date operator++(int);//Hau to
	Date& operator--();//Tien to
	Date operator--(int);//Hau to

	Date& operator+=(int days);
	Date& operator-=(int days);
	int operator-(const Date &a);

	bool operator<(const Date &a);
	bool operator<=(const Date &a);
	bool operator>(const Date &a);
	bool operator>=(const Date &a);

	friend ostream& operator<<(ostream &out, const Date &a);
	friend istream& operator>>(istream &in, Date &a);

	~Date();
};
#endif

