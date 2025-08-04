#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientListScreen : protected clsScreen
{
private:
    static void print_client_record_line(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.accountnumber();
        cout << "| " << setw(20) << left << Client.fullname();
        cout << "| " << setw(12) << left << Client.phone;
        cout << "| " << setw(20) << left << Client.email;
        cout << "| " << setw(10) << left << Client.pincode;
        cout << "| " << setw(12) << left << Client.accountbalance;

    }
    
public:
    static void show_client_list()
    {

        vector <clsBankClient> vClients = clsBankClient::get_client_list();

        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                print_client_record_line(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

