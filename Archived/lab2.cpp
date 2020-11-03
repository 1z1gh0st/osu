#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void power()
{
	int num = pow(2, 3);
	cout << "2^3 is: " << num << endl;
}

void my_random()
{
	int x;
	srand(time(NULL));

	x = rand();
	cout << x << endl;

	srand(time(NULL));

	x = rand();
	cout << x << endl;
}

void random_onetofive()
{
	srand(time(NULL));
	int x = rand() % 6;
	if (x == 0)
		cout << "Bummer, I'm a zero" << endl;
	else if ((x % 2) == 1)
	{
		cout << "I am odd" << endl;
		if (x == 1)
			cout << "I am one" << endl;
		else if (x == 3)
			cout << "Three" << endl;
		else
			cout << "literally five" << endl;
	}
	else
	{
		cout << "even mode activate" << endl;
		if (x == 2)
			cout << "the number two" << endl;
		else
			cout << "four" << endl;
	}
	cout << "Actual value of x: " << x << endl;

}

int main()
{
	power();
	my_random();
	random_onetofive();
	return 0;
}
