#pragma once
#include <iostream>
#include <string>
#include "InterfaceCommunication.h"
using namespace std;

class clsPerson : public InterfaceCommunication
{

private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone) {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;

    }
    //property set
 void setFirstname(string FirstName) {
     _FirstName = FirstName;
    }
 // property get
    string GetFirstName() {

        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = setFirstname)) string FirstName;

    //property set
    void SetLastName(string LastName) {
        _LastName = LastName;
    }
    //property Get
    string GetLastName() {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName))string LastName;

    //property Set
    void SetEmail(string Email) {
        _Email = Email;
    }

    // property Get
    string GetEmail() {
        return _Email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    //prpperty set
    void SetPhone(string Phone) {
        _Phone = Phone;
    }

    // property get
    string GetPhone() {
        return _Phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;

    //get fullName
    string  FullName() {
       return _FirstName + " " + _LastName;
    }

    void Print() {

        cout << "FirstName : " << _FirstName << endl;
        cout << "LastName  : " << _LastName << endl;
        cout << "FulltName : " << FullName() << endl;
        cout << "Email     : " << _Email << endl;
        cout << "Phone     : " << _Phone << endl;
    }

    void SendEmail(string Titel, string Body) {};
    void SendFax(string Titel, string Body) {};
    void SendSMS(string Titel, string Body) {};

};

