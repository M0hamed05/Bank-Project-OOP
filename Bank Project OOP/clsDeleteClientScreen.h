#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDeleteClientScreen:protected clsScreen
{
private:

    static  void _print_client(clsBankClient client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.fristname;
        cout << "\nLastName    : " << client.lastname;
        cout << "\nFull Name   : " << client.fullname();
        cout << "\nEmail       : " << client.email;
        cout << "\nPhone       : " << client.phone;
        cout << "\nAcc. Number : " << client.accountnumber();
        cout << "\nPassword    : " << client.pincode;
        cout << "\nBalance     : " << client.accountbalance;
        cout << "\n___________________\n";

    }

public:
    static void delete_client()
    {
        string accountnumber = "";
        cout << "\nPlease Enter Account Number : ";
        accountnumber = clsInputValidate::ReadString();
        while (!clsBankClient::is_client_exist(accountnumber))
        {
            cout << "\n Account number is not found, please enter anthor one : ";
            accountnumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::find(accountnumber);
        _print_client(client);
        cout << "\n are you want to delete this clinet y/n ? ";
        char ans = 'n';
        cin >> ans;

        if (ans == 'y' || ans == 'Y')
        {
            if (client.delete_client()) {
                cout << "\nClient Deleted Successfully\n";
                _print_client(client);
            }
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }

};

