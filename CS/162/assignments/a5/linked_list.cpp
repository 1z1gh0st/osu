#include "linked_list.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Linked_List::Linked_List() {
	this->length = 0;
	head = NULL;
}
 
Linked_List::~Linked_List() {
	clear();
}

Linked_List::Linked_List(const Linked_List &l) {
	length = 0;
	head = NULL;
	for (int i = 0; i < l.get_length(); i++) {
		push_back(l.get_value_at(i));
	}
}

Linked_List& Linked_List::operator=(const Linked_List &l) {
	clear();
	length = 0;
	head = NULL;
	for (int i = 0; i < l.get_length(); i++) {
		push_back(l.get_value_at(i));
	}
	return *this;
}

// Function: returns # of nodes in list
int Linked_List::get_length() const {
	return length;
}

// Print function
void Linked_List::print() {
	cout << endl << "--PRINTING LINKED LIST--" << endl;
	Node *curr = head;
	int i = 0;
	while (curr != NULL) {
		cout << "[" << i++ << "] " << curr->val << endl;
		curr = curr->next;
	}
}

// Empty out the old listo
void Linked_List::clear() {
	length = 0;
	Node *curr = head;
	while (curr != NULL) {
		Node *prev = curr;
		curr = curr->next;
		delete prev;
	}
	head = NULL;
}

// Push front
unsigned int Linked_List::push_front(int num) {
	Node *temp = new Node;
	temp->val = num;
	temp->next = head;
	head = temp;
	return ++length;
}

// Push back
unsigned int Linked_List::push_back(int num) {
	Node *temp = new Node;
	temp->val = num;
	temp->next = NULL;
	if (length == 0) {
		head = temp;
	} else {
		Node *curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = temp;
	}
	return ++length;
}

// Insert
unsigned int Linked_List::insert(int val, unsigned int index) {
	if (index == 0) {
		push_front(val);
	} else {
		Node *temp = new Node;
		temp->val = val;
		Node *curr = head;
		for (int i = 1; i < index; i++) {
			curr = curr->next;
		}
		temp->next = curr->next;
		curr->next = temp;
		length++;
	}
	return length;
}

void Linked_List::sort_ascending() {
	merge_sort_asc(&head);
}

void Linked_List::sort_descending() {
	merge_sort_des(&head);
}

void Linked_List::merge_sort_asc(Node **h) {
	// Made referencing Wikipedia and Geeks for Geeks
	Node *curr_head = *h;
	if (curr_head != NULL && curr_head->next != NULL) { // If the list from h is length 0 or 1, this condition fails and we are done
		Node *l, *r;
		split(curr_head, &l, &r); // l and r now both have half the list stored in them
		merge_sort_asc(&l);
		merge_sort_asc(&r);
		*h = merge_asc(l, r); // Put l and r back together into h
	}
}

void Linked_List::merge_sort_des(Node **h) {
	Node *curr_head = *h;
	if (curr_head != NULL && curr_head->next != NULL) { // If the list from h is length 0 or 1, this condition fails and we are done
		Node *l, *r;
		split(curr_head, &l, &r); // l and r now both have half the list stored in them
		merge_sort_des(&l);
		merge_sort_des(&r);
		*h = merge_des(l, r); // Put l and r back together into h
	}
}

void Linked_List::split(Node *h, Node **l, Node **r) {
	if (*l == *r) {
		return;
	}
	*l = h; // Set left equal to the front
	unsigned int length = get_length_from_nodes(h);
	Node *midpoint = h;
	for (int i = 1; i < length / 2; i++) {
		midpoint = midpoint->next;
	}
	*r = midpoint->next; // Setting right to everything after the midpoint
	midpoint->next = NULL; // De-linking the two halves
}

Node* Linked_List::merge_asc(Node *l, Node *r) {
	if (l == NULL) {
		return r; // Base cases (if one of the nodes passed in is NULL)
	} else if (r == NULL) {
		return l;
	} else {
		Node *list = NULL;
		if (l->val < r->val) {
			list = l;
			l = l->next;	
		} else {
			list = r;
			r = r->next;
		}
		list->next = merge_asc(l, r);
		return list;
	}
}

Node* Linked_List::merge_des(Node *l, Node *r) {
	if (l == NULL) {
		return r; // Base cases (if one of the nodes passed in is NULL)
	} else if (r == NULL) {
		return l;
	} else {
		Node *list = NULL;
		if (l->val > r->val) { // Changed from merge_asc() to be > instead of <
			list = l;
			l = l->next;	
		} else {
			list = r;
			r = r->next;
		}
		list->next = merge_des(l, r); // Recurring on new l and r (one of which has moved to next)
		return list;
	}
}

// Deprecated
int Linked_List::get_value_at(unsigned int i) const {
	Node *curr = head;
	for (int k = 0; k < i && curr->next != NULL; k++) {
		curr = curr->next;
	}
	return curr->val;
}

// Function for debugging purposes : DELETE
void Linked_List::print_from_nodes(Node *h) {
	Node *curr = h;
	int i = 0;
	cout << "LIST : ";
	while (curr != NULL) {
		cout << curr->val << " ";
		curr = curr->next;
	}
}

// Function for debugging purposes : DELETE
unsigned int Linked_List::get_length_from_nodes(Node *h) {
	Node *curr = h;
	unsigned int length = 0;
	while (curr != NULL) {
		length++;
		curr = curr->next;
	}
	return length;
}

// Counting prime numbers
unsigned int Linked_List::prime_count() {
	Node *curr = head;
	unsigned int num_primes = 0;
	while (curr != NULL) {
		num_primes += is_prime(curr->val);
		curr = curr->next;
	}
	return num_primes;

}

bool Linked_List::is_prime(int n) {
	if (n < 2) {
		return false;
	} else {
		for (int i = 2; i < (n / 2) + 1; i++) {
			if ((n % i) == 0) {
				return false;
			}
		}
	}
	return true;
}