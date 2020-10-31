// DA_Stack_Bag.c: Dynamic Array, Stack and Bag implementations
#include <assert.h>
#include <stdlib.h>
#include "DA_Stack_Bag.h"


#include <stdio.h>
/* ************************************************************************
	Struct DynArr
************************************************************************ */

struct DynArr {
	int size;
	int capacity;
	TYPE *values;
};

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

DynArr* newDynArr(int capacity) {
	struct DynArr* result = (DynArr*)malloc(1 * sizeof(DynArr));
	result->size = 0;
	result->capacity = capacity;
	result->values = (TYPE*)malloc(result->capacity * sizeof(TYPE));
	return result;
}

void deleteDynArr(DynArr *myDA) {
	if (myDA->values != NULL) {
		free(myDA->values);
		myDA->values = NULL;
	}
}

int sizeDynArr(DynArr *myDA) {
	return myDA->size;	
}

void addDynArr(DynArr *myDA, TYPE value) {
	if (myDA->size + 1 >  myDA->capacity) {
		myDA->capacity *= 2;
		myDA->values = (TYPE*)realloc(myDA->values, myDA->capacity * sizeof(TYPE));
	}
	myDA->values[myDA->size] = value;
	myDA->size++;
}

TYPE getDynArr(DynArr *myDA, int position) {
	return (myDA->values)[position];
}

void putDynArr(DynArr *myDA, int position, TYPE value) {
	(myDA->values)[position] = value;
}

void swapDynArr(DynArr *myDA, int idx_i, int idx_j) {
	TYPE temp = myDA->values[idx_i];
	myDA->values[idx_i] = myDA->values[idx_j];
	myDA->values[idx_j] = temp;
}

void removeAtDynArr(DynArr *myDA, int idx_i) {
	int i;
	for (i = 0; i < myDA->size - 1; i++) {
		if (i < idx_i) {
			myDA->values[i] = myDA->values[i];
		} else {
			myDA->values[i] = myDA->values[i + 1];
		}
	}
	if (myDA->size - 1 <= myDA->capacity / 2) {
		myDA->capacity /= 2;
		myDA->values = (TYPE*)realloc(myDA->values, myDA->capacity * sizeof(TYPE));
	}
	myDA->size--;
}

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */


/* ************************************************************************
	Bag Interface Functions
************************************************************************ */
