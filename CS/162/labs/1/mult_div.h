#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct mult_div_values {
	int mult;
	float div;
};

bool is_valid_dimension(char *, char *);
mult_div_values** create_array(int, int);
void set_values(mult_div_values**, int, int);
void delete_array(mult_div_values**, int, int);