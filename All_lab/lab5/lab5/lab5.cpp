#include <iostream> 
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <string.h> 

#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
FILE *fl;
struct infa
{
	int nomer;
	char tip[20];
	char punkt[20];
	double vr_ot, vr_pr;
} bf;


void show()
{
	cout << "nomer: " << bf.nomer << endl
		<< "tip: " << bf.tip << endl
		<< "punkt: " << bf.punkt << endl
		<< "vremya ot: " << bf.vr_ot << endl
		<< "vremya pr: " << bf.vr_pr << endl
		<< "-------------------" << endl;
}

void set()
{
	cout << "vvedite nomer: ";
	cin >> bf.nomer;
	cout << "vvedite tip: ";
	cin >> bf.tip;
	cout << "vvedite punkt: ";
	cin >> bf.punkt;
	cout << "vvedite vremya otpravleniya: ";
	cin >> bf.vr_ot;
	cout << "vvedite vremya pribitiya: ";
	cin >> bf.vr_pr;
}

int main()
{
	setlocale(LC_ALL, "Rus"); //локализаци€
	FILE *f = nullptr;
	int count = 0;
	while (true)
	{
		try{
			if ((f = fopen("\\file.txt", "rb")) != 0) //создание чтение 
				f = fopen("\\file.txt", "ab+"); //окрыть добав 
			else
				f = fopen("\\file.txt", "wb+"); // вывод 
		}
		catch(exception){
			cout << "Error";
		}
		cout << "1 - запишите информацию\n2 - показать всю информацию\n3 - задание\n4 - выход\n";
		short int sel;
		cin >> sel;
		switch (sel)
		{
		case 1:
		{
			cout << "Kol-vo zapiseu\? :";
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				set();
				fwrite(&bf, sizeof(infa), 1, f); // запись / чтение __что именно__, _размер_ вычисл€ем размер - сумму всех полей __кол-во раз, куда- в файл. 
			}
		}; break;

		case 2:
		{
			while (feof(f) == 0)
			{
				if (fread(&bf, sizeof(infa), 1, f))
					show();
			}
		}; break;

		case 3:
		{
			int nomer[30];
			double vr_ot[30], vr_pr[30];
			char *tip[20];
			char *punkt[20];
			double vr_pr1;
			bool temp = true;
			char *punkt1 = new char;
			cout << "vvedite punkt: "; cin >> punkt1;
			cout << "vvedite vremya pribitiya: "; cin >> vr_pr1;
			cout << "Kol-vo zapiseu\?: ";
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				fread(&bf, sizeof(infa), 1, f);
				if ((strcmp(punkt1, bf.punkt) == 0) && (vr_pr1 > bf.vr_pr) && (vr_pr1 > bf.vr_ot))
				{
					nomer[i] = bf.nomer;
					tip[i] = bf.tip;
					punkt[i] = bf.punkt;
					vr_ot[i] = bf.vr_ot;
					vr_pr[i] = bf.vr_pr;
					cout << "nomer: " << nomer[i] << endl
						<< "tip: " << tip[i] << endl
						<< "punkt: " << punkt[i] << endl
						<< "vremya ot: " << vr_ot[i] << endl
						<< "vremya pr: " << vr_pr[i] << endl
						<< "-------------------" << endl;
					temp = false;
				}
				if (temp == true)
				{
					cout << "Reysov net " << endl;
					break;
				}
			}
		}; break;
		case 4: return 0;
		default: puts("¬ыберите правильно!");
		}
		puts("Press any key to continue");
		_getch();
		system("cls");
	}
}

