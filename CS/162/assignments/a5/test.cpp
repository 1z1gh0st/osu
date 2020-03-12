#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {
	// Testing the list
	Linked_List l;
	for (int i = 0; i < 5; i++) {
		l.push_front(i);
	}
	l.print();
	l.sort_ascending();
	l.print();
	/*Linked_List assign;
	assign = l;
	assign.print();
	l.sort_descending();
	Linked_List copy = l;
	copy.print();*/
	return 0;
}
