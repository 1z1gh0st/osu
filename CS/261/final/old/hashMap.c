/*
 * CS 261 Data Structures
 * Name: Philip Warton 
 * Date: August 11, 2020
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

void employeePrint(Employee e) {
	printf("Name: %s %s\n", e.first_name, e.last_name);
	printf("ID: %s\n", e.id);
	printf("Date Started: %d/%d/%d\n", e.date_started.month, e.date_started.day, e.date_started.year);
	printf("Currently Employed: %d\n\n", e.currently_employed);
}

void employeeDelete(Employee* e) {
	free(e->first_name);
	free(e->last_name);
	free(e->id);
	free(e);
}

int hashFunction1(const char* key) {
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key) {
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        r += (i + 1) * key[i];
    }
    return r;
}

HashLink* hashLinkNew(const char* key, Employee value, HashLink* next) {
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

static void hashLinkDelete(HashLink* link) {
	employeeDelete(&(link->value));
    free(link->key);
    free(link);
}

void hashMapInit(HashMap* map, int capacity) {
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++) {
        map->table[i] = NULL;
    }
}

void hashMapCleanUp(HashMap* map) {
	if (map->table != NULL) {
		for (int i = 0; i < map->capacity; i++) {
			if (map->table[i] != NULL) {
				HashLink* curr = map->table[i];
				HashLink* prev;
				while (curr != NULL) {
					prev = curr;
					curr = curr->next;
					hashLinkDelete(prev);
				}
			}
		}
		free(map->table);
	}
}

HashMap* hashMapNew(int capacity) {
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

void hashMapDelete(HashMap* map) {
    hashMapCleanUp(map);
    free(map);
}

Employee* hashMapGet(HashMap* map, const char* key) {
	int index = HASH_FUNCTION(key) % map->capacity;
	HashLink* curr = map->table[index];
	while (curr != NULL) {
		if (strcmp(curr->key, key)) {
			curr = curr->next;
		} else {
			return &(curr->value);
		}
	}
	return NULL;
}

void resizeTable(HashMap* map, int capacity) {
	HashLink** newTable = malloc(sizeof(HashLink*) * capacity);
	for (int i = 0; i < capacity; i++) {
		newTable[i] = NULL;
	}
	for (int i = 0; i < map->capacity; i++) {
		if (map->table[i] != NULL) {
			HashLink* curr = map->table[i];
			while (curr != NULL) {
				int index = HASH_FUNCTION(curr->key) % capacity;
				if (newTable[index] == NULL) {
					newTable[index] = curr;
					curr = curr->next;
					newTable[index]->next = NULL;
				} else {
					HashLink* lastLink = newTable[index];
					while (lastLink->next != NULL) {
						lastLink = lastLink->next;
					}
					lastLink->next = curr;
					curr = curr->next;
					lastLink->next->next = NULL;
				}
			}
		}
	}
	free(map->table);
	map->table = newTable;
    map->capacity = capacity;
}

void hashMapPut(HashMap* map, const char* key, Employee value) {
	HashLink* newLink = hashLinkNew(key, value, NULL);
	int index = HASH_FUNCTION(key) % map->capacity;
	if (map->table[index] == NULL) {
		newLink->next = NULL;
		map->table[index] = newLink;
		map->size++;
	} else {
		HashLink* lastLink = map->table[index];
		int alreadyPresent = 0;
		while (lastLink->next != NULL) {
			if (!strcmp(lastLink->key, key)) {
				lastLink->value = value;
				alreadyPresent = 1;
				break;
			}
			lastLink = lastLink->next;
		}
		if (alreadyPresent) {
			hashLinkDelete(newLink);
		} else {
			lastLink->next = newLink;
			map->size++;
		}
	}
	if (hashMapTableLoad(map) > MAX_TABLE_LOAD) {
		resizeTable(map, map->capacity * 2);
	}
}

void hashMapRemove(HashMap* map, const char* key) {
	int index = HASH_FUNCTION(key) % map->capacity;
	HashLink* curr = map->table[index], *prev;
	while (curr != NULL) {
		if (!strcmp(curr->key, key)) {
			if (curr == map->table[index]) {
				map->table[index] = curr->next;
			} else {
				prev->next = curr->next;
			}
			hashLinkDelete(curr);
			map->size--;
			break;
		}
		prev = curr;
		curr = curr->next;
	}
}

int hashMapContainsKey(HashMap* map, const char* key) {
	int index = HASH_FUNCTION(key) % map->capacity;
	HashLink* curr = map->table[index];
	while (curr != NULL) {
		if (!strcmp(curr->key, key)) { return 1; }
		curr = curr->next;
	}
	return 0;
}

int hashMapSize(HashMap* map) {
    return map->size;
}

int hashMapCapacity(HashMap* map) {
	return map->capacity;
}

int hashMapEmptyBuckets(HashMap* map) {
	int emptyBucketCount = 0;
	for (int i = 0; i < map->capacity; i++) {
		emptyBucketCount += (map->table[i] == NULL);
	}
	return emptyBucketCount;
}

float hashMapTableLoad(HashMap* map) {
	return ((float)(map->size) / (float)(map->capacity));
}

void hashMapPrint(HashMap* map) {
	int isEmpty = 1;
	int i;
	for (i = 0; i < map->capacity; i++) {
		if (map->table[i] != NULL) {
			printf("--- BUCKET [%d] ---\n", i);
			isEmpty = 0;
			HashLink* curr = map->table[i];
			while (curr != NULL) {
				employeePrint(curr->value);
				curr = curr->next;
			}
		}
	}
	if (isEmpty) { printf("\n--Hash Table Empty--"); }
	printf("\n");
}

