#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;

void sredArifm(int a[], int, double*, int*, int*, int*);

int main()
{
	double sred;
	int i, n, a[10], sum, max, min;

	cout << "Vvedite razmer massiva: ";
	cin >> n;
	cout << "Vvedite massiv:\n";
	for (i = 0; i<n; i++)
	{
		cout << "Vvedite a[" << i << "]=";
		cin >> a[i];
	}
	cout << "Massiv a:\n";
	for (i = 0; i<n; i++)
		cout << setw(7) << a[i];
	cout << endl;
	max = a[0];
	min = a[0];
	sredArifm(a, n, &sred, &sum, &max, &min);
	cout << "sred=" << sred << endl;
	system("pause");
	return 0;
}

void sredArifm(int a[], int n, double* sred, int*sum, int*posPol, int*pervOtr)
{
	int i;

	posPol = 0;
	pervOtr = 0;

	for (i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			pervOtr = a + i;
			break;
		}
	}
	for (i = n - 1; i >= 0; i--)
	{
		if (!(a[i] % 2))
		{
			if (a[i] > 0)
			{
				posPol = a + i;
				printf("posPol: %d\n", *posPol);
				break;
			}
		}
	}

	if (posPol &&  pervOtr)
	{
		int n;
		n = 0;
		*sum = 0;
		printf("pervOtr: %d\n", *pervOtr);
		int* p = pervOtr + 1;
		while (p != posPol)
		{
			*sum += abs(*p);
			p++;
			n++;
		}
		*sred = (double)*sum / (double)n;
	}


}
