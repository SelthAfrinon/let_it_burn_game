/*
 * open_tile.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: Selth Afrinon
 */

#include "open_tile.h"

open_tile::open_tile(int x, int y){
	this->x = x;
	this->y = y;
	type = 0;
	cond = 0;
}

i_tile* open_tile::activate(int action){
	return new combustion_tile(x,y);
}

