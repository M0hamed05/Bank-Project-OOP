#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
{
private:

    static  void _read_client_info(clsBankClient& client)
    {
        cout << "\nEnter FirstName: ";
        client.fristname = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        client.lastname = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        client.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        client.phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        client.pincode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        client.accountbalance = clsInputValidate::ReadFloatNumber();
    }

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

    static void find_clinet() {
        _draw_screen_header("\tFind Client Screen");
        string accountnumber;
        cout << "\nPlease Enter an account number : ";
        accountnumber = clsInputValidate::ReadString();

        while (!clsBankClient::is_client_exist(accountnumber)) {
            cout << "\nAccount number is not found, choose anthor one : ";
            accountnumber = clsInputValidate::ReadString();

        }

        clsBankClient client = clsBankClient::find(accountnumber);

        if (!client.is_empty()) {
            cout << "\nClient found\n";
        }
        else {
            cout << "\nClient was not found\n";
        }
        _print_client(client);
 }

};

