#include "assignment2_header.h"

int main()
{
    // Testing the functions here in main with test cases from design.

    cout << "Check Range (1, 9, 3): " << check_range(1, 9, 3) << endl;
    cout << "Check Range (1, 9, 12): " << check_range(1, 9, 12) << endl;
    cout << "Is Capital (A): " << is_capital('A') << endl;
    cout << "Is Capital (a): " << is_capital('a') << endl;
    cout << "Is Capital (7): " << is_capital('7') << endl;
    cout << "Is Even (2): " << is_even(2) << endl;
    cout << "Is Even (3): " << is_even(3) << endl;
    cout << "Is Odd (3): " << is_odd(3) << endl;
    cout << "Is Odd (2): " << is_odd(2) << endl;
    cout << "Equality Test (123, 123): " << equality_test(123, 123) << endl;
    cout << "Equality Test (123, 1234): " << equality_test(123, 1234) << endl;
    cout << "Is Int (123ABC): " << is_int("123ABC") << endl;
    cout << "Is Int (123): " << is_int("123") << endl;
    cout << "Numbers Present (This is a test. Testing, testing, 123.): " << numbers_present("This is a test. Testing, testing, 123.") << endl;
    cout << "Numbers Present (This is a test. Testing, testing, 1, 2, 3.): " << numbers_present("This is a test. Testing, testing, 1, 2, 3.") << endl;
    cout << "Numbers Present (This is a test. Testing, testing, one two three.): " << numbers_present("This is a test. Testing, testing, one two three.") << endl;
    cout << "Letters Present (10k): " << letters_present("10k") << endl;
    cout << "Letters Present (10,000): " << letters_present("10,000") << endl;
    cout << "Contains Substring (racecar, car): " << contains_sub_string("racecar", "car") << endl;
    cout << "Contains Substring (racecar, trace): " << contains_sub_string("racecar", "trace") << endl;
    cout << "Word Count (Three words here.): " << word_count("Three words here.") << endl;
    cout << "Word Count (3 words here.): " << word_count("Three words here.") << endl;
    cout << "Word Count (1337): " << word_count("1337") << endl;
    cout << "Word Count (1,2,3,4 1, 2, 3, 4): " << word_count("1,2,3,4 1, 2, 3, 4") << endl;
	get_int("Please input a number: ");	
    return 0;
}
