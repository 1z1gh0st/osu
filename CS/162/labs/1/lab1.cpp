#include "./mult_div.h"

bool is_valid_dimension(char *m, char *n)
{
	for (int i = 0; i < strlen(m); i++)
	{
		if (m[i] > '9' || m[i] < '0')
		{
			return false;
		}
	}
	for (int i = 0; i < strlen(n); i++)
	{
		if (n[i] > '9' || n[i] < '0')
		{
			return false;
		}
	}
	return true;
}

mult_div_values** create_array(int rows, int cols)
{
	mult_div_values **table;
	table = new mult_div_values *[rows];
	for (int i = 0; i < rows; i++)
	{
		table[i] = new mult_div_values[cols];
	}
	return table;
}

void set_values(mult_div_values **a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j].mult = (i + 1) * (j + 1);
			a[i][j].div = (i + 1.0) / (j + 1.0);
		}
	}
}

void delete_array(mult_div_values **a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		delete [] a[i];
	}
	delete [] a;
}
