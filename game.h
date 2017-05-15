/*
 * game.h
 *
 *  Created on: Apr 24, 2017
 *      Author: Selth Afrinon
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include "map.h"
#include "coord_set.h"
#include "player.h"

class game{
private:
	map board;
	int max_x, max_y, turn_count;
	player user;
	void eval_set(coord_set*);
	void eval_set(coord_set*, bool);

public:
	game(int, int);
	game(int, int, int, int);
	void fill_tile(int, int, int);
	void smoke_tile(int, int);
	void smoke_all();
	void eval_tile(int, int, coord*, bool);
	bool move_player(std::string);
	void print_map();
	~game();
};

#endif /* GAME_H_ */
