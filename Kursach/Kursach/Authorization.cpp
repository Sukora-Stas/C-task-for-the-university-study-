#include "Authorization.h"

bool Authorization()
{
	string login;
	string password;
	cout << "јвторизаци€!\n¬ведите ваш логин и пароль\n\n";
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