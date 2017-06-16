/*
 * tile.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#include "tile.h"

// constructors
tile::tile(){
	x = 0;
	y = 0;
	cond = 0;
	type = 0;
	visual = "";
}

// functions to get information on the tile

int tile::get_x(){
	return x;
}

int tile::get_y(){
	return y;
}

int tile::get_cond(){
	return cond;
}

int tile::get_type(){
	return type;
}

std::string tile::get_visual(){
	return visual;
}

i_tile* tile::activate(int){
	return NULL;
}