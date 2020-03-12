#include "./a1_header.h"

/********************************************************************* 
 ** Function: check_valid_arguments
 ** Description: Sees if the command line arguments are good or bad
 ** Parameters: int, char *, string &, string &
 ** Pre-Conditions: must have valid int, char *, and two valid strings
 **     passed by reference
 ** Post-Conditions: Exits program with error if there are incorrect #
 **     of cmd line args. Otherwise sets filenames to args.
 *********************************************************************/ 
void check_valid_arguments(int argc, char *argv[], string &users_file, string &budgets_file)
{
    if (argc != 3)
    {
        cout << "Invalid number of arguments. Exiting program..." << endl;
        exit(1);
    }
    else
    {
        users_file = argv[1];
        budgets_file = argv[2];
        check_file_opens(users_file);
        check_file_opens(budgets_file);
    }
}

/********************************************************************* 
 ** Function: get_int
 ** Description: Demands integer input from user
 ** Parameters: string
 ** Pre-Conditions: prompt must make sense and be a valid string
 ** Post-Conditions: Returns positive integer number given by the user
 *********************************************************************/ 
int get_int(string prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);
    while (!is_int(input))
    {
        cout << "Input must be a number : ";
        getline(cin, input);
    }
    return stoi(input);
}

/********************************************************************* 
 ** Function: get_int_bounded
 ** Description: Demands integer input from user within range
 ** Parameters: string, int, int
 ** Pre-Conditions: prompt must make sense and be a valid string, min
 **     must be lesser than or equal to max
 ** Post-Conditions: Returns positive integer number given by the user
 **     within range
 *********************************************************************/ 
int get_int_bounded(string prompt, int min, int max)
{
    string input;
    int num;
    cout << prompt;
    getline(cin, input);
    while (1) 
    {
        while (!is_int(input))
        {
            cout << "Input must be a number : ";
            getline(cin, input);
        }
        num = stoi(input);
        if (num < min || num > max)
        {
            cout << "Number must be between " << min << " and " << max << " : ";
        }
        else
        {
            break;
        }
    }
    return num;
}

/********************************************************************* 
 ** Function: is_int
 ** Description: Checks wether string can be converted to integer
 ** Parameters: string
 ** Pre-Conditions: s must be a string
 ** Post-Conditions: Returns boolean true or false based on wether s is
 **     a positive integer or not
 *********************************************************************/ 
bool is_int(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) > '9' || s.at(i) < '0')
        {
            return false;
        }
    }
    return true;
}

/********************************************************************* 
 ** Function: execute_option
 ** Description: Does a different sort or exits based on option value
 ** Parameters: budget *, int, int
 ** Pre-Conditions: budgets_index must be in range of budgets_array
 ** Post-Conditions: Performs proper task based on option and terminates
 *********************************************************************/ 
void execute_option(budget *budgets_array, int budgets_index, int option)
{
    if (option == 1)
    {
        category_sort(budgets_array[budgets_index]);
    }
    else if (option == 2)
    {
        date_sort(budgets_array[budgets_index]);
    }
    else if (option == 3)
    {
        dollar_sort(budgets_array[budgets_index]);
    }
    else
    {
        cout << "Quit - Exiting program..." << endl;
        exit(0);
    }
}

/********************************************************************* 
 ** Function: print_or_write
 ** Description: Gets choice from user to print info to screen or write
 **     to file, then does that
 ** Parameters: budget *, int
 ** Pre-Conditions: budgets_index must be in range of budgets_array
 ** Post-Conditions: Performs proper task based on choice and terminates
 *********************************************************************/ 
void print_or_write(budget *budgets_array, int budgets_index)
{
    int choice = choose_print_or_write();
    if (choice == 1)
    {
        print_to_screen(budgets_array[budgets_index]);
    }
    else
    {
        write_to_file(budgets_array[budgets_index]);
    }
}

/********************************************************************* 
 ** Function: delete_info
 ** Description: Deletes the arrays and their associated pointers
 ** Parameters: user **, budget **, int
 ** Pre-Conditions: *u and *b must be arrays
 ** Post-Conditions: Frees all necessary memory
 *********************************************************************/ 
void delete_info(user** u, budget** b, int n)
{
    cout << "Freeing array pointers..." << endl;
    delete [] *b;
    delete [] *u;
    *b = nullptr;
    *u = nullptr;
}

/********************************************************************* 
 ** Function: run_program
 ** Description: Does all parts of program besides initialization and
 **     memory freeing
 ** Parameters: user *, budget *, int 
 ** Pre-Conditions: users_array and budgets_array must be filled with
 **     correct information. Count must be the correct number of elements
 **     in each array.
 ** Post-Conditions: Performs all required tasks of program
 *********************************************************************/ 
void run_program(user *users_array, budget *budgets_array, int count)
{
    int user_id = user_login(users_array, budgets_array, count);
    int budgets_index;
    for (int i = 0; i < count; i++)
    {
        if (budgets_array[i].id == user_id)
        {
            cout << i << endl;
            budgets_index = i;
        }
    }
    int option = get_option();
    execute_option(budgets_array, budgets_index, option);
    print_or_write(budgets_array, budgets_index);
}