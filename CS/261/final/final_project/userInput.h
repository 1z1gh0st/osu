#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "hashMap.h"
#include <stdio.h>

typedef struct Employee Employee;

int prompt_user_choice();
char* get_valid_string_input();
char* get_valid_int_input();
Employee* create_new_employee();

#endif
