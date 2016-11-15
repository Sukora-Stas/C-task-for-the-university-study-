#include <iostream>
#include<iomanip>
#include <math.h>
#include <stdio.h>

using namespace std;

void sredArifm(int a[], int, double*, int*, int*, int*);
void MinMax(int a[], int, int*, int*, int*, int*);  // Прототип функции 
const int nl = 10;
int main()
{
	double sred;
	int i, n, a[10], sum, max, min, imin, imax;;
	cout << "Vvedite razmer massiva: ";
	cin >> n;
	cout << "\Vvedite massiv:\n";
	for (i = 0; i<n; i++)
	{
		cout << "Vvedite a[" << i << "]=";
		cin >> a[i];
	}
//cout << "\Massiv a:\n";
	MinMax(a, n, &min, &max, &imin, &imax);
	
	sredArifm(a, n, &sred, &sum, &max, &min);
	//cout << a[i] << endl;
	cout << "\nPosPol= " << &max << "\nPervOtr= " << &min<<endl;
	cout << "\nsred=" << sred << endl;
	system("pause");
	return 0;
}
void MinMax(int a[], int n, int *min, int *max, int *imin, int *imax)
{
	int i;
	*min = *max = a[0];      // Инициализация значений 
	*imin = *imax = 0;
	for (i = 1; i < n; i++)
		if (a[i]<*min) {    // Поиск минимального элемента и его индекса    
			*min = a[i];
			*imin = i;
		}
		else  if (a[i]>*max) { // Поиск максимального элемента и его индекса    
			*max = a[i];
			*imax = i;
		}
}
void sredArifm(int a[], int n, double* sred, int*sum, int*posPol, int*pervOtr)
{
	int i;
	posPol = 0;
	pervOtr = 0;
	for (i = 0; i < n; i++)
	{
		//printf("%x ", &a[i]);
		//printf("%x ", a + i);
		
		if (a[i] < 0)
		{
			pervOtr = a + i;
			//printf("pervOtr %x ", a + i);
			//printf("%x\n", pervOtr);
			break;
		}
		printf("test %d\n", a[i]);
	}
	for (i = n - 1; i >= 0; i--)
	{
		//printf("%x ", &a[i]);
		//printf("%x ", a + i);
		
		if (!(a[i] % 2))
		{
			if (a[i] > 0)
			{
				posPol = a + i;
				printf("posPol %x ", a + i);
				printf("%x\n", posPol);
				break;
			}
		}
		printf("%d\n", a[i]);
	}
	if (posPol &&  pervOtr)
	{
		int n;
		n = 0;
		*sum = 0;
		printf("pervOtr: %x ", pervOtr);
		printf("pervOtr: %d\n", *pervOtr);
		int* p = pervOtr + 1;
		while (p != posPol)
		{
			*sum += abs(*p);
			p++;
			n++;
		}
		printf("n: %d \n", n);

	printf("sum: %d \n", *sum);
		*sred = (double)*sum / (double)n;
		printf("sred: %f \n", *sred);
	}
}