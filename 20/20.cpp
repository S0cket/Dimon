#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(void) {
	srand(time(NULL));

	int n;
	cin >> n;

	int* chisla = new int[n];
	for (int i = 0; i < n; ++ i) {
		*(chisla + i) = rand() % 100;
		cout << *(chisla + i) << " ";
	}
	cout << endl;

	int cnt = 1, index = 0;
	for (int* p = chisla; p != chisla + n; ++ p) {
		if (p == chisla)
			continue;
		if (*p <= *(p - 1)) {
			cnt ++;
			if (cnt == 2)
				index = (p - chisla) - 1;
		}
		else {
			if (cnt > 1)
				cout << index << " ";
			cnt = 1;
		}
	}
	if (cnt > 1)
		cout << index;
	cout << endl;

	delete [] chisla;
	return 0;
}