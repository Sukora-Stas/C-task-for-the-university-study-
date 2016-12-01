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
TStudent stud[30]; // Массив структур
char name[20]; // Имя файла
int nst = 0; // Число введенных структур
int Menu(); // Создание меню
void Newf(); // Создание нового файла
void Spisok(); // Формирование файла
void OutSpisok(); // Открытие файла
void SelectionFile(); // Вывод результата на экран
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
	GetConsoleTitle(Title, 1024); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	MoveWindow(hwnd, 600, 50,850, 900, TRUE);//xnew,ynew,wnew,hnew -новые положение x,y, ширина и высота
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
	printf("%-1c%-25s%-15s%-8s%-30i%-1c%-1c", '|', "", "Сукора С.И.", "Группа", 680961, '|','\n');
	printf("%-1c%-15s%-8s%-18s%-1c%-1c", '|', "", "Программа расчёта выплат по больничным листам","", '|', '\n');
	//cout << "\n\nПрограмма расчёта выплат по больничным листам" << endl;
	cout << "|------------------------------------------------------------------------------|\n" << endl;
}

int Menu() // Меню
{
	beginMenu();
	cout << "Меню:\n" << endl;
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "1.", "Созданеи нового файла", '|','\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "2.", "Заполнение БД", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "3.", "Показать БД больничных листов", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "4.", "Открыть файл", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "5.", "Индивидуальное задание 1", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "6.", "Индивидуальное задание 2", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "7.", "Задание", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "8.", "Выход", '|', '\n');
	cout << "\nВаш выбор: \n" << endl;
	int i;
	cin >> i; // Ввод выбранного пункта меню
	return i;
}

void Spisok() // Ввод данных в файла
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Ошибка при создании" << endl;
		system("pause");
		system("cls");
		Menu();
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
		system("pause");
		system("cls");
		Menu();
	}
	cout << "OK" << endl;
	fclose(fl);
}

void OutSpisok() // Вывод списка сотрудников
{
	int sum = 0;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Ошибка при открытие" << endl;
		system("pause");
		system("cls");
		Menu();
	}
	nst = 0;
	TStudent std;
	cout << "\n|-----------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "Фамилия", "Год", "Месяц", "кол.", "оплата", '|', '\n');
	printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "сотрудника", "", "", "дней", "за день", '|', '\n');
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
		case 1: month2 = "Январь"; break;
		case 2:month2 = "Февраль"; break;
		case 3: month2 = "Март"; break;
		case 4: month2 = "Апрель"; break;
		case 5:month2 = "Май"; break;
		case 6: month2 = "Июнь"; break;
		case 7: month2 = "Июль"; break;
		case 8:month2 = "Август"; break;
		case 9: month2 = "Сентябрь"; break;
		case 10: month2 = "Октябрб"; break;
		case 11: month2 = "Ноябрь"; break;
		case 12: month2 = "Декабрь"; break;
		default: cout << "Выберите правильно!\n";
		}
		printf("%-3c%-25s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
			stud[nst].FIO,
			stud[nst].year,
				month2.c_str(),
					stud[nst].day,
						stud[nst].stoimost,
						"руб.",
							'|',
								'\n');
		printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');
		
		nst++;
	}
	cout << "|-----------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "Сумма:", sum,"руб.", '|', '\n');
	cout << "|-----------------------------------------------------------------|\n" << endl;
	fclose(fl);
}

void SelectionFile() // Выбор файла
{
	cout << "Введите имя файла: ";
	cin >> name;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Ошибка при открытии, возможно такой файл не найден." << endl;
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
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "Задание:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Разработка программы расчёта выплат по больничным листам", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Сведения о больничных листах сотрудников компании имеют следующий вид:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Ф.И.О сотрудника;год; месяц; Количество дней, пропущеных по болезни;",'|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "оплата за один день.",'|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Индивидуальное задание: для месяца Х года У вывести список сотрудников", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "c указанием выплат по больничным листам для каждого из них.", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Вывести общую сумму выплат по больничнм листам за интересующий месяц.",'|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Х,У вводятся с клавиатуры.", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Общее для всех вариантов задание: реализовать авторизацию для", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "входа в систему(без регистрации!), ", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "функционал администратора и функционал пользователя, ", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "как минимум три вида поиска, как минимум три вида сортировки.",'|', '\n');
}

