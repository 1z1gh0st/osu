#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int command_line_arg(char *[], int);

void fix_arg_range(int &, int &, int &);

void failed_command_line_argumnets(int &, int &, int &);

bool is_int(string);

int get_int(int, int);

int ** create_board(int, int);

void print_board(int **, int, int);

void one_player(int **, int, int);

void two_player(int **, int, int);

void player_move(int **, int, int, int);

void computer_move(int **, int, int);

bool print_winner(int);

int check_vertical(int **, int , int, int, int);

int check_horizontal(int **, int , int, int, int);

int check_positive_diagonal(int **, int , int, int, int);

int check_negative_diagonal(int **, int , int, int, int);

int check_all_directions(int **, int , int, int, int);

int winner(int **, int, int);

int main(int argc, char* argv[])
{
    int players = 0;
    int columns = 0;
    int rows = 0;
	if (argc == 4)
	{
        players = command_line_arg(argv, 1);
        columns = command_line_arg(argv, 2);
        rows = command_line_arg(argv, 3);
        fix_arg_range(players, columns, rows);
	}
    else
    {
        failed_command_line_argumnets(players, columns, rows);
    }
    int **board = create_board(rows, columns);
    print_board(board, rows, columns);
    if (players == 1)
    {
        one_player(board, rows, columns);
    }
    else
    {
        two_player(board, rows, columns);
    }
    for (int i = 0; i < rows; i++)
    {
        delete [] board[i];
    }
    delete [] board;
    return 0;
}

/******************************************************************** 
 ** Function: command_line_arg 
 ** Description: Gets command line argument as integer or demands user input integer
 ** Parameters: char *argv[], int num
 ** Pre-Conditions: argv[num] must not be out of range
 ** Post-Conditions: Should return integer number based on command line argument
 ********************************************************************/
int command_line_arg(char *argv[], int num)
{
    for (int i = 0; i < strlen(argv[num]); i++)
    {
        if (argv[num][i] < 48 || argv[num][i] > 57)
        {
            cout << "Argument " << num << " is not a positive integer." << endl;
            if (num == 1)
            {
                cout << "1 or 2 players? : ";
                return get_int(1, 2);
            }
            else if (num == 2)
            {
                cout << "Number of columns? : ";
                return get_int(1, 20);
            }
            else
            {
                cout << "Number of rows? : ";
                return get_int(1, 20);
            }
        }
    }
    return atoi(argv[num]);
}

/******************************************************************** 
 ** Function: fix_arg_range 
 ** Description: Ensures that all three variables are within proper ranges
 ** Parameters: int &players, int &columns, int &rows
 ** Pre-Conditions: all arguments must be valid int addresses
 ** Post-Conditions: All three variables should be within proper range
 ********************************************************************/
void fix_arg_range(int &players, int &columns, int &rows)
{
    if (players < 1 || players > 2)
    {
        cout << "Error. Must have 1 or 2 players." << endl;
        players = get_int(1, 2);
    }
    if (columns < 1 || columns > 20)
    {
        cout << "Error. Must have between 1 and 20 columns." << endl;
        columns = get_int(1, 20);
    }
    if (rows < 1 || rows > 20)
    {
        cout << "Error. Must have between 1 and 20 rows." << endl;
        columns = get_int(1, 20);
    }
}

/******************************************************************** 
 ** Function: failed_command_line_arguments 
 ** Description: Gets valid input for players, columns and rows
 ** Parameters: int &players, int &columns, int &rows
 ** Pre-Conditions: all arguments must be valid int addresses
 ** Post-Conditions: All three variables should be given valid user input value
 ********************************************************************/
void failed_command_line_argumnets(int &players, int &columns, int &rows)
{
    cout << "Exactly four arguments required:" << endl;
    cout << "    [program name] [player count] [columns] [rows]" << endl;
    cout << "Enter number of players : ";
    players = get_int(1, 2);
    cout << "Enter number of columns : ";
    columns = get_int(1, 20);
    cout << "Enter nubmer of rows : ";
    rows = get_int(1, 20);
}

