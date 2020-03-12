#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {
	// Testing the list
	Linked_List l;
	l.push_front(1);
	l.insert(3, 1);
	l.push_back(5);
	l.push_front(7);
	l.print();
	l.sort_ascending();
	Linked_List assign;
	assign = l;
	assign.print();
	l.sort_descending();
	Linked_List copy = l;
	copy.print();
	return 0;
}
