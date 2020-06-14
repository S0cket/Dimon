#include <iostream>

using namespace std;

double f(double x, int n, int i = 0) {
	if (i == n)
		return i + x;
	return i + x / f(x, n, i + 1);
}

int main(void) {
	double x;
	int n;
	cin >> x >> n;
	cout << f(x, n) << endl;
	return 0;
}