#include <iostream>
#include "Date.h"
using namespace std;

Date operator+(int a, const Date& b)
{
	Date rez;
	rez.SetDay(b.GetDay());
	rez.SetMonth(b.GetMonth());
	rez.SetYear(b.GetYear());
	if (rez.GetDay() + a > rez.DayQuantityCheck(rez.GetMonth(), rez.GetYear())) {
		a -= rez.DayQuantityCheck(rez.GetMonth(), rez.GetYear()) - rez.GetDay();
		rez.SetDay(1);
		if (rez.GetMonth() == 12) {
			rez.SetYear(rez.GetYear() + 1);
			rez.SetMonth(1);
		}
		else {
			rez.SetMonth(rez.GetMonth() + 1);
		}
		while (a > rez.DayQuantityCheck(rez.GetMonth(), rez.GetYear())) {
			rez.SetDay(rez.DayQuantityCheck(rez.GetMonth(), rez.GetYear()));
			a -= rez.DayQuantityCheck(rez.GetMonth(), rez.GetYear());
			if (rez.GetMonth() == 12) {
				rez.SetYear(rez.GetYear() + 1);
				rez.SetMonth(1);
			}
			else {
				rez.SetMonth(rez.GetMonth() + 1);
			}
		}
		rez.SetDay(a);
		rez.PrintDate();
		return rez;
	}
	else {
		rez.SetDay(rez.GetDay() + a);
		rez.PrintDate();
		return rez;
	}
}
int operator-(int a, Date& b)
{
	int daycount = 0;
	daycount += b.GetDay();
	for (int i = 0; i < b.GetMonth(); i++) {
		daycount += b.DayQuantityCheck(b.GetMonth(), b.GetYear());
	}
	daycount += 365 * b.GetYear();
	int result = a - daycount;
	return result;
}

Date operator-(Date& obj1, const Date& obj)
{
	if (obj1.GetDay() - obj.GetDay() < 1) {
		if (obj1.GetMonth() == 1) {
			obj1.SetYear(obj1.GetYear() - 1);
			obj1.SetMonth(12);
		}
		else {
			obj1.SetMonth(obj1.GetMonth() - 1);
		}
		obj1.SetDay(obj1.DayQuantityCheck(obj1.GetMonth(), obj1.GetYear()) + (obj1.GetDay() - obj.GetDay()));
	}
	else {
		obj1.SetDay(obj1.GetDay() - obj.GetDay());
	}
	if (obj1.GetMonth() - obj.GetMonth() < 1) {
		obj1.SetYear(obj1.GetYear() - 1);
		obj1.SetMonth(12 + obj1.GetMonth() - obj.GetMonth());
		cout << obj1.GetMonth() << endl;
	}
	else {
		obj1.SetMonth(obj1.GetMonth() - 1);
	}
	obj1.SetYear(obj1.GetYear() - obj.GetYear());
	return obj1;
}

Date operator+=(Date& obj, int a)
{
	if (obj.GetDay() + a > obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear())) {
		a -= obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear()) - obj.GetDay();
		obj.SetDay(1);
		if (obj.GetMonth() == 12) {
			obj.SetYear(obj.GetYear() + 1);
			obj.SetMonth(1);
		}
		else {
			obj.SetMonth(obj.GetMonth() + 1);
		}
		while (a > obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear())) {
			obj.SetDay(obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear()));
			a -= obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear());
			if (obj.GetMonth() == 12) {
				obj.SetYear(obj.GetYear() + 1);
				obj.SetMonth(1);
			}
			else {
				obj.SetMonth(obj.GetMonth() + 1);
			}
		}
		obj.SetDay(a);
		return obj;
	}
	else {
		obj.SetDay(obj.GetDay() + a);
		return obj;
	}
}

Date operator-=(Date& obj, int a)
{
	if (obj.GetDay() - a < 1) {
		obj.SetDay(1);
		if (obj.GetMonth() == 1) {
			obj.SetYear(obj.GetYear() - 1);
			obj.SetMonth(12);
		}
		else {
			obj.SetMonth(obj.GetMonth() - 1);
		}
		a -= obj.GetDay();
		while (a > obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear())) {
			obj.SetDay(1);
			a -= obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear());
			if (obj.GetMonth() == 1) {
				obj.SetYear(obj.GetYear() - 1);
				obj.SetMonth(12);
			}
			else {
				obj.SetMonth(obj.GetMonth() - 1);
			}
		}
		obj.SetMonth(obj.GetMonth() - 1);
		obj.SetDay(obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear()) - a);
		return obj;
	}
	else {
		obj.SetDay(obj.GetDay() - a);
		return obj;
	}
}
Date operator++(Date& obj, int t)
{
	Date temp(obj);
	obj.SetDay(obj.GetDay() + 1);
	if (obj.GetDay() > obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear())) {
		obj.SetMonth(obj.GetMonth() + 1); obj.SetDay(1);
		if (obj.GetMonth() > 12) {
			obj.SetYear(obj.GetYear() + 1);
			obj.SetMonth(1);
		}
	}
	return temp;
}

