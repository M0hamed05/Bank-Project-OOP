#pragma once

#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"

using namespace std;

class clsCurrency
{
private:
	enum enmode { emptymode = 0, udpatemode = 1 };
	enmode _mode;

	string _country;
	string _currencycode;
	string _currencyname;
	float _rate;


static	clsCurrency _convert_line_to_object_currency(string line, string seperator = "#//#") {
		
		vector<string>vdata;
		vdata = clsString::split_sentence_extra(line, seperator);

		return clsCurrency(enmode::udpatemode, vdata[0], vdata[1], vdata[2], stof(vdata[3]));
	}

static string _convert_object_to_line_currency(clsCurrency currency, string seperator = "#//#")
{
	string stCurrencyRecord = "";
	stCurrencyRecord += currency.country() + seperator;
	stCurrencyRecord += currency.currencycode() + seperator;
	stCurrencyRecord += currency.currencyname() + seperator;
	stCurrencyRecord += to_string(currency.rate());

	return stCurrencyRecord;
}

static	vector <clsCurrency> _load_currency_data_from_file() {
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		vector<clsCurrency>vcurrencyData;
		string line;

		if (myfile.is_open()) {
			while (getline(myfile, line)) {

				clsCurrency currency = _convert_line_to_object_currency(line);
				vcurrencyData.push_back(currency);
			}
			myfile.close();
		}
		return vcurrencyData;
	}

static void _save_currency_data_to_file(vector <clsCurrency> vCurrencys)
{

	fstream MyFile;
	MyFile.open("Currencies.txt", ios::out);//overwrite

	string DataLine;

	if (MyFile.is_open())
	{

		for (clsCurrency C : vCurrencys)
		{
			DataLine = _convert_object_to_line_currency(C);
			MyFile << DataLine << endl;



		}

		MyFile.close();

	}

}

void _update() {
		
		vector<clsCurrency> _vcurrency;

		_vcurrency = _load_currency_data_from_file();

		for (clsCurrency& c : _vcurrency)
		{
			if (c.currencycode() == currencycode()) {
				c = *this;
				break;
			}
		}
		_save_currency_data_to_file(_vcurrency);
	}

static clsCurrency _get_empty_currency_object()
	{
		return clsCurrency(enmode::emptymode, "", "", "", 0);
	}


public:

	clsCurrency(enmode mode, string country, string currencycode, string currencyname, float rate)
	{
		_mode = mode;
		_country = country;
		_currencycode = currencycode;
		_currencyname = currencyname;
		_rate = rate;
	}

	bool is_empty()
	{
		return(_mode == enmode::emptymode);
	}

	string country() { return _country; }

	string currencycode() { return _currencycode; }

	string currencyname() { return _currencyname; }

	float rate() { return _rate; }

	 void updaterate(float newrate) {
		_rate = newrate;
		_update();
	}

	static clsCurrency find_by_code(string code) {

		code = clsString::make_it_allcapital(code);

		fstream myfile;
		myfile.open("Currencies.txt", ios::in);

		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {

				clsCurrency currency = _convert_line_to_object_currency(line);
				
				if (clsString::make_it_allcapital(currency.currencycode()) == code) {
					myfile.close();
					return currency;
			}
			}
			myfile.close();
		}
		return _get_empty_currency_object();
	}

	static clsCurrency find_by_country(string country) {

		country = clsString::make_it_allcapital(country);

		fstream myfile;
		myfile.open("Currencies.txt", ios::in);

		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				clsCurrency currency = _convert_line_to_object_currency(line);
				if (clsString::make_it_allcapital(currency.country()) == country) {
					myfile.close();
					return currency;
				}
			}
			myfile.close();
		}
		return _get_empty_currency_object();
	}

	static bool is_country_exist(string country_code)
	{
		clsCurrency c1 = clsCurrency::find_by_code(country_code);
		return(!c1.is_empty());
	}

	static vector<clsCurrency> get_currencies_list() 
	{
		return _load_currency_data_from_file();
	}

	static void PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.country();
		cout << "\nCode       : " << Currency.currencycode();
		cout << "\nName       : " << Currency.currencyname();
		cout << "\nRate(1$) = : " << Currency.rate();

		cout << "\n_____________________________\n";

	}


};

