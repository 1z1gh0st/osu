#include "./file_io.h"

int main()
{
	string file_name = "inputs.txt";
	fstream file;
	file.open(file_name, fstream::in);
    if (!file.is_open())
    {
        cout << "File " << file_name << " failed to open. Exiting program..." << endl;
        exit(1);
    }
	int n = 0;
	file >> n;
	student *a = create_student_db(n);
	get_student_db_info(a, n, file);
	for (int i = 0; i < n; i++)
	{
		cout << a[i].id << " ";
		cout << a[i].fname << " ";
		cout << a[i].lname << " ";
		cout << a[i].major << "\n";
	}
	string input;
	cout << "Write the name of your output file : ";
	getline(cin, input);
	input.append(".txt");
	file.open(input, fstream::out);
	file << "ID SORT: \n";
	sort_id(a, n);
	for (int i = 0; i < n; i++)
	{
		file << a[i].id << " ";
		file << a[i].fname << " ";
		file << a[i].lname << " ";
		file << a[i].major << "\n";
	}
	file << "LAST NAME SORT: \n";
	sort_lname(a, n);
	for (int i = 0; i < n; i++)
	{
		file << a[i].id << " ";
		file << a[i].fname << " ";
		file << a[i].lname << " ";
		file << a[i].major << "\n";
	}
	file.close();
	return 0;
}