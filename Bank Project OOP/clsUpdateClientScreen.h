#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsUpdateClientScreen :protected clsScreen
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

    static void update_client() {
        string accountnumber = "";
        cout << "\nPlease Enter client Account Number : ";
        accountnumber = clsInputValidate::ReadString();

        while (!clsBankClient::is_client_exist(accountnumber)) {
            cout << "Account number is not found, choose anthor one : ";
            accountnumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(accountnumber);

        _print_client(client);
        cout << "\n\nUpdate Client Info : ";
        cout << "\n--------------------\n";

        _read_client_info(client);

        clsBankClient::enSaveResults Saveresult;

        Saveresult = client.save();

        switch (Saveresult) {
        case clsBankClient::enSaveResults::Succeeeded:
            cout << "\nAccount Updated Successfully\n";
            _print_client(client);
            break;
        case clsBankClient::enSaveResults::FialdEmptyObject:
            cout << "\nError account was not saved because it's empty\n";
            break;


        }

    }

};

