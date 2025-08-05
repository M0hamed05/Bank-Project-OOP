#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsUtil.h"

class clsLoginScreen :protected clsScreen
{

protected:

    static  bool _Login()
    {
        bool LoginFaild = false;

        int trail = 3;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                trail--;
                cout << "\nInvlaid Username/Password!";
                cout << "You have " << trail << " left\n\n";
            
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.is_empty();

            if (trail == 1) {
                cout << "\nYou are Locked after 3 faild trails.\n\n";
                return false;
            }

        } while (LoginFaild);

        _save_login_to_file();
        clsMainScreen::ShowMainMenue();
        return true;

    }

    static string _convert_object_to_line_login_history(string Seperator = "#//#")
    {

        string UserRecord = "";
        string time = clsDate::date_to_string_with_hours(clsDate());
        UserRecord += time + Seperator;
        UserRecord += CurrentUser.username + Seperator;
        UserRecord += clsUtil::encrypt_text(CurrentUser.password) + Seperator;
        UserRecord += to_string(CurrentUser.permissions);
        return UserRecord;

    }

    static void _save_login_to_file()
    {

        fstream MyFile;
        MyFile.open("LoginHistory.txt", ios::app);//not overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            DataLine = _convert_object_to_line_login_history();
            MyFile << DataLine << endl;

            MyFile.close();

        }

    }


public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _draw_screen_header("\t  Login Screen");
       return _Login();

    }

};

