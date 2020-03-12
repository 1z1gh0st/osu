#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int get_input(int min, int max, string message)
{
	int result;
	cout << message;
	cin >> result;
	while (result < min || result > max)
	{
		cout << "Please input a number between " << min << " and " << max << endl;
		cout << message;
		cin >> result;
	}
	return result;
}

string random_characters(int min, int max, int length_in)
{
	string result = "";
	for (int i = 0; i < length_in; i++)
	{
		int random_value = rand() % (max - min) + min;
		cout << random_value << ", ";
		result += random_value;
	}
	cout << result << endl;
	return result;
}

string generate_password()
{
	int pass_length = get_input(8, 32, "please enter password length: ");
	int letters = get_input(0, pass_length, "please enter # of desired letters: ");
	int pass_uppercase = get_input(0, letters, "please enter # of desired uppercase letters :");
	int lowercase = letters - pass_uppercase;
	int numbers = pass_length - letters;

	
	string upper = random_characters(65, 90, pass_uppercase);
	string lower = random_characters(97, 122, lowercase);
	string nums = random_characters(48, 57, numbers);

	string password = upper + lower + nums;
	return password;
}

int main()
{
	srand(time(NULL));
	string password = generate_password();
	cout << "Your password | " << password << endl;
	return 0;
}
