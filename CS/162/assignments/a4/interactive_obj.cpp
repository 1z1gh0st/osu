#include "interactive_obj.h"

using std::string;
using std::cout;
using std::endl;
using std::invalid_argument;

InteractiveObject::InteractiveObject() {
    dead = false;
    gold = false;
    skip_turn = false;
}

InteractiveObject::InteractiveObject(string n, Point p, int s) {
    dead = false;
    gold = false;
    name = n;
    pos = p;
    board_size = s;
    skip_turn = false;
}

void InteractiveObject::move_obj(string direction) {
    if (direction == "up") {
        Point temp = Point(pos.get_x() - 1, pos.get_y());
        if (temp.in_range(board_size, board_size)) {
            pos = temp;
        }
    } else if (direction == "down") {
        Point temp = Point(pos.get_x() + 1, pos.get_y());
        if (temp.in_range(board_size, board_size)) {
            pos = temp;
        }
    } else if (direction == "left") {
        Point temp = Point(pos.get_x(), pos.get_y() - 1);
        if (temp.in_range(board_size, board_size)) {
            pos = temp;
        }
    } else if (direction == "right") {
        Point temp = Point(pos.get_x(), pos.get_y() + 1);
        if (temp.in_range(board_size, board_size)) {
            pos = temp;
        }
    } else {
        throw invalid_argument(direction + " is not a valid direction. Please pass in 'up', 'down', 'left', or 'right'."); 
    }
}

string InteractiveObject::get_name() {
    return name;
}

Point InteractiveObject::get_pos() {
    return pos;
}

void InteractiveObject::die() {
    dead = true;
}

void InteractiveObject::give_gold() {
    gold = true;
}

void InteractiveObject::player_move() {
    move_obj(get_direction_input());
}

string InteractiveObject::get_direction_input() {
    cout << "input a direction, w, a, s, or d";
    char in = InputHandler::get_wasd();
    if (in == 'w') { return "up"; }
    else if (in == 'a') { return "left"; }
    else if (in == 's') { return "down"; }
    else { return "right"; }
}

bool InteractiveObject::has_gold() {
    return gold;
}

bool InteractiveObject::is_dead() {
    return dead;
}

void InteractiveObject::move_rand() {
    pos = Point(rand() % board_size, rand() % board_size);
}

void InteractiveObject::change_skip_turn() {
    skip_turn = !skip_turn;
}

bool InteractiveObject::is_skip_turn() {
    return skip_turn;
}