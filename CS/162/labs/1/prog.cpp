#include "mult_div.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		return 1;
	}
	if (!is_valid_dimension(argv[1], argv[2]))
	{
		return 1;
	}
	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);
	mult_div_values **table = create_array(rows, cols);
	set_values(table, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(5) << table[i][j].mult << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(5) << table[i][j].div << " ";
		}
		cout << endl;
	}
	delete_array(table, rows, cols);
	return 0;
}