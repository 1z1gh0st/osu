#include "linkedList.h"
#include <stdio.h>

int main()
{
	/* DEQUE */

	Deque* myDeque = DequeCreate(); 
	addFrontDeque(myDeque, (TYPE)1);
	addBackDeque(myDeque, (TYPE)2);
	addBackDeque(myDeque, (TYPE)3);
	addFrontDeque(myDeque, (TYPE)4);
	addFrontDeque(myDeque, (TYPE)5);
	addBackDeque(myDeque, (TYPE)6);
	printDeque(myDeque);
	printf("%i\n", frontDeque(myDeque));
	printf("%i\n", backDeque(myDeque));
	removeFrontDeque(myDeque);
	removeBackDeque(myDeque);
	printDeque(myDeque);
	deleteDeque(myDeque);

	/* BAG */

	Bag* myBag = bagCreate(); 
	addBag(myBag, (TYPE)10);
	addBag(myBag, (TYPE)11);
	addBag(myBag, (TYPE)13);
	addBag(myBag, (TYPE)14);
	removeBag(myBag, (TYPE)11);
	printBag(myBag);
	deleteBag(myBag);
	
	return 0;
}

