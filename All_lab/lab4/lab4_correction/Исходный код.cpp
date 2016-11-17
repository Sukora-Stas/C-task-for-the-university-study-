#include <iostream>

using namespace std;

int main()
{
	int **a, i, j, n, m, S;
	cout << "Vvedite razmer massiva na 1 bolshe chem neobxodimo:\n";
	cout << "row n=";
	cin >> n;
	cout << "column m=";
	cin >> m;

	a = new int*[n]; // Выделение памяти под массив указателей
	for (i = 0; i<n; i++) // Выделение памяти под соответствующие этим указателям строки матрицы
		a[i] = new int[m];
	cout << "\nMassiv[" << i-1 << "][" << m-1 << "]" << endl; // Ввод элементов двумерного массива
	S = 0;
	for (i = 0; i<n; i++)
		for (j = 0; j<m; j++)
		{
			a[i][j] = 0 + rand() % 10;
			if (i % 2 == 0)
			{
				S += a[i][j];
			}
		}
	for (i = 1; i <= n-1; i++)
	{
		for (j = 1; j <= m-1; j++)
		{
			cout << a[i][j] << " ";
			
		} cout << endl;
	}
	cout << "The sum of the even rows= " << S << endl;
	for (i = 0; i<n; i++) // Освобождение выделенной памяти
		delete[] a[i];
	delete[]a;
	a = NULL;
	system("pause");
	return 0;
}