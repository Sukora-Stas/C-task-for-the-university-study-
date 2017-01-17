#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void allocArray(int* &arr, int amount) {
	arr = new int[amount];
}

void releaseArray(int* &arr) {
	if (arr)
		delete[] arr, arr = NULL;
}

void initArray(int *arr, int amount) {
	for (int i = 0; i < amount; i++) {
		cout << "Введите " << i << "-й элемент массива: ";
		cin >> arr[i];
	}
}

void showArray(int *arr, int amount) {
	for (int i = 0; i < amount; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n\n";
}

int doTask(int *arr, int amount) {
	int count = 0;
	for (int i = 0; i < amount; i++) {
		if (arr[i] % 2 != 0) {
			count++;
		}
		if (arr[i] == 0) {
			count = 0;
		}
	}

	return count;
}

void writeResult(int count) {
	ofstream fos;

	fos.open("out.txt");
	fos << count;
	fos.close();

	cout << "Количество нечетных элементов после последнего нуля равно: " << count << "\n\n";
}

int main() {
	setlocale(LC_ALL, "rus"); // для корректного отображения кириллицы в командной строке

	int amount = 0;
	int *arr = NULL;

	cout << "Введите количество элементов в массиве: ";
	cin >> amount;
	cout << "\n";

	if (amount > 0) {
		allocArray(arr, amount);

		initArray(arr, amount);

		showArray(arr, amount);

		int count = doTask(arr, amount);

		writeResult(count);

		releaseArray(arr);
	}
	else {
		cout << "Количество элементов не может быть меньше <= 0 или равняться нецелочисленному значению!\n\n";
	}

	system("pause");
	return 0;
}