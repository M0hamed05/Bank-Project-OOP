#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{

private :
	string _fristname;
	string _lastname;
	string _email;
	string _phone;

public:

	clsPerson(string fristname, string lastnmae, string email, string phone) 
	{
		_fristname = fristname;
		_lastname = lastnmae;
		_email = email;
		_phone = phone;
	}

	void set_fristname(string fristname) 
	{
		_fristname = fristname;
	}
	string get_fristname()
	{
		return _fristname;
	}
	__declspec(property(get = get_fristname, put = set_fristname))string fristname;

	void set_lastname(string lastname)
	{
		_lastname = lastname;
	}
	string get_lastname()
	{
		return _lastname;
	}
	__declspec(property(get = get_lastname, put = set_lastname))string lastname;

	string fullname()
	{
		return _fristname + " " + _lastname;
	}

	void set_email(string email)
	{
		_email = email;
	}
	string get_email() 
	{
		return _email;
	}
	__declspec(property(get = get_email, put = set_email))string email;

	void set_phone(string phone)
	{
		_phone = phone;
	}
	string get_phone()
	{
		return _phone;
	}
	__declspec(property(get = get_phone, put = set_phone))string phone;





};

