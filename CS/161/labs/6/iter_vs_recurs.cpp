#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using std::cout; 
using std::endl; 

int fib_iter(int);

int fib_recurs(int);

void test_iter(int n) {
	typedef struct timeval time; 
	time stop, start; 
	gettimeofday(&start, NULL); 
	cout << fib_iter(n) << endl;
	gettimeofday(&stop, NULL); 
	if(stop.tv_sec > start.tv_sec) 
		cout<< "Seconds: " << stop.tv_sec-start.tv_sec << endl; 
	else 
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl; 
}

void test_recurs(int n) {
	typedef struct timeval time; 
	time stop, start; 
	gettimeofday(&start, NULL); 
	cout << fib_recurs(n) << endl;
	gettimeofday(&stop, NULL); 
	if(stop.tv_sec > start.tv_sec) 
		cout<< "Seconds: " << stop.tv_sec-start.tv_sec << endl; 
	else 
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl; 
}

int main() { 
	cout << "Iterative tests:" << endl;
	test_iter(1);
	test_iter(5);
	test_iter(15);
	test_iter(25);
	test_iter(45);

	cout << "\nRecursive tests:" << endl;
	test_recurs(1);
	test_recurs(5);
	test_recurs(15);
	test_recurs(25);
	test_recurs(45);

	return 0; 
}

int fib_iter(int n) { 
	if (n == 0)
		return 0;
	int value = 1;
	int previous = 1;
	for (int i = 2; i < n; i++) {
		int current = value;
		value += previous;	
		previous = current;
	}
	return value;
}

int fib_recurs(int n) {
	if (n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fib_recurs(n - 1) + fib_recurs(n - 2);
}

