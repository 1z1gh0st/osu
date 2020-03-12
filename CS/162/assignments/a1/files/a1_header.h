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
void execute_option(budget*, int, int);
void run_program(user *, budget *, int);

void category_sort(budget &);
void date_sort(budget &);
void dollar_sort(budget &);
void swap(int, int, budget &);

int choose_print_or_write();
void print_to_screen(budget);
void write_to_file(budget);
void print_or_write(budget *, int);

// Required functions
budget* create_budgets(int);
void get_budget_data(budget*, int, ifstream &);
transaction* create_transaction(int);
void get_transaction_data(transaction*, int, ifstream &);
void delete_info(user**, budget**, int);