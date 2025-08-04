#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalances.h"

class clsTranscationsScreen :protected clsScreen
{
private:
	enum entranscationChoice { eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3, eShowMainMenue = 4 };

	static short read_transations_menue_option()
	{
		cout << setw(37) << left << "" << "Choose choice :  ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Please enter a numer between 1 and 4");
		return choice;
	}

    static void _show_deposit_screen()
    {
        clsDepositScreen::show_deposit_screen();
    }

    static void _show_withdraw_screen()
    {
        clsWithDrawScreen::show_withdraw_screen();
    }

    static void _show_total_balances_screen()
    {
        clsTotalBalances::show_total_balances();
    }

    static void _go_back_to_transcations_menue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        show_transactions_menue();

    }

    static void _preform_transcation_option(entranscationChoice TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case entranscationChoice::eDeposit:
        {
            system("cls");
            _show_deposit_screen();
            _go_back_to_transcations_menue();
            break;
        }

        case entranscationChoice::eWithdraw:
        {
            system("cls");
            _show_withdraw_screen();
            _go_back_to_transcations_menue();
            break;
        }

        case entranscationChoice::eShowTotalBalances:
        {
            system("cls");
            _show_total_balances_screen();
            _go_back_to_transcations_menue();
            break;
        }


        case entranscationChoice::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }

public:


    static void show_transactions_menue()
    {


        system("cls");
        _draw_screen_header("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _preform_transcation_option((entranscationChoice)read_transations_menue_option());
    }

};

