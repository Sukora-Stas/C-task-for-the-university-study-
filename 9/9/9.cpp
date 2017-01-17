#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void inputArray(double*, int);
void showArray(double*, int);
void writeFile(double, string);

int main()
{
	int n;
	int m;
	int d = 0;
	string s;
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива a: ";
	cin >> n;
	double* a = new double[n];
	int* arr = new int[n];
	inputArray(a, n);
	showArray(a, n);
	cout << "Введите размер массива b: ";
	cin >> m;
	double* b = new double[m];
	int* arr2 = new int[m];
	inputArray(b, m);
	showArray(b, m);
	int max, imax = 0;
	max = abs(a[0]);
	for (int i = 0; i < n; i++)
		if (a[i] > max)
		{
			max = a[i];
			imax = i;
		}
	cout << " Максимальный элемент массива а=" << max << endl;
	for (int t = 0; t < m; t++)
		if (b[t] == max)
		{
			cout << "  В массиве b есть элемент, который равен максимальному элементу массива а" << endl;
			s = "<  В массиве b есть элемент, который равен максимальному элементу массива а";
			d = 1;
			break;
		}
	if (d == 0) {
		cout << "  В массиве b нет максимального элемента массива а" << endl;
		s = ">  В массиве b нет максимального элемента массива а";
	}
	writeFile(max, s);
	delete[] a;
	delete[] arr;
	delete[] b;
	delete[] arr2;
	system("pause");
	return 0;
}

void writeFile(double sum, string s)
{
	ofstream f;
	f.open("file.txt");
	f << sum;
	f << s;
	f.close();
}

void inputArray(double* a, int n)
{
	cout << "\nВведите массив:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент [" << i << "]=";
		std::cin >> a[i];
	}
}

void showArray(double* a, int n)
{
	cout << "Массив: ";
	for (int i = 0; i < n; i++)
		cout << setw(7) << a[i];
	cout << endl;
}
