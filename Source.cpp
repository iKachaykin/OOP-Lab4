#include "Fibonacci.h"

using namespace std;

void main() {
	setlocale(LC_ALL, "ru");
	Fibonacci<int> fib_gen(10);
	for (int i = 0; i < 10; i++)
		cout << fib_gen.at(i) <<"\n";
	system("pause");
}