#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("%-5s%-11s%-25s%-11s", "���", "��������", "������", "��������"); 
	cout<<"\n-------------------------------------------------"<<endl; 
	printf("%-5s%-11d%-25s%-11.4f", "\nAUD", 1, "������������� ������", 44.9883); 
	printf("%-5s%-11d%-25s%-11.4f", "\nGBP", 1, "���� ����������", 86.8429); 
	printf("%-5s%-11d%-25s%-11.4f", "\nBYR", 10000, "����������� �����", 39.7716); 
	printf("%-5s%-11d%-25s%-11.4f", "\nDKK", 10, "������� �����", 84.9192); 
	printf("%-5s%-11d%-25s%-11.4f", "\nUSD", 1, "������ ���", 58.4643); 
	printf("%-5s%-11d%-25s%-11.4f", "\nEUR", 1, "����", 63.3695); 
	printf("%-5s%-11d%-25s%-11.4f", "\nKZT", 100, "��������� �����", 31.4654);
	cout << "\n-------------------------------------------------" << endl;
	system("pause");
}