void IZadanie1() // Вывод результата в текстовый файл
{
	int x = 0;
	int y = 0;
	cout << "Задание\n ";
	cout << "для месяца Х года У вывести список сотрудников\n ";
	cout << "с указанием выплат по больничным листам для каждого из них\n";

	cout << "Введите Месяц:";
	cout << "x = ";
	cin >> x;
	cout << "Введите Год:";
	cout << "y = ";
	cin >> y;

	int sum = 0;
	int all_sum = 0;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Ошибка при открытие" << endl;
		system("pause");
		system("cls");
		Menu();
	}
	nst = 0;
	TStudent std;
	cout << "\n|------------------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "Фамилия", "Год", "Месяц", "Кол.", "оплата","Выплатить", '|', '\n');
	printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "сотрудника", "", "", "дней", "за день","", '|', '\n');
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
		case 1: month2 = "Январь"; break;
		case 2:month2 = "Февраль"; break;
		case 3: month2 = "Март"; break;
		case 4: month2 = "Апрель"; break;
		case 5:month2 = "Май"; break;
		case 6: month2 = "Июнь"; break;
		case 7: month2 = "Июль"; break;
		case 8:month2 = "Август"; break;
		case 9: month2 = "Сентябрь"; break;
		case 10: month2 = "Октябрб"; break;
		case 11: month2 = "Ноябрь"; break;
		case 12: month2 = "Декабрь"; break;
		default: cout << "Выберите правильно!\n";
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
				"руб",
				sum,
				"руб",
				'|',
				'\n');
			printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "", "", "", "", "", "", '|', '\n');
			sum = 0;
			nst++;
		}
	}
	cout << "|------------------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-8s%-8s%-5i%-4s%-1c%-1c", '|', "", "", "","", "Сумма:", all_sum,"руб", '|', '\n');
	cout << "|------------------------------------------------------------------------|\n" << endl;
	fclose(fl);
}
void IZadanie2()
{
	int x = 0;

	cout << "Задание\n ";
	cout << "Вывести общую сумму выплат по больничнм листам\n ";
	cout << " за интересующий месяц.\n";

	cout << "Введите Месяц:";
	cout << "x = ";
	cin >> x;

	int sum = 0;
	int all_sum = 0;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Ошибка при открытие" << endl;
		system("pause");
		system("cls");
		Menu();
	}
	nst = 0;
	TStudent std;
	cout << "\n|------------------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "Фамилия", "Год", "Месяц", "Кол.", "оплата", "Выплатить", '|', '\n');
	printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "сотрудника", "", "", "дней", "за день", "", '|', '\n');
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
		case 1:  month2 = "Январь";  break;
		case 2:  month2 = "Февраль"; break;
		case 3:  month2 = "Март";    break;
		case 4:  month2 = "Апрель";  break;
		case 5:  month2 = "Май";     break;
		case 6:  month2 = "Июнь";    break;
		case 7:  month2 = "Июль";    break;
		case 8:  month2 = "Август";  break;
		case 9:  month2 = "Сентябрь";break;
		case 10: month2 = "Октябрб"; break;
		case 11: month2 = "Ноябрь";  break;
		case 12: month2 = "Декабрь"; break;
		default: cout << "Выберите правильно!\n";
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
				"руб",
				sum,
				"руб",
				'|',
				'\n');
			printf("%-3c%-25s%-10s%-10s%-6s%-9s%-10s%-1c%-1c", '|', "", "", "", "", "", "", '|', '\n');
			sum = 0;
			nst++;
		}
	}
	cout << "|------------------------------------------------------------------------|\n" << endl;
	printf("%-3c%-25s%-10s%-10s%-8s%-8s%-5i%-4s%-1c%-1c", '|', "", "", "", "", "Сумма:", all_sum, "руб", '|', '\n');
	cout << "|------------------------------------------------------------------------|\n" << endl;
	fclose(fl);
}