/*******************************************************************
 ** Program: assignment4.cpp
 ** Author: Philip Warton
 ** Date: 11/20/2019
 ** Description: Analyze properties of text using c strings
 ** Input: String of text, which analysis to be done, and search for
 **     words
 ** Output: Analysis of text
 *******************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

void print_c_string(char *);

int word_count(char *);

char * get_line(int);

char * get_string(char *);

bool is_int(char *);

int get_int();

int choose_option();

void do_option(int, char *);

char * without_specials(char *);

char * without_spaces(char *);

bool is_palindrome(char *);

void add_unique_word(int &, char *, char * [], int[]);

void all_word_frequency(char *, char * [], int[]);

void given_word_frequency(char *);

int main()
{
    bool run_again = false;
    do
    {
        char prompt[] = {"Please enter a string of text : "};
        char * user_input = get_string(prompt);
        cout << endl;
        int choice = choose_option();
        do_option(choice, user_input);

        // Free the memory to avoid leaks
        delete [] user_input;

        // UI prompt
        cout << "Would you like to run the progam again?" << endl;
        cout << "    (0) No" << endl;
        cout << "    (1) Yes" << endl;
        cout << " > ";
        int user_number = get_int();
        while (user_number != 0 && user_number != 1)
        {
            cout << "You must enter 0 or 1 : ";
            user_number = get_int();
        }
        user_number == 1 ? run_again = true : run_again = false;
    }
    while (run_again);
    return 0;
}

/******************************************************************** 
 ** Function: print_c_string 
 ** Description: Iterates through c-style string and prints out each
 **     character
 ** Parameters: char * str
 ** Pre-Conditions: str must be a valid c-style string
 ** Post-Conditions: Desired string has been printed
 ********************************************************************/
void print_c_string(char * str)
{
    // Printing out all the letters in a c style string
    for (int i = 0; i < strlen(str); i++)
    {
        cout << str[i];
    }
}

/******************************************************************** 
 ** Function: word_count 
 ** Description: Counts the number of letter words in a c-style string
 ** Parameters: char * str
 ** Pre-Conditions: str must be a valid c-style string
 ** Post-Conditions: Returns the number of words in the string as an int
 ********************************************************************/
int word_count(char * str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        // Checks if character is a lowercase letter or uppercase letter
        if ((str[i] >= 65 && str[i] <= 90) ||
        (str[i] >= 97 && str[i] <= 122))
        {
            count += 1;
            // Checks same condition as above if statement
            while ((str[i] >= 65 && str[i] <= 90) ||
            (str[i] >= 97 && str[i] <= 122))
            {
                i++;
            }
        }
    }
    return count;
}

/******************************************************************** 
 ** Function: get_line 
 ** Description: Gets a line of input from the user of a given size
 **     and handles any error regarding the size of the input text
 ** Parameters: int size
 ** Pre-Conditions: size must be a valid integer
 ** Post-Conditions: Returns a c-style string of the given size with
 **     user input
 ********************************************************************/
char * get_line(int size)
{
    // Create a an array of a given size to take user input
    char * result = new char [size];
    cin.getline(result, size);
    if (cin.fail())
    {
        cin.ignore(size, '\n');
        cin.clear();
    }
    return result;
}

/******************************************************************** 
 ** Function: get_string 
 ** Description: Prints a prompt and then returns the user input,
 **     demanding that it has at least one word
 ** Parameters: char * prompt
 ** Pre-Conditions: prompt must be a valid c-style string
 ** Post-Conditions: Returns a c-style string of the user input with at
 **     least one word
 ********************************************************************/
char * get_string(char * prompt)
{
    print_c_string(prompt);
    char * result = get_line(1025);

    // Make sure that there is at least one word in input
    while (word_count(result) < 1)
    {
        cout << "Must have at least one word : ";
        result = get_line(1025);
    }
    return result;
}

/******************************************************************** 
 ** Function: is_int 
 ** Description: Checks if a c-style string is a valid integer
 ** Parameters: char * str
 ** Pre-Conditions: str must be a valid c-style string
 ** Post-Conditions: Returns true or false depending on if non-number
 **     characters are found
 ********************************************************************/
bool is_int(char * str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        // Ascii values to see if each character is a number
        if (str[i] < 48 || str[i] > 57)
        {
            return false;
        }
    }
    return true;
}

/******************************************************************** 
 ** Function: get_int
 ** Description: Gets a integer from user input
 ** Parameters: none
 ** Pre-Conditions: User must know what an integer is
 ** Post-Conditions: Returns the integer entered by the user, after
 **     rejecting any invalid input
 ********************************************************************/
int get_int()
{
    char * input = get_line(256);
    while (!is_int(input))
    {
        cout << "Input must be an integer. Try again : ";
        input = get_line(256);
    }
    int result = 0;

    // For each digit n, add input[i] * 10^n
    for (int i = 0; i < strlen(input); i++)
    {
        int place = pow(10, strlen(input) - i - 1);
        int value = input[i] - 48;
        result += place * value;
    }

    // Free up the memory allocated to input
    delete [] input;
    return result;
}

