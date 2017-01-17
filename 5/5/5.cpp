#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void inputArray(double *a, int n);
void showArray(double *a, int n);
int searchMax(double *a, int n);
double calculation(double *a, int *arr, int n);
void writeFile(double p);

int main()
{
	int n;
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	cin >> n;
	double* a = new double[n];
	int* arr = new int[n];
	inputArray(a, n);
	showArray(a, n);
	double p = calculation(a, arr, n);
	writeFile(p);
	delete[] a;
	delete[] arr;
	system("pause");
	return 0;
}

void writeFile(double p)
{
	ofstream f;
	f.open("file.txt");
	f << p;
	f.close();
}

void inputArray(double *a, int n)
{
	cout << "\nВведите массив:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Введите a[" << i << "]=";
		std::cin >> a[i];
	}
}

void showArray(double *a, int n)
{
	cout << "Массив: ";
	for (int i = 0; i < n; i++)
		cout << setw(7) << a[i];
	cout << endl;
}

int searchMax(double *a, int n)
{
	int max, imax = 0;
	max = abs(a[0]);
	for (int i = 0; i < n; i++)
		if (abs(a[i]) > max)
		{
			max = abs(a[i]);
			imax = i;
		}
	return imax;
}

double calculation(double *a, int *arr, int n)
{
	int max;
	double p;
	p = 1;
	max = searchMax(a, n);
	cout << "Максимальный элемент с индексом " << max << endl;
	for (int i = max + 1; i < n; i++)
	{
		arr[i] = static_cast<int>(a[i]);
		if ((arr[i] < 0) && (arr[i] % 2 == 0))
		{
			p *= a[i];
		}
	}
	cout << "Произведение отрицательных четных элементов массива = " << p << endl;
	return p;
}
