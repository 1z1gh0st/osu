#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

// Done
int word_count(char *);

char * get_line(int);

char * get_string(char *);

string get_valid_string(string);

int choose_option();

string purge_specials(string);

string purge_spaces(string);

bool is_palindrome(string);

void all_word_frequency(string, string[], int[]);

void given_word_frequency(string);

int main()
{
    string user_input = get_valid_string("Please enter a string of text : ");
    int choice = choose_option();
    if (choice == 1)
    {
        if (is_palindrome(user_input))
        {
            cout << "Your text is palindromic." << endl;
        }
        else
        {
            cout << "Your text is not palindromic." << endl;
        }
    }
    else if (choice == 2)
    {
        string words[256];
        int count[256];
        for (int i = 0; i < 256; i++)
        {
            count[i] = 0;
        }
        all_word_frequency(user_input, words, count);
        for (int i = 0; i < 256; i++)
        {
            if (words[i] != "")
            {
                cout << "Word : " << words[i] << endl << "Count : " << count[i] << endl << endl;
            }
        }
    }
    else
    {
        given_word_frequency(user_input);
    }
    return 0;
}

int word_count(char * str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        // Checks if character is a lowercase letter, uppercase letter, or numbers
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

char * get_line(int size)
{
    char * result = new char [size];
    cin.getline(result, size);
    if (cin.fail())
    {
        cin.ignore(size, '\n');
        cin.clear();
    }
    return result;
}

char * get_string(char * prompt)
{
    for (int i = 0; i < strlen(prompt); i++)
    {
        cout << prompt[i];
    }
    char * result = get_line(1025);
    while (word_count(result) < 1)
    {
        cout << "Must have at least one word : ";
        char * result = get_line(1025);
    }
    return result;
}

bool is_int(char * str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] < 48 || str[i] > 57)
        {
            return false;
        }
    }
    return true;
}

int get_int()
{
    char * input = get_line(256);
    while (!is_int(input))
    {
        cout << "Input must be an integer. Try again : ";
        input = get_line(256);
    }
    int result = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        int place = pow(10, strlen(input) - i - 1);
        int value = input[i] - 48;
        result += place * value;
    }
    return result;
}

string get_valid_string(string prompt)
{
    string result = "";
    // char temp[1025];
    cout << prompt;
    // cin.getline(temp, 1025);
    getline(cin, result);
    /*while (word_count(temp) < 1)
    {
        cout << "Please include at least one word : ";
        // getline(cin, result);
        cin.getline(temp, 1025);
    }*/
    return result;
}

int choose_option()
{
    int option = 0;
    cout << "Choose one of the following: " << endl;
    cout << "    (1) Check if your text is palindromic" << endl;
    cout << "    (2) Check the frequency of all words" << endl;
    cout << "    (3) Search for specific words and see their frequencies" << endl;
    char * input = new char [256];
    cin.getline(input, 256);
    if (cin.fail())
    {
        cin.ignore(256, '\n');
        cin.clear();
    }
    option = stoi(input);
    while (option != 1 && option != 2 && option != 3)
    {
        cout << "You must enter 1, 2, or 3" << endl;
        cin.getline(input, 256);
        if (cin.fail())
        {
            cin.ignore(256, '\n');
            cin.clear();
        }
        option = stoi(input);
    }
    return option;
}

string purge_specials(string text)
{
    string purged_text = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] > 64 && text[i] < 91)
        {
            purged_text += text[i] + 32;
        }
        else if (text[i] > 96 && text[i] < 122)
        {
            purged_text += text[i];
        }
        else if (text[i] == 32)
        {
            purged_text += text[i];
        }
    }
    return purged_text;
}

string purge_spaces(string text)
{
    string purged_text = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] > 96 && text[i] < 122)
        {
            purged_text += text[i];
        }
    }
    return purged_text;
}

bool is_palindrome(string text)
{
    string purged_text = purge_spaces(purge_specials(text));
    cout << "Purged text : " << purged_text << endl;
    for (int i = 0; i < purged_text.length(); i++)
    {
        /* Want to check that the indicies on the outside are equal then work inwards
         * [0][1][2]...[length - 3][length - 2][length - 1] */
        if (purged_text[i] != purged_text[purged_text.length() - 1 - i])
        {
            return false;
        }
        /* If we are past the midway point in our string without returning false, we can return true */
        else if (i > purged_text.length() - 1 - i)
        {
            return true;
        }
    }
    /* Shit has hit the fan if we get here */
    return false;
}

void all_word_frequency(string text, string word[], int count[])
{
    string purged_text = purge_specials(text);
    // string word[256];
    // int count[256];
    for (int i = 0; i < 256; i++)
    {
        count[i] = 0;
    }
    string current_word = "";
    int index = 0;
    for (int i = 0; i < purged_text.length(); i++)
    {
        if (purged_text[i] == 32)
        {
            int previous_index = index;
            for (int j = 0; j < 256; j++)
            {
                if (current_word == word[j])
                {
                    index = j;
                }
            }
            word[index] = current_word;
            count[index]++;
            if (index == previous_index)
            {
                index++;
            }
            else
            {
                index = previous_index;
            }
            current_word = "";
        }
        else if (i == (purged_text.length() - 1))
        {
            current_word += purged_text[i];
            int previous_index = index;
            for (int j = 0; j < 10; j++)
            {
                if (current_word == word[j])
                {
                    index = j;
                }
            }
            word[index] = current_word;
            count[index]++;
        }
        else
        {
            current_word += purged_text[i];
        }
    }
    /* for (int i = 0; i < 256; i++)
    {
        if (word[i] != "")
        {
            cout << "Word : " << word[i] << endl << "Count : " << count[i] << endl << endl;
        }
    } */
}

void given_word_frequency(string text)
{
    string words_text[256];
    int count_text[256];
    for (int i = 0; i < 256; i++)
    {
        count_text[i] = 0;
    }
    all_word_frequency(text, words_text, count_text);
    string search = get_valid_string("Please enter your search : ");
    string words_search[256];
    int count_search[256];
    all_word_frequency(search, words_search, count_search);
    for (int i = 0; i < 256; i++)
    {
        count_search[i] = 0;
    }
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
    for (int i = 0; i < 256; i++)
        {
            if (words_search[i] != "")
            {
                cout << "Word : " << words_search[i] << endl << "Count : " << count_search[i] << endl << endl;
            }
        }
}
