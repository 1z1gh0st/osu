#include <iostream>

using namespace std;

void print_towers(int** b, int rows)
{
	for (int row = 0; row < rows; row++)	
	{
		for (int col = 0; col < 3; col++)
		{
			cout << b[row][col]; 
		}
		cout << endl;
	}
	cout << "---" << endl;
}

/*void towers(int disk_count, int b[][3], int target_col, int destination_col, int spare)
{
	if (disk_count > 0)
	{
		towers(disk_count - 1, b, target_col, spare, destination_col);
			
		print_towers(b);	
	}
}*/

int** create_array(int rows)
{
	int** ret;
	ret = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		ret[i] = 0;
	}
	return ret;
}

void delete_array(int*** ptr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete [] *ptr[i];
	}
	delete [] *ptr; 
	*ptr = NULL;
}

int main(int argc, char* argv[]) 
{
	int num = 0;
	if (argc > 1)
	{
		num = atoi(argv[1]);
	}
	int** array = create_array(num);

//	print_towers(array, num);
	delete_array(&array, num);
	return 0;
}