/******************************************************************** 
 ** Function: is_int 
 ** Description: Determines if a string is a positive integer number or not
 ** Parameters: string input
 ** Pre-Conditions: input must be a valid std::string
 ** Post-Conditions: Should return true if the string is a positive integer number
 ********************************************************************/
bool is_int(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] < 48 || input[i] > 57)
        {
            return false;
        }
    }
    return true;
}

/******************************************************************** 
 ** Function: get_int 
 ** Description: Gets a valid integer input from user between min and max inclusive
 ** Parameters: int min, int max
 ** Pre-Conditions: min and max must be valid integers
 ** Post-Conditions: Should return true if the string is a positive integer number
 ********************************************************************/
int get_int(int min, int max)
{
    string input = "";
    getline(cin, input);
    while (!is_int(input))
    {
        cout << "Input must be an integer : ";
        getline(cin, input);
    }
    int num = atoi(input.c_str());
    while (num < min || num > max)
    {
        cout << "Input must be between " << min << " and " << max << " : ";
        getline(cin, input);
        while (!is_int(input))
        {
            cout << "Input must be an integer : ";
            getline(cin, input);
        }
        num = atoi(input.c_str());
    }
    return num;
}

/******************************************************************** 
 ** Function: create_board 
 ** Description: Creates a 2D array for the game board given width and height
 ** Parameters: int rows, int columns
 ** Pre-Conditions: rows and columns must be valid integers
 ** Post-Conditions: Should return a 2D array full of zero of the correct size
 ********************************************************************/
int ** create_board(int rows, int columns)
{
    int **board;
	board = new int * [rows];
	for (int i = 0; i < rows; i++)
	{
		board[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = 0;
        }
	}
	return board;
}

/******************************************************************** 
 ** Function: print_board 
 ** Description: Prints out the board in a nice looking with labels
 **     on each column and with X's on 1's and O's on 2's
 ** Parameters: int **board, int rows, int columns
 ** Pre-Conditions: int **board must be a rows x columns 2D matrix,
 **     and rows and columns must be valid integers
 ** Post-Conditions: Should print board nicely
 ********************************************************************/
void print_board(int **board, int rows, int columns)
{
    cout << endl << endl << "  ";
    for (int i = 0; i < columns; i++)
    {
        cout << i + 1 << "   ";
    }
    cout << endl;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            if (board[row][col] == 1)
            {
                cout << "| X ";
            }
            else if (board[row][col] == 2)
            {
                cout << "| O ";
            }
            else
            {
                cout << "|   ";
            }
        }
        cout << "|" << endl;
    }
}

/******************************************************************** 
 ** Function: one_player 
 ** Description: Runs game loop for one player mode
 ** Parameters: int **board, int rows, int columns
 ** Pre-Conditions: board must be valid 2D array of size rows x columns
 ** Post-Conditions: Should end upon win conditions and keep going
 **     otherwise
 ********************************************************************/
void one_player(int **board, int rows, int columns)
{
    // int input = get_int(between 0 and 1);
    bool first_move = false;
    bool game_over = false;
    cout << "Would you like to go first?" << endl;
    cout << "    (0) No" << endl;
    cout << "    (1) Yes" << endl;
    cout << " > ";
    first_move = (bool)get_int(0, 1);
    if (first_move)
    {
        player_move(board, rows, columns, 1);
        print_board(board, rows, columns);
    }
    while (1)
    {
        int win = 0;
        computer_move(board, rows, columns);
        print_board(board, rows, columns);
        win = winner(board, rows, columns);
        if (print_winner(win))
        {
            break;
        }
        player_move(board, rows, columns, 1);        
        print_board(board, rows, columns);
        win = winner(board, rows, columns);
        if (print_winner(win))
        {
            break;
        }
    }
}

