#include <stdio.h>
#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

const int N = 5;

typedef struct {
	unsigned reg_number;
	string author;
	string name;
	short year;
	
} book;

void print(book elem) {
	cout << "Book {\n"
	<< "\treg_number=" << elem.reg_number << "\n"
	<< "\tauthor=" << elem.author << "\n"
	<< "\tname=" << elem.name << "\n"
	<< "\tyear=" << elem.year << "\n}\n";
}

void remove(book* mass, int& n, int index) {
	book tmp;
	tmp = mass[index];
	mass[index] = mass[n - 1];
	mass[n - 1] = tmp;
	-- n;
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	int n = N;

	book mass[N] = {
		{1, "Ray Bradbury", "Fahrenheit 451", 1953},
		{2, "George Orwell", "1984", 1949},
		{3, "Александр Островский", "Гроза", 1859},
		{4, "Mark Twain", "The Adventures of Tom Sawyer", 1876},
		{5, "Фёдор Достоевский", "Преступление и наказание", 1866}
	};
	cout << "begin of old:\n";
	for (int i = 0; i < n; ++ i)
		print(mass[i]);
	cout << "end of old\n";



	short year;
	cout << "year>";
	cin >> year;

	for (int i = 0; i < n; ++ i) {
		if (mass[i].year < year) {
			remove(mass, n, i);
			-- i;
		}
	}

	cout << "begin of new:\n";
	for (int i = 0; i < n; ++ i)
		print(mass[i]);
	cout << "end of new\n";

	return 0;
}