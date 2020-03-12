/*******************************************************************
 ** Program: helper_functions.h
 ** Author: Philip Warton
 ** Date: 10/27/2019
 ** Description: Declerations and includes of all the helper
 **     functions for CS161 assignment 2
 ** Input: none
 ** Output: none
 *******************************************************************/

#ifndef ASSIGNMENT2_HEADER_H
#define ASSIGNMENT2_HEADER_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool check_range(int, int, int);

bool is_capital(char);

bool is_even(int);

bool is_odd(int);

int equality_test(int, int);

bool float_is_equal(float, float, float);

bool is_int(string);

bool numbers_present(string);

bool letters_present(string);

bool contains_sub_string(string, string);

int word_count(string);

string to_upper(string);

string to_lower(string);

int get_int(string);

#endif
