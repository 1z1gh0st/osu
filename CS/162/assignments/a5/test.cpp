#include "linked_list.h"
#include "input_handler.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Testing the list
	char yn[] = {'y', 'n', 'Y', 'N'}; // Valid user inputs
	char ad[] = {'a', 'd', 'A', 'D'};
	Linked_List l;
	char response;
	do {
		cout << "Please enter a number: ";
		int num_in = Input_Handler::get_integer();
		l.push_back(num_in);
		cout << "Do you want another num(y or n): ";
		response = Input_Handler::get_specific_char(yn);
	} while (response == 'y' || response == 'Y');
	cout << "Sort ascending or descending (a or d)?";
	response = Input_Handler::get_specific_char(ad);
	if (response == 'a' || response == 'A') {
		l.sort_ascending();
	} else {
		l.sort_descending();
	}
	l.print();
	cout << "Primes: " << l.prime_count() << endl;
	return 0;
}
