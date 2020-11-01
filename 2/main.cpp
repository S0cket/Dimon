#include <set>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void print(multiset<int> s) {
	for (auto i = s.begin(); i != s.end(); ++ i)
		cout << *i << " ";
	cout << endl;
}

int main(void) {
	srand(time(NULL));

	int n;
	cin >> n;
	multiset<int> s, sb;
	for (int i = 0; i < n; ++ i)
		s.insert(rand() % 100);
	print(s);

	int key;
	cin >> key;
	s.erase(key);
	print(s);

	if (!s.empty())
		s.erase(*s.begin());
	print(s);

	if (!s.empty()) {
		int r = *(--s.end()) - *s.begin();
		sb = s;
		s.clear();
		for (auto i = sb.begin(); i != sb.end(); ++ i)
			s.insert(*i - r);
	}
	print(s);

	return 0;
}