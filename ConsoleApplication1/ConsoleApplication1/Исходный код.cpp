#include <iostream> 
#include <string> 
#include <fstream> 
using namespace std;

void allocArray(double* &arr, int amount) {
	arr = new double[amount];
}

void releaseArray(double* &arr) {
	if (arr)
		delete[] arr, arr = NULL;
}

void initArray(double *arr, int amount) {
	for (int i = 0; i < amount; i++) {
		cout << "������� " << i << "-� ������� �������: ";
		cin >> arr[i];
	}
}

void showArray(double *arr, int amount) {
	for (int i = 0; i < amount; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n\n";
}

double doTask(double *arr, int amount) {
	double sum = 1;

	for (int i = 0; i < amount; i++) {
		if (arr[i] > 0) {
			sum *= arr[i];
		}
	}

	return sum;
}

void writeResult(double sum) {
	ofstream fos;

	fos.open("out.txt");
	fos << sum;
	fos.close();

	cout << "�����: " << sum << "\n\n";
}

int main() {
	setlocale(LC_ALL, "rus"); // ��� ����������� ����������� ��������� � ��������� ������ 

	int amount = 0;
	double *arr = NULL;

	cout << "������� ���������� ��������� � �������: ";
	cin >> amount;
	cout << "\n";

	if (amount > 0) {
		allocArray(arr, amount);

		initArray(arr, amount);

		showArray(arr, amount);

		double sum = doTask(arr, amount);

		writeResult(sum);

		releaseArray(arr);
	}
	else {
		cout << "���������� ��������� �� ����� ���� ������ <= 0 ��� ��������� ���������������� ��������!\n\n";
	}

	system("pause");
	return 0;
}