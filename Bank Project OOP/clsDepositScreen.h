#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDepositScreen :protected clsScreen {

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

    static string _read_accountnumber() {

        cout << "\nPlease enter an account number : ";
        string accountnumber;
        cin >> accountnumber;
        return accountnumber;

    }

public:

    static void show_deposit_screen()
    {
        _draw_screen_header("\t Deposit Screen");
        string accountnumber = _read_accountnumber();

        while (!clsBankClient::is_client_exist(accountnumber)) {
            cout << "\nclient with [" << accountnumber << "] doesn't exist, enter anthor : ";
            accountnumber = _read_accountnumber();
        }
        clsBankClient client = clsBankClient::find(accountnumber);
        _print_client(client);

        double amount = 0;

        cout << "\nPlease enter deposit amount : ";
        amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transcation ? y/n : ";
        char answer;
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            client.deposit(amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance is : " << client.accountbalance << endl;
        }
        else
        {
            cout << "\nOperation was Cancelled.\n";
        }
    }

};