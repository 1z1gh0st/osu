/******************************************************
** Program: linked_list.hpp
** Author: Philip Warton
** Date: 03/14/2020
** Description: Template class for Linked_List
** Input: none
** Output: none
******************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Linked_List {
	private:
        unsigned int length;
        Node<T> *head;

        // Private functions for internal use
        /********************************************************************* 
        ** Function: is_prime(int)
        ** Description: Checks if an integer is prime
        ** Parameters: int n
        ** Pre-Conditions: n should be positive but it doesn't have to be necessarily
        ** Post-Conditions: Should return true if n is prime or false otherwise
        *********************************************************************/ 
        bool is_prime(T n) {
            if (n < 2) { // Eliminates negative numbers and 0 and 1 cases
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

        // FUNCTION FOR DEBUGGING PURPOSES
        // DEPRECATED
        void print_from_nodes(Node<T> *h) {
            Node<T> *curr = h;
            int i = 0;
            cout << "LIST : ";
            while (curr != NULL) {
                cout << curr->val << " ";
                curr = curr->next;
            }
        }

        /********************************************************************* 
        ** Function: get_length_from_nodes(Node<T> *h)
        ** Description: Given a node, this will return the length of everything from there on
        ** Parameters: Node<T> *h
        ** Pre-Conditions: h should be the front of our list
        ** Post-Conditions: Should return the length of the list
        *********************************************************************/ 
        unsigned int get_length_from_nodes(Node<T> *h) {
            Node<T> *curr = h;
            unsigned int length = 0;
            while (curr != NULL) {
                length++;
                curr = curr->next;
            }
            return length;
        }
        /********************************************************************* 
         ** Function: merge_sort_asc(Node**)
        ** Description: Implementation of merge sort algorithms
        ** Parameters: Node<T> **h
        ** Pre-Conditions: h should be the first Node<T>in the list that we want to sort
        ** Post-Conditions: Should call itself recursively until list is split into single nodes, and then merge it all back together
        *********************************************************************/ 
        void merge_sort_asc(Node<T> **h) {
            // Made referencing Wikipedia and Geeks for Geeks
            Node<T> *curr_head = *h;
            if (curr_head != NULL && curr_head->next != NULL) { // If the list from h is length 0 or 1, this condition fails and we are done
                Node<T> *l, *r;
                split(curr_head, &l, &r); // l and r now both have half the list stored in them
                merge_sort_asc(&l); // Recurr
                merge_sort_asc(&r);
                *h = merge_asc(l, r); // Put l and r back together into h
            }
        }

        /********************************************************************* 
         ** Function: merge_sort_des(Node**), [identical to asc]
        ** Description: Implementation of merge sort algorithms
        ** Parameters: Node<T> **h
        ** Pre-Conditions: h should be the first Node<T>in the list that we want to sort
        ** Post-Conditions: Should call itself recursively until list is split into single nodes, and then merge it all back together
        *********************************************************************/ 
        void merge_sort_des(Node<T> **h) {
            Node<T> *curr_head = *h;
            if (curr_head != NULL && curr_head->next != NULL) { // If the list from h is length 0 or 1, this condition fails and we are done
                Node<T> *l, *r;
                split(curr_head, &l, &r); // l and r now both have half the list stored in them
                merge_sort_des(&l);
                merge_sort_des(&r);
                *h = merge_des(l, r); // Put l and r back together into h
            }
        }

        /********************************************************************* 
         ** Function: split(Node*, Node**, Node**)
        ** Description: Takes the list from h, and puts first half into l and second half into r
        ** Parameters: Node<T> *h, Node<T> **l, Node<T> **r
        ** Pre-Conditions: h should be the first Node<T>in given list, l and r should be of type Node* passed by pointer
        ** Post-Conditions: Should print out list to console
        *********************************************************************/ 
        void split(Node<T> *h, Node<T> **l, Node<T> **r) {
            if (*l == *r) {
                return;
            }
            *l = h; // Set left equal to the front
            unsigned int length = get_length_from_nodes(h);
            Node<T> *midpoint = h;
            for (int i = 1; i < length / 2; i++) {
                midpoint = midpoint->next;
            }
            *r = midpoint->next; // Setting right to everything after the midpoint
            midpoint->next = NULL; // De-linking the two halves
        }

        /********************************************************************* 
         ** Function: merge_asc(Node<T> *, Node*)
        ** Description: Merges two sorted lists l and r into one sorted list, and returns it
        ** Parameters: Node<T> *l, Node<T> *r
        ** Pre-Conditions: l and r must be sorted disjoint partitions of list being sorted
        ** Post-Conditions: Should return the sorted combination of l and r
        *********************************************************************/ 
        Node<T> * merge_asc(Node<T> *l, Node<T> *r) {
            if (l == NULL) {
                return r; // Base cases (if one of the nodes passed in is NULL)
            } else if (r == NULL) {
                return l;
            } else {
                Node<T> *list = NULL;
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

        /********************************************************************* 
         ** Function: merge_des(Node<T> *, Node*)
        ** Description: Merges two sorted lists l and r into one sorted list, and returns it
        ** Parameters: Node<T> *l, Node<T> *r
        ** Pre-Conditions: l and r must be sorted disjoint partitions of list being sorted
        ** Post-Conditions: Should return the sorted combination of l and r
        *********************************************************************/ 
        Node<T> * merge_des(Node<T> *l, Node<T> *r) {
            if (l == NULL) {
                return r; // Base cases (if one of the nodes passed in is NULL)
            } else if (r == NULL) {
                return l;
            } else {
                Node<T> *list = NULL;
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
	public:
		/********************************************************************* 
        ** Function: Linked_List()
        ** Description: Default constructor for Linked_List
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: Should initialize Linked_List with length zero and head as the null pointer
        *********************************************************************/ 
        Linked_List() {
            this->length = 0;
            head = NULL;
        }

        /********************************************************************* 
         ** Function: Linked_List(const Linked_List &)
        ** Description: Copy constructor for Linked_List
        ** Parameters: const Linked_List &l
        ** Pre-Conditions: Assuming that l.length matches the actual number of nodes in l
        ** Post-Conditions: Should initialize Linked_List that is identical to l
        *********************************************************************/ 
        Linked_List(const Linked_List &l) {
            length = 0;
            head = NULL;
            for (int i = 0; i < l.get_length(); i++) {
                push_back(l.get_value_at(i));
            }
        }

        /********************************************************************* 
         ** Function: operator=(const Linked_List &)
        ** Description: Assignment operator overload
        ** Parameters: const Linked_List &l
        ** Pre-Conditions: Assuming that l.length matches the actual number of nodes in l
        ** Post-Conditions: Should set the current Linked_List to be identical to l
        *********************************************************************/ 
        Linked_List& operator=(const Linked_List &l) {
            clear();
            length = 0;
            head = NULL;
            for (int i = 0; i < l.get_length(); i++) {
                push_back(l.get_value_at(i));
            }
            return *this;
        }

        /********************************************************************* 
         ** Function: ~Linked_List()
        ** Description: Destructor for Linked_List
        ** Parameters: none
        ** Pre-Conditions: Assumes clear() works correctly
        ** Post-Conditions: Should free all memory before destroying object
        *********************************************************************/ 
        ~Linked_List() {
            clear();
        }

        /********************************************************************* 
         ** Function: get_length() const
        ** Description: Gets the number of nodes in Linked_List
        ** Parameters: none
        ** Pre-Conditions: Assumes clear() works correctly
        ** Post-Conditions: Should free all memory before destroying object
        *********************************************************************/ 
        unsigned int get_length() const {
            return length;
        }

        /********************************************************************* 
         ** Function: print()
        ** Description: Prints out all the values in Linked_List
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: Should print out list to console
        *********************************************************************/ 
        void print() {
            cout << endl << "Linked_List at : " << this << endl;
            Node<T> *curr = head;
            int i = 0;
            while (curr != NULL) {
                cout << "[" << i++ << "] " << curr->val << endl;
                curr = curr->next;
            }
        }

        /********************************************************************* 
         ** Function: clear()
        ** Description: Sets length to 0 and deletes all nodes
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: Should free all of the memory for the nodes and set head to the null pointer
        *********************************************************************/ 
        void clear() {
            length = 0;
            Node<T> *curr = head;
            while (curr != NULL) {
                Node<T> *prev = curr; // Hold on to prev for deletion
                curr = curr->next;
                delete prev;
            }
            head = NULL;
        }

        /********************************************************************* 
         ** Function: push_front(int)
        ** Description: Pushes number to front of the list, returns length
        ** Parameters: int num
        ** Pre-Conditions: none
        ** Post-Conditions: Should return new length and add num to front of list
        *********************************************************************/ 
        unsigned int push_front(T val_in) {
            Node<T> *temp = new Node<T>;
            temp->val = val_in;
            temp->next = head;
            head = temp;
            return ++length;
        }

        /********************************************************************* 
         ** Function: push_back()
        ** Description: Should add number to the back of the list and return the new length
        ** Parameters: int num
        ** Pre-Conditions: none
        ** Post-Conditions: Should have list with num at back and return new length
        *********************************************************************/ 
        unsigned int push_back(T val_in) {
            Node<T> *temp = new Node<T>; // This is our new Node<T>to put at the back
            temp->val = val_in;
            temp->next = NULL;
            if (length == 0) {
                head = temp;
            } else {
                Node<T> *curr = head;
                while (curr->next != NULL) {
                    curr = curr->next; // Go to end
                }
                curr->next = temp; // Attach temp as "Last Node"->next
            }
            return ++length;
        }

        /********************************************************************* 
         ** Function: insert(int, unsigned int)
        ** Description: Inserts a value at a given index, pushing everything after it back one index
        ** Parameters: int val, unsigned int index
        ** Pre-Conditions: index must be less than length
        ** Post-Conditions: Should add val at index and push everything after it back one index
        *********************************************************************/ 
        unsigned int insert(T val_in, unsigned int index) {
            if (index >= length)
                throw out_of_range("ERROR: Linked_List index arg for insert() out of range ");
            if (index == 0)
                push_front(val_in);
            else {
                Node<T> *temp = new Node<T>;
                temp->val = val_in;
                Node<T> *curr = head;
                for (int i = 1; i < index; i++) {
                    curr = curr->next;
                }
                temp->next = curr->next;
                curr->next = temp;
                length++;
            }
            return length;
        }

        /********************************************************************* 
         ** Function: sort_ascending()
        ** Description: Sorts the list in ascending order
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: Should sort Linked_List correctly
        *********************************************************************/ 
        void sort_ascending() {
            merge_sort_asc(&head);
        }

        /********************************************************************* 
         ** Function: sort_ascending()
        ** Description: Sorts the list in descending order
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: Should sort Linked_List correctly
        *********************************************************************/ 
        void sort_descending() {
            merge_sort_des(&head);
        }

        /********************************************************************* 
         ** Function: get_value_at(unsigned int) const
        ** Description: Retrieves value from linked list at index
        ** Parameters: unsigned int i
        ** Pre-Conditions: i must be less than length
        ** Post-Conditions: Should return the value of the i'th node
        *********************************************************************/ 
        T get_value_at(unsigned int i) const {
            if (i >= length) // If pre-condition is not met
                throw out_of_range("ERROR: Linked_List index arg for get_value_at() out of range ");
            Node<T> *curr = head;
            for (int k = 0; k < i && curr->next != NULL; k++) {
                curr = curr->next;
            }
            return curr->val;
        }

        /********************************************************************* 
         ** Function: prime_count()
        ** Description: Counts number of primes in the list
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: Should return the number of primes in the list
        *********************************************************************/ 
        unsigned int prime_count() {
            Node<T> *curr = head;
            unsigned int num_primes = 0;
            while (curr != NULL) {
                num_primes += is_prime(curr->val);
                curr = curr->next;
            }
            return num_primes;
        }
};

#endif
