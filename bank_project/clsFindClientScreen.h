#pragma once
#include <fstream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {

		cout << "\n_____________________________\n";
		cout << "\t Card Client";
		cout << "\n_____________________________\n";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFullName    : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc.Number  : " << Client.AccountNumber();
		cout << "\nPassWord    : " << Client.PinCode;
		cout << "\nbalance     : " << Client.AccountBalance;
		cout << "\n_____________________________\n";

	}
public:
	static void ShowFindClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t Find Client Screen");


		string AccountNumber = "";
		cout << "\nEnter AccountNumber : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "AccountNumber is Not Found, try Another AccountNumber";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
			_PrintClient(Client1);
		}
		else {
			cout << "Client was Not Found :-)";
		}
	}
};

