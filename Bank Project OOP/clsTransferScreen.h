#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"Global.h"
using namespace std;

class clsTransferScreen :protected clsScreen
{
private:

    struct stransfer {
        string time;
        string accountnumber1;
        string accountnumber2;
        double amount;
        double amount1;
        double amount2;
        string username;
    };

   static void print_client_card(clsBankClient client)
    {

        cout << "\nClient Card : ";
        cout << "\n___________________";
        cout << "\nFull Name   : " << client.fullname();
        cout << "\nAcc.Number  : " << client.accountnumber();
        cout << "\nBalance     : " << client.accountbalance;
        cout << "\n___________________\n";
    }

   static string _convert_object_to_line_transfer_history( clsBankClient client1,clsBankClient client2,
       double amount,string Seperator = "#//#")
   {

       string UserRecord = "";
       string time = clsDate::date_to_string_with_hours(clsDate());
       UserRecord += time + Seperator;
       UserRecord += client1.accountnumber() + Seperator;
       UserRecord += client2.accountnumber() + Seperator;
       UserRecord += to_string(amount) + Seperator;
       UserRecord += to_string(client1.accountbalance) + Seperator;
       UserRecord += to_string(client2.accountbalance) + Seperator;
       UserRecord += CurrentUser.username;
       return UserRecord;

   }

   static void _save_transfer_to_file(clsBankClient client1,clsBankClient client2,double amount)
   {

       fstream MyFile;
       MyFile.open("TransferHistory.txt", ios::app);//not overwrite

       string DataLine;

       if (MyFile.is_open())
       {

           DataLine = _convert_object_to_line_transfer_history(client1,client2,amount);
           MyFile << DataLine << endl;

           MyFile.close();

       }

   }

   static void _print_data_record_line(stransfer log)
    {

        cout << "| " << setw(25) << left << log.time;
        cout << "| " << setw(10) << left << log.accountnumber1;
        cout << "| " << setw(10) << left << log.accountnumber2;
        cout << "| " << setw(10) << left << log.amount;
        cout << "| " << setw(15) << left << log.amount1;
        cout << "| " << setw(15) << left << log.amount2;
        cout << "| " << setw(15) << left << log.username;


    }

    static stransfer _convert_line_data_to_struct(string line, string seperator = "#//#")
    {
        stransfer log;
        vector<string> vdata;
        vdata = clsString::split_sentence_extra(line, seperator);
        log.time = vdata[0];
        log.accountnumber1 = vdata[1];
        log.accountnumber2 = vdata[2];
        log.amount = stoi(vdata[3]);
        log.amount1 = stoi(vdata[4]);
        log.amount2 = stoi(vdata[5]);
        log.username = vdata[6];

        return log;
    }

    static vector <stransfer> _load_login_data_from_file()
    {
        vector <stransfer> vdata;
        fstream myfile;
        myfile.open("TransferHistory.txt", ios::in);
        if (myfile.is_open()) {
            string line;
            while (getline(myfile, line)) {
                stransfer data = _convert_line_data_to_struct(line);
                vdata.push_back(data);
            }
            myfile.close();
        }
        return vdata;
    }

public:

  static  void show_transfer_screen()
    {
        system("cls");
        _draw_screen_header("\t  Transfer Screen");


        cout << "\nEnter Account Number to Transfer from: ";
        string accountnumber1 = clsInputValidate::ReadString();

        while (!clsBankClient::is_client_exist(accountnumber1))
        {
            cout << "\nAccount number is not found, choose anthor one : ";
            accountnumber1 = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(accountnumber1);
        print_client_card(client);



        cout << "\nPlease enter Account Number to Transfer to : ";
        string accountnumber2 = clsString::read_string();

        while (accountnumber1 == accountnumber2)
        {
            cout << "\nPlease enter Anthor Account Number to Transfer to : ";
             accountnumber2 = clsString::read_string();
        }

        while (!clsBankClient::is_client_exist(accountnumber2))
        {
            cout << "\nAccount number is not found, choose anthor one : ";
            accountnumber2 = clsInputValidate::ReadString();

        }
        clsBankClient client2 = clsBankClient::Find(accountnumber2);
        print_client_card(client2);


        cout << "\nEnter Transfer Amount : ";
        double amount = clsInputValidate::ReadDblNumberBetween(0,client.accountbalance,"\nPlease enter a valid amount :");

        cout << "\nAre you sure you want to perform this Operation ? y/n : ";
        char answer;
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            client.withdraw(amount);
            client2.deposit(amount);
            cout << "\nTransfer Done Successfully.\n";
            print_client_card(client);
            print_client_card(client2);

            _save_transfer_to_file(client,client2,amount);
        }
        else
        {
            cout << "\nOperation was Cancelled.\n";
        }


    }

  static void show_transfer_log()
  {
      vector <stransfer> vdata = _load_login_data_from_file();

      _draw_screen_header("\t Transfer Regsiter List Screen\n");

      cout << "\n\t\t\t\t\t (" << vdata.size() << ") Records(s).";
      cout << "\n_______________________________________________________";
      cout << "_________________________________________________________\n" << endl;
      cout << "| " << left << setw(25) << "Time";
      cout << "| " << left << setw(10) << "s.Acct";
      cout << "| " << left << setw(10) << "d.Acct";
      cout << "| " << left << setw(10) << "Amount";
      cout << "| " << left << setw(15) << "s.Balance";
      cout << "| " << left << setw(15) << "d.Balance";
      cout << "| " << left << setw(15) << "User";

      cout << "\n_______________________________________________________";
      cout << "_________________________________________________________\n" << endl;

      if (vdata.size() == 0)
          cout << "\t\t\t\tNo Records Available In the System!";
      else

          for (stransfer data : vdata)
          {

              _print_data_record_line(data);
              cout << endl;
          }

      cout << "\n_______________________________________________________";
      cout << "_________________________________________________________\n" << endl;
  }

};
