#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <istream>
#include <Windows.h>
#include <fstream>
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
	char day[2];
	char stoimost[3];
	char sum[7];
	char check;
	//char tr = 
} TStudent;
TStudent stud[300]; // Массив структур
char name[20]; // Имя файла
int nst = 0; // Число введенных структур
int Menu(); // Создание меню

void Newf(); // Создание нового файла
void Spisok(); // Формирование файла
void Opf(); // Открытие файла
void Resc(); // Вывод результата на экран
void Resf(); // Вывод результата в файл

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
			//Menu();
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
	cout << "Меню:\n" << endl;
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "1.", "Созданеи нового файла", '|','\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "2.", "Заполнение БД", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "3.", "Показать БД больничных листов", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "4.", "Вывести результат", '|', '\n');
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
		cout << "Введите Ф.И.О. ";
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
		cout << "Ошибка при создании" << endl;
		exit(1);
	}
	nst = 0;
	TStudent std;
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		printf("%-3c%-25s%-10s%-10s%-5s%-7s%-1c%-1c", '|',
			stud[nst].FIO,
			stud[nst].year,
				stud[nst].month,
					stud[nst].day,
						stud[nst].stoimost,
							'|',
								'\n');
		cout << stud[nst].FIO << " " << stud[nst].year<< " " << stud[nst].check << endl;
		nst++;
	}
	fclose(fl);
}
void Resc() // Вывод результата на экран
{
	for (int i = 0; i < nst; i++)
		if (stud[i].check == '0')
			cout << stud[i].FIO << endl;
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
		exit(1);
	}
	char s[80];
	for (int i = 0; i < nst; i++)
		if (stud[i].check == '0')
		{
			strcpy(s, stud[i].FIO);
			strcat(s, "\n"); // Добавление разделителя строк
			fputs(s, ft);
		}
	fclose(ft);
}