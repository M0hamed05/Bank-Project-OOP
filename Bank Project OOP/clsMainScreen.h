#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"

#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsers.h"
using namespace std;

class clsMainScreen :protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _read_main_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static  void _go_back_to_main_menue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _show_allclients_screen()
    {
        clsClientListScreen::show_client_list();
    }

    static void _show_add_client_screen()
    {
        clsAddNewClientScreen::add_new_client();
    }

    static void _show_delete_client_screen()
    {
        clsDeleteClientScreen::delete_client();
    }

    static void _show_update_client_screen()
    {
        clsUpdateClientScreen::update_client();
    }

    static void _show_find_client_screen()
    {
        clsFindClientScreen::find_clinet();
    }

    static void _show_transcations_menue()
    {
        clsTranscationsScreen::show_transactions_menue();
    }

    static void _show_manage_users_menue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _show_end_screen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }

    static void _preform_main_menue_option(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _show_allclients_screen();
            _go_back_to_main_menue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _show_add_client_screen();
            _go_back_to_main_menue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _show_delete_client_screen();
            _go_back_to_main_menue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _show_update_client_screen();
            _go_back_to_main_menue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _show_find_client_screen();
            _go_back_to_main_menue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _show_transcations_menue();
            _go_back_to_main_menue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _show_manage_users_menue();
            _go_back_to_main_menue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _show_end_screen();
            //Login();

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _draw_screen_header("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _preform_main_menue_option((enMainMenueOptions)_read_main_menue_option());
    }

};

