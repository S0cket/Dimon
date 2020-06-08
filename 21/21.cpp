#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Добавляет в конец массива элемент, увеличивая его размер на 1
int* ins(int* mass, int n, int a) {
	int* old = mass;
	mass = new int[n + 1];
	for (int i = 0; i < n; ++ i)
		mass[i] = old[i];
	mass[n] = a;
	delete [] old;
	return mass;
}

//Поиск элемента в массиве
int search(int* mass, int n, int a) {
	for (int i = 0; i < n; ++ i)
		if (mass[i] == a)
			return i;
	return -1;
}

//Возвращает динамический массив повторяющихся элементов матрицы таким образом, что количество элементов находится в 0-ом элементе (0-й элемент не считается)
int* get_rep(int** matrix, int n) {
	int *a = new int[1];
	a[0] = 0;
	int *b = new int[a[0]];

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			int x = search(a + 1, a[0], matrix[i][j]);
			if (x == -1) {
				a = ins(a, a[0] + 1, matrix[i][j]);
				b = ins(b, a[0], 1);
				a[0] ++;
			}
			else
				b[x] ++;
		}
	}
	int* ret = new int[1];
	ret[0] = 0;
	for (int i = 0; i < a[0]; ++ i) {
		if (b[i] > 1) {
			ret = ins(ret, ret[0] + 1, a[i + 1]);
			ret[0] ++;
		}
	}
	delete [] a;
	delete [] b;
	return ret;
}

//Возвращает максимальный элемент массива
int maximum(int* mass, int n) {
	int ret = mass[0];
	for (int i = 1; i < n; ++ i) {
		if (mass[i] > ret)
			ret = mass[i];
	}
	return ret;
}

int main(void) {
	srand(time(NULL));

	int n;
	cin >> n;
	int** m = new int*[n];
	for (int i = 0; i < n; ++ i) {
		m[i] = new int[n];
		for (int j = 0; j < n; ++ j) {
			m[i][j] = rand() % 20;
			cout << setw(4) << m[i][j] << " ";
		}
		cout << endl;
	}

	int *arr = get_rep(m, n);
	if (arr[0] == 0)
		cout << "\nNo repeat\n";
	else
		cout << endl << maximum(arr + 1, arr[0]) << endl;

	for (int i = 0; i < n; ++ i)
		delete [] m[i];
	delete [] m;
	delete [] arr;
	return 0;
}