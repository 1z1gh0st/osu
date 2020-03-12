/********************************************************************
 ** Program: main.cpp
 ** Author: Philip Warton
 ** Date: 10/13/2019
 ** Description: This program calculates gross income and total taxes due.
 ** Input: Accepts several parameters regarding income and sales.
 ** Output: Outputs gross income and total taxes due.
 *******************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Initializing functions in order to put main() at the top
bool is_number(string);
float get_input(string);
int gross_income();
int taxes(int);

int main()
{
	int gross = gross_income();
	cout << endl << "Gross Income | $" << gross << std::endl << std::endl;

	int tax = taxes(gross);
	cout << endl << "Taxes | $" << tax << std::endl;

	int difference = gross - tax;
	cout << endl << "Remaining Income | $" << difference << std::endl;
}

/*********************************************************************
** Function: get_input()  
** Description: Displays message and then stores input as a int
** Parameters: string message 
** Pre-Conditions: Message must be a valid string 
** Post-Conditions: Result must be a valid int 
*********************************************************************/
float get_input(string message)
{
	float result;
	do
	{
		cout << message;
		cin >> result;
	} while (result < 0);;
	return result;
}

/*********************************************************************
** Function: gross_income()  
** Description: Gets all parameters necessary for calculating gross
				annual income and then proceeds to return this value.
** Parameters: none 
** Pre-Conditions: User must input valid ints  
** Post-Conditions: Numbers must not be large enough to overload ints 
*********************************************************************/
int gross_income()
{
	float monthly = get_input("Input monthly salary: ");
	float months_worked = 0;
	do
	{
		months_worked = get_input("Input number of months worked: ");
	} while (months_worked > 12);
	int cost = (int)get_input("Input cost of car: ");
	int sold = (int)get_input("Input number of cars sold: ");;
	int misconducts = (int)get_input("Input number of misconducts: ");;

	int annual_salary = monthly * months_worked;
	cout << endl << "ANNUAL SALARY: $" << annual_salary << std::endl; 

	// Seed the random function based on current time
	srand (time(NULL));
	float random = (rand() % 5 + 105) / 100.0;
	cout << "RANDOM PRICE INCREASE: x" << random << endl;

	int price = (int)cost * random;
	cout << "CAR PRICE: $" << price << endl;

	int profit = sold * (price - cost);
	cout << "PROFIT: $" << profit << endl;

	int deduction;
	if (misconducts == 0)
		deduction = 0;
	else
	{
		deduction = 100 * pow(2.0, (misconducts - 1));
		cout << "DEDUCTION: $" << deduction << endl;
	}
	int gross = annual_salary + (profit * 0.02) - deduction;
	return gross;
}

/*********************************************************************
** Function: taxes()  
** Description: Gets all parameters necessary for calculating taxes
				due and then proceeds to return this value.
** Parameters: gross income (int) 
** Pre-Conditions: User must input valid year and state  
** Post-Conditions: The number must not be too large for the ints 
*********************************************************************/
int taxes(int gross)
{
	int tax = 0;
	int year = 0;
	do
	{
		year = (int)get_input("Input tax year ('1' for 2017 or '2' for 2018): ");
	} while (year != 1 && year != 2);
	char state = 0;
	do
	{
		// get_input() is not used here becuase this is the only non-number input 
		cout << "Input state (A, B, or C): ";
		cin >> state;
	} while (state != 'a'
			&& state != 'b'
			&& state != 'c'
			&& state != 'A'
			&& state != 'B'
			&& state != 'C');
	if (year == 1)
	{
		if (state == 'A')
			tax = gross * 0.06;
		else if (state == 'B')
		{
			if (gross < 2000)
				tax = 0;
			else if (gross < 10000)
				tax = 100;
			else
				tax = ((gross - 10000) * 0.10) + 100;
		}
		else
		{
			if (gross < 3500)
				tax = gross * 0.05;
			else if (gross < 9000)
				tax = ((gross - 3500) * 0.07) + 175;
			else if (gross < 125000)
			{
				tax = ((gross - 9000) * 0.09) + 560;
			}
			else
				tax = ((gross - 125000) * 0.099) + 11000;
		}
	}
	else 
	{
		if (state == 'A')
			tax = gross * 0.08;
		else if (state == 'B')
			if (gross < 2500)
				tax = 0;
			else if (gross < 10000)
				tax = 115;
			else
				tax = ((gross - 10000) * 0.105) + 115;
		else
			if (gross < 3450)
				tax = gross * 0.05;
			else if (gross < 8700)
				tax = ((gross - 3450) * 0.07) + 172.5;
			else if (gross < 125000)
				tax = ((gross - 8700) * 0.09) + 540;
			else
				tax = ((gross - 125000) * 0.099) + 11007;
	}
	return tax;
}
