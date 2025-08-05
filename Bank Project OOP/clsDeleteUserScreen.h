#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsUser.h"

using namespace std;

class clsDeleteUserScreen :protected clsScreen
{
public:
    static void ShowDeleteUserScreen()
    {

        _draw_screen_header("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::is_user_exists(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        clsUser::print_user(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.delete_user())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                clsUser::print_user(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }
};
