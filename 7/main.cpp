#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Vector {
public:
	vector<T> vec;
	Vector() {}
	Vector(vector<T> v) {
		vec = v;
	}
	~Vector() {}
	T operator[](int index) {
		return vec[index];
	}
	void operator+(Vector<T> V) {
		int m = min(vec.size(), V.vec.size());
		for (int i = 0; i < m; ++ i)
			vec[i] += V.vec[i];
	}
	void operator+(T elem) {
		for (int i = 0; i < vec.size(); ++ i)
			vec[i] += elem;
	}
};

class Time {
private:
	int min, sec;
public:
	Time() {
		min = 0;
		sec = 0;
	}
	Time(int m, int s) {
		min = m + s / 60;
		sec = s % 60;
	}
	~Time() {}
	void print() {
		cout << min << ":" << sec << endl;
	}
};

void print(Vector<int> v) {
	for (int i = 0; i < v.vec.size(); ++ i)
		cout << v.vec[i] << " ";
	cout << endl;
}

int main(void) {
	vector<int> a(7, 9), b(3, 2);
	Vector<int> A(a), B(b);
	print(A);
	print(B);
	A + B;
	print(A);
	A + 3;
	print(A);
	Time(3, 4).print();
	return 0;
}