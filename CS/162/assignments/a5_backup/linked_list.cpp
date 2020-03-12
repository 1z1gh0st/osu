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
	merge_sort_asc(*this);
	// Recurse
	// Merge back together
}

void Linked_List::sort_descending() {
	merge_sort_des(*this);
}

void Linked_List::merge_sort_asc(Linked_List &list) {
	if (list.get_length() < 2) {
		return;
	} else {
		Linked_List left;
		Linked_List right;
		list.split(left, right);
		merge_sort_asc(left);
		merge_sort_asc(right);
		merge_asc(list, left, right);
	}
	
}

void Linked_List::merge_sort_des(Linked_List &list) {
	if (list.get_length() < 2) {
		return;
	} else {
		Linked_List left;
		Linked_List right;
		list.split(left, right);
		merge_sort_des(left);
		merge_sort_des(right);
		merge_des(list, left, right);
	}
}

void Linked_List::split(Linked_List &left, Linked_List &right) {
	Node *curr = head;
	int i = 0;
	for (i = 0; i < length / 2; i++) {
		left.push_back(curr->val);
		curr = curr->next;
	}
	i = length / 2;
	while (i < length) {
		right.push_back(curr->val);
		curr = curr->next;
		i++;
	}
}

void Linked_List::merge_asc(Linked_List &list, Linked_List &left, Linked_List &right) {
	list.clear();
	int ln = left.get_length(), rn = right.get_length();
	for (int i = 0, j = 0; i < ln || j < rn; ) {
		if (i < ln && j < rn) {
			if (left.get_value_at(i) < right.get_value_at(j)) {
				list.push_back(left.get_value_at(i));
				i++;
			} else {
				list.push_back(right.get_value_at(j));
				j++;
			}
		} else if (i < ln) {
			list.push_back(left.get_value_at(i));
			i++;
		} else {
			list.push_back(right.get_value_at(j));
			j++;
		}
	}
}

void Linked_List::merge_des(Linked_List &list, Linked_List &left, Linked_List &right) {
	list.clear();
	int ln = left.get_length(), rn = right.get_length();
	for (int i = 0, j = 0; i < ln || j < rn; ) {
		if (i < ln && j < rn) {
			if (left.get_value_at(i) < right.get_value_at(j)) {
				list.push_back(right.get_value_at(j));
				j++;
			} else {
				list.push_back(left.get_value_at(i));
				i++;
			}
		} else if (i < ln) {
			list.push_back(left.get_value_at(i));
			i++;
		} else {
			list.push_back(right.get_value_at(j));
			j++;
		}
	}
}

int Linked_List::get_value_at(unsigned int i) const {
	Node *curr = head;
	for (int k = 0; k < i && curr->next != NULL; k++) {
		curr = curr->next;
	}
	return curr->val;
}