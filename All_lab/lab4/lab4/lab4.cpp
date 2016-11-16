#include <iostream>

using namespace std;

int main()
{
	int a[4][4];
	int i, j, S = 0;
	cout << "Massiv 4x4" << endl;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			a[i][j] = 0 + rand() % 10;
			if (i % 2 == 0){ S = S + a[i][j]; }
		}
	}
	cout << "Mass a[i][j]= \n";
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			cout << a[i][j] << " ";
		} cout << endl;
	}
	cout <<"The sum of the even rows= "<<  S << endl;
	system("pause");
	return 0;
}