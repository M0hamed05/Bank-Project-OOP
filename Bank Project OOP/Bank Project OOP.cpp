#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;


void read_client_info(clsBankClient& client)
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

void update_client() {
	string accountnumber = "";
	cout << "\nPlease Enter client Account Number : ";
	accountnumber = clsInputValidate::ReadString();

	while (!clsBankClient::is_client_exist(accountnumber)) {
		cout << "Account number is not found, choose anthor one : ";
        accountnumber = clsInputValidate ::ReadString();
	}

	clsBankClient client = clsBankClient::find(accountnumber);

	client.print();
	cout << "\n\nUpdate Client Info : ";
	cout << "\n--------------------\n"; 
    
    read_client_info(client);

    clsBankClient::enSaveResults Saveresult;

    Saveresult = client.save();

    switch (Saveresult) {
    case clsBankClient::enSaveResults::Succeeeded:
        cout << "\nAccount Updated Successfully\n";
        client.print();
        break;
    case clsBankClient::enSaveResults::FialdEmptyObject:
        cout << "\nError account was not saved because it's empty\n";
        break;


    }

}

int main()
{
    update_client();
}
