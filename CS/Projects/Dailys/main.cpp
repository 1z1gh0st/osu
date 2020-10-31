#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	bool passed = true;
	cout << "time of bed : ";
	getline(cin, input);
	int bedTime = 0;
	bedTime = stoi(input);	
	if (bedTime < 10 || bedTime > 12) {
		passed = false;	
	}
	cout << "brushed teeth count : ";
	getline(cin, input);
	int brushCount = stoi(input);
	if (brushCount != 3) {
		passed = false;
	}
	cout << "floss count : ";
	getline(cin, input);
	int flossCount = stoi(input);
	if (flossCount != 2) {
		passed = false;
	}
	cout << "minutes of excersize : ";
	getline(cin, input);
	int ex = stoi(input);
	if (ex < 15) {
		passed = false;
	}
	(passed) ? cout << "Yay u did basic human functions!!!" << endl : cout << "You did your best today, make tomorrow a good one. :)" << endl;
	cout << endl << endl << "goodnight. sweet dreams. sleep well." << endl << endl << endl;
	return 0;
}
