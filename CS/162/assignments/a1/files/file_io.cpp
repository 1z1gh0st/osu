#include "./a1_header.h"

/********************************************************************* 
 ** Function: check_file_opens
 ** Description: Tries to open file of a file name
 ** Parameters: string
 ** Pre-Conditions: file_name must be a string
 ** Post-Conditions: Program should exit if file does not open, otherwise
 **     the function will terminate
 *********************************************************************/ 
void check_file_opens(string file_name)
{
    ifstream file_in;
    file_in.open(file_name);
    if (!file_in.is_open())
    {
        cout << "File " << file_name << " failed to open. Exiting program..." << endl;
        exit(1);
    }
}

/********************************************************************* 
 ** Function: create_users_array
 ** Description: Sorts transaction array alphabetically by category
 ** Parameters: budget &
 ** Pre-Conditions: Budget must have a transactions array initialized,
 **     and it must be associated with the correct user
 ** Post-Conditions: b should be sorted by category alphabetically after
 **     this function runs
 *********************************************************************/ 
user* create_users_array(int &count, string users_file)
{
    ifstream user_text_in;
    user_text_in.open(users_file);
    user_text_in >> count;
    user *users_array;
    users_array = new user [count];
    for (int i = 0; i < count; i++)
    {
        user_text_in >> users_array[i].name;
        user_text_in >> users_array[i].id;
        user_text_in >> users_array[i].password;
    }
    user_text_in.close();
    return users_array;
}

/********************************************************************* 
 ** Function: create_budgets
 ** Description: Allocates memory for array of budgets of size count
 ** Parameters: int
 ** Pre-Conditions: Count must be the correct number of budgets in
 **     the provided txt file
 ** Post-Conditions: Should return array of budgets with size count
 *********************************************************************/ 
budget* create_budgets(int count)
{
    return new budget [count];
}

/********************************************************************* 
 ** Function: get_budget_data
 ** Description: Imports data from open file to budget array
 ** Parameters: budget *, int, ifstream &
 ** Pre-Conditions: Count must be the correct number of budgets in
 **     the provided txt file, budget_array must be initialized, and
 **     budget_text_in must have correct file open with its cursor past
 **     the initial number
 ** Post-Conditions: Budgets array should be filled with information
 *********************************************************************/ 
void get_budget_data(budget *budget_array, int count, ifstream &budget_text_in)
{
    for (int i = 0; i < count; i++)
    {
        budget_text_in >> budget_array[i].id;
        budget_text_in >> budget_array[i].balance;
        budget_text_in >> budget_array[i].num_transactions;
        budget_array[i].t = create_transaction(budget_array[i].num_transactions);
        for (int j = 0; j < budget_array[i].num_transactions; j++)
        {
            get_transaction_data(budget_array[i].t, j, budget_text_in);
        }
    }
}

/********************************************************************* 
 ** Function: create_transaction
 ** Description: Allocates memory for array of transactions of size n
 ** Parameters: int
 ** Pre-Conditions: Int must be the correct number of budgets in
 **     the provided txt file
 ** Post-Conditions: Should return array of transactions with size n
 *********************************************************************/ 
transaction* create_transaction(int n)
{
    return new transaction [n];
}

/********************************************************************* 
 ** Function: get_transaction_data
 ** Description: Imports data from open file to transaction array at 1 index
 ** Parameters: transaction *, int, ifstream &
 ** Pre-Conditions: J must be the correct index in t for the next item
 **     in the array, t array must be initialized, and budget_text_in
 **      must have correct file open with its cursor in correct posiition
 ** Post-Conditions: Transaction array[j] should be filled with information
 *********************************************************************/ 
void get_transaction_data(transaction *t, int j, ifstream &budget_text_in)
{
    budget_text_in >> t[j].date;
    budget_text_in >> t[j].amount;
    budget_text_in >> t[j].description;
    budget_text_in >> t[j].category;
}

/********************************************************************* 
 ** Function: create_budgets_array
 ** Description: Runs functions to create a complete budget array
 ** Parameters: int, string
 ** Pre-Conditions: Count must be the correct number of budgets in txt
 **     file, budgets_file must be a valid filename for a properly
 **     formatted budget file
 ** Post-Conditions: Should return a budget array full of information
 *********************************************************************/ 
budget* create_budgets_array(int count, string budgets_file)
{
    ifstream budget_text_in;
    budget_text_in.open(budgets_file);
    budget_text_in >> count;
    budget *budget_array = create_budgets(count);
    get_budget_data(budget_array, count, budget_text_in);
    budget_text_in.close();
    return budget_array;
}

/********************************************************************* 
 ** Function: write_to_file
 ** Description: Writes sorted budget to file of name given by input
 ** Parameters: budget
 ** Pre-Conditions: B must be valid budget with transactions sorted
 **     already
 ** Post-Conditions: A file should be written with the correct information
 *********************************************************************/ 
void write_to_file(budget b)
{
    fstream file;
    cout << "Enter your desired file name : ";
    string input;
    getline(cin, input);
    file.open(input, fstream::out);
    int n = b.num_transactions;
    for (int i = 0; i < n; i++)
    {
        file << setw(7) << "Date: " << setw(11) << b.t[i].date;
        file << setw(11) << "| Amount: " << setw(10) << b.t[i].amount;
        file << setw(17) << "| Description: " << setw(22) << b.t[i].description;
        file << setw(13) << "| Category: " << setw(17) << b.t[i].category;
        file << endl;
    }
    file.close();
}
