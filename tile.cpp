/*
 * tile.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#include "tile.h"

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

tile::tile(coord* in_pos, bool in_mask, bool is_exit){
	x = in_pos->get_x();
	y = in_pos->get_y();
	cond = 7;
	mask = in_mask;
	exit = is_exit;
}

tile::tile(int in_x, int in_y, bool in_mask, bool is_exit){
	x = in_x;
	y = in_y;
	cond = 7;
	mask = in_mask;
	exit = is_exit;
}

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

void tile::set_mask(bool in){
	mask = in;
}

bool tile::has_mask(){
	return mask;
}

void tile::make_exit(){
	exit = true;
}

bool tile::is_exit(){
	return exit;
}
