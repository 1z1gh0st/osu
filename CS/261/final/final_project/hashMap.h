#ifndef HASH_MAP_H
#define HASH_MAP_H 1

#define HASH_FUNCTION hashFunction1
#define MAX_TABLE_LOAD 1

#include <stdio.h>

typedef struct HashMap HashMap;
typedef struct HashLink HashLink;
typedef struct Employee Employee;
typedef struct Date Date;

struct Date {
	int month;
	int day;
	int year;
};

struct Employee {
	char* first_name;
	char* last_name;
	char* id;
	Date date_started;
	int currently_employed;
};

struct HashLink {
    char* key;
    Employee* value;
    HashLink* next;
};

struct HashMap {
    HashLink** table;	
    int size;			
	int capacity;		
};

void employeeDelete(Employee* e);
void employeePrint(Employee e);
HashMap* hashMapNew(int capacity);
void hashMapDelete(HashMap* map);
Employee* hashMapGet(HashMap* map, const char* key);
void hashMapPut(HashMap* map, const char* key, Employee* value);
void hashMapRemove(HashMap* map, const char* key);
int hashMapContainsKey(HashMap* map, const char* key);

int hashMapSize(HashMap* map);
int hashMapCapacity(HashMap* map);
int hashMapEmptyBuckets(HashMap* map);
float hashMapTableLoad(HashMap* map);
void hashMapPrint(HashMap* map);
void hashMapWrite(HashMap* map, FILE* file);

#endif

