#include "./file_io.h"

student* create_student_db(int n)
{
	student *a = new student [n];
	return a;
}

void get_student_db_info(student *a, int n, fstream &file)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << endl;
		file >> a[i].id;
		file >> a[i].fname;
		file >> a[i].lname;
		file >> a[i].major;
	}
	file.close();
}

void sort_id(student *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j].id > a[j+1].id)
			{
				student swap = a[j];
				a[j] = a[j+1];
				a[j+1] = swap;
			}
		}
		
	}
}

void sort_lname(student *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j].lname.at(0) > a[j+1].lname.at(0))
			{
				student swap = a[j];
				a[j] = a[j+1];
				a[j+1] = swap;
			}
		}
	}
}

void delete_array(student **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete [] a[i];
	}
	delete [] a;
}
