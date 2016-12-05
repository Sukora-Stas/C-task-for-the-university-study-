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
//#include "poiskk.h"

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
void sort();

void bubbleSortDescending(int *, int);
void bubbleSortScending(int *, int);

string _switch(int month);

void beginMenu();
int main()
{
	HWND hwnd;
	WCHAR Title[1024];
	GetConsoleTitle(Title, 1024); // ������ ��� ����
	hwnd = FindWindow(NULL, Title); // ������ hwnd ����
	MoveWindow(hwnd, 600, 50,850, 900, TRUE);//-����� ��������� x,y, ������ � ������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
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
		case 8: sort(); break;
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
	printf("%-1c%-25s%-15s%-8s%-30i%-1c%-1c", '|', "", "������ �.�.", "������", 680961, '|','\n');
	printf("%-1c%-15s%-8s%-18s%-1c%-1c", '|', "", "��������� ������� ������ �� ���������� ������","", '|', '\n');
	cout << "|______________________________________________________________________________|\n" << endl;
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
	printf("%-18s%-3c%-7s%-35s%-1c%-1c","", '|', "����:", "", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "", "", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "1.", "�������� ������ �����", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "2.", "���������� ��", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "3.", "�������� �� ���������� ������", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "4.", "������� ����", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "5.", "�������������� ������� 1", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "6.", "�������������� ������� 2", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "7.", "�����", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "8.", "����������", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "9.", "�������", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "10.", "�����", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "", "", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "", "��� �����:", '|', '\n');
	int i;
	cout << "                    ";
	cin >> i; // ���� ���������� ������ ����
	return i;
}

void Spisok() // ���� ������ � �����
{
	int id = 1;
	proverka();
	cout << "������� ����� �����������, ������� ���������� ��������" << endl;
	cin >> nst;
	for (int i = 0; i<nst; i++)
	{
		cout << "��������� � " << id << " �� " << nst << endl;
		cout << " "<<endl;
		stud[i].id = id;
		id++;
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
		printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "������ ��� ��������", '|', '\n');
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
	proverka();
	nst = 0;
	TStudent std;
	cout << "\n       |-----------------------------------------------------------------|\n" << endl;
	printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c","", '|',"�����", "�������", "���", "�����", "���.", "������", '|', '\n');
	printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c","", '|',"", "����������", "", "", "����", "�� ����", '|', '\n');
	cout << "       |-----------------------------------------------------------------|\n" << endl;

	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		int month = atoi(stud[nst].month);
		sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
		string month2 = _switch(month);
		printf("%-7s%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c","", '|',
			stud[nst].id,
			stud[nst].FIO,
			stud[nst].year,
				month2.c_str(),
					stud[nst].day,
						stud[nst].stoimost,
						"���.",
							'|',
								'\n');
		printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c","", '|', "", "", "", "", "", '|', '\n');
		
		nst++;
	}
	cout << "       |-----------------------------------------------------------------|\n" << endl;
	printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c","", '|', "", "", "", "�����:", sum,"���.", '|', '\n');
	cout << "       |-----------------------------------------------------------------|\n" << endl;
	fclose(fl);
}

void SelectionFile() // ����� �����
{
	cout << "������� ��� �����: ";
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
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "�������:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "��� ������ � ���� � ������� ������ �����������", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "� ��������� ������ �� ���������� ������ ��� ������� �� ���", '|', '\n');

	cout << "������� �����:";
	cout << "x = ";
	cin >> x;
	cout << "������� ���:";
	cout << "y = ";
	cin >> y;

	int sum = 0;
	int all_sum = 0;
	proverka();
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

		string month2 = _switch(month);
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
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "�������:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "������� ����� ����� ������ �� ��������� ������", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "�� ������������ �����", '|', '\n');
	cout << "\n������� �����:";
	cout << "x = ";
	cin >> x;

	int sum = 0;
	int all_sum = 0;
	proverka();
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
		string month2 = _switch(month);
		if (month == x){
			sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			all_sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			printf("%-3c%-25s%-10s%-10s%-6s%-3s%-7s%-5i%-4s%-1c%-1c", '|',
				stud[nst].FIO,
				stud[nst].year,
				month2.c_str(),
				stud[nst].day,
				stud[nst].stoimost, "���",
				sum, "���",
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

void poisk()
{
	cout << "|______________________________________________________________________________|\n" << endl;
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ����� ��������� �� ������ ������������?", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "�� id", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "�� �������", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "3.", "�� ����", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "4.", "�� ������", '|');
	printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
	int i;
	cin >> i;

	if (i == 1)  //�� ID
	{
		int number = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� id", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �����", '|', '\n');
		cin >> number;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "����������", "", "", "����", "�� ����", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			int id = stud[nst].id;
			
			string month2 = _switch(month);
			if (number==id){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
					stud[nst].id,
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
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum, "���.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 2)    //�� �������
	{
		string name;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� �������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �������", '|', '\n');
		cin >> name;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "����������", "", "", "����", "�� ����", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
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
				printf("%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
					stud[nst].id,
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
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum, "���.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 3)  //�� ����
	{
		int year = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ����", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� ���", '|', '\n');
		cin >> year;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "����������", "", "", "����", "�� ����", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
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
				printf("%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
					stud[nst].id,
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
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum, "���.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 4)  //�� ������
	{
		int monthe = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �����", '|', '\n');
		cin >> monthe;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "����������", "", "", "����", "�� ����", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			string month2 = _switch(month);
			if (monthe == month){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
					stud[nst].id,
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
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum, "���.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
}

void sort()
{
	int n = 0;
	proverka();
	nst = 0;
	TStudent std;
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
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ����� ��������� �� ������ ������������?", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "�� id", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "�� ����", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "3.", "�� ������", '|');
	printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
	int i;
	cin >> i;
	if (i == 1)
	{
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
			bubbleSortScending(arr, n);
			for (int i = 0; i < n; ++i)
			{
				cout << arr[i] << " ";
			}
		}
		if (j == 2)
		{
			bubbleSortDescending(arr, n);
			for (int i = 0; i < n; ++i)
			{
				cout << arr[i] << " ";
			}
		}
	}
	if (i == 2)
	{
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

		}
		if (j == 2)
		{

		}
	}
	if (i == 3)
	{
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

		}
		if (j == 2)
		{

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
void bubbleSortDescending(int *arr, int n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (arr[r] < arr[r + 1])
			{
				int temp = arr[r];
				arr[r] = arr[r + 1];
				arr[r + 1] = temp;
			}
		}
	}
}
void bubbleSortScending(int *arr, int n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (arr[r] > arr[r + 1])
			{
				int temp = arr[r];
				arr[r] = arr[r + 1];
				arr[r + 1] = temp;
			}
		}
	}
}
