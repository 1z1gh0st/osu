#include "bear.h"

using std::cout;
using std::string;

/********************************************************************* 
 ** Function: Bear() 
 ** Description: Contsructor for bear
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should initialize bear animal
 *********************************************************************/ 
Bear::Bear() {
    cost = 5000;
    monthly_revenue = cost / 10;
    birth_rate = 2;  
    animal_type = "Bear";
}