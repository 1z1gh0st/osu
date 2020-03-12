/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream>

using namespace std;

int main(){

	int x=3, y;
	char myAnswer;

	y = x;
	bool again = true;
	while(again) {
		cout << "y is set to: " << y << endl;

		cout << "Please input a number: ";
		cin >> y;
		if(x > y) {
			cout << "X is greater than Y" << endl;
		}
		else if (x == y) {
			cout << "X is equal to Y" << endl;
		}
		else {
			cout << "X is less than Y" << endl;
		}
		cout << "would you like to input another number? yes(1), no(0)" << endl;
		cin >> again;
	}
	for(int x = 0; x < 10; x++) {
		cout << x << endl;
	}
	cout << "What number would you like to find the factorial for? " << endl;
	int num = 0;
	cin >> num;
	int result = num; 
	for(int x = num; x > 1; x--) {
		result *= x - 1;
	}
	cout << num << " factorial is " << result << endl; 
	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myAnswer;
	if(myAnswer == 'y' )
		cout << "YAY" << endl;
	else
		cout << "YOU WILL SOON!" << endl;

	return 0;
}
