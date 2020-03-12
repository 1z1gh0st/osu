#include "tiger.h"

/********************************************************************* 
 ** Function: Tiger() 
 ** Description: Contsructor for tiger
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should initialize tiger animal
 *********************************************************************/ 
Tiger::Tiger() {
    cost = 12000;
    monthly_revenue = cost / 10;
    birth_rate = 3;  
    animal_type = "Tiger";
}
