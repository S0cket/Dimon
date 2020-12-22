#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class mnj {
public:
	vector<int> e;
	mnj() {}
	mnj(vector<int> a) {
		e = a;
	}
	~mnj() {}
	int operator[](unsigned index) {
		if (index >= e.size()) throw 1;
		return e[index];
	}
	bool operator!=(mnj m) {
		return (e != m.e);
	}
	bool operator<(int n) {
		return (count(e.begin(), e.end(), n) != 0);
	}
};

int main(void) {
	mnj a(vector<int>(4, 3)), b(vector<int>(4, 3)), c(vector<int>(4, 4));
	cout << (a != b) << " " << (b != c) << endl;
	cout << a[3] << endl;
	try {
		cout << a[4] << endl;
	}
	catch (int) {
		cout << "ERROR!!!!\n";
	}
	return 0;
}