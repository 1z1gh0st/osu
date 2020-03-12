#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int my_variable = 0;

	int *my_pointer = &my_variable;

	cout << "The number: " << my_variable << endl;

	cout << "The addy: " << &my_variable << endl;

	cout << "The pointer: " << *my_pointer << endl;

	cout << "The point: " << my_pointer << endl;

	cout << "The addy Of the pointer: " << &my_pointer << endl;
	return 0;
}
