#include "Authorization.h"

bool Authorization()
{
	string login;
	string password;
	printf("%-1c%-35s%-8s%-32s%-1c%-1c", '|', "", "јвторизаци€", "", '|', '\n');
	printf("%-1c%-25s%-8s%-27s%-1c%-1c", '|', "", "¬ведите ваш логин и пароль", "", '|', '\n');
	//cout << "јвторизаци€!\n¬ведите ваш логин и пароль\n\n";
	printf("%15s", "Login: ");
	getline(cin, login);
	printf("%15s", "Password: ");

	char ch;
	ch = _getch();
	while (ch != 13){		//character 13 is enter
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	if (login == "admin" && password == "admin"){
		return true;
	}
	else
	{
		return false;
	}
}