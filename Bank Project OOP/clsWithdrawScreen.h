#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"

class clsWithDrawScreen :protected clsScreen
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

    static string _read_accountnumber() {

        cout << "\nPlease enter an account number : ";
        string accountnumber;
        cin >> accountnumber;
        return accountnumber;

    }

public:

    static void show_withdraw_screen()
    {
        _draw_screen_header("\t Withdraw Screen");
        string accountnumber = _read_accountnumber();

        while (!clsBankClient::is_client_exist(accountnumber)) {
            cout << "\nclient with [" << accountnumber << "] doesn't exist, enter anthor : ";
            accountnumber = _read_accountnumber();
        }
        clsBankClient client = clsBankClient::Find(accountnumber);
        _print_client(client);

        double amount = 0;

        cout << "\nPlease enter withdraw amount : ";
        amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transcation ? y/n : ";
        char answer;
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (client.withdraw(amount)) {
                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance is : " << client.accountbalance << endl;
            }
            else
            {
                do {
                    cout << endl << amount << " exceeds the Balance " << client.accountbalance << endl;
                    cout << "Enter anthor : ";
                    amount = clsInputValidate::ReadDblNumber();
                } while (!client.withdraw(amount));
            }
        }
        else
        {
            cout << "\nOperation was Cancelled\n";
        }
    }

};