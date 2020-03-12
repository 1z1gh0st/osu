#include "sea_lion.h"

using std::cout;

/********************************************************************* 
 ** Function: Sea_Lion() 
 ** Description: Contsructor for sea lion
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should initialize sea lion animal
 *********************************************************************/ 
Sea_Lion::Sea_Lion() {
    cost = 700;
    monthly_revenue = cost / 5;
    birth_rate = 1;
    animal_type = "Sea_Lion";
}