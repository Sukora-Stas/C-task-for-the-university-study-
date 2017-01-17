#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void inputArrayA(int *a, int n);
void inputArrayB(int *b, int n);
void showArrayA(int *a, int n);
void showArrayB(int *b, int n);
void showArrayS(int *a, int *b, int *s, int n);
void writeFile(int *s, int k);

int main()
{
	int n;
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массивов А и B: ";
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int* s = new int[n];
	inputArrayA(a, n);
	inputArrayB(b, n);
	showArrayA(a, n);
	showArrayB(b, n);
	showArrayS(a, b, s, n);
	delete[] a;
	delete[] b;
	delete[] s;
	system("pause");
	return 0;
}

void writeFile(int *s, int k)
{
	ofstream f;
	f.open("file.txt");
	for (int i = 0; i < k; i++)
	{
		f << s[i];
	}
	f.close();
}

void inputArrayA(int *a, int n)
{
	cout << "\nВведите массив A:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Введите a[" << i << "]=";
		std::cin >> a[i];
	}
}

void inputArrayB(int *b, int n)
{
	cout << "\nВведите массив B:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Введите b[" << i << "]=";
		std::cin >> b[i];
	}
}

void showArrayA(int *a, int n)
{
	cout << "Массив A: ";
	for (int i = 0; i < n; i++)
		cout << setw(7) << a[i];
	cout << endl;
}

void showArrayB(int *b, int n)
{
	cout << "Массив B: ";
	for (int i = 0; i < n; i++)
		cout << setw(7) << b[i];
	cout << endl;
}

void showArrayS(int *a, int *b, int *s, int n)
{
	int k = 0;
	cout << "Массив S: ";
	for (int i = 0; i < n; i++)
		if ((i % 3 == 0) && (i != 0))
		{
			s[k] = a[i] + b[i];
			k++;
		}
		else //это для коректного отображения
		{
			s[k] = 0;
			k++;
		}
	for (int i = 0; i < k; i++)
		cout << setw(7) << s[i];
	cout << endl;
	writeFile(s, k);
}
