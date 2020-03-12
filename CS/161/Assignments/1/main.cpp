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

using namespace std;

float get_input(string);
float gross_income();
float taxes(float);

int main()
{
	float gross = gross_income();
	cout << "\nGross Income | " << gross << endl << endl;

	float tax = taxes(gross);
	cout << "\nTaxes | " << tax << endl;
}

/*********************************************************************
** Function: get_input()  
** Description: Displays message and then stores input as a float
** Parameters: string message 
** Pre-Conditions: Message must be a valid string 
** Post-Conditions: Result must be a valid float 
*********************************************************************/
float get_input(string message)
{
	float result;
	cout << message;
	cin >> result;
	return result;
}

/*********************************************************************
** Function: gross_income()  
** Description: Gets all parameters necessary for calculating gross
				annual income and then proceeds to return this value.
** Parameters: none 
** Pre-Conditions: User must input valid floats  
** Post-Conditions: Numbers must not be large enough to overload floats 
*********************************************************************/
float gross_income()
{
	float monthly = get_input("Input monthly salary: ");
	float months_worked = get_input("Input number of months worked: ");
	float cost = get_input("Input cost of car: ");
	float sold = get_input("Input number of cars sold: ");;
	float misconducts = get_input("Input number of misconducts: ");;

	float annual_salary = monthly * months_worked;
	float price = cost * ((rand() % 5 + 105) / 100);
	float profit = sold * (price - cost);

	float deduction;
	if (misconducts == 0)
		deduction = 0;
	else
		deduction = 100 * pow(2.0, (misconducts - 1));

	float gross = annual_salary + (profit * 0.02) - deduction;
	return gross;
}

/*********************************************************************
** Function: taxes()  
** Description: Gets all parameters necessary for calculating taxes
				due and then proceeds to return this value.
** Parameters: gross income (float) 
** Pre-Conditions: User must input valid year and state  
** Post-Conditions: The number must not be too large for the floats 
*********************************************************************/
float taxes(float gross)
{
	float tax;
	float year = get_input("Input tax year (2017 or 2018): ");
	char state;

	// get_input() is not used here becuase this is the only non-number input 
	cout << "Input state (A, B, or C): ";
	cin >> state;
	
	if (year == 2017)
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
