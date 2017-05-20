/*
 * tile_set.cpp
 *
 *  Created on: May 20, 2017
 *      Author: Selth Afrinon
 */

#include "tile_set.h"

// Constructors

tile_set::tile_set() : tile_pointers(0){

}

// Mutators

void tile_set::add_tile(tile* in){
	tile_pointers.push_back(in);
}

// Getters

tile* tile_set::get_tile(int index){
	return tile_pointers.at(index);
}

int tile_set::get_size(){
	return tile_pointers.size();
}
