#include <iostream>
#include <cstring>

using namespace std;

char * purge_string(char *);

char * get_string(char *);

int main()
{
    char prompt[] = {"Please enter a string : "};
    char *my_string = get_string(prompt);
    // cin.getline(my_string, 1025);
    char *no_spaces = purge_string(my_string);
    for (int i = 0; i < strlen(no_spaces); i++)
    {
        cout << no_spaces[i];
    }
    cout << endl;
    delete [] no_spaces;
    return 0;
}

char * purge_string(char *str)
{
    char * temp_str = new char [1024];
    strcpy(temp_str, str);
    for (int i = 0; i < strlen(temp_str); i++)
    {
        if (temp_str[i] == ' ')
        {
            strcpy(&temp_str[i], &temp_str[i + 1]);
            i--;
        }
    }
    return temp_str;
}

char * get_string(char *prompt)
{
    for (int i = 0; i < strlen(prompt); i++)
    {
        cout << prompt[i];
    }
    char * result = new char [1025];
    cin.getline(result, 1025);
    return result;
}
