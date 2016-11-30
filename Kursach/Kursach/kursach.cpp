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

/*Разработка программы расчёта выплат по больничным листам
 *Сведения о больничных листах сотрудников компании имеют следующий вид: Ф.И.О сотрудника;
 *год; месяц; Количество дней, пропущеных по болезни; оплата за один день.
 *
 *Индивидуальное задание: для месяца Х года У вывести список сотрудников
 * с указанием выплат по больничным листам для каждого из них. Вывести общую сумму
 * выплат по больничнм листам за интересующий месяц. Х,У вводятся с клавиатуры.
 * 
 * Общее для всех вариантов задание: реализовать авторизацию дл входа в систему(без регистрации!),
 * функционал администратора и функционал пользователя, как минимум три вида поиска, как минимум три вида сортировки.
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
TStudent stud[30]; // Массив структур
char name[20]; // Имя файла
int nst = 0; // Число введенных структур
int Menu(); // Создание меню
char sum[7];
void Newf(); // Создание нового файла
void Spisok(); // Формирование файла
void Opf(); // Открытие файла
void Resc(); // Вывод результата на экран
void Resf(); // Вывод результата в файл
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
			cout<<"Выберите правильно!\n";
			system("pause");
			system("cls");
			Menu();
		}
		system("pause");
		system("cls"); // Очистка экрана
	}
}

void beginMenu()
{
	printf("%-15s%-8s%-7i", "Сукора С.И.", "Группа", 680961);
	cout << "\n\nПрограмма расчёта выплат по больничным листам" << endl;
	cout << "-------------------------------------------------\n" << endl;
}

int Menu() // Меню
{
	beginMenu();
	cout << "Меню:\n" << endl;
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "1.", "Созданеи нового файла", '|','\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "2.", "Заполнение БД", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "3.", "Показать БД больничных листов", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "4.", "Открыть файл", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "5.", "Записать в файл", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "6.", "Выход", '|', '\n');
	cout << "Ваш выбор: " << endl;
	int i;
	cin >> i; // Ввод выбранного пункта меню
	return i;
}

void Spisok() // Ввод данных в файла
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Ошибка при создании" << endl;
		exit(1);
	}
	cout << "Введите число сотрудников, которых необходимо добавить" << endl;
	cin >> nst;
	for (int i = 0; i<nst; i++)
	{
		cout << "Введите Фамилию ";
		cin >> stud[i].FIO;
		cout << "Введите год: ";
		cin >> stud[i].year;
		cout << "Введите месяц: ";
		cin >> stud[i].month;
		cout << "Введите количество дней по болезни: ";
		cin >> stud[i].day;
		cout << "Введите оплату за одинь день по болезни: ";
		cin >> stud[i].stoimost;
		fwrite(&stud[i], sizeof(TStudent), 1, fl);
		system("cls");
		beginMenu();
	}
	fclose(fl);
}

void Newf() // Создание нового файла
{
	cout << "Введите имя файла" << endl;
	cin >> name;
	if ((fl = fopen(name, "wb")) == NULL)
	{
		cout << "Ошибка при создании" << endl;
		exit(1);
	}
	cout << "OK" << endl;
	fclose(fl);
}

void Opf() // Открытие бинарного файла
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Ошибка при открытие" << endl;
		exit(1);
	}
	nst = 0;
	TStudent std;
	cout << "|--------------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-15s%-1c%-1c", '|', "Фамилия", "Год", "Месяц", "кол.", "оплата", '|', '\n');
	printf("%-3c%-25s%-10s%-10s%-6s%-15s%-1c%-1c", '|', "сотрудника", "", "", "дней", "за день, руб.", '|', '\n');
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
		case '1': month2 = "Январь"; break;
		case '2':month2 = "Февраль"; break;
		case '3': month2 = "Март"; break;
		case '4': month2 = "Апрель"; break;
		case '5':month2 = "Май"; break;
		case '6': month2 = "Июнь"; break;
		case '7': month2 = "Июль"; break;
		case '8':month2 = "Август"; break;
		case '9': month2 = "Сентябрь"; break;		
		default: cout << "Выберите правильно!\n";
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

void Resc() // Выбор файла
{
	cout << "Введите имя файла: ";
	cin >> name;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Ошибка при открытии, возможно такой файл не найден." << endl;
		exit(1);
	}
	else
	{
		cout << "OK\n";
	}
}
void Resf() // Вывод результата в текстовый файл
{
	char namet[30];
	FILE *ft;
	cout << "Введите имя файла, текстового" << endl;
	cin >> namet;
	if ((ft = fopen(namet, "w")) == NULL)
	{
		cout << "Ошибка при соЗдании" << endl;
		system("pause");
		Resf();
	}
	char s[80];
	for (int i = 0; i < nst; i++)
		//if (stud[i].check == '0')
		//{
		//	strcpy(s, stud[i].FIO);
		//	strcat(s, "\n"); // Добавление разделителя строк
		//	fputs(s, ft);
		//}
	fclose(ft);
}