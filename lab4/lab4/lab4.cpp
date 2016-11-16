
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	cout << "\n\t       Fourth" << endl;
	int i, n, **aa, j, m, sum1 = 0;
	cout << "\t Input N, M : ";
	cin >> n;
	m = n;

	aa = new int*[n]; 					// Захват памяти под указатели
	for (i = 0; i<n; i++)
		aa[i] = new int[m]; 		// Захват памяти под элементы
	cout << "\n Input A" << endl;
	for (i = 0; i<n; i++)
		for (j = 0; j<m; j++) {
			cout << "\t a[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> aa[i][j];
		}
	cout << "\n Matrix A:" << endl;
	for (i = 0; i<n; i++) {
		for (j = 0; j<m; j++)
			cout << "\t" << aa[i][j];
		cout << endl;
	}
	for (i = 0; i<n; i++) {
		for (j = 0; j < m; j++)
			if ((i + j <= n) & (aa[i][j] < 0)) {
				cout << aa[i][j];
				sum1 += aa[i][j];
			}
	}
	cout << "\n" << sum1;
	cout << "\n Press any key ... " << endl;
	system("pause");
	return 0;
}
