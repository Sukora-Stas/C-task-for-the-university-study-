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

bool doTask(int *arr, int amount) {
	for (int i = 0; i < amount; i++) {
		if (i > 1) {
			if (arr[i] == arr[i - 1]) {
				return true;
			}
		}
	}

	return false;
}

void writeResult(bool isHas) {
	ofstream fos;

	string response = isHas ? "Есть" : "Нет";

	fos.open("out.txt");
	fos << response;
	fos.close();

	cout << "Есть ли в массиве хотя бы одна пара совпадающих по величине элементов: " << response << "\n\n";
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

		bool isHas = doTask(arr, amount);

		writeResult(isHas);

		releaseArray(arr);
	}
	else {
		cout << "Количество элементов не может быть меньше <= 0 или равняться нецелочисленному значению!\n\n";
	}

	system("pause");
	return 0;
}
