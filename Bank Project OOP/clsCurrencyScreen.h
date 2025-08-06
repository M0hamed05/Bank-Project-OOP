#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsInputValidate.h"

#include"clsListCurrency.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculator.h"

using namespace std;

class clsCurrencyScreen:protected clsScreen
{
private:

    enum enCurrencyChoice
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4,
        eMainMenue = 5
    };

    static void _go_back_to_Currency_menue()
    {
        cout << "\n\nPress any key to go back to Currency Menue...";
        system("pause>0");
        show_Currency_menue();

    }

    static  short _read_currency_menue_option()
    {
        cout << setw(37) << left << "" << "Choose What you want to do? [1 to 5] : ";
        int choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number Between 1 and 5 : ");
        return choice;
    }

    static void _preform_currency_option(enCurrencyChoice choice )
    {
        switch (choice)
        {
        case enCurrencyChoice::eListCurrencies:
        {
            system("cls");
            clsListCurrency::list_currency_screen();
            _go_back_to_Currency_menue();
            break;
        }

        case enCurrencyChoice::eFindCurrency:
        {
            system("cls");
            clsFindCurrency::show_find_currency_screen();
            _go_back_to_Currency_menue();
            break;
        }

        case enCurrencyChoice::eUpdateRate:
        {
            system("cls");
            clsUpdateCurrencyRate::show_update_rate_screen();
            _go_back_to_Currency_menue();
            break;
        }

        case enCurrencyChoice::eCurrencyCalculator:
        {
            system("cls");
            clsCurrencyCalculator::show_calculator_currency_screen();
            _go_back_to_Currency_menue();
            break;
        }

        case enCurrencyChoice::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }

public:

    static void show_Currency_menue()
    {
        system("cls");
        _draw_screen_header("   Currancy Exchange Main Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _preform_currency_option((enCurrencyChoice)_read_currency_menue_option());
    }

};

