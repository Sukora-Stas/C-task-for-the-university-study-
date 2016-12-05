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
	GetConsoleTitle(Title, 1024); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	MoveWindow(hwnd, 600, 50,850, 900, TRUE);//-новые положение x,y, ширина и высота
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
			printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "Выбирете правильно", '|', '\n');
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
	cout << "|______________________________________________________________________________|\n" << endl;
}

void proverka()
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "Ошибка при открытие", '|', '\n');
		system("pause");
		system("cls");
		Menu();
	}
}

int Menu() // Меню
{
	beginMenu();
	printf("%-18s%-3c%-7s%-35s%-1c%-1c","", '|', "Меню:", "", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "", "", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "1.", "Создание нового файла", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "2.", "Заполнение БД", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "3.", "Показать БД больничных листов", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "4.", "Открыть файл", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "5.", "Индивидуальное задание 1", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "6.", "Индивидуальное задание 2", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "7.", "Поиск", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "8.", "Сортировка", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "9.", "Задание", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "10.", "Выход", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "", "", '|', '\n');
	printf("%-18s%-3c%-7s%-35s%-1c%-1c", "", '|', "", "Ваш выбор:", '|', '\n');
	int i;
	cout << "                    ";
	cin >> i; // Ввод выбранного пункта меню
	return i;
}

void Spisok() // Ввод данных в файла
{
	int id = 1;
	proverka();
	cout << "Введите число сотрудников, которых необходимо добавить" << endl;
	cin >> nst;
	for (int i = 0; i<nst; i++)
	{
		cout << "Сотрудник № " << id << " из " << nst << endl;
		cout << " "<<endl;
		stud[i].id = id;
		id++;
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
		printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "Ошибка при создание", '|', '\n');
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
	proverka();
	nst = 0;
	TStudent std;
	cout << "\n       |-----------------------------------------------------------------|\n" << endl;
	printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c","", '|',"Номер", "Фамилия", "Год", "Месяц", "кол.", "оплата", '|', '\n');
	printf("%-7s%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c","", '|',"", "сотрудника", "", "", "дней", "за день", '|', '\n');
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
						"руб.",
							'|',
								'\n');
		printf("%-7s%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c","", '|', "", "", "", "", "", '|', '\n');
		
		nst++;
	}
	cout << "       |-----------------------------------------------------------------|\n" << endl;
	printf("%-7s%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c","", '|', "", "", "", "Сумма:", sum,"руб.", '|', '\n');
	cout << "       |-----------------------------------------------------------------|\n" << endl;
	fclose(fl);
}

void SelectionFile() // Выбор файла
{
	cout << "Введите имя файла: ";
	cin >> name;
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "Ошибка при открытии, возможно такой файл не найден.", '|', '\n');
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
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "Задание:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Для месяца Х года У вывести список сотрудников", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "с указанием выплат по больничным листам для каждого из них", '|', '\n');

	cout << "Введите Месяц:";
	cout << "x = ";
	cin >> x;
	cout << "Введите Год:";
	cout << "y = ";
	cin >> y;

	int sum = 0;
	int all_sum = 0;
	proverka();
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
	printf("%-1c%-1c%-10s%-68s%-1c%-1c", '\n', '|', "", "Задание:", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "Вывести общую сумму выплат по больничнм листам", '|', '\n');
	printf("%-1c%-5s%-73s%-1c%-1c", '|', "", "за интересующий месяц", '|', '\n');
	cout << "\nВведите Месяц:";
	cout << "x = ";
	cin >> x;

	int sum = 0;
	int all_sum = 0;
	proverka();
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
		string month2 = _switch(month);
		if (month == x){
			sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			all_sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
			printf("%-3c%-25s%-10s%-10s%-6s%-3s%-7s%-5i%-4s%-1c%-1c", '|',
				stud[nst].FIO,
				stud[nst].year,
				month2.c_str(),
				stud[nst].day,
				stud[nst].stoimost, "руб",
				sum, "руб",
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

void poisk()
{
	cout << "|______________________________________________________________________________|\n" << endl;
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Поиск по каким критериям вы хотите организовать?", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "По id", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "По Фамилии", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "3.", "По году", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "4.", "По месяцу", '|');
	printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
	int i;
	cin >> i;

	if (i == 1)  //по ID
	{
		int number = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Поиск по id", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "Введите номер", '|', '\n');
		cin >> number;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "Номер", "Фамилия", "Год", "Месяц", "кол.", "оплата", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "сотрудника", "", "", "дней", "за день", '|', '\n');
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
					"руб.",
					'|',
					'\n');
				printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');

				nst++;
			}
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "Сумма:", sum, "руб.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 2)    //По Фамилии
	{
		string name;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Поиск по фамилии", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "Введите фамилию", '|', '\n');
		cin >> name;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "Номер", "Фамилия", "Год", "Месяц", "кол.", "оплата", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "сотрудника", "", "", "дней", "за день", '|', '\n');
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
					"руб.",
					'|',
					'\n');
				printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');

				nst++;
			}
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "Сумма:", sum, "руб.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 3)  //по году
	{
		int year = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Поиск по году", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "Введите год", '|', '\n');
		cin >> year;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "Номер", "Фамилия", "Год", "Месяц", "кол.", "оплата", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "сотрудника", "", "", "дней", "за день", '|', '\n');
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
					"руб.",
					'|',
					'\n');
				printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');

				nst++;
			}
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "Сумма:", sum, "руб.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 4)  //по месяцу
	{
		int monthe = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Поиск по месяцу", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "Введите месяц", '|', '\n');
		cin >> monthe;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "Номер", "Фамилия", "Год", "Месяц", "кол.", "оплата", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "сотрудника", "", "", "дней", "за день", '|', '\n');
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
					"руб.",
					'|',
					'\n');
				printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');
				nst++;
			}
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "Сумма:", sum, "руб.", '|', '\n');
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
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Поиск по каким критериям вы хотите организовать?", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "По id", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "По году", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "3.", "По месяцу", '|');
	printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
	int i;
	cin >> i;
	if (i == 1)
	{
		cout << "|______________________________________________________________________________|\n" << endl;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Выберити: по возрастанию или по убыванию", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "По возрастанию", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "По убыванию", '|');
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
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Выберити: по возрастанию или по убыванию", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "По возрастанию", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "По убыванию", '|');
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
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "Выберити: по возрастанию или по убыванию", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "По возрастанию", '|');
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "По убыванию", '|');
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
	case 1:  month2 = "Январь";  break;
	case 2:  month2 = "Февраль"; break;
	case 3:  month2 = "Март";    break;
	case 4:  month2 = "Апрель";  break;
	case 5:  month2 = "Май";     break;
	case 6:  month2 = "Июнь";    break;
	case 7:  month2 = "Июль";    break;
	case 8:  month2 = "Август";  break;
	case 9:  month2 = "Сентябрь"; break;
	case 10: month2 = "Октябрб"; break;
	case 11: month2 = "Ноябрь";  break;
	case 12: month2 = "Декабрь"; break;
	default: printf("%-1c%-1c%-5s%-73s%-1c%-1c", '\n', '|', "", "Ошибка", '|', '\n');
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