Date& operator++(Date& obj)
{
	obj.SetDay(obj.GetDay() + 1);
	if (obj.GetDay() > obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear())) {
		obj.SetMonth(obj.GetMonth() + 1); obj.SetDay(1);
		if (obj.GetMonth() > 12) {
			obj.SetYear(obj.GetYear() + 1);
			obj.SetMonth(1);
		}
	}
	return obj;
}
Date& operator--(Date& obj, int t)
{
	Date temp(obj);
	obj.SetDay(obj.GetDay() - 1);
	if (obj.GetDay() < 1) {
		obj.SetMonth(obj.GetMonth() - 1);
		obj.SetDay(obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear()));
		if (obj.GetMonth() < 1) {
			obj.SetYear(obj.GetYear() - 1);
			obj.SetMonth(12);
		}
	}
	return temp;
}

Date& operator--(Date& obj)
{
	obj.SetDay(obj.GetDay() - 1);
	if (obj.GetDay() < 1) {
		obj.SetMonth(obj.GetMonth() - 1);
		obj.SetDay(obj.DayQuantityCheck(obj.GetMonth(), obj.GetYear()));
		if (obj.GetMonth() < 1) {
			obj.SetYear(obj.GetYear() - 1);
			obj.SetMonth(12);
		}
	}
	return obj;
}
bool operator<(const Date& obj1, const Date& obj)
{
	if (obj1.GetYear() < obj.GetYear()) {
		return true;
	}
	else if (obj1.GetYear() == obj.GetYear()) {
		if (obj1.GetDay() < obj.GetMonth()) {
			return true;
		}
		else if (obj1.GetMonth() == obj.GetMonth()) {
			if (obj1.GetDay() < obj.GetDay()) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
bool operator>(const Date& obj1, const Date& obj)
{
	if (obj1.GetYear() > obj.GetYear()) {
		return true;
	}
	else if (obj1.GetYear() == obj.GetYear()) {
		if (obj1.GetDay() > obj.GetMonth()) {
			return true;
		}
		else if (obj1.GetMonth() == obj.GetMonth()) {
			if (obj1.GetDay() > obj.GetDay()) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
bool operator<=(const Date& obj1, const Date& obj)
{
	if (obj1.GetYear() < obj.GetYear()) {
		return true;
	}
	else if (obj1.GetYear() == obj.GetYear()) {
		if (obj1.GetDay() < obj.GetMonth()) {
			return true;
		}
		else if (obj1.GetMonth() == obj.GetMonth()) {
			if (obj1.GetDay() < obj.GetDay()) {
				return true;
			}
			else if (obj1.GetDay() == obj.GetDay()) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool operator>=(const Date& obj1, const Date& obj)
{
	if (obj1.GetYear() > obj.GetYear()) {
		return true;
	}
	else if (obj1.GetYear() == obj.GetYear()) {
		if (obj1.GetDay() > obj.GetMonth()) {
			return true;
		}
		else if (obj1.GetMonth() == obj.GetMonth()) {
			if (obj1.GetDay() > obj.GetDay()) {
				return true;
			}
			else if (obj1.GetDay() == obj.GetDay()) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool operator==(const Date& obj1, const Date& obj)
{
	if (obj1.GetYear() != obj.GetYear()) {
		return false;
	}
	else {
		if (obj1.GetMonth() != obj.GetMonth()) {
			return false;
		}
		else {
			if (obj1.GetDay() != obj.GetDay()) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}
bool operator!=(const Date& obj1, const Date& obj)
{
	if (obj1.GetYear() != obj.GetYear()) {
		return true;
	}
	else {
		if (obj1.GetMonth() != obj.GetMonth()) {
			return true;
		}
		else {
			if (obj1.GetDay() != obj.GetDay()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

int main() {
	Date date1(29, 2, 2020);
	Date date2(29, 2, 2016);
	date1.PrintDate();
	date2.PrintDate();
	cout << 87 - date1;
	cout << endl;
	cout << date1.GetYear();
	bool C = date1 != date2;
	cout << endl << C;
}