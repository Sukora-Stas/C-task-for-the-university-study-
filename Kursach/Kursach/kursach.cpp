#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <istream>
#include <Windows.h>

#include <algorithm>
#include <vector>

#include "Authorization.h"

using namespace std;

FILE *fl;
typedef struct
{
	int id;
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

void proverka();
void poisk();
void MySort();

bool sortByIdUp(const TStudent&, const TStudent&); //�������� �������
bool sortByIdDown(const TStudent&, const TStudent&); //�������� �������

bool sortByYearUp(const TStudent&, const TStudent&); //�������� �������
bool sortByYearDown(const TStudent&, const TStudent&); //�������� �������

bool sortByMonthUp(const TStudent&, const TStudent&); //�������� �������
bool sortByMonthDown(const TStudent&, const TStudent&); //�������� �������

bool sortByFioUp(const TStudent&, const TStudent&); //�������� �������
bool sortByFioDown(const TStudent&, const TStudent&); //�������� �������

string _switch(int month);

void beginMenu();

int main()
{
	HWND hwnd;
	WCHAR Title[1024];
	GetConsoleTitle(Title, 1024); // ������ ��� ����
	hwnd = FindWindow(NULL, Title); // ������ hwnd ����
	MoveWindow(hwnd, 600, 50, 844, 900, TRUE);//-����� ��������� x,y, ������ � ������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "ru_RU.UTF-8");
	setlocale(LC_ALL, "");
	beginMenu();
	do
	{
		if (Authorization()){
			printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "Password accepted, Welcome!", '|', '\n');
			system("pause");
			system("cls");
			break;
		}
		printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "Error! Return please!", '|', '\n');
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
		case 7: poisk(); break;
		case 8: MySort(); break;
		case 9: Zadanie(); break;
		case 10: return 0;
		default:
			printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "�������� ���������", '|', '\n');
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
	printf("%-1c%-25s%-15s%-8s%-30i%-1c%-1c", '|', "", "������ �.�.", "������", 680961, '|', '\n');
	printf("%-1c%-15s%-8s%-18s%-1c%-1c", '|', "", "��������� ������� ������ �� ���������� ������", "", '|', '\n');
	cout << "|______________________________________________________________________________|\n";
}

void proverka()
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "������ ��� ��������", '|', '\n');
		system("pause");
		system("cls");
		Menu();
	}
}

int Menu() // ����
{
	beginMenu();
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "����:", "", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "", "", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "1.", "�������� ������ �����", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "2.", "���������� ��", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "3.", "�������� �� ���������� ������", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "4.", "������� ����", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "5.", "�������������� ������� 1", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "6.", "�������������� ������� 2", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "7.", "�����", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "8.", "����������", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "9.", "�������", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "10.", "�����", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "", "", '|', '|', '\n');
	printf("%-18c%-3c%-7s%-35s%-1c%16c%-1c", '|', '|', "", "��� �����:", '|', '|', '\n');
	int i;
	cout << "|                                      ";
	cin >> i; // ���� ���������� ������ ����
	return i;
}

void Spisok() // ���� ������ � �����
{
	int id = 1;
	proverka();
	cout << "|                  ������� ����� �����������, ������� ���������� ��������" << endl;
	cin >> nst;
	for (int i = 0; i<nst; i++)
	{
		cout << "|                  ��������� � " << id << " �� " << nst << endl;
		cout << " " << endl;
		stud[i].id = id;
		id++;
		cout << "|                  ������� ������� ";
		cin >> stud[i].FIO;
		cout << "|                  ������� ���: ";
		cin >> stud[i].year;
		cout << "|                  ������� �����: ";
		cin >> stud[i].month;
		cout << "|                  ������� ���������� ���� �� �������: ";
		cin >> stud[i].day;
		cout << "|                  ������� ������ �� ����� ���� �� �������: ";
		cin >> stud[i].stoimost;
		fwrite(&stud[i], sizeof(TStudent), 1, fl);
		system("cls");
		beginMenu();
	}
	fclose(fl);
}

