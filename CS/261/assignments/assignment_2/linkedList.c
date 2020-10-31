/***********************************************************
* Author: Philip Warton and Chenyu Song
* Email: wartonp@oregonstate.edu
* Date Created: 07/08/2020
* Filename: linkedList.c
*
* Overview:
*	This program is a linked list implementation of the deque and bag ADTs. 
*	Note that both implementations utilize a linked list with
*	both a front and back sentinel and double links (links with
*	next and prev pointers).
************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

#ifndef FORMAT_SPECIFIER
#define FORMAT_SPECIFIER "%d"
#endif


/* ************************************************************************
	Structs Link and LinkedList
************************************************************************ */

struct LinkedList {
	struct Link* head;
};

struct Link {
	TYPE value;
	struct Link* next;
};

/* ************************************************************************
	Linked List Functions
************************************************************************ */

LinkedList* linkedListCreate() {
	struct LinkedList* result = (LinkedList*)malloc(sizeof(LinkedList));
	result->head = NULL;
	return result;
}

void deletelinkedList(LinkedList* list) {
	Link* curr = list->head;
	while (curr != NULL) {
		Link* prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(curr);
	free(list);
}

int sizelinkedList(LinkedList* myList) {
	int result = 0;
	Link* curr = myList->head;
	while (curr != NULL) {
		result++;
		curr = curr->next;
	}
	free(curr);
	return result;
}

int isEmptyLinkedList(LinkedList* myList) {
	return (myList->head == NULL);
}

static void addLinkBefore(LinkedList* list, Link* link, TYPE value) {
	Link* curr = list->head;
	Link* prev;
	Link* newLink = (Link*)malloc(sizeof(Link));
	newLink->value = value;
	if (list->head == NULL) {
		newLink->next = NULL;
		list->head = newLink;
	}
	while (curr != NULL) {
		if (curr == link) {
			newLink->next = curr;
			if (curr == list->head) {
				list->head = newLink;
			} else {
				prev->next = newLink;
			}
			break;
		}
		prev = curr;
		curr = curr->next;
	}
}

static void removeLink(LinkedList* list, Link* link) {
	Link* curr = list->head;
	if (link == list->head) {
		list->head = list->head->next;
	} else{
		while (curr != NULL) {
			if (curr->next == link) {
				Link* prev = curr;
				curr = curr->next;
				prev->next = curr->next;
				break;
			}
			curr = curr->next;
		}
	}
	free(curr);
}

void printLinkedList(LinkedList* list) {
	Link* curr = list->head;
	while (curr != NULL) {
		printf("%d", curr->value);
		if (curr->next != NULL) { 
			printf(" ");
		} else {
			printf("\n");
		}
		curr = curr->next;
	}
}

/* ************************************************************************
	Deque Functions
************************************************************************ */

Deque* dequeCreate() {
	return linkedListCreate();
}

void deleteDeque(Deque* myDeque) {
	deletelinkedList(myDeque);
}

int sizeDeque(Deque* myDeque) {
	return sizelinkedList(myDeque);
}

int isEmptyDeque(Deque* myDeque) {
	return (myDeque->head == NULL);
}

void addFrontDeque(Deque* myDeque, TYPE value) {
	addLinkBefore(myDeque, myDeque->head, value);
}

void addBackDeque(Deque* myDeque, TYPE value) {
	Link* newLink = (Link*)malloc(sizeof(Link));
	newLink->value = value;
	newLink->next = NULL;
	Link* curr = myDeque->head;
	if (myDeque->head == NULL) {
		myDeque->head = newLink;
	} else {
		while (curr != NULL) {
			if (curr->next == NULL) {
				curr->next = newLink;
				break;
			}
			curr = curr->next;
		}
	}
}

TYPE frontDeque(Deque* myDeque) {
	return (myDeque->head->value);
}

TYPE backDeque(Deque* myDeque) {
	Link* curr = myDeque->head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	return curr->value;
}

void removeFrontDeque(Deque* myDeque) {
	if (myDeque->head != NULL) {
		removeLink(myDeque, myDeque->head);
	}
}

void removeBackDeque(Deque* myDeque) {
	if (myDeque->head != NULL) {
		Link* curr = myDeque->head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		removeLink(myDeque, curr);
	}
}

void printDeque(Deque* myDeque) {
	printLinkedList(myDeque);
}

/* ************************************************************************
	Bag Functions
************************************************************************ */

Bag* bagCreate() {
	return linkedListCreate();
}

void deleteBag(Bag* myBag) {
	deletelinkedList(myBag);
}

int sizeBag(Bag* myBag) {
	return sizelinkedList(myBag);
}

int isBagEmpty(Bag* myBag) {
	return (isEmptyLinkedList(myBag));
}

void addBag(Bag* myBag, TYPE value) {
	addLinkBefore(myBag, myBag->head, value);
}

int containsBag(Bag* myBag, TYPE value) {
	if (myBag->head != NULL) {
		Link* curr = myBag->head;
		while (curr != NULL) {
			if (curr->value == value) {
				return 1;
			}
		}
	}
	return 0;
}

void removeBag(Bag* myBag, TYPE value) {
	if (myBag->head != NULL) {	
		Link* curr = myBag->head;
		while (curr != NULL) {
			if (curr->value == value) {
				Link* prev = curr;
				curr = curr->next;
				removeLink(myBag, prev);
			} else {
				curr = curr->next;
			}
		}
	}
}

void printBag(Bag* myBag) {
	printLinkedList(myBag);
}
