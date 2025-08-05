#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "clsPerson.h"
#include "clsString.h"


class clsBankClient : public clsPerson
{
private:

	enum enmode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enmode _mode;

	string _accountnumber;
	string _pincode;
	float _accountbalance;
	bool _markfordelete = false;

	static clsBankClient _convert_line_to_client_object(string line, string seperator = "#//#")
	{
		vector<string> vclientdate;
		vclientdate = clsString::split_sentence_extra(line, seperator);
		return clsBankClient(enmode::UpdateMode, vclientdate[0],
							vclientdate[1], vclientdate[2], 
							vclientdate[3], vclientdate[4],
							vclientdate[5], stod(vclientdate[6]));
	}

	static string _convert_client_object_to_line(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.fristname + Seperator;
		stClientRecord += Client.lastname + Seperator;
		stClientRecord += Client.email +Seperator;
		stClientRecord += Client.phone + Seperator;
		stClientRecord += Client.accountnumber() + Seperator;
		stClientRecord += Client.pincode + Seperator;
		stClientRecord += to_string(Client.accountbalance);

		return stClientRecord;

	}

	static clsBankClient _get_empty_client_object() 
	{
		return clsBankClient(enmode::EmptyMode, "", "", "", "", "", "", 0);
	}
	
	static vector <clsBankClient> _load_client_data_from_file()
	{
		vector <clsBankClient> vclient;
		fstream myfile;
		myfile.open("Clients.txt",ios::in);
		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				clsBankClient client = _convert_line_to_client_object(line);
				vclient.push_back(client);
			}
			myfile.close();
		}
		return vclient;
	}

	static void _save_client_data_to_file(vector<clsBankClient> vclient) {

		fstream myfile;

		myfile.open("Clients.txt", ios::out);

		string dataline;

		if (myfile.is_open()) {

			for (clsBankClient c : vclient) {

				if (c.markfordelete() == false) {
					dataline = _convert_client_object_to_line(c);
					myfile << dataline << endl;
				}
			}

			myfile.close();


		}
	}

	void _update() 
	{
		
		vector<clsBankClient> vclient;
		vclient = _load_client_data_from_file();
		for (clsBankClient& c : vclient) {
			if (c.accountnumber() == accountnumber()) {
				c = *this;
				break;
			}
		}
		_save_client_data_to_file(vclient);
	}

	void _add_new()
	{
		_add_data_line_to_file(_convert_client_object_to_line(*this));
	}

	void _add_data_line_to_file(string dataline)
	{
		fstream myfile;
		myfile.open("Clients.txt", ios::out | ios::app);
		if (myfile.is_open()) {
			myfile << dataline << endl;
			myfile.close();
		}
	}

public:

	clsBankClient(enmode mode, string fristname, string lastname, string email, string phone,
		string accountnumber, string pincode, float accountbalance) :
		clsPerson(fristname, lastname, email, phone)
	{
		_mode = mode;
		_accountnumber = accountnumber;
		_pincode = pincode;
		_accountbalance = accountbalance;
	}

	bool is_empty()
	{
		return (_mode == enmode::EmptyMode);
	}
	string accountnumber()
	{
		return _accountnumber;
	}

	void set_pincode(string pincode)
	{
		_pincode = pincode;
	}
	string get_pincode()
	{
		return _pincode;
	}
	__declspec(property(get = get_pincode, put = set_pincode))string pincode;

	void set_accountbalance(float accountbalance)
	{
		_accountbalance = accountbalance;
	}
	float get_accountbalance()
	{
		return _accountbalance;

	}
	__declspec(property(get = get_accountbalance, put = set_accountbalance))float accountbalance;

	bool markfordelete() {
		return _markfordelete;
	}

	/*void print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << fristname;
		cout << "\nLastName    : " << lastname;
		cout << "\nFull Name   : " << fullname();
		cout << "\nEmail       : " << email;
		cout << "\nPhone       : " << phone;
		cout << "\nAcc. Number : " << _accountnumber;
		cout << "\nPassword    : " << _pincode;
		cout << "\nBalance     : " << _accountbalance;
		cout << "\n___________________\n";

	}
	*/

	static clsBankClient Find(string accountnumber)
	{
		vector <clsBankClient> vClients;
		 
		fstream myfile;
		myfile.open("Clients.txt", ios::in);//read mode;
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line)) {
				clsBankClient client = _convert_line_to_client_object(line);
				if (client.accountnumber() == accountnumber) {
					myfile.close();
					return client;
				}
				vClients.push_back(client);
			}
			myfile.close();
		}

		return	_get_empty_client_object();
	}

	static clsBankClient Find(string accountnumber,string pincode)
	{
		vector <clsBankClient> vClients;

		fstream myfile;
		myfile.open("Clients.txt", ios::in);//read mode;
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line)) {
				clsBankClient client = _convert_line_to_client_object(line);
				if (client.accountnumber() == accountnumber && client.pincode == pincode) {
					myfile.close();
					return client;
				}
				vClients.push_back(client);
			}
			myfile.close();
		}

		return	_get_empty_client_object();
	}

	enum enSaveResults { FialdEmptyObject=0, Succeeeded=1, fiad_accout_exist=2};

	enSaveResults save() {
		switch (_mode) {
		case enmode::EmptyMode:
			return enSaveResults::FialdEmptyObject;

		case enmode::UpdateMode:
			_update();
			return enSaveResults::Succeeeded;

		case enmode::AddNewMode:
			if (clsBankClient::is_client_exist(_accountnumber))
			{
				return enSaveResults::fiad_accout_exist;
			}
			else
			{
				_add_new();
				_mode = enmode::UpdateMode;
				return enSaveResults::Succeeeded;
			}
		}
	}

	static bool is_client_exist(string accountnumber)
	{
		clsBankClient client = Find(accountnumber);

		return(!client.is_empty());
	}

	static clsBankClient get_add_new_client_object(string accountnumber)
	{
		return clsBankClient(enmode::AddNewMode, "", "", "", "",accountnumber, "", 0);
	}

	static vector <clsBankClient> get_client_list()
	{
		return _load_client_data_from_file();
	}

	void deposit(double amount) {
		_accountbalance += amount;
		save();
	}

	bool withdraw(double amount) {

		if (amount > accountbalance) {
			return false;
		}
		_accountbalance -= amount;
		save();
		return true;
	}

	bool delete_client() {
		vector <clsBankClient> vclients;
		vclients = _load_client_data_from_file();

		for (clsBankClient& c : vclients) {
			if (c.accountnumber() == _accountnumber) {
				c._markfordelete = true;
				break;
			}
		}
		
		_save_client_data_to_file(vclients);

		*this = _get_empty_client_object();
		return true;
	}

	static float get_total_balances() 
	{
		vector <clsBankClient> vclient = get_client_list();
		double total = 0;

		for (clsBankClient client : vclient)
		{
			total += client.accountbalance;
		}

		return total;
	}

};