void Newf() // �������� ������ �����
{
	cout << "|                  ������� ��� �����" << endl;
	cin >> name;
	if ((fl = fopen(name, "wb")) == NULL)
	{
		printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "������ ��� ��������", '|', '\n');
		system("pause");
		system("cls");
		Menu();
	}
	cout << "|                  OK" << endl;
	fclose(fl);
}

void OutSpisok() // ����� ������ �����������
{
	int sum = 0;
	proverka();
	nst = 0;
	TStudent std;
	cout << "\n|      |-----------------------------------------------------------------|     |\n";
	printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
	printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
	cout << "|      |-----------------------------------------------------------------|     |\n";

	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		int month = atoi(stud[nst].month);
		sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
		string month2 = _switch(month);
		printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
			stud[nst].id,
			stud[nst].FIO,
			stud[nst].year,
			month2.c_str(),
			stud[nst].day,
			stud[nst].stoimost,
			"���.",
			'|',
			'|',
			'\n');
		printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');

		nst++;
	}
	cout << "|      |-----------------------------------------------------------------|     |\n";
	printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
	cout << "|      |-----------------------------------------------------------------|     |\n";
	fclose(fl);
}

void SelectionFile() // ����� �����
{
	cout << "|                  ������� ��� �����: ";
	cin >> name;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "������ ��� ��������, �������� ����� ���� �� ������.", '|', '\n');
		system("pause");
		system("cls");
		Menu();
	}
	else
	{
		cout << "|                  OK\n";
	}
}

void Zadanie()
{
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "�������:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "���������� ��������� ������� ������ �� ���������� ������", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�������� � ���������� ������ ����������� �������� ����� ��������� ���:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�.�.� ����������;���; �����; ���������� ����, ���������� �� �������;", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "������ �� ���� ����.", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�������������� �������: ��� ������ � ���� � ������� ������ �����������", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "c ��������� ������ �� ���������� ������ ��� ������� �� ���.", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "������� ����� ����� ������ �� ��������� ������ �� ������������ �����.", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�,� �������� � ����������.", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "����� ��� ���� ��������� �������: ����������� ����������� ���", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "����� � �������(��� �����������!), ", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "���������� �������������� � ���������� ������������, ", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "��� ������� ��� ���� ������, ��� ������� ��� ���� ����������.", '|', '\n');
}

void IZadanie1() // ����� ���������� � ��������� ����
{
	int x = 0;
	int y = 0;
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "�������:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "��� ������ � ���� � ������� ������ �����������", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "� ��������� ������ �� ���������� ������ ��� ������� �� ���", '|', '\n');
	cout << "|______________________________________________________________________________|\n";
	cout << "|                  ������� �����:";
	cout << " x = ";
	cin >> x;
	cout << "|                  ������� ���:";
	cout << " y = ";
	cin >> y;

	int sum = 0;
	int all_sum = 0;
	proverka();
	nst = 0;
	TStudent std;
	cout << "\n|  |------------------------------------------------------------------------|  |\n";
	printf("%-3c%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%3c%-1c", '|', '|', "�������", "���", "�����", "���.", "������", "���������", '|', '|', '\n');
	printf("%-3c%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%3c%-1c", '|', '|', "����������", "", "", "����", "�� ����", "", '|', '|', '\n');
	cout << "|  |------------------------------------------------------------------------|  |\n";
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;

		int month = atoi(stud[nst].month);
		int year = atoi(stud[nst].year);

		string month2 = _switch(month);
		if (month == x&&year == y){
			sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			all_sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			printf("%-3c%-3c%-25s%-10s%-10s%-6s%-3s%-7s%-5i%-4s%-1c%-1c", '|', '|',
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
			printf("%-3c%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%3c%-1c", '|', '|', "", "", "", "", "", "", '|', '|', '\n');
			sum = 0;
			nst++;
		}
	}
	cout << "|  |------------------------------------------------------------------------|  |\n";
	printf("%-3c%-3c%-25s%-10s%-10s%-8s%-8s%-5i%-4s%-1c%3c%-1c", '|', '|', "", "", "", "", "�����:", all_sum, "���", '|', '|', '\n');
	cout << "|  |------------------------------------------------------------------------|  |\n";
	fclose(fl);
}

