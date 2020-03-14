/******************************************************
** Program: linked_list.h
** Author: Philip Warton
** Date: 03/14/2020
** Description: Class decleration for Linked_List
** Input: none
** Output: none
******************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class Linked_List {
	private:
	   unsigned int length;
	   Node *head;
	   // Private functions for internal use
	   void merge_sort_asc(Node **);
	   void merge_sort_des(Node **);
	   void split(Node*, Node**, Node**);
	   Node* merge_asc(Node*, Node*);
	   Node* merge_des(Node*, Node*);
	   unsigned int get_length_from_nodes(Node*);
	   void print_from_nodes(Node *);
	   bool is_prime(int);
	public:
		Linked_List();

		// Big Three
		~Linked_List();
		Linked_List(const Linked_List &);
		Linked_List& operator=(const Linked_List &);

		unsigned int get_length() const;
		int get_value_at(unsigned int) const;
		void print();
		void clear();

		// Adding to list
		unsigned int push_front(int);
		unsigned int push_back(int);
		unsigned int insert(int val, unsigned int index);
		
		// Sorting
		void sort_ascending();
		void sort_descending();

		unsigned int prime_count();
};

#endif
