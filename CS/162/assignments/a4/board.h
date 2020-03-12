#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "room.h"
#include "interactive_obj.h"

using std::vector;
using std::string;

class Board {
    private:
        vector<vector<Room>> array;
        int size;
        bool debug_mode;
        InteractiveObject player;
        Point rope;
        int arrows;
    public:
        Board(int, bool);
        Point pick_random_room();

        void swap_rooms(Point, Point);
        void print_board();

        void add_event(string);
        void turn();

        InteractiveObject get_player();

        void player_shoots_arrow();
        void fire_arrow(string);
};

#endif