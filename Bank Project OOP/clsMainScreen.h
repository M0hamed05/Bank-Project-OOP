#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsUser.h"

#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsers.h"
#include"Global.h"
#include"clsShowLoginRegister.h"
#include"clsCurrencyScreen.h"
using namespace std;

class clsMainScreen :protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrency = 9, eExit = 10
    };

    static short _read_main_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10? ");
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
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        clsClientListScreen::show_client_list();
    }

    static void _show_add_client_screen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        clsAddNewClientScreen::add_new_client();
    }

    static void _show_delete_client_screen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        clsDeleteClientScreen::delete_client();
    }

    static void _show_update_client_screen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }
        clsUpdateClientScreen::update_client();
    }

    static void _show_find_client_screen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        clsFindClientScreen::find_clinet();
    }

    static void _show_transcations_menue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        clsTranscationsScreen::show_transactions_menue();
    }

    static void _show_manage_users_menue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _show_Login_Register_screen() 
    {
        if (!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
        {
            return;
        }
        clsShowLoginRegister::show_login_regsiter();
    }

    static void _show_Currency_Exchange_screen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrency))
        {
            return;
        }
        clsCurrencyScreen::show_Currency_menue();
        
    }

    static void _logout()
    {
        CurrentUser = clsUser::Find("","");
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

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _show_Login_Register_screen();
            _go_back_to_main_menue();
            break;

        case enMainMenueOptions::eCurrency:
            system("cls");
            _show_Currency_Exchange_screen();
            _go_back_to_main_menue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _logout();
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
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _preform_main_menue_option((enMainMenueOptions)_read_main_menue_option());
    }

};

