#include <iostream>

using namespace std;

class Fraction {
private:
	long a;
	unsigned short b;
	bool neg;
public:
	Fraction() {
		a = 0;
		b = 0;
		neg = false;
	}
	Fraction(float n) {
		a = (int)n;
		b = (int)((n - (int)n) * 1000);
		neg = (n < 0);
	}
	Fraction(long a, unsigned short b, bool neg = false) {
		this->a = a + b / 1000;
		this->b = b % 1000;
		this->neg = (a < 0);
		if (a == 0)
			this->neg = neg;
	}
	Fraction(long long x) {
		a = x / 1000;
		b = abs(x % 1000);
		neg = (x < 0);
	}
	~Fraction() {}
	void print() {
		if (a == 0 && neg)
			printf("-");
		printf("%d.%03d\n", a, b);
	}
	long long get() {
		long long x = (long long)a * 1000 + b;
		if ((neg != (x < 0)))
			x = -x;
		return x;
	}

	Fraction operator+(Fraction F) {
		return Fraction(get() + F.get());
	}
	Fraction operator-(Fraction F) {
		return Fraction(get() - F.get());
	}
	Fraction operator*(Fraction F) {
		return Fraction(get() * F.get() / 1000);
	}
	bool operator>(Fraction F) {
		return get() > F.get();
	}
	bool operator<(Fraction F) {
		return get() < F.get();
	}
	bool operator>=(Fraction F) {
		return get() >= F.get();
	}
	bool operator<=(Fraction F) {
		return get() <= F.get();
	}
	bool operator==(Fraction F) {
		return get() == F.get();
	}
	bool operator!=(Fraction F) {
		return get() != F.get();
	}


};

int main(void) {
	Fraction a(1, 5), b(2, 6), c = a + b, d = a - b, e = a * b;
	a.print();
	b.print();
	c.print();
	d.print();
	e.print();
	cout << (c > d) << endl;
	return 0;
}