/******************************************************************** 
 ** Function: choose_option 
 ** Description: Tells user 3 options and demands that 1 is selected
 ** Parameters: none
 ** Pre-Conditions: get_int() must work properly.
 ** Post-Conditions: Returns 1, 2, or 3 based on user input, taking
 **     only valid inputs
 ********************************************************************/
int choose_option()
{
    int option = 0;
    // UI prompt
    cout << "Choose one of the following: " << endl;
    cout << "    (1) Check if your text is palindromic" << endl;
    cout << "    (2) Check the frequency of all words" << endl;
    cout << "    (3) Search for specific words and see their frequencies" << endl;
    cout << " > ";
    option = get_int();

    // Restrict options to provided numbers
    while (option != 1 && option != 2 && option != 3)
    {
        cout << "You must enter 1, 2, or 3 : ";
        option = get_int();
    }
    cout << endl << "--OPTION " << option << " SELECTED--" << endl;
    return option;
}

/******************************************************************** 
 ** Function: do_option 
 ** Description: Does one of 3 options based on given choice
 ** Parameters: int choice, char * user_input
 ** Pre-Conditions: choice must be 1, 2, or 3, and user_input must be
 **     valid c-style string
 ** Post-Conditions: Runs the appropriate option based on given choice
 ********************************************************************/
void do_option(int choice, char * user_input)
{
    // Option 1 -- Check if user_input is a palindrome
    if (choice == 1)
    {
        if (is_palindrome(user_input))
        {
            cout << "Your text is palindromic." << endl << endl;
        }
        else
        {
            cout << "Your text is not palindromic." << endl << endl;
        }
        
    }
    // Option 2 -- Check how often every word in the user_input appears
    else if (choice == 2)
    {
        char** words = new char* [256];
        for (int i = 0; i < 256; i++)
        {
            words[i] = new char[256];
        }
        int count[256];
        for (int i = 0; i < 256; i++)
        {
            count[i] = 0;
        }
        all_word_frequency(user_input, words, count);
        // Printing all the words and counts
        for (int i = 0; i < 256; i++)
        {
            //if (strcmp(words[i], "") != 0)
            //{
                cout << "   Word : " << words[i] << endl << "  Count : " << count[i] << endl << endl;
            //}
        }
    }
    // Option 3 -- Get user search and check every word in 
    // search for its frequency in user_input
    else
    {
        //given_word_frequency(user_input);
    }
}

/******************************************************************** 
 ** Function: without_specials 
 ** Description: Deletes all special characters and converts uppercase
 **     letters to lowercase
 ** Parameters: char * input
 ** Pre-Conditions: input must be a valid c-style string
 ** Post-Conditions: Returns the same text as input but all lowercase,
 **     and without special characters
 ********************************************************************/
char * without_specials(char * input)
{
    char * output = new char [1025];
    strcpy(output, input);
    for (int i = 0; i < strlen(output); i++)
    {
        // Convert uppercase to lowercase
        if (output[i] > 64 && output[i] < 91)
        {
            output[i] += 32;
        }
        // Remove any non-letter / non-space characters
        else if ((output[i] < 97 || output[i] > 122) && output[i] != ' ')
        {
            strcpy(&output[i], &output[i + 1]);
            i--;
        }
    }
    return output;
}

/******************************************************************** 
 ** Function: without_spaces 
 ** Description: Deletes all spaces
 ** Parameters: char * input
 ** Pre-Conditions: input must be a valid c-style string
 ** Post-Conditions: Returns the same text as input but without spaces
 ********************************************************************/
char* without_spaces(char * input)
{
    char* output = new char [1025];
    strcpy(output, input);
    for (int i = 0; i < strlen(output); i++)
    {
        if (output[i] == ' ')
        {
            // Algorithm for using strcpy to remove spaces
            // shown in lecture
            strcpy(&output[i], &output[i + 1]);
            i--;
        }
    }
    return output;
}

/******************************************************************** 
 ** Function: is_palindrome 
 ** Description: Checks if the entire string of text is palindromic
 ** Parameters: char * text
 ** Pre-Conditions: text must be a valid c-style string
 ** Post-Conditions: Returns true or false based on if the text is a
 **     palindrome
 ********************************************************************/
bool is_palindrome(char * text)
{
    char * text_without_specials = without_specials(text);
    char * purged_text = without_spaces(text_without_specials);
    cout << "Purged text : ";
    print_c_string(purged_text);
    cout << endl;
    for (int i = 0; i < strlen(purged_text); i++)
    {
        // Want to check that the indicies on the outside are equal then work inwards
        // [0][1][2]...[length - 3][length - 2][length - 1]
        if (purged_text[i] != purged_text[strlen(purged_text) - 1 - i])
        {
            delete [] text_without_specials;
            delete [] purged_text;
            return false;
        }
        // If we are past the midway point in our string without returning false, we can return true
        else if (i > strlen(purged_text) - 1 - i)
        {
            delete [] text_without_specials;
            delete [] purged_text;
            return true;
        }
    }
    // This state should be unreachable, but we return false by default
    delete [] text_without_specials;
    delete [] purged_text;
    return false;
}

