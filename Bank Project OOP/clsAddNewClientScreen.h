#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsAddNewClientScreen:protected clsScreen
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

    static void add_new_client()
    {
        _draw_screen_header("\t Add New Client Screen");

        string accountnumber = "";
        cout << "\nPlease Enter Account Number : ";
        accountnumber = clsInputValidate::ReadString();
        while (clsBankClient::is_client_exist(accountnumber))
        {
            cout << "\n Account number is already exists, please enter anthor one : ";
            accountnumber = clsInputValidate::ReadString();
        }

        clsBankClient newclient = clsBankClient::get_add_new_client_object(accountnumber);

        _read_client_info(newclient);

        clsBankClient::enSaveResults saveresult;

        saveresult = newclient.save();

        switch (saveresult)
        {
        case clsBankClient::enSaveResults::Succeeeded:
            cout << "\nAccount Added Successfully :-)\n";
            _print_client(newclient);
            break;

        case clsBankClient::enSaveResults::FialdEmptyObject:
            cout << "\nError account was not saved because  it's empty";
            break;


        }


    }


};

