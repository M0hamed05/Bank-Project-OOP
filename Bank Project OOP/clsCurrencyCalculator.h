#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsString.h"
class clsCurrencyCalculator : protected clsScreen
{
private:

	static void print_currency(clsCurrency Currency)
	{
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.country();
		cout << "\nCode       : " << Currency.currencycode();
		cout << "\nName       : " << Currency.currencyname();
		cout << "\nRate(1$) = : " << Currency.rate();

		cout << "\n_____________________________\n";

	}

	static void _print_calculation(string code1, string code2, double amount)
	{
		clsCurrency c1 = clsCurrency::find_by_code(code1);
		clsCurrency c2 = clsCurrency::find_by_code(code2);

		if (clsString::make_it_allcapital(code2) == "USD")
		{
			cout << "\nConvert from\n";
			print_currency(c1);
			cout << endl << amount << " " << c1.currencycode() << " = " << amount / c1.rate() << " " << c2.currencycode() << endl;
		}
		else if (clsString::make_it_allcapital(code1) == "USD") 
		{
			cout << "\nConvert from\n";
			print_currency(c1);
			cout << endl << amount << " " << c1.currencycode() << " = " << amount * c1.rate() << " " << c2.currencycode() << endl;
		}
		else
		{
			clsCurrency dollar = clsCurrency::find_by_code("USD");
			cout << "\nConvert from\n";
			print_currency(c1);
			float rate = amount / c1.rate();
			cout << endl << amount << " " << c1.currencycode() << " = " << rate << " " << dollar.currencycode() << endl;

			cout << "\nto \n";
			print_currency(c2);
			cout << endl << amount << " " << c1.currencycode() << " = " << rate*c2.rate() << " " << c2.currencycode() << endl;


		}
	
	}

public:

	static void show_calculator_currency_screen()
	{
		_draw_screen_header("\t   Calculator Currency");
		char test = 'y';

		while (test == 'y' || test == 'Y') {
			cout << "\nPlease Enter Currency1 Code : ";
			string code1 = clsInputValidate::ReadString();
			clsCurrency currency1 = clsCurrency::find_by_code(code1);
			while (currency1.is_empty())
			{
				cout << "\nThis code is not found, Anthor Currency1 Code : ";
				code1 = clsInputValidate::ReadString();
				currency1 = clsCurrency::find_by_code(code1);
			}

			cout << "\nPlease Enter Currency2 Code : ";
			string code2 = clsInputValidate::ReadString();
			while (code1 == code2) {
				cout << "\nPlease Enter anthor Currency2 Code : ";
				code2 = clsInputValidate::ReadString();
			}
			clsCurrency currency2 = clsCurrency::find_by_code(code1);
			while (currency2.is_empty())
			{
				cout << "\nThis code is not found, Anthor Currency2 Code : ";
				code2 = clsInputValidate::ReadString();
				while (code1 == code2) {
					cout << "\nPlease Enter anthor Currency2 Code : ";
					code2 = clsInputValidate::ReadString();
				}
				currency2 = clsCurrency::find_by_code(code1);
			}


			cout << "\nEnter amoun to exchange : ";
			double amount = clsInputValidate::ReadDblNumber();
			_print_calculation(code1, code2, amount);
			cout << "\nDo you want to perform anthor calculation? y/n : ";
			cin >> test;
			if (test == 'y' || test == 'Y')
			{
				system("cls");
				_draw_screen_header("\t   Calculator Currency");
			}
		}
	}
};

