#include <iostream>

using namespace std;

void get_sentence_ref(string &s) {
	s = "pass by reference sentence";
	// Hardcoded sentence for ease of writing
}

void get_sentence_ptr(string *s) {
	*s = "pointer sentence";
}

int main() {
	string sentence;

	get_sentence_ref(sentence);
	cout << sentence << endl;

	get_sentence_ptr(&sentence);
	cout << sentence << endl;

	return 0;
}

// NAME | VALUE | ADDRESS
// &name -> address
// *address -> value
