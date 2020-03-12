#include "./a1_header.h"

/******************************************************
** Program: Budget Buddy
** Author: Philip Warton
** Date: 01/15/2020
** Description: Allows users to view/organize budgets
** Input: filename1, filename2, user ID, password,
**      sorting option, choice of viewing/saving, file
**      out name
** Output: Sorted budget as file or printed to screen
******************************************************/
int main(int argc, char *argv[])
{
    string users_file;
    string budgets_file;
    check_valid_arguments(argc, argv, users_file, budgets_file);
    int count;
    user *users_array = create_users_array(count, users_file);
    budget *budgets_array = create_budgets_array(count, budgets_file);
    bool repeat = false;
    do 
    {
        run_program(users_array, budgets_array, count);
        repeat = get_int_bounded("Run again?\n    0. no\n    1. yes\n", 0, 1);
    }
    while (repeat);
    cout << "Freeing memory" << endl;
    for (int j = 0; j < count; j++)
    {
        cout << "Freeing transaction ptrs..." << endl;
        delete [] budgets_array[j].t;
    }
    delete_info(&users_array, &budgets_array, count);
    return 0;
}
