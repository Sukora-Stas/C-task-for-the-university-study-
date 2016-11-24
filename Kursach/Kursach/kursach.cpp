#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <io.h>

using namespace std;

/*���������� ��������� ������� ������ �� ���������� ������
 *�������� � ���������� ����������� �������� ����� ��������� ���: �.�.� ����������;
 *���; �����; ���������� ����, ���������� �� �������; ������ �� ���� ����.
 *
 *�������������� �������: ��� ������ � ���� � ������� ������ �����������
 * � ��������� ������ �� ���������� ������ ��� ������� �� ���. ������� ����� �����
 * ������ �� ��������� ������ �� ������������ �����. �,� �������� � ����������.
 * 
 * ����� ��� ���� ��������� �������: ����������� ����������� �� ����� � �������(��� �����������!),
 * ���������� �������������� � ���������� ������������, ��� ������� ��� ���� ������, ��� ������� ��� ���� ����������.
 */

FILE *fl;
typedef struct
{
	char marka[50];
	unsigned char date[10];
	unsigned char check;
	//char tr = 
} TStudent;
TStudent stud[30]; // ������ ��������
char name[20]; // ��� �����
char login[5];
char password[5];
int nst = 0; // ����� ��������� ��������
int Menu(); // �������� ����
void Authorization(); //�����������
void Newf(); // �������� ������ �����
void Spisok(); // ������������ �����
void Opf(); // �������� �����
void Resc(); // ����� ���������� �� �����
void Resf(); // ����� ���������� � ����
void beginMenu();


int main()
{
	setlocale(LC_ALL, "Russian");
	beginMenu();
	Authorization();
	
	if (login == (string)"admin" && password == (string)"admin"){
		cout << "OK!\n";
		system("pause");
		system("cls");
		beginMenu();
		while (true)
		{
			switch (Menu())
			{
				//case 1: Nnf(); break;
			case 1: Newf(); break;
			case 2: Spisok(); break;
			case 3: Opf(); break;
			case 4: Resc(); break;
			case 5: Resf(); break;
			case 6: return 0;
			default: puts("Viberite pravilno!");
			}
			system("pause");
			system("cls"); // ������� ������
		}
	}
	if (login != (string)"admin" || password != (string)"admin")
		cout << "Error! Return please!";
}

void Authorization()
{
	cout << "�����������!\n������� ��� ����� � ������\n\n";
	printf("%15s", "Login: ");
	cin >> login;
	printf("%15s", "Password: ");
	cin >> password;
}

void beginMenu()
{
	printf("%-15s%-8s%-7i", "������ �.�.", "������", 680961);
	cout << "\n\n��������� ������� ������ �� ���������� ������" << endl;
	cout<<"-------------------------------------------------\n"<<endl;
	//printf("%-5s%-11d%-25s%-11.4f", "\nAUD", 1, "������������� ������", 44.9883);
}

int Menu() // ����
{
	cout << "VIBERITE:" << endl;
	//cout << "1. Vvod file name" << endl;
	cout << "1. New file" << endl;
	cout << "2. Vvesti spisok" << endl;
	cout << "3. Open file" << endl;
	cout << "4. Vivesti result" << endl;
	cout << "5. Vivesti v fail" << endl;
	cout << "6. Exit" << endl;
	int i;
	cin >> i; // ���� ���������� ������ ����
	return i;
}
//void Nnf() // ���� ����� �����
//{
//	cout << "Vvedite file name" << endl;
//	cin >> name;
//}
void Newf() // �������� ������ �����
{
	cout << "Vvedite file name" << endl;
	cin >> name;
	if ((fl = fopen(name, "wb")) == NULL)
	{
		cout << "Oshibka pri sozdanii" << endl;
		exit(1);
	}
	cout << "OK" << endl;
	fclose(fl);
}
void Spisok() // ���� ������ � �����
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Oshibka pri sozdanii" << endl;
		exit(1);
	}
	cout << "Vvedite chislo TV" << endl;
	cin >> nst;
	for (int i = 0; i<nst; i++)
	{
		cout << "Vvedite Marku: ";
		cin >> stud[i].marka;
		cout << "Vvedite date: ";
		cin >> stud[i].date;
		cout << "Vvedite vipolnen ili net: ";
		cin >> stud[i].check;
		fwrite(&stud[i], sizeof(TStudent), 1, fl);
	}
	fclose(fl);
}
void Opf() // �������� ��������� �����
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Oshibka pri otkritii" << endl;
		exit(1);
	}
	nst = 0;
	TStudent std;
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		cout << stud[nst].marka << stud[nst].date << stud[nst].check << endl;
		nst++;
	}
	fclose(fl);
}
void Resc() // ����� ���������� �� �����
{
	for (int i = 0; i < nst; i++)
		if (stud[i].check == '0')
			cout << stud[i].marka << endl;
}
void Resf() // ����� ���������� � ��������� ����
{
	char namet[30];
	FILE *ft;
	cout << "Vvedite imya faila" << endl;
	cin >> namet;
	if ((ft = fopen(namet, "w")) == NULL)
	{
		cout << "Oshibka pri sozdanii" << endl;
		exit(1);
	}
	char s[80];
	for (int i = 0; i < nst; i++)
		if (stud[i].check == '0')
		{
			strcpy(s, stud[i].marka);
			strcat(s, "\n"); // ���������� ����������� �����
			fputs(s, ft);
		}
	fclose(ft);
}