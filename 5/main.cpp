#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <utility>

using namespace std;

void print(vector<int> v) {
	for (int i = 0; i < v.size(); ++ i)
		cout << v[i] << " ";
	cout << "\n";
}

class Triangle {
public:
	double a, b, c;
	double a_angle, b_angle, c_angle;
	Triangle() {
		this->a = 1;
		this->b = 1;
		this->c = 1;
		a_angle = acos((b * b + c * c - a * a) / (2 * b * c));
		b_angle = acos((a * a + c * c - b * b) / (2 * a * c));
		c_angle = acos((a * a + b * b - c * c) / (2 * a * b));
	}
	Triangle(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;
		a_angle = acos((b * b + c * c - a * a) / (2 * b * c));
		b_angle = acos((a * a + c * c - b * b) / (2 * a * c));
		c_angle = acos((a * a + b * b - c * c) / (2 * a * b));
	}
	~Triangle() {}
	bool is() {
		return (a + b > c && a + c > b && b + c > a);
	}
	double P() {
		return a + b + c;
	}
	double S() {
		double p = P() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	void print() {
		cout << "Triangle:\n";
		cout << "\tP:" << P() << "\n";
		cout << "\tS:" << S() << "\n";

		cout << "\tSides:\n";
		cout << "\t\ta:" << a << "\n";
		cout << "\t\tb:" << b << "\n";
		cout << "\t\tc:" << c << "\n";

		cout << "\tAngles:\n";
		cout << "\t\ta_angle:" << a_angle << "\n";
		cout << "\t\tb_angle:" << b_angle << "\n";
		cout << "\t\tc_angle:" << c_angle << "\n";
		cout << "\n";
	}
};

class RectTriangle : public Triangle {
public:
	RectTriangle() {
		this->a = 1;
		this->b = 1;
		this->c = 1;
		a_angle = acos((b * b + c * c - a * a) / (2 * b * c));
		b_angle = acos((a * a + c * c - b * b) / (2 * a * c));
		c_angle = acos((a * a + b * b - c * c) / (2 * a * b));
	}
	RectTriangle(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;
		a_angle = acos((b * b + c * c - a * a) / (2 * b * c));
		b_angle = acos((a * a + c * c - b * b) / (2 * a * c));
		c_angle = acos((a * a + b * b - c * c) / (2 * a * b));
	}
	~RectTriangle() {}
	bool is() {
		double h = hip();
		double c1 = -1, c2 = -1;
		if (a != h)
			c1 = a;
		if (b != h) {
			if (c1 > 0)
				c2 = b;
			else
				c1 = b;
		}
		if (c != h) {
			if (c1 > 0)
				c2 = c;
			else
				c1 = c;
		}

		return (a + b > c && a + c > b && b + c > a && (h == sqrt(c1 * c1 + c2 * c2)));
	}
	double hip() {
		return max(a, max(b, c));
	}
	bool operator<(RectTriangle T) {
		return (S() < T.S());
	}
	bool operator>(RectTriangle T) {
		return (S() > T.S());
	}
	bool operator<=(RectTriangle T) {
		return (S() <= T.S());
	}
	bool operator>=(RectTriangle T) {
		return (S() >= T.S());
	}
	bool operator==(RectTriangle T) {
		return (a == T.a && b == T.b && c == T.c);
	}
	bool operator!=(RectTriangle T) {
		return (a != T.a || b != T.b || c != T.c);
	}
};

int main(void) {
	int n, m;
	cin >> n >> m;

	Triangle mx, mn;
	bool flag = true;
	for (int i = 0; i < n; ++ i) {
		cout << "Triangle " << (i + 1) << ":\n";
		double a, b, c;
		cin >> a >> b >> c;
		Triangle t(a, b, c);
		if (!t.is()) {
			cout << "Triangle is not exist\n";
			-- i;
		}
		else {
			if (flag) {
				flag = false;
				mx = t;
				mn = t;
			}
			else {
				if (t.S() > mx.S())
					mx = t;
				if (t.S() < mn.S())
					mn = t;
			}
		}
	}

	RectTriangle *arr = new RectTriangle[m];
	for (int i = 0; i < m; ++ i) {
		cout << "RectTriangle " << (i + 1) << ":\n";
		double a, b, c;
		cin >> a >> b >> c;
		RectTriangle t(a, b, c);
		if (!t.is()) {
			cout << "RectTriangle is not exist\n";
			-- i;
		}
		else {
			arr[i] = t;
		}
	}
	cout << "\n\nAnswers:\n";
	mx.print();
	mn.print();
	set<pair<double, pair<double, double>>> used;
	for (int i = 0; i < m; ++ i) {
		if (used.count(pair<double, pair<double, double>>(arr[i].a, pair<double, double>(arr[i].b, arr[i].c))) == 0) {
			used.insert(pair<double, pair<double, double>>(arr[i].a, pair<double, double>(arr[i].b, arr[i].c)));
			vector<int> inst;
			inst.push_back(i);
			for (int j = i + 1; j < m; ++ j) {
				if (arr[i] == arr[j])
					inst.push_back(j);
			}
			if (inst.size() > 1)
				print(inst);
		}
	}
	return 0;
}