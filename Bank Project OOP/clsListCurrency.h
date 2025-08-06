#pragma once
#include<iostream>
#include<iomanip>
#include<string>

#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;

class clsListCurrency : protected clsScreen
{

private : 

	static void _print_currency_data(clsCurrency curr)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << curr.country();
		cout << "| " << left << setw(10) << curr.currencycode();
		cout << "| " << left << setw(35) << curr.currencyname();
		cout << "| " << left << setw(15) << curr.rate();
	}

public :

	static void list_currency_screen() {

		vector <clsCurrency> vcurrency = clsCurrency::get_currencies_list();

		string title = "\t Currencies List Screen";
		string subtitle = "\t  (" + to_string(vcurrency.size()) + ") Currency";

		_draw_screen_header(title, subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(35) << "Name";
		cout << "| " << left << setw(15) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t________________________________________________________";
		cout << "____________________________________________________\n" << endl;

		if (vcurrency.size() == 0) cout << "No Currencies Avalaible";
		else
		{
			for (clsCurrency c : vcurrency)
			{
				_print_currency_data(c);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}

};

