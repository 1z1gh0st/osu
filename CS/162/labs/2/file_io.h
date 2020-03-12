#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

struct student {
	int id;
	string fname;
	string lname;
	string major;
};

student* create_student_db(int);
void get_student_db_info(student *, int, fstream &);
void delete_student_db_info(student **, int);
void sort_id(student *, int);
void sort_lname(student *, int);
