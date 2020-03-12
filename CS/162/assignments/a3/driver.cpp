/******************************************************
** Program: Zoo Tycoon
** Author: Philip Warton
** Date: 02/14/2020
** Description: Zoo game
** Input: numbers in console
** Output: Zoo gameplay in console
******************************************************/

#include "tiger.h"
#include "animal.h"
#include "bear.h"
#include "sea_lion.h"
#include "zoo.h"

using namespace std;

int main() {
    Zoo zoo;
    bool continue_game = true;
    while (zoo.get_money() > 0 && continue_game) {
        zoo.iterate_month();
        cout << "Do you want to keep playing?" << endl;
        cout << "    0. No" << endl;
        cout << "    1. Yes" << endl;
        cout << ">> ";
        continue_game = InputHandler::get_input_between(0, 1);
    }
    return 0;
}
