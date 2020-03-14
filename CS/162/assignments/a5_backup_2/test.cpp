/******************************************************
** Program: test.cpp
** Author: Philip Warton
** Date: 03/14/2020
** Description: Main() function for Linked_List testing
** Input: none
** Output: none
******************************************************/

#include "linked_list.h"
#include "input_handler.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Testing the list
	char ad[] = {'a', 'd', 'A', 'D'};
	char yn[] = {'y', 'n', 'Y', 'N'}; // Valid user inputs
	Linked_List l;
	char response;
	do {
		// Get a number and add it to list
		cout << "Please enter a number: ";
		int num_in = Input_Handler::get_integer();
		l.push_back(num_in);
		// Get input for repeat
		cout << "Do you want another num(y or n): ";
		response = Input_Handler::get_specific_char(yn);
	} while (response == 'y' || response == 'Y');
	// Sorting input and sorting the lists
	cout << "Sort ascending or descending (a or d)?";
	response = Input_Handler::get_specific_char(ad);
	if (response == 'a' || response == 'A')
		l.sort_ascending();
	else
		l.sort_descending();
	l.print();
	// Counting primes
	cout << "Primes : " << l.prime_count() << endl;
	return 0;
}
