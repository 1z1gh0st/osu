/* -----------------------
 * Program to test matrix
 * library
 * ----------------------*/

#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <chrono>

using namespace std;

void init() {
	srand(time(NULL));
}

unsigned long testMultiplication(Matrix &A, Matrix&B, bool print) {
	auto begin = chrono::high_resolution_clock::now();
	Matrix result = A * B;
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	cout << "multiplication time(ms) : " << ms << endl;
	if (print) { result.print(); }
	return ms;
}

void testDeterminant(Matrix &A) {
		auto begin = chrono::high_resolution_clock::now();
		try {
			A.determinant();
			cout << "passed.";
		} catch (char const* ex) {
			cout << "failed.";
		}
		auto end = chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << " time(ms) : " << ms << endl;
}

void runMultiplicationTest(unsigned n) {
	unsigned long total = 0;
	for (int i = 0; i < 1000; i++) {
		Matrix m_Rand1(n, n, "rand");
		Matrix m_Rand2(n, n, "rand");
		total += testMultiplication(m_Rand1, m_Rand2, false);	
	}
	cout << "Average time for multiplication : " << total / 1000.0 << endl;
}

int main() {
	Matrix A(2, 2, vector<double> {1, 2, 3, 4});
	Matrix B(2, 2, vector<double> {0, 5, 6, 7});
	A.kroeneckerProduct(B);
	A.print();
    return 0;
}
