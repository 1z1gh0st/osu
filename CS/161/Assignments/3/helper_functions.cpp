/*******************************************************************
 ** Program: helper_functions.cpp
 ** Author: Philip Warton
 ** Date: 10/27/2019
 ** Description: Definitions of all the helper functions for CS161
 **     assignment 2
 ** Input: none
 ** Output: none
 *******************************************************************/

#include "helper_functions.h"

/******************************************************************** 
 ** Function: check_range 
 ** Description: determines wether or not an integer is between two 
 **     other integers 
 ** Parameters: int lower, int upper, int input
 ** Pre-Conditions: all three numbers must not be too large for
 **     integer datatype 
 ** Post-Conditions: returns true or false wether or not the number
 **     belongs in the range 
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
 ** Post-Conditions: returns true or false wether or not the input
 **     character is capital 
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

/******************************************************************** 
 ** Function: is_even 
 ** Description: determines wether an integer is even or not 
 ** Parameters: int input 
 ** Pre-Conditions: 'input' must be a valid integer 
 ** Post-Conditions: returns true or false wether or not the input
 **     number is even or odd 
 ********************************************************************/
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

/******************************************************************** 
 ** Function: is_odd 
 ** Description: determines wether an integer is odd or not 
 ** Parameters: int input 
 ** Pre-Conditions: 'input' must be a valid integer 
 ** Post-Conditions: returns true or false wether or not the input
 **     number is even or odd 
 ********************************************************************/
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

/******************************************************************** 
 ** Function: equality_test 
 ** Description: determines wether two integer numbers are equal to 
 **     each other 
 ** Parameters: int num1, int num3 
 ** Pre-Conditions: 'num1' and 'num2' must both be valid integers 
 ** Post-Conditions: returns -1 if num2 is larger, 0 if they are
 **     equal, and 1 if num1 is larger 
 ********************************************************************/
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
 
/******************************************************************** 
 ** Function: float_is_equal 
 ** Description: determines if two floating point numbers are within
 ** 	a given distance of each other, this distance being given by 
 **     a third floating point number, precision 
 ** Parameters: int num1, int num3 
 ** Pre-Conditions: 'num1' and 'num2' must both be valid integers 
 ** Post-Conditions: returns -1 if num2 is larger, 0 if they are
 **     equal, and 1 if num1 is larger 
 ********************************************************************/
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

/******************************************************************** 
 ** Function: is_int
 ** Description: determines if string is a valid integer
 ** Parameters: string num
 ** Pre-Conditions: 'num' must be a valid string
 ** Post-Conditions: returns true if the string is a valid integer,
 **     and false if not
 ********************************************************************/
bool is_int(string num)
{
    for (int i = 0; i < num.length(); i++)
    {
        if (i == 0)
        {
            if ((num[i] < 48 || num[i] > 57) && num[i] != '-')
            {
                return false;
            }
        }
        else
        {
            if (num[i] < 48 || num[i] > 57)
            {
                return false;
            }
        }
    }
    return true;
}

/******************************************************************** 
 ** Function: numbers_present
 ** Description: determines if there is at least one number in the
 **     given string
 ** Parameters: string sentence
 ** Pre-Conditions: 'sentence' must be a valid string
 ** Post-Conditions: returns true if there is at lease one number,
 **     and returns false if no numbers are found
 ********************************************************************/
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

/******************************************************************** 
 ** Function: letters_present
 ** Description: determines if there are any alphabetical letters in
 **     a given string
 ** Parameters: string sentence
 ** Pre-Conditions: 'sentence' must be a valid string
 ** Post-Conditions: returns true if there are letters in the string,
 **     and false if no letters are found
 ********************************************************************/
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

/******************************************************************** 
 ** Function: constains_sub_string
 ** Description: determines if a string of characters can be found
 **     within another string of characters
 ** Parameters: string sentence, string sub_string
 ** Pre-Conditions: 'sentence' and 'substring' bust both be valid
 **     strings
 ** Post-Conditions: returns true if the substring is found within
 **     sentence, and false if it is not
 ********************************************************************/
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

/******************************************************************** 
 ** Function: word_count
 ** Description: determines the number of words in a given string
 ** Parameters: string sentence
 ** Pre-Conditions: 'sentence' must be a valid string
 ** Post-Conditions: returns an integer value of how many words were
 **     in the string
 ********************************************************************/
int word_count(string sentence)
{
    int count = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        // Checks if character is a lowercase letter, uppercase letter, or numbers
        if ((sentence[i] >= 65 && sentence[i] <= 90) ||
        (sentence[i] >= 97 && sentence[i] <= 122) ||
        (sentence[i] >= 47 && sentence[i] <= 57))
        {
            count += 1;
            // Checks same condition as above if statement
            while ((sentence[i] >= 65 && sentence[i] <= 90) ||
            (sentence[i] >= 97 && sentence[i] <= 122) ||
            (sentence[i] >= 47 && sentence[i] <= 57))
            {
                i++;
            }
        }
    }
    return count;
}

/******************************************************************** 
 ** Function: to_upper
 ** Description: takes the input sentence and converts all lowercase
 **     characters to uppercase characters
 ** Parameters: string sentence
 ** Pre-Conditions: 'sentence' must be a valid string
 ** Post-Conditions: returns string where all characters are uppercase
 ********************************************************************/
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

/******************************************************************** 
 ** Function: to_lower
 ** Description: takes the input sentence and converts all uppercase
 **     characters to lowercase characters
 ** Parameters: string sentence
 ** Pre-Conditions: 'sentence' must be a valid string
 ** Post-Conditions: returns string where all characters are lowercase
 ********************************************************************/
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

/******************************************************************** 
 ** Function: get_int
 ** Description: prompts the user with a message, and demands that a
 **     valid integer is given
 ** Parameters: string prompt
 ** Pre-Conditions: 'prompt' must be a valid string
 ** Post-Conditions: returns valid integer given by user
 ********************************************************************/
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
            int result = 0;
            for (int i = 0; i < input.length(); i++)
            {
                int place = pow(10, input.length() - i - 1);
                int value = input[i] - 48;
                result += place * value;
            }
            return result;
        }
    }
}