/******************************************************************** 
 ** Function: add_unique_word 
 ** Description: Adds word and increases its count in our arrays
 ** Parameters: int &index, string current_word, string word[], int count[]
 ** Pre-Conditions: index must be address of an integer variable,
 **     string current_word must be a valid c++ string, word[] must be a
 **     valid array of c++ strings, and count[] must be a valid array of
 **     integers
 ** Post-Conditions: Current_word is added to word[] if not already there,
 **     and the count is increased by one for that word, and the index is
 **     left at the proper location
 ********************************************************************/
void add_unique_word(int& index, char* current_word, char* word[], int count[])
{
    // Remember where we left off in case we move to an old index
    int previous_index = index;
    for (int j = 0; j < 10; j++)
    {
        // If the current word is already in array word[], we wish only to increase the count
        if (current_word == word[j])
        {
            index = j;
        }
    }
    // Change word to current_word and increase count
    cout << current_word << endl;
    word[index] = current_word;
    count[index]++;
    if (index == previous_index)
    {
        // If we didn't go back to an old index, go up by one
        index++;
    }
    else
    {
        // If we went back to different index, return to where we left off
        index = previous_index;
    }
}

/******************************************************************** 
 ** Function: all_word_frequency 
 ** Description: Takes c-style string and adds all the words and their
 **     associated frequencies to the input arrays
 ** Parameters: char * text, string word[], int count[]
 ** Pre-Conditions: text must be a valid c-style string, word[] and
 **     count[] must be arrays of size 256 of the proper data type
 ** Post-Conditions: All words in the text and the # of times they
 **     should be correctly identified and added to the arrays
 ********************************************************************/
void all_word_frequency(char* text, char* word[], int count[])
{
    char* purged_text = without_specials(text);

    // Set count[] to all 0's
    for (int i = 0; i < 256; i++)
    {
        count[i] = 0;
    }
    char* current_word = new char [256];

    // Keeping seperate index for our word[] and count[] arrays
    int index = 0;

    int char_index = 0;
    
    // Iterating through the string to find words
    for (int i = 0; i < strlen(purged_text); i++)
    {
        // End of word
        if (purged_text[i] == 32)
        {
            current_word[char_index] = '\0';
            // If we encouonter a space, add whatever is already in current word
            // and reset current word to empty
            add_unique_word(index, current_word, word, count);
            current_word[0] = '\0';
            char_index = 0;
            //current_word = "";
        }
        // End of string of text
        else if (i == (strlen(purged_text) - 1))
        {
            // Add the last letter to current word if we reach the end of text,
            // and then add current word
            current_word[char_index] = purged_text[i];
            char_index++;
            current_word[char_index] = '\0';
            //strcpy(current_word, &purged_text[i], 1);
            //current_word += purged_text[i];
            add_unique_word(index, current_word, word, count);
        }
        else
        {
            // Add the next letter to current word
            current_word[char_index] = purged_text[i];
            char_index++;
            //strcat(current_word, purged_text[i]);
            //strcpy(current_word, &purged_text[i], 1);
            //current_word += purged_text[i];
        }
    }
    delete [] current_word;
    delete [] purged_text;
}

/******************************************************************** 
 ** Function: given_word_frequency 
 ** Description: Takes user search and checks how often those words
 **     appear in the given string of text
 ** Parameters: char * text
 ** Pre-Conditions: text must be a valid c-style string, and all_word_frequency
 **     function must work properly
 ** Post-Conditions: The frequency of each word in the search must be
 **     correctly identified in the given text
 ********************************************************************/
/*void given_word_frequency(char * text)
{
    string words_text[256];
    int count_text[256];

    // Set array to all 0's
    for (int i = 0; i < 256; i++)
    {
        count_text[i] = 0;
    }
    // Count words in text
    all_word_frequency(text, words_text, count_text);
    char prompt[] = {"Please enter your search : "};
    char * search = get_string(prompt);
    string words_search[256];
    int count_search[256];

    // Get an array of all words in the search, then set the count of these
    // words to 0's
    all_word_frequency(search, words_search, count_search);
    delete search;
    for (int i = 0; i < 256; i++)
    {
        count_search[i] = 0;
    }
    // For each word in the search, if the word is found in the text, set the
    // count to what the count is in the text
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            if (words_search[i] == words_text[j])
            {
                count_search[i] = count_text[j];
            }
            
        }
    }
    // Print the frequency for each nonempty word
    for (int i = 0; i < 256; i++)
    {
        if (words_search[i] != "")
        {
            cout << "   Word : " << words_search[i] << endl << "  Count : " << count_search[i] << endl << endl;
        }
    }
}
*/
