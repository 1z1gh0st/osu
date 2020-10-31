#include "hashMap.h"
#include "userInput.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>

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

char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
	while (1) {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
			(c == '/') ||
            c == '\'') {
            if (length + 1 >= maxLength) {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = (length == 0) ? c : tolower(c);
            length++;
        }
        else if (length > 0 || c == EOF) {
            break;
        }
    }
    if (length == 0) {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

HashMap* read_employee_list(FILE* file) {
	char* current_word = nextWord(file);
	int n = current_word[0] - 48;
	free(current_word);
    HashMap* map = hashMapNew(n);
	for (int i = 0; i < n; i++) {
		Employee* entry = (Employee*)malloc(sizeof(Employee));
		char* first = nextWord(file);
		entry->first_name = first;

		char* last = nextWord(file);
		entry->last_name = last;

		char* id = nextWord(file);
		entry->id = id;

		char* date = nextWord(file);
		entry->date_started.month = ((date[0] - 48) * 10) + (date[1] - 48);
		entry->date_started.day = ((date[3] - 48) * 10) + (date[4] - 48);
		entry->date_started.year = ((date[6] - 48) * 1000) +
			((date[7] - 48) * 100) + 
			((date[8] - 48) * 10) + 
			(date[9] - 48);
		free(date);

		char* employed = nextWord(file);
		entry->currently_employed = employed[0] - 48;
		free(employed);
		
		hashMapPut(map, entry->id, entry);
	}
	return map;
}

void write_employee_list(HashMap* map, FILE* file) {
	freopen("employees.txt", "w", stdout);	
	hashMapWrite(map, file);
}

void user_choice(int index, HashMap* map, FILE* file) {
	switch (index)
	{
		case 1:{
			Employee* E = create_new_employee();
			hashMapPut(map, E->id, E);
			printf("\nEmployee successfully added\n");
			printf("\nWriting to file...\n");
			write_employee_list(map, file);
			break;
		}
		case 2: {
			printf("Please enter employee id >> ");
			char* key = get_valid_string_input();
			Employee* E = hashMapGet(map, key);
			if (E != NULL) {
				employeePrint(*E);
			} else {
				printf("Sorry, ID not found. \n");
			}
			free(key);
			break;
		}
		case 3: {
			hashMapPrint(map);
			printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
			printf("Number of links: %d\n", hashMapSize(map));
			printf("Number of buckets: %d\n", hashMapCapacity(map));
			printf("Table load: %f\n", hashMapTableLoad(map));
		}
	}
} 

int main(int argc, const char** argv) {
    const char* fileName = "employees.txt";
    if (argc > 1) {
        fileName = argv[1]; 
	}
    
	FILE* input;
	input = fopen(fileName, "r");
	HashMap* map = read_employee_list(input);

	int choice = prompt_user_choice();
	user_choice(choice, map, input);
	
	fclose(input);
	hashMapDelete(map);
    return 0;
}
