#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <istream>
#include <Windows.h>
#include "Authorization.h"

using namespace std;

FILE *fl;
typedef struct
{
	char FIO[25];
	char year[10];
	char month[3];
	char day[3];
	char stoimost[3];
} TStudent;
TStudent stud[30]; // ������ ��������
char name[20]; // ��� �����
int nst = 0; // ����� ��������� ��������
int Menu(); // �������� ����
void Newf(); // �������� ������ �����
void Spisok(); // ������������ �����
void OutSpisok(); // �������� �����
void SelectionFile(); // ����� ���������� �� �����
void Zadanie();
void IZadanie1();
void IZadanie2();
string Month();

void beginMenu();
string login;
string password;
int main()
{
	HWND hwnd;
	WCHAR Title[1024];
	GetConsoleTitle(Title, 1024); // ������ ��� ����
	hwnd = FindWindow(NULL, Title); // ������ hwnd ����
	MoveWindow(hwnd, 600, 50,850, 900, TRUE);//xnew,ynew,wnew,hnew -����� ��������� x,y, ������ � ������
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
		case 3: OutSpisok(); break;
		case 4: SelectionFile(); break;
		case 5: IZadanie1(); break;
		case 6: IZadanie2(); break;
		case 7: Zadanie(); break;
		case 8: return 0;
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
	printf("%-1c%-25s%-15s%-8s%-30i%-1c%-1c", '|', "", "������ �.�.", "������", 680961, '|','\n');
	printf("%-1c%-15s%-8s%-18s%-1c%-1c", '|', "", "��������� ������� ������ �� ���������� ������","", '|', '\n');
	//cout << "\n\n��������� ������� ������ �� ���������� ������" << endl;
	cout << "|------------------------------------------------------------------------------|\n" << endl;
}

int Menu() // ����
{
	beginMenu();
	cout << "����:\n" << endl;
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "1.", "�������� ������ �����", '|','\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "2.", "���������� ��", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "3.", "�������� �� ���������� ������", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "4.", "������� ����", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "5.", "�������������� ������� 1", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "6.", "�������������� ������� 2", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "7.", "�������", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "8.", "�����", '|', '\n');
	cout << "\n��� �����: \n" << endl;
	int i;
	cin >> i; // ���� ���������� ������ ����
	return i;
}

void Spisok() // ���� ������ � �����
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		system("pause");
		system("cls");
		Menu();
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
		system("pause");
		system("cls");
		Menu();
	}
	cout << "OK" << endl;
	fclose(fl);
}

void OutSpisok() // ����� ������ �����������
{
	int sum = 0;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		system("pause");
		system("cls");
		Menu();
	}
	nst = 0;
	TStudent std;
	cout << "\n|-----------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�������", "���", "�����", "���.", "������", '|', '\n');
	printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "����������", "", "", "����", "�� ����", '|', '\n');
	cout << "|-----------------------------------------------------------------|\n" << endl;
	
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		int month = atoi(stud[nst].month);
		sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
		string month2;
		switch (month)
		{
		case 1: month2 = "������"; break;
		case 2:month2 = "�������"; break;
		case 3: month2 = "����"; break;
		case 4: month2 = "������"; break;
		case 5:month2 = "���"; break;
		case 6: month2 = "����"; break;
		case 7: month2 = "����"; break;
		case 8:month2 = "������"; break;
		case 9: month2 = "��������"; break;
		case 10: month2 = "�������"; break;
		case 11: month2 = "������"; break;
		case 12: month2 = "�������"; break;
		default: cout << "�������� ���������!\n";
		}
		printf("%-3c%-25s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
			stud[nst].FIO,
			stud[nst].year,
				month2.c_str(),
					stud[nst].day,
						stud[nst].stoimost,
						"���.",
							'|',
								'\n');
		printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');
		
		nst++;
	}
	cout << "|-----------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum,"���.", '|', '\n');
	cout << "|-----------------------------------------------------------------|\n" << endl;
	fclose(fl);
}

void SelectionFile() // ����� �����
{
	cout << "������� ��� �����: ";
	cin >> name;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������, �������� ����� ���� �� ������." << endl;
		system("pause");
		system("cls");
		Menu();
	}
	else
	{
		cout << "OK\n";
	}
}

void Zadanie()
{
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "�������:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "���������� ��������� ������� ������ �� ���������� ������", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�������� � ���������� ������ ����������� �������� ����� ��������� ���:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�.�.� ����������;���; �����; ���������� ����, ���������� �� �������;",'|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "������ �� ���� ����.",'|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�������������� �������: ��� ������ � ���� � ������� ������ �����������", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "c ��������� ������ �� ���������� ������ ��� ������� �� ���.", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "������� ����� ����� ������ �� ��������� ������ �� ������������ �����.",'|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�,� �������� � ����������.", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "����� ��� ���� ��������� �������: ����������� ����������� ���", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "����� � �������(��� �����������!), ", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "���������� �������������� � ���������� ������������, ", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "��� ������� ��� ���� ������, ��� ������� ��� ���� ����������.",'|', '\n');
}

