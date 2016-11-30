#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <istream>
#include <Windows.h>
#include <cstdio>
#include <io.h>
#include <string>
#include "Authorization.h"

using namespace std;

/*���������� ��������� ������� ������ �� ���������� ������
 *�������� � ���������� ������ ����������� �������� ����� ��������� ���: �.�.� ����������;
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
	char FIO[25];
	char year[10];
	char month[2];
	char day[3];
	char stoimost[3];
} TStudent;
TStudent stud[30]; // ������ ��������
char name[20]; // ��� �����
int nst = 0; // ����� ��������� ��������
int Menu(); // �������� ����
char sum[7];
void Newf(); // �������� ������ �����
void Spisok(); // ������������ �����
void Opf(); // �������� �����
void Resc(); // ����� ���������� �� �����
void Resf(); // ����� ���������� � ����
string Month();

void beginMenu();
string login;
string password;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	beginMenu();
	do
	{
		if (Authorization()){
			cout << "\nOK!\n";
			system("pause");
			system("cls");
			break;
		}
		cout << "\nError! Return please!\n";
		system("pause");
		system("cls");
		beginMenu();
	} while (true);

	while (true)
	{
		switch (Menu())
		{
		case 1: Newf(); break;
		case 2: Spisok(); break;
		case 3: Opf(); break;
		case 4: Resc(); break;
		case 5: Resf(); break;
		case 6: return 0;
		default: 
			cout<<"�������� ���������!\n";
			system("pause");
			system("cls");
			Menu();
		}
		system("pause");
		system("cls"); // ������� ������
	}
}

void beginMenu()
{
	printf("%-15s%-8s%-7i", "������ �.�.", "������", 680961);
	cout << "\n\n��������� ������� ������ �� ���������� ������" << endl;
	cout << "-------------------------------------------------\n" << endl;
}

int Menu() // ����
{
	beginMenu();
	cout << "����:\n" << endl;
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "1.", "�������� ������ �����", '|','\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "2.", "���������� ��", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "3.", "�������� �� ���������� ������", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "4.", "������� ����", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "5.", "�������� � ����", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "6.", "�����", '|', '\n');
	cout << "��� �����: " << endl;
	int i;
	cin >> i; // ���� ���������� ������ ����
	return i;
}

void Spisok() // ���� ������ � �����
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		exit(1);
	}
	cout << "������� ����� �����������, ������� ���������� ��������" << endl;
	cin >> nst;
	for (int i = 0; i<nst; i++)
	{
		cout << "������� ������� ";
		cin >> stud[i].FIO;
		cout << "������� ���: ";
		cin >> stud[i].year;
		cout << "������� �����: ";
		cin >> stud[i].month;
		cout << "������� ���������� ���� �� �������: ";
		cin >> stud[i].day;
		cout << "������� ������ �� ����� ���� �� �������: ";
		cin >> stud[i].stoimost;
		fwrite(&stud[i], sizeof(TStudent), 1, fl);
		system("cls");
		beginMenu();
	}
	fclose(fl);
}

void Newf() // �������� ������ �����
{
	cout << "������� ��� �����" << endl;
	cin >> name;
	if ((fl = fopen(name, "wb")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		exit(1);
	}
	cout << "OK" << endl;
	fclose(fl);
}

void Opf() // �������� ��������� �����
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		exit(1);
	}
	nst = 0;
	TStudent std;
	cout << "|--------------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-15s%-1c%-1c", '|', "�������", "���", "�����", "���.", "������", '|', '\n');
	printf("%-3c%-25s%-10s%-10s%-6s%-15s%-1c%-1c", '|', "����������", "", "", "����", "�� ����, ���.", '|', '\n');
	cout << "|--------------------------------------------------------------------|\n" << endl;
	
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		char month = *stud[nst].month;
		string month2;
		switch (month)
		{
		case '1': month2 = "������"; break;
		case '2':month2 = "�������"; break;
		case '3': month2 = "����"; break;
		case '4': month2 = "������"; break;
		case '5':month2 = "���"; break;
		case '6': month2 = "����"; break;
		case '7': month2 = "����"; break;
		case '8':month2 = "������"; break;
		case '9': month2 = "��������"; break;		
		default: cout << "�������� ���������!\n";
		}
		printf("%-3c%-25s%-10s%-10s%-6s%-15s%-1c%-1c", '|',
			stud[nst].FIO,
			stud[nst].year,
				month2.c_str(),
					stud[nst].day,
						stud[nst].stoimost,
							'|',
								'\n');
		printf("%-3c%-25s%-10s%-10s%-6s%-15s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');
		
		nst++;
	}
	cout << "|--------------------------------------------------------------------|\n" << endl;
	fclose(fl);
}

void Resc() // ����� �����
{
	cout << "������� ��� �����: ";
	cin >> name;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������, �������� ����� ���� �� ������." << endl;
		exit(1);
	}
	else
	{
		cout << "OK\n";
	}
}
void Resf() // ����� ���������� � ��������� ����
{
	char namet[30];
	FILE *ft;
	cout << "������� ��� �����, ����������" << endl;
	cin >> namet;
	if ((ft = fopen(namet, "w")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		system("pause");
		Resf();
	}
	char s[80];
	for (int i = 0; i < nst; i++)
		//if (stud[i].check == '0')
		//{
		//	strcpy(s, stud[i].FIO);
		//	strcat(s, "\n"); // ���������� ����������� �����
		//	fputs(s, ft);
		//}
	fclose(ft);
}