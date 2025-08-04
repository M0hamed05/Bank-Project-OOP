#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _mode;
    string _username;
    string _password;
    int _permissions;
    bool _MarkedForDelete = false;

    static clsUser _convert_line_to_object(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::split_sentence_extra(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

    }

    static string _convert_object_to_line(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.fristname + Seperator;
        UserRecord += User.lastname + Seperator;
        UserRecord += User.email + Seperator;
        UserRecord += User.phone + Seperator;
        UserRecord += User.username + Seperator;
        UserRecord += User.password + Seperator;
        UserRecord += to_string(User.permissions);

        return UserRecord;

    }

    static  vector <clsUser> _load_user_data_from_file()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _convert_line_to_object(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _save_users_data_to_file(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _convert_object_to_line(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _load_user_data_from_file();

        for (clsUser& U : _vUsers)
        {
            if (U.username == username)
            {
                U = *this;
                break;
            }

        }

        _save_users_data_to_file(_vUsers);

    }

    void _addnew()
    {

        _add_data_line_to_file(_convert_object_to_line(*this));
    }

    void _add_data_line_to_file(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _get_empty_user_object()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
    };

    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _mode = Mode;
        _username = UserName;
        _password = Password;
        _permissions = Permissions;
    }

    bool is_empty()
    {
        return (_mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _username;
    }

    void SetUserName(string UserName)
    {
        _username = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string username;

    void SetPassword(string Password)
    {
        _password = Password;
    }

    string GetPassword()
    {
        return _password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string password;

    void SetPermissions(int Permissions)
    {
        _permissions = Permissions;
    }

    int GetPermissions()
    {
        return _permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int permissions;

    static clsUser find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _convert_line_to_object(Line);
                if (User.username == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _get_empty_user_object();
    }

    static clsUser find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _convert_line_to_object(Line);
                if (User.username == UserName && User.password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _get_empty_user_object();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults save()
    {

        switch (_mode)
        {
        case enMode::EmptyMode:
        {
            if (is_empty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::is_user_exists(_username))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _addnew();
                //We need to set the mode to update after add new
                _mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool is_user_exists(string UserName)
    {

        clsUser User = clsUser::find(UserName);
        return (!User.is_empty());
    }

    bool delete_user()
    {
        vector <clsUser> _vUsers;
        _vUsers = _load_user_data_from_file();

        for (clsUser& U : _vUsers)
        {
            if (U.username == _username)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _save_users_data_to_file(_vUsers);

        *this = _get_empty_user_object();

        return true;

    }

    static clsUser get_add_new_user_object(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> get_user_list()
    {
        return _load_user_data_from_file();
    }

    static void print_user(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.fristname;
        cout << "\nLastName    : " << User.lastname;
        cout << "\nFull Name   : " << User.fullname();
        cout << "\nEmail       : " << User.email;
        cout << "\nPhone       : " << User.phone;
        cout << "\nUser Name   : " << User.username;
        cout << "\nPassword    : " << User.password;
        cout << "\nPermissions : " << User.permissions;
        cout << "\n___________________\n";

    }


};

