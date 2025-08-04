#pragma once
#include<iostream>
#include<iomanip>

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
class clsTotalBalances : protected clsScreen
{
private:

    static void print_client_record_balance_line(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.accountnumber();
        cout << "| " << setw(40) << left << Client.fullname();
        cout << "| " << setw(12) << left << Client.accountbalance;

    }

public:

   static void show_total_balances()
    {
        vector <clsBankClient> vClients = clsBankClient::get_client_list();

        cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::get_total_balances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                print_client_record_balance_line(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
    }

};

