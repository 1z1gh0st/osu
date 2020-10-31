/* CS261- Assignment 1A - Question 0
   Name: Philip Warton
   Date: 06/22/2020
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr)
{
	printf("Calling fooA...\n");
	printf("*iptr = %d        iptr = %p\n", *iptr, iptr);
	*iptr += 5;      
	printf("&iptr = %p\n", &iptr);
}


void fooB(int* jptr)
{
	printf("Calling fooB...\n");
	printf("*jptr = %d        jptr = %p\n", *jptr, jptr);
    *jptr -= 1; 
	printf("&jptr = %p\n", &jptr);
}


int main()
{
	srand(time(NULL)); 
	printf("\n\n---Running Q0.c---\n\n");
   	int x = rand() % 11; 
   	printf("x = %d        &x = %p\n", x, &x); 
   	fooA(&x); 
	printf("x = %d\n", x);    
	B(&x); 
   	printf("x = %d        &x = %p\n", x, &x); 
    return 0;
}


