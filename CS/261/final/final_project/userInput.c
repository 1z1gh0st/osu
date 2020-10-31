#include "userInput.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
CS 261 Final Project Group 3
Employee Profile Manager
Authors: 
Christian Herinckx
Tieying Chu
Isaac Towai 
Philip Warton
Date: August 12 2020
*/

typedef struct Employee Employee;

int prompt_user_choice() {
	char input[256];
	printf("Enter 'new' to create a new employee.\nEnter 'view' to view the employees.\nEnter 'hash' to view the hash table for maintenence.\n >>");
	scanf("%s", input);
	if ((strcmp(input, "new") == 0) || (strcmp(input, "New") == 0)) {
		return 1;
	}
	else if ((strcmp(input, "view") == 0) || (strcmp(input, "View") == 0)) {
		return 2;
	}
	else if ((strcmp(input, "hash") == 0) || (strcmp(input, "Hash") == 0)) {
		return 3;
	}
	else {
		return 0;
	}
}

char* get_valid_string_input() {
	char input[256];
	scanf("%s", input);
	char* result = (char*)malloc((strlen(input) + 1) * sizeof(char));
	int j = 0;
	for (int i = 0; i < strlen(input); i++) {
		if ((input[i] >= 'A' && input[i] <= 'Z') ||
			(input[i] >= 'a' && input[i] <= 'z') ||
			(input[i] >= '0' && input[i] <= '9')) {
			result[j] = input[i];
			j++;
		}
	}
	result[j] = '\0';
	return result;
}

Employee *create_new_employee() {
	struct Employee *employees = (struct Employee *)malloc(sizeof(struct Employee));

	printf("\nEnter the employee's first name: ");
	employees->first_name = get_valid_string_input();

	printf("\nEnter the employee's last name: \n");
	employees->last_name = get_valid_string_input();

	printf("\nEnter the employee's id: \n");
	employees->id = get_valid_string_input();

	int month = 13;
	while (month > 12 || month < 0) {
		printf("\nEnter the number referring to the month the employee started at the company: \n");
		scanf("%d", &month);
	}
	employees->date_started.month = month;

	int day = 32;
	while (day > 31 || day < 0) {
		printf("\nEnter the day the employee started at the company: \n");
		scanf("%d", &day);
	}
	employees->date_started.day = day;

	int year = -1;
	while (year < 1950) {
		printf("\nEnter the year the employee started at the company.\n");
		scanf("%d", &year);	
	}
	employees->date_started.year = year;

	int boolean = -1;
	while (boolean != 0 && boolean != 1) {
		printf("\nEnter 1 if the employee is currently employed by the company. Otherwise, enter 0.\n");
		scanf("%d", &boolean);
	}
	employees->currently_employed = boolean;

	return employees;
}

