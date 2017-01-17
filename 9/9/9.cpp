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
	cout << "������� ������ ������� a: ";
	cin >> n;
	double* a = new double[n];
	int* arr = new int[n];
	inputArray(a, n);
	showArray(a, n);
	cout << "������� ������ ������� b: ";
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
	cout << " ������������ ������� ������� �=" << max << endl;
	for (int t = 0; t < m; t++)
		if (b[t] == max)
		{
			cout << "  � ������� b ���� �������, ������� ����� ������������� �������� ������� �" << endl;
			s = "<  � ������� b ���� �������, ������� ����� ������������� �������� ������� �";
			d = 1;
			break;
		}
	if (d == 0) {
		cout << "  � ������� b ��� ������������� �������� ������� �" << endl;
		s = ">  � ������� b ��� ������������� �������� ������� �";
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
	cout << "\n������� ������:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "������� ������� [" << i << "]=";
		std::cin >> a[i];
	}
}

void showArray(double* a, int n)
{
	cout << "������: ";
	for (int i = 0; i < n; i++)
		cout << setw(7) << a[i];
	cout << endl;
}
