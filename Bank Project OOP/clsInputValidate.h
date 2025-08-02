#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(int number, int from, int to)
	{
		if (number >= from && number <= to) {
			return 1;
		}
		return 0;
	}
	static bool IsNumberBetween(double number, double from, double to)
	{
		if (number >= from && number <= to) {
			return 1;
		}
		return 0;
	}

	static bool IsDateBetween(clsDate date, clsDate datefrom, clsDate dateto)
	{
		if (clsDate::IsDate1AfterDate2(datefrom, dateto)) {
			clsDate::SwapDates(datefrom, dateto);
		}
		if ((clsDate::IsDate1AfterDate2(date, datefrom) || clsDate::IsDate1EqualDate2(date, datefrom))
			&& (clsDate::IsDate1BeforeDate2(date, dateto) || clsDate::IsDate1EqualDate2(date, dateto))) {
			return true;
		}
		return false;
	}
	static bool IsValideDate(clsDate date) {
		return clsDate::IsValidDate(date);
	}

	static int ReadIntNumber(string error_massage = "Invalid Number, Enter again\n")
	{
		int num = 0;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_massage;
			cin >> num;
		}
		return num;
	}
	static double ReadDblNumber(string error_massage = "Invalid Number, Enter again\n")
	{

		double num = 0;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_massage;
			cin >> num;
		}
		return num;
	}
	static double ReadFloatNumber(string error_massage = "Invalid Number, Enter again\n")
	{

		float num = 0;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_massage;
			cin >> num;
		}
		return num;
	}

	static int ReadIntNumberBetween(int from, int to, string error_massage = "Invalid Number, Enter again\n") {
		int x = 0;
		cin >> x;
		while (!(x <= from && x >= from)) {
			cout << error_massage << endl;
			cin >> x;
		}
		return x;
	}
	static int ReadDblNumberBetween(double from, double to, string error_massage = "Invalid Number, Enter again\n") {
		double x = 0;
		cin >> x;
		while (!(x <= from && x >= from)) {
			cout << error_massage << endl;
			cin >> x;
		}
		return x;
	}

	static string ReadString()
	{
		string  S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
};


