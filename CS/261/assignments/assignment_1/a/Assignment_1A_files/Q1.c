/* CS261- Assignment 1A - Question 1
   Name: Philip Warton
   Date: 06/22/2020
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	struct student* result = (struct student*) malloc(10 * sizeof(struct student));     
	return result;
}

void generate(struct student* students) {
	srand(time(NULL));
	int i;
	for (i = 0; i < 10; i++) {
		students[i].id = (rand() % 10) + 1;
		students[i].score = rand() % 101;
	}
}

void output(struct student* students) {
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students) {
	int min = 100, max = 0, i, total = 0;
	float average;
	for (i = 0; i < 10; i++) {
		int score = students[i].score;
		if (score < min) { min = score; }
		else if (score > max) { max = score; }
		total += score;
	}
	average = (float)total / 10.0;
	printf("MIN: %d\nMAX: %d\nAVG: %f\n", min, max, average);
}

void deallocate(struct student* stud) {
	free(stud);
}

int main() {
    struct student* stud = NULL;
	stud = allocate();    
	generate(stud);
	output(stud);
   	summary(stud); 
	deallocate(stud);
    return 0;
}

