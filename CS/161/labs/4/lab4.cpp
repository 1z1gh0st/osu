#include <iostream>

using namespace std;

int a_to_i(char);
char i_to_a(int);

int main() {
	cout << "input a letter: ";
	char letter;
	cin >> letter;
	int asNum = a_to_i(letter);
	cout << asNum << endl;
	char asChar = i_to_a(asNum);
	cout << asChar << endl;
	return 0;
}

int a_to_i(char input) {
	return (int)input;
}

char i_to_a(int input) {
	return (char)input;
}