void IZadanie1() // ����� ���������� � ��������� ����
{
	int x = 0;
	int y = 0;
	cout << "�������\n ";
	cout << "��� ������ � ���� � ������� ������ �����������\n ";
	cout << "� ��������� ������ �� ���������� ������ ��� ������� �� ���\n";

	cout << "������� �����:";
	cout << "x = ";
	cin >> x;
	cout << "������� ���:";
	cout << "y = ";
	cin >> y;

	int sum = 0;
	int all_sum = 0;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		system("pause");
		system("cls");
		Menu();
	}
	nst = 0;
	TStudent std;
	cout << "\n|------------------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "�������", "���", "�����", "���.", "������","���������", '|', '\n');
	printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "����������", "", "", "����", "�� ����","", '|', '\n');
	cout << "|------------------------------------------------------------------------|\n" << endl;
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;

		int month = atoi(stud[nst].month);
		int year = atoi(stud[nst].year);

		string month2;
		switch (month)
		{
		case 1: month2 = "������"; break;
		case 2:month2 = "�������"; break;
		case 3: month2 = "����"; break;
		case 4: month2 = "������"; break;
		case 5:month2 = "���"; break;
		case 6: month2 = "����"; break;
		case 7: month2 = "����"; break;
		case 8:month2 = "������"; break;
		case 9: month2 = "��������"; break;
		case 10: month2 = "�������"; break;
		case 11: month2 = "������"; break;
		case 12: month2 = "�������"; break;
		default: cout << "�������� ���������!\n";
		}
		if (month == x&&year == y){
			sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			all_sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			printf("%-3c%-25s%-10s%-10s%-6s%-3s%-7s%-5i%-4s%-1c%-1c", '|',
				stud[nst].FIO,
				stud[nst].year,
				month2.c_str(),
				stud[nst].day,
				stud[nst].stoimost,
				"���",
				sum,
				"���",
				'|',
				'\n');
			printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "", "", "", "", "", "", '|', '\n');
			sum = 0;
			nst++;
		}
	}
	cout << "|------------------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-8s%-8s%-5i%-4s%-1c%-1c", '|', "", "", "","", "�����:", all_sum,"���", '|', '\n');
	cout << "|------------------------------------------------------------------------|\n" << endl;
	fclose(fl);
}
void IZadanie2()
{
	int x = 0;

	cout << "�������\n ";
	cout << "������� ����� ����� ������ �� ��������� ������\n ";
	cout << " �� ������������ �����.\n";

	cout << "������� �����:";
	cout << "x = ";
	cin >> x;

	int sum = 0;
	int all_sum = 0;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		system("pause");
		system("cls");
		Menu();
	}
	nst = 0;
	TStudent std;
	cout << "\n|------------------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "�������", "���", "�����", "���.", "������", "���������", '|', '\n');
	printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "����������", "", "", "����", "�� ����", "", '|', '\n');
	cout << "|------------------------------------------------------------------------|\n" << endl;
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;

		int month = atoi(stud[nst].month);
		int year = atoi(stud[nst].year);

		string month2;
		switch (month)
		{
		case 1:  month2 = "������";  break;
		case 2:  month2 = "�������"; break;
		case 3:  month2 = "����";    break;
		case 4:  month2 = "������";  break;
		case 5:  month2 = "���";     break;
		case 6:  month2 = "����";    break;
		case 7:  month2 = "����";    break;
		case 8:  month2 = "������";  break;
		case 9:  month2 = "��������";break;
		case 10: month2 = "�������"; break;
		case 11: month2 = "������";  break;
		case 12: month2 = "�������"; break;
		default: cout << "�������� ���������!\n";
		}
		if (month == x){
			sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			all_sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			printf("%-3c%-25s%-10s%-10s%-6s%-3s%-7s%-5i%-4s%-1c%-1c", '|',
				stud[nst].FIO,
				stud[nst].year,
				month2.c_str(),
				stud[nst].day,
				stud[nst].stoimost,
				"���",
				sum,
				"���",
				'|',
				'\n');
			printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "", "", "", "", "", "", '|', '\n');
			sum = 0;
			nst++;
		}
	}
	cout << "|------------------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-8s%-8s%-5i%-4s%-1c%-1c", '|', "", "", "", "", "�����:", all_sum, "���", '|', '\n');
	cout << "|------------------------------------------------------------------------|\n" << endl;
	fclose(fl);
}