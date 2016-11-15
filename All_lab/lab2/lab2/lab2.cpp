#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
double Summa(double, int);// Передача параметров по значению 
void Summa(double*, int*, double*);// Передача параметров по указателю 
void Summa(double&, int&, double&);// Передача параметров по ссылке 

int main()
{
	double s, x, a, b, h;
	int k;
	cout << "Vvedite a,b,h,k:\n";
	cin >> a >> b >> h >> k;
	cout << "\n Value" << setw(20) << "Pointer" << setw(24) << "Reference\n";
	x = a;
	do
	{
		cout << setw(5) << x << setw(10) << Summa(x, k);
		Summa(&x, &k, &s);
		cout << setw(10) << x << setw(10) << s;
		Summa(x, k, s);
		cout << setw(10) << x << setw(10) << s << endl;
		x += h;
	} while (x <= b + h / 2);
	cout << endl;
	system("pause");
	return 0;
}
double Summa(double x, int k)
{
	double s;
	int n;
	s = 0;
	for (n = 1; n <= k; n++)
		s += pow(x, (2 * n - 2)) / (4*cos(pow(n*x,2)));
	return s;
}
void Summa(double *x, int *k, double *s)
{
	int n;
	*s = 0;
	for (n = 1; n <= *k; n++)
		*s += pow(*x, (2 * n - 2)) / (4 * cos(pow(n * *x, 2)));
}

void Summa(double &x, int &k, double &s) 
{
	int n;
	s = 0;
	for (n = 1; n <= k; n++)
		s += pow((1 + x), (n - 1)) / abs(pow(sin(x), n));
}
