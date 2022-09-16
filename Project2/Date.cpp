#include "Date.h"
#include "Date.h"
#include <iostream>
using namespace std;
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	if (day > this->DayQuantityCheck(m, y)) {
		//invalid date
		day = 0;
		month = 0;
		year = 0;
	}
}

void Date::InputDate()
{
	cout << "enter day: ";
	cin >> day;
	cout << "enter month: ";
	cin >> month;
	cout << "enter year: ";
	cin >> year;
	if (day > this->DayQuantityCheck(month, year) && year < 1) {
		//invalid date
		day = 0;
		month = 0;
		year = 0;
	}
}
int Date::DayQuantityCheck(int month, int year)
{
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int d = days[month];
	if (month == 2 && year % 4 == 0)
	{
		d += 1;
	}
	return d;
}
void Date::PrintDate()
{
	cout << "date: " << day << "." << month << "." << year << endl;
}

void Date::SetDay(int SetDay)
{
	if (SetDay > this->DayQuantityCheck(month, year)) {
		cout << "Error";
	}
	else {
		day = SetDay;
	}
}

int Date::GetDay()const
{
	return day;
}

void Date::SetMonth(int SetMonth)
{
	if ((SetMonth > 12 || SetMonth < 1) || (day > this->DayQuantityCheck(SetMonth, year))) {
		cout << "Error" << endl;
	}
	else {
		month = SetMonth;
	}
}

int Date::GetMonth()const
{
	return month;
}

void Date::SetYear(int SetYear)
{
	if ((year < 1) || (day > this->DayQuantityCheck(month, SetYear))) {
		cout << "Error" << endl;
	}
	else {
		year = SetYear;
	}
}

int Date::GetYear()const
{
	return year;
}

