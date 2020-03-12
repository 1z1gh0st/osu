/*******************************************************************
 ** Program: recursive_fractal.cpp
 ** Author: Philip Warton
 ** Date: 11/10/2019
 ** Description: Prints out a fractal made up of stars
 ** Input: N number of stars in widest row, Col starting column of 
 **     fractal
 ** Output: Printed fractal
 *******************************************************************/
#include <iostream>
#include "helper_functions.h"

using namespace std;

void pattern(int, int);

int main()
{
    int n = get_int("Enter number of stars 'n': ");
    int col = get_int("Enter column at which fractal starts 'col': ");
    pattern(n, col);
    return 0;
}

/******************************************************************** 
 ** Function: pattern 
 ** Description: Recursive function that prints fractal pattern given
 **     n stars, and col columns of whitespace
 ** Parameters: int n, int col
 ** Pre-Conditions: Both numbers must be valid, positive, integers
 ** Post-Conditions: Prints the proper fractal pattern on the screen
 ********************************************************************/
void pattern(int n, int col)
{
    if (n > 0)
    {
        pattern(n - 2, col + 1);
        for (int i = 0; i < col * 2; i++) cout << " ";
        for (int i = 0; i < n; i++) cout << "* ";
        cout << endl;
        pattern(n - 2, col + 1);
    }
}
