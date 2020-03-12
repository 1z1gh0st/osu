#include "./a1_header.h"

/********************************************************************* 
 ** Function: category_sort
 ** Description: Sorts transaction array alphabetically by category
 ** Parameters: budget &
 ** Pre-Conditions: Budget must have a transactions array initialized,
 **     and it must be associated with the correct user
 ** Post-Conditions: b should be sorted by category alphabetically after
 **     this function runs
 *********************************************************************/ 
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

/********************************************************************* 
 ** Function: convert_date
 ** Description: Takes date in normal form and eturns integer in the 
 **     form yyyymmdd
 ** Parameters: string
 ** Pre-Conditions: date must be in the form "mm/dd/yyyy" or else the 
 **     function does not work correctly
 ** Post-Conditions: Returns integer in the desired form 
 *********************************************************************/ 
int convert_date(string date)
{
    int yy = stoi(date.substr(6,9));
    int mm = stoi(date.substr(0,1));
    int dd = stoi(date.substr(3,4));
    return (yy * pow(10, 4)) + (mm * pow(10, 2)) + (dd);
}

/********************************************************************* 
 ** Function: date_sort
 ** Description: Sorts transaction array by date ascending
 ** Parameters: budget &
 ** Pre-Conditions: Budget must have a transactions array initialized,
 **     and it must be associated with the correct user
 ** Post-Conditions: b should be sorted by date ascending after
 **     this function runs
 *********************************************************************/ 
void date_sort(budget &b)
{
    int *date_num = new int[b.num_transactions];
    for (int i = 0; i < b.num_transactions; i++)
    {
        date_num[i] = convert_date(b.t[i].date);
    }
    for (int i = 0; i < b.num_transactions - 1; i++)
    {
        for (int j = 0; j < b.num_transactions - i - 1; j++)
        {
            int year = date_num[j];
            int year_next = date_num[j+1];
            if (year > year_next)
            {
                swap(j, j+1, b);
                int swap_num = date_num[j];
                date_num[j] = date_num[j+1];
                date_num[j+1] = swap_num;
            }
        }
    }
    delete [] date_num;
}

/********************************************************************* 
 ** Function: dollar_sort
 ** Description: Sorts transaction array by dollar amount ascending
 ** Parameters: budget &
 ** Pre-Conditions: Budget must have a transactions array initialized,
 **     and it must be associated with the correct user
 ** Post-Conditions: b should be sorted by dollar amount ascending after
 **     this function runs
 *********************************************************************/ 
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

/********************************************************************* 
 ** Function: swap
 ** Description: Swaps two transactions at indicies a and b
 ** Parameters: int, int, budget &
 ** Pre-Conditions: Budget must have a transactions array initialized,
 **     and it must be associated with the correct user, a and b must
 **     be in range of the budget.t
 ** Post-Conditions: b should have transactions at a and b swapped
 *********************************************************************/ 
void swap(int a, int b, budget &budget)
{
    transaction swap = budget.t[a];
    budget.t[a] = budget.t[b];
    budget.t[b] = swap;
}
