#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void get_string(string *);

void set_replace_string(string, string *);

int get_search_replace(char, string, string &);

int main()
{
    string sentence = "";
    get_string(&sentence);
    string copy = sentence;
    cout << copy << endl;
    set_replace_string(sentence, &copy);
    cout << copy << endl;
    return 0;
}

void get_string(string *input)
{
    cout << "Enter a string: ";
    getline(cin, *input);
}

void set_replace_string(string input, string *copy)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (input.at(i) == ' ')
        {
            copy->at(i) = '-';
        }
    }
}


