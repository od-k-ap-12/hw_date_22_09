#pragma once
	class Date
	{
		int day;
		int month;
		int year;
	public:
		Date();
		Date(int d, int m, int y);
		void InputDate();
		void PrintDate();
		void SetDay(int SetDay);
		int GetDay()const;
		void SetMonth(int SetMonth);
		int GetMonth()const;
		void SetYear(int SetYear);
		int GetYear()const;
		int DayQuantityCheck(int month, int year); //������� ��� ���������� ���� � if-statement, ������ ���-�� ���� � �������
	};

