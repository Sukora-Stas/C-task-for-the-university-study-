#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

using namespace std;

/*В радиоателье хранятся квитанции о сданных в ремонт телевизорах.
* Каждая квитанция содержит марку телевизора, дату приемки в ремонт,
*  состояние готовности заказа (выполнен, не выполнен).
*  Вывести информацию о невыполненных на текущий момент заказах.*/
FILE *fl;
typedef struct
{
	unsigned char marka;
	unsigned char date;
	unsigned char check;
} TStudent;
TStudent stud[30]; // Массив структур
char name[20]; // Имя файла
int nst = 0; // Число введенных структур
int Menu(); // Создание меню
void Nnf(); // Ввод имени файла
void Newf(); // Создание нового файла
void Spisok(); // Формирование файла
void Opf(); // Открытие файла
void Resc(); // Вывод результата на экран
void Resf(); // Вывод результата в файл

int main()
{
	while (true)
	{
		switch (Menu())
		{
		case 1: Nnf(); break;
		case 2: Newf(); break;
		case 3: Spisok(); break;
		case 4: Opf(); break;
		case 5: Resc(); break;
		case 6: Resf(); break;
		case 7: return 0;
		default: puts("Viberite pravilno!");
		}
		system("pause");
		system("cls"); // Очистка экрана
	}
}
int Menu() // Меню
{
	cout << "VIBERITE:" << endl;
	cout << "1. Vvod file name" << endl;
	cout << "2. New file" << endl;
	cout << "3. Vvesti spisok" << endl;
	cout << "4. Open file" << endl;
	cout << "5. Vivesti result" << endl;
	cout << "6. Vivesti v fail" << endl;
	cout << "7. Exit" << endl;
	int i;
	cin >> i; // Ввод выбранного пункта меню
	return i;
}
void Nnf() // Ввод имени файла
{
	cout << "Vvedite file name" << endl;
	cin >> name;
}
void Newf() // Создание нового файла
{
	if ((fl = fopen(name, "wb")) == NULL)
	{
		cout << "Oshibka pri sozdanii" << endl;
		exit(1);
	}
	cout << "OK" << endl;
	fclose(fl);
}
void Spisok() // Ввод данных в файла
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
void Opf() // Открытие бинарного файла
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
void Resc() // Вывод результата на экран
{
	for (int i = 0; i < nst; i++)
		if (stud[i].check == false)
			cout << stud[i].marka << endl;
}
//void Resf() // Вывод результата в текстовый файл
//{
//	char namet[30];
//	FILE *ft;
//	cout << "Vvedite imya faila" << endl;
//	cin >> namet;
//	if ((ft = fopen(namet, "w")) == NULL)
//	{
//		cout << "Oshibka pri sozdanii" << endl;
//		exit(1);
//	}
//	char s[80];
//	for (int i = 0; i < nst; i++)
//		if ((stud[i].matem + stud[i].oaip + stud[i].hist + stud[i].english) / 4 >= '7')
//		{
//			strcpy(s, stud[i].fio);
//			strcat(s, "\n"); // Добавление разделителя строк
//			fputs(s, ft);
//		}
//	fclose(ft);
//}