/******************************************************************** 
 ** Function: two_player 
 ** Description: Runs game loop for two player mode
 ** Parameters: int **board, int rows, int columns
 ** Pre-Conditions: board must be valid 2D array of size rows x columns
 ** Post-Conditions: Should end upon win conditions and keep going
 **     otherwise
 ********************************************************************/
void two_player(int **board, int rows, int columns)
{
    bool game_over = false;
    while (1)
    {
        int win = 0;
        cout << "Player 1. ";
        player_move(board, rows, columns, 1);
        print_board(board, rows, columns);
        win = winner(board, rows, columns);
        if (print_winner(win))
        {
            break;
        }
        cout << "Player 2. ";
        player_move(board, rows, columns, 2);
        print_board(board, rows, columns);
        win = winner(board, rows, columns);
        if (print_winner(win))
        {
            break;
        }
    }
}

/******************************************************************** 
 ** Function: player_move 
 ** Description: Gets input column and places correct number in lowermost
 **     empty spot in the column
** Parameters: int **board, int rows, int columns, int players
 ** Pre-Conditions: rows, columns, and player must be valid integers,
 **     board must be a valid 2D array
 ** Post-Conditions: Should get exactly one move and terminate
 ********************************************************************/
void player_move(int **board, int rows, int columns, int player)
{
    int column_chosen = 0;
    bool done = false;
    cout << "In which column would you like to place a piece? : ";
    column_chosen = get_int(1, columns);
    do
    {
        for (int i = rows - 1; i >= 0; i--)
        {
            if (board[i][column_chosen - 1] == 0)
            {
                board[i][column_chosen - 1] = player;
                done = true;
                break;
            }
            else if (board[0][column_chosen - 1] != 0)
            {
                cout << "Column full, please select a different column : ";
                column_chosen = get_int(1, columns);
                break;
            }
        }
    } while (!done);
}

/******************************************************************** 
 ** Function: computer_move 
 ** Description: Computer chooses a random column and puts a piece down
 **     there
 ** Parameters: int **board, int rows, int columns
 ** Pre-Conditions: rows, columns, and player must be valid integers,
 **     board must be a valid 2D array
 ** Post-Conditions: Should do exactly one random move and terminate
 ********************************************************************/
void computer_move(int **board, int rows, int columns)
{
    int column_chosen = 0;
    bool done = false;
    srand(time(NULL));
    column_chosen = rand() % columns;
    do
    {
        for (int i = rows - 1; i >= 0; i--)
        {
            if (board[i][column_chosen] == 0)
            {
                board[i][column_chosen] = 2;
                done = true;
                break;
            }
            else if (board[0][column_chosen] != 0)
            {
                column_chosen = rand() % columns;
                break;
            }
        }
    } while (!done);
}

/******************************************************************** 
 ** Function: print_winner 
 ** Description: Prints out win conditions and returns true or false if
 **     the game is over
 ** Parameters: int win
 ** Pre-Conditions: t win must be a valid integer
 ** Post-Conditions: Should return false if game is not over, or true if
 **     game is over
 ********************************************************************/
bool print_winner(int win)
{
    if (win != 0)
    {
        if (win < 3)
        {
            cout << "Player " << win << " has won!" << endl;
        }
        else
        {
            cout << "Tie game." << endl;
        }
        return true;
    }
    else
    {
        return false;
    }
}

/******************************************************************** 
 ** Function: check_vertical 
 ** Description: From a given a_ij checks if there are four consecutive numbers downwards
 ** Parameters: int **board, int rows, int columns, int i, int j
 ** Pre-Conditions: board[i][j] must be within range
 ** Post-Conditions: Properly determines if win conditions are met
 ********************************************************************/
