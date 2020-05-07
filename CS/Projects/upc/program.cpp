#include <iostream>
#include <cstdlib>
#include <string>
#include "stdlib.h"
using namespace std;
string remove_dashes(string s) {
	string result = "";
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '-' || s.at(i) == '_') {
			continue;
		} else {
			result += (s.at(i));
		}
	}
	return result;
}
int main(int argc, char * argv[]) {
	if (argc != 2) {
		cout << "Incorrect # of arguments" << endl;
		exit(1);
	} else {
		string input = argv[1];
		input = remove_dashes(input);
		if (input.length() != 12) {
			cout << "Incorrect UBC code length" << endl;
			exit(1);
		} else {
			unsigned long int result = 0;
			for (int i = 0; i < 12; i++) {
				if (i % 2 == 0) {result += (input.at(i) - '0') * 3;}
				else {result += input.at(i) - '0';}
			}
			cout << "Your UBC code " << input; 
			if (result % 10 == 0) { cout << " is valid." << endl;}
			else {cout<<" is not valid. "<<endl;}
		}
	}
}
