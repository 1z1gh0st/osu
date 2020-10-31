#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>

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
	char * current_word = nextWord(file);
	// First word is number of entries
	int n = current_word[0] - 48;
    HashMap* map = hashMapNew(n);
	for (int i = 0; i < n; i++) {
		Employee current_entry;

		current_word = nextWord(file);
		current_entry.first_name = current_word;

		current_word = nextWord(file);
		current_entry.last_name = current_word;

		current_word = nextWord(file);
		current_entry.id = current_word;

		current_word = nextWord(file);
		current_entry.date_started.month = ((current_word[0] - 48) * 10) + (current_word[1] - 48);
		current_entry.date_started.day = ((current_word[3] - 48) * 10) + (current_word[4] - 48);
		current_entry.date_started.year = ((current_word[6] - 48) * 1000) +
			((current_word[7] - 48) * 100) + 
			((current_word[8] - 48) * 10) + 
			(current_word[9] - 48);

		current_word = nextWord(file);
		current_entry.currently_employed = current_word[0] - 48;
		
		hashMapPut(map, current_entry.id, current_entry);
	}
	return map;
}

int main(int argc, const char** argv) {
    const char* fileName = "input1.txt";
    if (argc > 1) {
        fileName = argv[1];
    }
    
	FILE* input;
	input = fopen(fileName, "r");
	HashMap* map = read_employee_list(input);
	fclose(input);
	hashMapPrint(map);
    
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
    hashMapDelete(map);
    return 0;
}
