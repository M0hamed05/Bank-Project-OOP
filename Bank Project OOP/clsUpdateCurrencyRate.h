#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsUpdateCurrencyRate : protected clsScreen
{

private:
	static void _update_rate(clsCurrency currency)
	{
		clsCurrency::PrintCurrency(currency);
		cout << "\nAre you sure you want to update the rate of this Currency ? y/n : ";
		char test = 'n';
		cin >> test;
		if (test == 'y' || test == 'Y')
		{
			cout << "\nUpdate Currency Rate : ";
			cout << "\n_______________________\n";

			cout << "\nEnter New Rate : ";
			float newrate = clsInputValidate::ReadFloatNumber();

			currency.updaterate(newrate);

			cout << "\nCurrency Rate Updated Successfully\n";

			clsCurrency::PrintCurrency(currency);
		}
	}
public:

	static void show_update_rate_screen()
	{
		_draw_screen_header("\tUpdate Currency Screen");
		cout << "\nPlease Enter Currency Code : ";
		string code = clsInputValidate::ReadString();

		clsCurrency currency = clsCurrency::find_by_code(code);

		if (currency.is_empty()) cout << "\nCurrency Code is not Found\n";
		else
		{
			_update_rate(currency);
		}

	}
};
