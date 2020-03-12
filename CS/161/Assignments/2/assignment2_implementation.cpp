/***************************************
 * Author: Philip Warton
 * Date: 10/27/19
 * Project Name: Assignment 2
 * *************************************/

#include "assignment2_header.h"

/******************************************************************** 
 ** Function: check_range 
 ** Description: determines wether or not an integer is between two other integers 
 ** Parameters: int lower, int upper, int input 
 ** Pre-Conditions: all three numbers must not be too large for integer datatype 
 ** Post-Conditions: returns true or  false wether or not the number belongs in the range 
 ********************************************************************/
bool check_range(int lower, int upper, int input)
{
    if (input < lower || input > upper)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/******************************************************************** 
 ** Function: is_capital 
 ** Description: checks if a letter is capital or not 
 ** Parameters: char input 
 ** Pre-Conditions: 'input' must be a valid char 
 ** Post-Conditions: returns true or  false wether or not the input character is capital 
 ********************************************************************/
bool is_capital(char input)
{
    if (input < 65 || input > 90)
    {
        return false;
    }
    else 
	{
        return true;
    }
}

bool is_even(int input)
{
    if (input % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_odd(int input)
{
    if (!is_even(input))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int equality_test(int num1, int num2)
{
    if (num1 < num2)
    {
        return -1;
    }
    else if (num1 > num2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool float_is_equal(float num1, float num2, float precision)
{
    if (num1 - num2 < precision)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_int(string num)
{
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] < 48 || num[i] > 57)
        {
            return false;
        }
    }
    return true;
}

bool numbers_present(string sentence)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] >= 48 && sentence[i] <= 57)
        {
            return true;
        }
    }
    return false;
}

bool letters_present(string sentence)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122))
        {
            return true;
        }
    }
    return false;
}

bool contains_sub_string(string sentence, string sub_string)
{
    for (int i = 0; i < sentence.length(); i++)
    {
		next:
        if (sentence[i] == sub_string[0])
        {
            for (int j = 0; j < sub_string.length(); j++)
            {
                if ((i + j) > sentence.length())
                {
                    return false;
                }
				else if(sentence[(i + j)] != sub_string[j])
				{
					i++;
					goto next;
				}
            }
            return true;
        }
    }
    return false;
}

int word_count(string sentence)
{
    int count = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        if ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122) || (sentence[i] >= 47 && sentence[i] <= 57))
        {
            count += 1;
            while ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122) || (sentence[i] >= 47 && sentence[i] <= 57))
            {
                i++;
            }
        }
    }
    return count;
}

string to_upper(string sentence)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] >= 97 && sentence[i] <= 122)
        {
            sentence[i] -= 32;
        }
    }
    return sentence;
}

string to_lower(string sentence)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] >= 65 && sentence[i] <= 90)
        {
            sentence[i] += 32;
        }
    }
    return sentence;
}

int get_int(string prompt)
{
    string input = "";
    while(1)
    {
        cout << prompt;
        getline(cin, input);
        if (!is_int(input))
        {
            cout << "Please input a valid integer." << endl;
        }
        else
        {
            cout << "good job." << endl;
            return stoi(input);
        }
    }
}
