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
#include <stdio.h> // for std::sprintf

#include "map.h"
#include "coord_set.h"
#include "player.h"

class game{
private:
	int max_x, max_y, turn_count;
	map board;
	player user;

	// Tile Evaluators
	void 	eval_tile(coord*, bool);
	void 	eval_set(coord_set*, bool);


public:
	// Constructors
	game(int, int);

	// Setters
	void 	set_tile_mask(int, int);
	void 	set_tile_exit(int, int);
	void 	set_tile_user(int, int);

	// Manipulators
	void 	fill_tile(int, int, int);
	void 	smoke_tile(int, int);
	void 	smoke_all();
	int 	move_player(std::string);
	std::string 	print_map();

	// Destructor
	~game() {}
};

#endif /* GAME_H_ */
