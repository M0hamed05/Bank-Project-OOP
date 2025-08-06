#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsFindCurrency : protected clsScreen
{
private:

	enum enWayChoice { enCode = 1, enCountry = 2 };

	static void _print_by_code() {
		cout << "\nPlaese Enter CurrencyCode : ";
		string code = clsInputValidate::ReadString();
		clsCurrency currency = clsCurrency::find_by_code(code);

		if (currency.is_empty()) cout << "Currency is not found";
		else
		{
			cout << "\nCurreny Found\n";
			clsCurrency::PrintCurrency(currency);
		}
}

	static void _print_by_country() {
		cout << "\nPlaese Enter Currency Country : ";
		string country = clsInputValidate::ReadString();
		clsCurrency currency = clsCurrency::find_by_country(country);

		if (currency.is_empty()) cout << "Currency is not found";
		else
		{
			cout << "\nCurreny Found\n";
			clsCurrency::PrintCurrency(currency);
		}
	}

public:

	static void show_find_currency_screen()
	{
		_draw_screen_header("\t Find Currency Screen");

		cout << "\nFind By [1] Code or [2] Country ? ";
		
		int choice = clsInputValidate::ReadIntNumberBetween(1, 2, "Enter 1 or 2 :");
		if (choice == enCode) {
			_print_by_code();
		}
		else {
			_print_by_country();
		}


	}

};