int check_vertical(int **board, int rows, int columns, int i, int j)
{
    int k = 1;
    int consecutive = 1;
    // Detect vertical wins
    while (k < 5 && (i + k) < rows)
    {
        if (board[i][j] == board[i + k][j])
        {
            k++;
            consecutive++;
            if (consecutive == 4)
            {
                return board[i][j];
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

/******************************************************************** 
 ** Function: check_horizontal 
 ** Description: From a given a_ij checks if there are four consecutive numbers rightwards
 ** Parameters: int **board, int rows, int columns, int i, int j
 ** Pre-Conditions: board[i][j] must be within range
 ** Post-Conditions: Properly determines if win conditions are met
 ********************************************************************/
int check_horizontal(int **board, int rows, int columns, int i, int j)
{
    int k = 1;
    int consecutive = 1;
    // Detect horizontal wins
    while (k < 5 && (j + k) < columns)
    {
        if (board[i][j] == board[i][j + k])
        {
            k++;
            consecutive++;
            if (consecutive == 4)
            {
                return board[i][j];
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

/******************************************************************** 
 ** Function: check_positivie_diagonal
 ** Description: From a given a_ij checks if there are four consecutive numbers in the up-right diagonal direction
 ** Parameters: int **board, int rows, int columns, int i, int j
 ** Pre-Conditions: board[i][j] must be within range
 ** Post-Conditions: Properly determines if win conditions are met
 ********************************************************************/
int check_positive_diagonal(int **board, int rows, int columns, int i, int j)
{
    int k = 1;
    int consecutive = 1;
    // Detect positive diagonal wins
    while (k < 5 && (i - k) >= 0 && (j + k) < columns)
    {
        if (board[i][j] == board[i - k][j + k])
        {
            k++;
            consecutive++;
            if (consecutive == 4)
            {
                return board[i][j];
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

/******************************************************************** 
 ** Function: check_negative_diagonal 
 ** Description: From a given a_ij checks if there are four consecutive numbers in the down-right diagonal direction
 ** Parameters: int **board, int rows, int columns, int i, int j
 ** Pre-Conditions: board[i][j] must be within range
 ** Post-Conditions: Properly determines if win conditions are met
 ********************************************************************/
int check_negative_diagonal(int **board, int rows, int columns, int i, int j)
{
    int k = 1;
    int consecutive = 1;
    // Detect negative diagonal wins
    while (k < 5 && (i + k) < rows && (j + k) < columns)
    {
        if (board[i][j] == board[i + k][j + k])
        {
            k++;
            consecutive++;
            if (consecutive == 4)
            {
                return board[i][j];
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

/******************************************************************** 
 ** Function: check_all_directions 
 ** Description: From a given a_ij checks if there are four consecutive numbers in any direction
 ** Parameters: int **board, int rows, int columns, int i, int j
 ** Pre-Conditions: board[i][j] must be within range
 ** Post-Conditions: Returns which number is the winner or 0 if win conditions are not met
 ********************************************************************/
int check_all_directions(int **board, int rows, int columns, int i, int j)
{
    int vert = check_vertical(board, rows, columns, i, j);
    if (vert != 0)
    {
        return vert;
    }
    int horiz = check_horizontal(board, rows, columns, i, j);
    if (horiz != 0)
    {
        return horiz;
    }
    int diag_1 = check_positive_diagonal(board, rows, columns, i, j);
    if (diag_1 != 0)
    {
        return diag_1;
    }
    int diag_2 = check_negative_diagonal(board, rows, columns, i, j);
    if (diag_2 != 0)
    {
        return diag_2;
    }
    return 0;
}

/******************************************************************** 
 ** Function: winner 
 ** Description: Computer chooses a random column and puts a piece down
 **     there
 ** Parameters: int **board, int rows, int columns
 ** Pre-Conditions: rows, columns, and player must be valid integers,
 **     board must be a valid 2D array
 ** Post-Conditions: Should do exactly one random move and terminate
 ********************************************************************/
int winner(int **board, int rows, int columns)
{
    int empty_spaces = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j] != 0)
            {
                int winner = check_all_directions(board, rows, columns, i, j);
                if (winner != 0)
                {
                    return winner;
                }
            }
            else if (board[i][j] == 0)
            {
                empty_spaces++;
            }
        }
    }
    if (empty_spaces == 0)
    {
        return 3;
    }
    return 0;
}
