/*
 * game.h
 *
 *  Created on: Apr 24, 2017
 *      Author: Selth Afrinon
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <stdio.h> // for std::sprintf

#include "map.h"
#include "player.h"
#include "tile_set.h"

class game{
private:
	int max_x, max_y, turn_count;
	map board;
	player user;

	// Tile Evaluators
	void 	eval_tile(tile*, bool);
	void 	eval_set(tile_set*, bool);


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
	void	inc_turn();
	std::string 	print_map();

	// Destructor
	~game() {}
};

#endif /* GAME_H_ */