void IZadanie2()
{
	int x = 0;
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "�������:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "������� ����� ����� ������ �� ��������� ������", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�� ������������ �����", '|', '\n');
	cout << "|______________________________________________________________________________|\n";
	cout << "|                  ������� �����:";
	cout << " x = ";
	cin >> x;

	int sum = 0;
	int all_sum = 0;
	proverka();
	nst = 0;
	TStudent std;
	cout << "\n|  |------------------------------------------------------------------------|  |\n";
	printf("%-3s%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%3c%-1c", "|", '|', "�������", "���", "�����", "���.", "������", "���������", '|', '|', '\n');
	printf("%-3s%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%3c%-1c", "|", '|', "����������", "", "", "����", "�� ����", "", '|', '|', '\n');
	cout << "|  |------------------------------------------------------------------------|  |\n";
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		int month = atoi(stud[nst].month);
		string month2 = _switch(month);
		if (month == x){
			sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			all_sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			printf("%-3s%-3c%-25s%-10s%-10s%-6s%-3s%-7s%-5i%-4s%-1c%3c%-1c", "|", '|',
				stud[nst].FIO,
				stud[nst].year,
				month2.c_str(),
				stud[nst].day,
				stud[nst].stoimost, "���",
				sum, "���",
				'|', '|',
				'\n');
			printf("%-3s%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%3c%-1c", "|", '|', "", "", "", "", "", "", '|', '|', '\n');
			sum = 0;
			nst++;
		}
	}
	cout << "|  |------------------------------------------------------------------------|  |\n";
	printf("%-3s%-3c%-25s%-10s%-10s%-8s%-8s%-5i%-4s%-1c%3c%-1c", "|", '|', "", "", "", "", "�����:", all_sum, "���", '|', '|', '\n');
	cout << "|  |------------------------------------------------------------------------|  |\n";
	fclose(fl);
}

