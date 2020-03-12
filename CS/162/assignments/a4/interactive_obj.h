#ifndef INTERACTIVE_OBJ_H
#define INTERACTIVE_OBJ_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include "point.h"
#include "input_handler.h"

using std::string;

class InteractiveObject {
    private:
        string name;
        Point pos;
        int board_size;
        bool gold;
        bool dead;
        bool skip_turn;
    public:
        InteractiveObject();
        InteractiveObject(string, Point, int);
        void move_obj(string);
        string get_name();
        Point get_pos();
        void die();
        void give_gold();
        void player_move();
        string get_direction_input();
        bool has_gold();
        bool is_dead();
        void move_rand();
        void change_skip_turn();
        bool is_skip_turn();
};

#endif