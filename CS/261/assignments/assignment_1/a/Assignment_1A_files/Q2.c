/* CS261- Assignment 1A - Question 2
   Name: Philip Warton
   Date: 06/22/2020
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c) {
   	int temp = *a; 
	*a = *b;
	*b = temp;
	return --c;
}

int main() {
	srand(time(NULL));    
	int x = rand() % 11, y = rand() % 11, z = rand() % 11;
	printf("x = %d,  y = %d,  z = %d\n", x, y, z);
   	int foo_val = foo(&x, &y, z); 
	printf("x = %d,  y = %d,  z = %d\n", x, y, z);
	printf("foo() = %d\n", foo_val); 
    return 0;
}

