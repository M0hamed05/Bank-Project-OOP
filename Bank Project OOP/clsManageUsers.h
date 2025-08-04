#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsUser.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

using namespace std;


class clsManageUsersScreen :protected clsScreen
{

private:
    enum enmanage_options {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _read_mange_users_options()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _go_back_to_manage_menue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _show_list_users()
    {
        clsListUsersScreen::ShowUsersList();
    }

    static void _add_users()
    {
        clsAddNewUserScreen::add_new_user();
    }

    static void _delete_users()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _update_users()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _find_user()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _perform_manage_options(enmanage_options ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enmanage_options::eListUsers:
        {
            system("cls");
            _show_list_users();
            _go_back_to_manage_menue();
            break;
        }

        case enmanage_options::eAddNewUser:
        {
            system("cls");
            _add_users();
            _go_back_to_manage_menue();
            break;
        }

        case enmanage_options::eDeleteUser:
        {
            system("cls");
            _delete_users();
            _go_back_to_manage_menue();
            break;
        }

        case enmanage_options::eUpdateUser:
        {
            system("cls");
            _update_users();
            _go_back_to_manage_menue();
            break;
        }

        case enmanage_options::eFindUser:
        {
            system("cls");

            _find_user();
            _go_back_to_manage_menue();
            break;
        }

        case enmanage_options::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:


    static void ShowManageUsersMenue()
    {

        system("cls");
        _draw_screen_header("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_manage_options((enmanage_options)_read_mange_users_options());
    }

};

