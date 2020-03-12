#include <iostream>
#include <string>

using namespace std;

string get_sentence(string);

void get_sentence_by_ref(string, string&);

int main()
{
    string sentence;
    sentence = get_sentence("Enter your sentence: ");
    cout << sentence << endl << endl;

    get_sentence_by_ref("Enter another sentence: ", sentence);
    cout << sentence << endl << endl;
    return 0;
}

string get_sentence(string prompt)
{
    string result;
    cout << prompt;
    getline(cin, result);
    return result;
}

void get_sentence_by_ref(string prompt, string &sentence)
{
    cout << prompt;
    getline(cin, sentence);
}
