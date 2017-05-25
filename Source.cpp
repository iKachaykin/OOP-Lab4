#define _CRT_SECURE_NO_WARNINGS
#include "Fibonacci.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

typedef int test_type;

using namespace std;

void main() {
	setlocale(LC_ALL, "ru");
	bool invalid_input = false;
	int sh_val = 0, fib_size = 10;
	test_type to_find_val;
	Fibonacci<test_type> fib_for_test(fib_size, 10, -5);
	do {
		if (invalid_input)
			cout << "������������ ����!\n������ ������ ���� ����� ��������������� ������, ������� �� ����������� ����� ����� ������� ���������� ���������.\n";
		cout << "������� �������� �������: ";
		cin >> sh_val;
		invalid_input = sh_val < 0 || sh_val > fib_size / 2;
	} while (invalid_input);
	cout << "��������� ��������� ���������:\n";
	for (Fibonacci<test_type>::const_iterator iter = fib_for_test.cbegin(); iter <= fib_for_test.cend(); iter++)
		cout << *iter << " ";
	vector<test_type> fib_vect(fib_for_test.cbegin() + sh_val, fib_for_test.cend() - sh_val);
	cout << "\n������������� ������:\n";
	for (int i = 0; i < fib_vect.size(); i++)
		cout << fib_vect[i] << " ";
	sort(fib_vect.begin(), fib_vect.end());
	cout << "\n��������������� ������:\n";
	for (int i = 0; i < fib_vect.size(); i++)
		cout << fib_vect[i] << " ";
	cout << "\n������� ��������, ������� ���������� ����� � �������:\n";
	cin >> to_find_val;
	cout << "��������� ������: " << (binary_search(fib_vect.begin(), fib_vect.end(), to_find_val) ? "������ ������� ��������� � ������ ���������.\n" : "������ ������� ����������� � ������ ���������.\n");
	system("pause");
}