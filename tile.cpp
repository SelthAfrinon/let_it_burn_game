/*
 * tile.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#include "tile.h"

// initializers
tile::tile(coord* in_pos){
	x = in_pos->get_x();
	y = in_pos->get_y();
	cond = 7;
	mask = false;
	exit = false;
}

tile::tile(int in_x, int in_y){
	x = in_x;
	y = in_y;
	cond = 7;
	mask = false;
	exit = false;
}

// functions to change tile behavior
void tile::apply_smoke(){
	if(cond == 7){
		cond = 0;
	}else if(cond == 0){
		cond = 1;
	}else if(cond == 1){
		cond = 8;
	}
}

void tile::apply_fp(int type){
		cond = type;
}

void tile::set_mask(bool in){
	mask = in;
}

void tile::make_exit(){
	exit = true;
}

// functions to get information on the tile
coord* tile::get_coord(){
	return new coord(x,y);
}

int tile::get_x(){
	return x;
}

int tile::get_y(){
	return y;
}

int tile::get_cond(){
	return cond;
}

bool tile::get_mask(){
	return mask;
}

bool tile::get_exit(){
	return exit;
}
