#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct user
{
    string name;
    long id;
    string password;
};

struct budget
{
    int id;
    float balance;
    int num_transactions;
    struct transaction *t;
};

struct transaction
{
    float amount;
    string date;
    string category;
    string description;
};

void check_valid_arguments(int, char * [], string &, string &);
void check_file_opens(string);

user* create_users_array(int &, string);
budget* create_budgets_array(int, string);

int get_int(string);
int get_int_bounded(string, int, int);
bool is_int(string);

int user_login_id(user*, int);
bool user_login_pwd(user*, int, int);
int user_login(user*, budget*, int);

int get_option();

void category_sort(budget &);
void date_sort(budget &);
void dollar_sort(budget &);
void swap(int, int, budget &);

int choose_print_or_write();
void print_to_screen(budget);
void write_to_file(budget);

budget* create_budgets(int);
void get_budget_data(budget*, int, ifstream &);
transaction* create_transaction(int);
void get_transaction_data(transaction*, int, ifstream &);
void delete_info(user**, budget**, int);

int main(int argc, char *argv[])
{
    string users_file;
    string budgets_file;
    check_valid_arguments(argc, argv, users_file, budgets_file);
    int count;
    user *users_array = create_users_array(count, users_file);
    budget *budgets_array = create_budgets_array(count, budgets_file);
    int user_id = user_login(users_array, budgets_array, count);
    int budgets_index = 666;
    for (int i = 0; i < count; i++)
    {
        if (budgets_array[i].id == user_id)
        {
            cout << i << endl;
            budgets_index = i;
        }
    }
    int option = get_option();
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
    int choice = choose_print_or_write();
    if (choice == 1)
    {
        print_to_screen(budgets_array[budgets_index]);
    }
    else
    {
        write_to_file(budgets_array[budgets_index]);
    }
    return 0;
}

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

budget* create_budgets_array(int count, string budgets_file)
{
    ifstream budget_text_in;
    budget_text_in.open(budgets_file);
    budget_text_in >> count;
    budget *budget_array;
    budget_array = new budget [count];
    for (int i = 0; i < count; i++)
    {
        budget_text_in >> budget_array[i].id;
        budget_text_in >> budget_array[i].balance;
        budget_text_in >> budget_array[i].num_transactions;
        budget_array[i].t = new transaction [budget_array[i].num_transactions];
        for (int j = 0; j < budget_array[i].num_transactions; j++)
        {
            budget_text_in >> budget_array[i].t[j].date;
            budget_text_in >> budget_array[i].t[j].amount;
            budget_text_in >> budget_array[i].t[j].description;
            budget_text_in >> budget_array[i].t[j].category;
        }
    }
    budget_text_in.close();
    return budget_array;
}

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

bool user_login_pwd(user *users_array, int count, int index)
{
    cout << "Please enter your password : ";
    string password;
    getline(cin, password);
    for (int tries = 1; tries < 3; tries++)
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

int user_login(user *users_array, budget *budgets_array, int count)
{
    int users_array_index = user_login_id(users_array, count);
    if (!user_login_pwd(users_array, count, users_array_index))
    {
        exit(1);
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

void category_sort(budget &b)
{
    for (int i = 0; i < b.num_transactions - 1; i++)
    {
        for(int j = 0; j < b.num_transactions - i -1; j++)
        {
            if (b.t[j].category.at(0) > b.t[j+1].category.at(0))
            {
                swap(j, j+1, b);
            }
        }
    }
}

void date_sort(budget &b)
{
    int n = b.num_transactions;
    int *date_raw = new int[n];
    for (int i = 0; i < n; i++)
    {
        int yy = stoi(b.t[i].date.substr(6,9));
        int mm = stoi(b.t[i].date.substr(0,1));
        int dd = stoi(b.t[i].date.substr(3,4));
        date_raw[i] = (yy * pow(10, 4)) + (mm * pow(10, 2)) + (dd);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int year = date_raw[j];
            int year_next = date_raw[j+1];
            if (year > year_next)
            {
                swap(j, j+1, b);
                int swap_raw = date_raw[j];
                date_raw[j] = date_raw[j+1];
                date_raw[j+1] = swap_raw;
            }
        }
    }
    delete [] date_raw;
}

void dollar_sort(budget &b)
{
    for (int i = 0; i < b.num_transactions - 1; i++)
    {
        for (int j = 0; j < b.num_transactions - i - 1; j++)
        {
            if (b.t[j].amount > b.t[j+1].amount)
            {
                swap(j, j+1, b);
            }
        }
    }
}

void swap(int a, int b, budget &budget)
{
    transaction swap = budget.t[a];
    budget.t[a] = budget.t[b];
    budget.t[b] = swap;
}

int choose_print_or_write()
{
    cout << "Choose one of the following options: " << endl;
    cout << "    1. Print budget to screen" << endl;
    cout << "    2. Save budget to text file" << endl;
    int option = get_int_bounded("", 1, 2);
    cout << endl << endl << "--Option " << option << " Selected--" << endl;
    return option;
}

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

void write_to_file(budget b)
{
    fstream file;
    cout << "Enter your desired file name : ";
    string input;
    getline(cin, input);
    input.append(".txt");
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
}

