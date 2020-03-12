/*******************************************************************
 ** Program: simplify_fraction.cpp
 ** Author: Philip Warton
 ** Date: 11/10/2019
 ** Description: Fraction simplifying program for CS161 assignment 3
 ** Input: numerator, denominator
 ** Output: simplified fraction
 *******************************************************************/

#include <iostream>
#include "helper_functions.h"

using namespace std;

bool to_lowest_terms(int&, int&);

int g_c_d(int, int);

void simplify_fraction(int, int);

bool get_1_or_0(string);

int main()
{    
    bool another;
    do 
    {
        int numerator = get_int("Enter numerator: ");
        int denominator = 0;
        while (denominator == 0)
        {
            denominator = get_int("Enter denominator (cannot be zero): ");
        }
        simplify_fraction(numerator, denominator);
        another = get_1_or_0("Do you want another conversion? (0-no, 1-yes): ");
    } while (another == true);
    return 0;
}

/******************************************************************** 
 ** Function: to_lowest_terms 
 ** Description: Returns true or false if the fraction is completely
 **     simplified. If the greatest common divisor is one, then it
 **     is simplified.
 ** Parameters: int numerator, int denominator
 ** Pre-Conditions: Both numbers must be valid integers, denominator 
 **     should probably not be zero
 ** Post-Conditions: Returns true or false wether or not the fraction
 **     is completely simplified 
 ********************************************************************/
bool to_lowest_terms(int &numerator, int &denominator)
{
    return g_c_d(numerator, denominator) == 1 ? true : false;
}

/******************************************************************** 
 ** Function: g_c_d 
 ** Description: Finds the greatest common divisor of two numbers
 **     using Euclidean algorithm
 ** Parameters: int num1, int num2
 ** Pre-Conditions: Both numbers must be valid integers
 ** Post-Conditions: Returns the correct greatest common divisor for
 **     num1 and num2
 ********************************************************************/
int g_c_d(int num1, int num2)
{
    return num2 == 0 ? num1 : g_c_d(num2, num1 % num2);
}

/******************************************************************** 
 ** Function: simplify_fraction 
 ** Description: Divides both the numerator and denominator by GCD
 **     until the fraction is in lowest terms, then prints the fraction
 ** Parameters: int numerator, int denominator
 ** Pre-Conditions: Both numbers must be valid integers
 ** Post-Conditions: Prints the correct simplified fraction in readable
 **     output
 ********************************************************************/
void simplify_fraction(int numerator, int denominator)
{
    while (!to_lowest_terms(numerator, denominator))
    {
        int divisor = g_c_d(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }
    cout << "Fraction in lowest terms: " << numerator << " / " << denominator << endl;
}

/******************************************************************** 
 ** Function: get_1_or_0 
 ** Description: Demands valid boolean input from user after displaying
 **     prompt
 ** Parameters: string Prompt
 ** Pre-Conditions: 'Prompt' must be a valid string
 ** Post-Conditions: Returns either true or false based on user input
 ********************************************************************/
bool get_1_or_0(string prompt)
{
    int answer;
    while (1)
        {
            answer = get_int(prompt);
            if (answer == 1 || answer == 0)
            {
                break;
            }
            else
            {
                cout << "You must enter either 0 or 1." << endl;
            }
        }
    return answer;
}
