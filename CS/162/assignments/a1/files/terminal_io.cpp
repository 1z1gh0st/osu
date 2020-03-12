#include "./a1_header.h"

/********************************************************************* 
 ** Function: user_login_id
 ** Description: Demands user input an ID, and if it is not found the
 **     entire program terminates
 ** Parameters: user *, int
 ** Pre-Conditions: users_array must be an array, count must indicate
 **     number of entries in array
 ** Post-Conditions: Returns correct ID number if entered, or exists
 **     after three tries
 *********************************************************************/ 
int user_login_id(user *users_array, int count)
{
    long user_id_in = get_int("Please enter your user ID : ");
    long user_id = 0;
    int users_array_index;
    int tries = 1;
    for (int tries = 1; tries < 3; tries++)
    {
        for (int index = 0; index < count; index++)
        {
            if (users_array[index].id == user_id_in)
            {
                return index;
            }
        }
        user_id_in = get_int("User ID not found. Please try again : ");
    }
    cout << "Failed. Too many attempts. Exiting program..." << endl;
    exit(1);
}

/********************************************************************* 
 ** Function: user_login_pwd
 ** Description: Demands user input a password, and returns boolean
 **     if the login attempt is successful or not
 ** Parameters: user *, int, int
 ** Pre-Conditions: users_array must be an array, count must indicate
 **     number of entries in array
 ** Post-Conditions: Allows for three attempts and returns true if one
 **     is successful or false if none are successful
 *********************************************************************/ 
bool user_login_pwd(user *users_array, int count, int index)
{
    cout << "Please enter your password : ";
    string password;
    getline(cin, password);
    for (int tries = 1; tries <= 3; tries++)
    {
        if (password == users_array[index].password)
        {
            return true;
        }
        else
        {
            cout << "Incorrect password. Please try again : ";
            getline(cin, password);
        } 
    }
    return false;
}

/********************************************************************* 
 ** Function: user_login_pwd
 ** Description: Runs login functions, prints out information upon
 **     successful login, and returns the user id that was entered on
 **     successful login attempt
 ** Parameters: user *, budget *
 ** Pre-Conditions: users_array must be an array, count must indicate
 **     number of entries in array, and budgets_array must also be an
 **     array
 ** Post-Conditions: Returns user ID entered on successful login attempt
 *********************************************************************/ 
int user_login(user *users_array, budget *budgets_array, int count)
{
    int users_array_index = user_login_id(users_array, count);
    if (!user_login_pwd(users_array, count, users_array_index))
    {
        cout << "Too many attempts. Exiting program..." << endl;
        exit(0);
    }
    cout << "Correct password. Login successful." << endl << endl;
    int budgets_array_index;
    for (int i = 0; i < count; i++)
    {
        if (users_array[users_array_index].id == budgets_array[i].id)
        {
            budgets_array_index = i;
        }
    }
    cout << "Name: " << users_array[users_array_index].name << " | ";
    cout << "ID: " << users_array[users_array_index].id << " | ";
    cout << "Balance: $" << budgets_array[budgets_array_index].balance << endl << endl;
    return users_array[users_array_index].id;
}

/********************************************************************* 
 ** Function: get_option
 ** Description: Prints out menu of options, then demands input
 **     corrosponding to one of them
 ** Parameters: none
 ** Pre-Conditions: No conditions must be met to run this function
 ** Post-Conditions: Returns integer 1 - 4 depending on what the user
 **     picked
 *********************************************************************/ 
int get_option()
{
    cout << "Choose one of the following options: " << endl;
    cout << "    1. Sort transactions by category" << endl;
    cout << "    2. Sort transactions by date" << endl;
    cout << "    3. Sort transactions by dollar amount" << endl;
    cout << "    4. Quit the program" << endl;
    int option = get_int_bounded("", 1, 4);
    cout << endl << endl << "--Option " << option << " Selected--" << endl;
    return option;
}

/********************************************************************* 
 ** Function: choose_print_or_write
 ** Description: Prints out two options, and demands the user select one
 ** Parameters: none
 ** Pre-Conditions: No conditions must be met to run this function
 ** Post-Conditions: Returns integer 1 or 2 depending on what the user
 **     picked
 *********************************************************************/ 
int choose_print_or_write()
{
    cout << "Choose one of the following options: " << endl;
    cout << "    1. Print budget to screen" << endl;
    cout << "    2. Save budget to text file" << endl;
    int option = get_int_bounded("", 1, 2);
    cout << endl << endl << "--Option " << option << " Selected--" << endl;
    return option;
}

/********************************************************************* 
 ** Function: print_to_screen
 ** Description: Prints out sorted information from budget array
 ** Parameters: budget
 ** Pre-Conditions: Budget must already be sorted, and must be associated
 **     with the correct user
 ** Post-Conditions: Prints information as desired
 *********************************************************************/ 
void print_to_screen(budget b)
{
    int n = b.num_transactions;
    for (int i = 0; i < n; i++)
    {
        cout << setw(7) << "Date: " << setw(11) << b.t[i].date;
        cout << setw(11) << "| Amount: " << setw(10) << b.t[i].amount;
        cout << setw(17) << "| Description: " << setw(22) << b.t[i].description;
        cout << setw(13) << "| Category: " << setw(17) << b.t[i].category;
        cout << endl;
    }
}

