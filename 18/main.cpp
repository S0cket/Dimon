#include <iostream>
#include <fstream>

using namespace std;

int n1, n2[6];

int main(void) {
	ifstream file("f.txt");
	char c;
	bool flag = false;
	
	while (file.get(c)) {
		if (c == 'a')
			flag = true;
		else if (flag && c == 'b') {
			n1 ++;
			flag = false;
		}
		else
			flag = false;

		int n = c - 'a';
		if (n >= 0 && n < 6)
			n2[n] ++;
	}
	file.close();

	cout << "count \"ab\" = " << n1 << endl;
	for (int i = 0; i < 6; ++ i)
		cout << "count \"" << (char)('a' + i) << "\" = " << n2[i] << endl;
	return 0;
}