void poisk()
{
	cout << "|______________________________________________________________________________|\n";
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ����� ��������� �� ������ ������������?", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
	printf("%-1c%-5c%-4s%-70s%-1c", '\n', '|', "1.", "�� id", '|');
	printf("%-1c%-5c%-4s%-70s%-1c", '\n', '|', "2.", "�� �������", '|');
	printf("%-1c%-5c%-4s%-70s%-1c", '\n', '|', "3.", "�� ����", '|');
	printf("%-1c%-5c%-4s%-70s%-1c", '\n', '|', "4.", "�� ������", '|');
	printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
	cout << "|    ";
	int i;
	cin >> i;

	if (i == 1)  //�� ID
	{
		int number = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� id", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �����", '|', '\n');
		cout << "|    ";
		cin >> number;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|     |-----------------------------------------------------------------|      |\n";
		printf("%-6c%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
		printf("%-6c%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
		cout << "|     |-----------------------------------------------------------------|      |\n";
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			int id = stud[nst].id;

			string month2 = _switch(month);
			if (number == id){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-6c%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%7c%-1c", '|', '|',
					stud[nst].id,
					stud[nst].FIO,
					stud[nst].year,
					month2.c_str(),
					stud[nst].day,
					stud[nst].stoimost,
					"���.",
					'|', '|',
					'\n');
				printf("%-6c%-3c%-25s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "", "", "", "", "", '|', '|', '\n');

				nst++;
			}
		}
		cout << "|     |-----------------------------------------------------------------|      |\n";
		printf("%-6c%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%7c%-1c", '|', '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
		cout << "|     |-----------------------------------------------------------------|      |\n";
		fclose(fl);
	}
	if (i == 2)    //�� �������
	{
		string name;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� �������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �������", '|', '\n');
		cout << "|    ";
		cin >> name;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|     |-----------------------------------------------------------------|      |\n";
		printf("%-6c%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
		printf("%-6c%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
		cout << "|     |-----------------------------------------------------------------|      |\n";
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			string fio = stud[nst].FIO;
			string month2 = _switch(month);
			if (name == fio){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-6c%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%7c%-1c", '|', '|',
					stud[nst].id,
					stud[nst].FIO,
					stud[nst].year,
					month2.c_str(),
					stud[nst].day,
					stud[nst].stoimost,
					"���.",
					'|', '|',
					'\n');
				printf("%-6c%-3c%-25s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "", "", "", "", "", '|', '|', '\n');

				nst++;
			}
		}
		cout << "|     |-----------------------------------------------------------------|      |\n";
		printf("%-6c%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%7c%-1c", '|', '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
		cout << "|     |-----------------------------------------------------------------|      |\n";
		fclose(fl);
	}
	if (i == 3)  //�� ����
	{
		int year = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ����", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� ���", '|', '\n');
		cout << "|    ";
		cin >> year;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|     |-----------------------------------------------------------------|      |\n";
		printf("%-6c%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
		printf("%-6c%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
		cout << "|     |-----------------------------------------------------------------|      |\n";
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			int yea = atoi(stud[nst].year);

			string month2 = _switch(month);
			if (year == yea){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-6c%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%7c%-1c", '|', '|',
					stud[nst].id,
					stud[nst].FIO,
					stud[nst].year,
					month2.c_str(),
					stud[nst].day,
					stud[nst].stoimost,
					"���.",
					'|', '|',
					'\n');
				printf("%-6c%-3c%-25s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "", "", "", "", "", '|', '|', '\n');

				nst++;
			}
		}
		cout << "|     |-----------------------------------------------------------------|      |\n";
		printf("%-6c%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%7c%-1c", '|', '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
		cout << "|     |-----------------------------------------------------------------|      |\n";
		fclose(fl);
	}
	if (i == 4)  //�� ������
	{
		int monthe = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �����", '|', '\n');
		cout << "|    ";
		cin >> monthe;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|     |-----------------------------------------------------------------|      |\n";
		printf("%-6c%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
		printf("%-6c%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
		cout << "|     |-----------------------------------------------------------------|      |\n";
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			string month2 = _switch(month);
			if (monthe == month){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-6c%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%7c%-1c", '|', '|',
					stud[nst].id,
					stud[nst].FIO,
					stud[nst].year,
					month2.c_str(),
					stud[nst].day,
					stud[nst].stoimost,
					"���.",
					'|', '|',
					'\n');
				printf("%-6c%-3c%-25s%-10s%-10s%-6s%-12s%-1c%7c%-1c", '|', '|', "", "", "", "", "", '|', '|', '\n');
				nst++;
			}
		}
		cout << "|     |-----------------------------------------------------------------|      |\n";
		printf("%-6c%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%7c%-1c", '|', '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
		cout << "|     |-----------------------------------------------------------------|      |\n";
		fclose(fl);
	}
}

void MySort()
{
	proverka();
	nst = 0;
	TStudent std;
	cout << "|______________________________________________________________________________|\n";
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ����� ��������� �� ������ ������������?", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "�� id", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "�� ����", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "3.", "�� ������", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "4.", "�� �������", '|');
	printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
	int i;
	cin >> i;
	if (i == 1)
	{
		int n = 0;
		int *arr = new int[n];
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			arr[nst] = stud[nst].id;
			nst++;
			n++;
		}
		cout << "|______________________________________________________________________________|\n" << endl;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "��������: �� ����������� ��� �� ��������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "�� �����������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "�� ��������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
		int j;
		cin >> j;
		if (j == 1)
		{
			int sum = 0;
			fclose(fl);
			vector <TStudent> studentList;
			for (int f = 0; f < 30; f++)
			{
				if (stud[f].id == '\0')
					break;
				studentList.insert(studentList.end(), stud[f]);
			}
			sort(studentList.begin(), studentList.end(), sortByIdUp);
			cout << "\n|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
			for (int g = 0; g < studentList.size(); g++)
			{
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				string month = _switch(atoi(studentList[g].month));
				printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
					studentList[g].id,
					studentList[g].FIO,
					studentList[g].year,
					month.c_str(),
					studentList[g].day,
					studentList[g].stoimost,
					"���.",
					'|',
					'|',
					'\n');
				printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');
			}
			cout << "|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
		}
		if (j == 2)
		{
			int sum = 0;
			fclose(fl);
			vector <TStudent> studentList;
			for (int s = 0; s < 30; s++)
			{
				if (stud[s].id == '\0')
					break;
				studentList.insert(studentList.end(), stud[s]);
			}
			sort(studentList.begin(), studentList.end(), sortByIdDown);
			cout << "\n|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
			for (int d = 0; d < studentList.size(); d++)
			{
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				string month = _switch(atoi(studentList[d].month));
				printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
					studentList[d].id,
					studentList[d].FIO,
					studentList[d].year,
					month.c_str(),
					studentList[d].day,
					studentList[d].stoimost,
					"���.",
					'|',
					'|',
					'\n');
				printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');
			}
			cout << "|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
		}
	}
	if (i == 2)
	{
		int n = 0;
		int *arr = new int[n];
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			arr[nst] = atoi(stud[nst].year);
			nst++;
			n++;
		}
		cout << "|______________________________________________________________________________|\n" << endl;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "��������: �� ����������� ��� �� ��������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "�� �����������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "�� ��������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
		int j;
		cin >> j;
		if (j == 1)
		{
			int sum = 0;
			fclose(fl);
			vector <TStudent> studentList;
			for (int l = 0; l < 30; l++)
			{
				if (stud[l].year[0] == '\0')
					break;
				studentList.insert(studentList.end(), stud[l]);
			}
			sort(studentList.begin(), studentList.end(), sortByYearUp);
			cout << "\n|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
			for (int p = 0; p < studentList.size(); p++)
			{
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				string month = _switch(atoi(studentList[p].month));
				printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
					studentList[p].id,
					studentList[p].FIO,
					studentList[p].year,
					month.c_str(),
					studentList[p].day,
					studentList[p].stoimost,
					"���.",
					'|',
					'|',
					'\n');
				printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');
			}
			cout << "|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
		}
		if (j == 2)
		{
			int sum = 0;
			fclose(fl);
			vector <TStudent> studentList;
			for (int a = 0; a < 30; a++)
			{
				if (stud[a].year[0] == '\0')
					break;
				studentList.insert(studentList.end(), stud[a]);
			}
			sort(studentList.begin(), studentList.end(), sortByYearDown);
			cout << "\n|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
			for (int k = 0; k < studentList.size(); k++)
			{
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				string month = _switch(atoi(studentList[k].month));
				printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
					studentList[k].id,
					studentList[k].FIO,
					studentList[k].year,
					month.c_str(),
					studentList[k].day,
					studentList[k].stoimost,
					"���.",
					'|',
					'|',
					'\n');
				printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');
			}
			cout << "|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
		}
	}
	if (i == 3)
	{
		int n = 0;
		int *arr = new int[n];
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			arr[nst] = stud[nst].id;
			nst++;
			n++;
		}
		cout << "|______________________________________________________________________________|\n";
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "��������: �� ����������� ��� �� ��������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "�� �����������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "�� ��������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
		int j;
		cin >> j;
		if (j == 1)
		{
			int sum = 0;
			fclose(fl);
			vector <TStudent> studentList;
			for (int m = 0; m < 30; m++)
			{
				if (stud[m].month[0] == '\0')
					break;
				studentList.insert(studentList.end(), stud[m]);
			}
			sort(studentList.begin(), studentList.end(), sortByMonthUp);
			cout << "\n|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
			for (int v = 0; v < studentList.size(); v++)
			{
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				string month = _switch(atoi(studentList[v].month));
				printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
					studentList[v].id,
					studentList[v].FIO,
					studentList[v].year,
					month.c_str(),
					studentList[v].day,
					studentList[v].stoimost,
					"���.",
					'|',
					'|',
					'\n');
				printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');
			}
			cout << "|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
		}
		if (j == 2)
		{
			int sum = 0;
			fclose(fl);
			vector <TStudent> studentList;
			for (int m = 0; m < 30; m++)
			{
				if (stud[m].month[0] == '\0')
					break;
				studentList.insert(studentList.end(), stud[m]);
			}
			sort(studentList.begin(), studentList.end(), sortByMonthDown);
			cout << "\n|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
			for (int b = 0; b < studentList.size(); b++)
			{
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				string month = _switch(atoi(studentList[b].month));
				printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
					studentList[b].id,
					studentList[b].FIO,
					studentList[b].year,
					month.c_str(),
					studentList[b].day,
					studentList[b].stoimost,
					"���.",
					'|',
					'|',
					'\n');
				printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');
			}
			cout << "|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
		}
	}
	if (i == 4)
	{
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			nst++;
		}
		cout << "|______________________________________________________________________________|\n";
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "��������: �� ����������� ��� �� ��������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "�� �����������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "�� ��������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
		int j;
		cin >> j;
		if (j == 1)
		{
			int sum = 0;
			fclose(fl);
			vector <TStudent> studentList;
			for (int m = 0; m < 30; m++)
			{
				if (stud[m].FIO[0] == '\0')
					break;
				studentList.insert(studentList.end(), stud[m]);
			}
			sort(studentList.begin(), studentList.end(), sortByFioUp);
			cout << "\n|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
			for (int n = 0; n < studentList.size(); n++)
			{
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				string month = _switch(atoi(studentList[n].month));
				printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
					studentList[n].id,
					studentList[n].FIO,
					studentList[n].year,
					month.c_str(),
					studentList[n].day,
					studentList[n].stoimost,
					"���.",
					'|',
					'|',
					'\n');
				printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');
			}
			cout << "|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
		}
		if (j == 2)
		{
			int sum = 0;
			fclose(fl);
			vector <TStudent> studentList;
			for (int m = 0; m < 30; m++)
			{
				if (stud[m].FIO[0] == '\0')
					break;
				studentList.insert(studentList.end(), stud[m]);
			}
			sort(studentList.begin(), studentList.end(), sortByFioDown);
			cout << "\n|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '|', '\n');
			printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "����������", "", "", "����", "�� ����", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
			for (int n = 0; n < studentList.size(); n++)
			{
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				string month = _switch(atoi(studentList[n].month));
				printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%6c%-1c", "|", '|',
					studentList[n].id,
					studentList[n].FIO,
					studentList[n].year,
					month.c_str(),
					studentList[n].day,
					studentList[n].stoimost,
					"���.",
					'|',
					'|',
					'\n');
				printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%6c%-1c", "|", '|', "", "", "", "", "", '|', '|', '\n');
			}
			cout << "|      |-----------------------------------------------------------------|     |\n";
			printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%6c%-1c", "|", '|', "", "", "", "�����:", sum, "���.", '|', '|', '\n');
			cout << "|      |-----------------------------------------------------------------|     |\n";
		}
	}
}

string _switch(int month)
{
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
	case 9:  month2 = "��������"; break;
	case 10: month2 = "�������"; break;
	case 11: month2 = "������";  break;
	case 12: month2 = "�������"; break;
	default: printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "������", '|', '\n');
	}
	return month2;
}

bool sortByIdUp(const TStudent& left, const TStudent& right)
{
	return left.id < right.id;
}
bool sortByIdDown(const TStudent& left, const TStudent& right)
{
	return left.id > right.id;
}

bool sortByYearUp(const TStudent& left, const TStudent& right)
{
	return strcmp(left.year, right.year) < 0;
}

bool sortByYearDown(const TStudent& left, const TStudent& right)
{
	return strcmp(left.year, right.year) > 0;
}

bool sortByMonthUp(const TStudent& left, const TStudent& right)
{
	return strcmp(left.month, right.month) < 0;
}

bool sortByMonthDown(const TStudent& left, const TStudent& right)
{
	return strcmp(left.month, right.month) > 0;
}

bool sortByFioUp(const TStudent& left, const TStudent& right)
{
	return strcmp(left.FIO, right.FIO) < 0;
}

bool sortByFioDown(const TStudent& left, const TStudent& right)
{
	return strcmp(left.FIO, right.FIO) > 0;
}