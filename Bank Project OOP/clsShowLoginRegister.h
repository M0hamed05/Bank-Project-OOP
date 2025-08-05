#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsString.h"
#include "clsUtil.h"

class clsShowLoginRegister : protected clsScreen
{
private :
    
    struct stlog {
        string time;
        string username;
        string password;
        int permissioons;
    };

    static void _print_data_record_line(stlog log)
    {

        cout << "| " << setw(25) << left << log.time;
        cout << "| " << setw(15) << left << log.username;
        cout << "| " << setw(20) << left << log.password;
        cout << "| " << setw(15) << left << log.permissioons;

    }

    static stlog _convert_line_data_to_struct(string line, string seperator = "#//#")
    {
        stlog log;
        vector<string> vdata;
        vdata = clsString::split_sentence_extra(line, seperator);
        log.time = vdata[0];
        log.username = vdata[1];
        log.password = vdata[2];
        log.permissioons = stoi(vdata[3]);

        return log;
    }

    static string _convert_object_to_line_login_history2(string Seperator = "#//#")
    {

        string UserRecord = "";
        string time = clsDate::date_to_string_with_hours(clsDate());
        UserRecord += time + Seperator;
        UserRecord += CurrentUser.username + Seperator;
        UserRecord += clsUtil::encrypt_text(CurrentUser.password) + Seperator;
        UserRecord += to_string(CurrentUser.permissions);
        return UserRecord;

    }

    static vector <stlog> _load_login_data_from_file()
    {
        vector <stlog> vdata;
        fstream myfile;
        myfile.open("LoginHistory.txt", ios::in);
        if (myfile.is_open()) {
            string line;
            while (getline(myfile, line)) {
                stlog data = _convert_line_data_to_struct(line);
                vdata.push_back(data);
            }
            myfile.close();
        }
        return vdata;
    }

public:

    static void show_login_regsiter()
    {

        vector <stlog> vdata = _load_login_data_from_file();

        _draw_screen_header("\t Login Regsiter List Screen\n");

        cout << "\n\t\t\t\t\t (" << vdata.size() << ") Records(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "| " << left << setw(25) << "Time";
        cout << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(15) << "Permissions";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vdata.size() == 0)
            cout << "\t\t\t\tNo Records Available In the System!";
        else

            for (stlog data : vdata)
            {

                _print_data_record_line(data);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};
