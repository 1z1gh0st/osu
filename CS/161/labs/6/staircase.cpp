#include <iostream>

using namespace std;

int fib(int);

int main() {
	int stairs;
	cout << "How many stairs: ";
	cin >> stairs;
	cout << "There are " << fib(stairs + 1) << " ways to climb the stairs." << endl;
	return 0;
}

int fib(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
