/* -----------------------
 * Program to test matrix
 * library
 * ----------------------*/

#include "matrix.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Matrix mA(3, 3, vector<double> {1, 3, 9, 1, 2, 4, 1, 1, 1});
    mA.print();
    cout << mA.determinant() << endl;
    return 0;
}
