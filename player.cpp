/*
 * player.cpp
 *
 *  Created on: May 9, 2017
 *      Author: Selth Afrinon
 */

#include "player.h"

player::player(int start_x, int start_y){
	pos_x = start_x;
	pos_y = start_y;
	mask = false;
}

int player::get_x(){
	return pos_x;
}

int player::get_y(){
	return pos_y;
}

void player::move_up(){
	pos_y++;
}

void player::move_down(){
	pos_y--;
}

void player::move_left(){
	pos_x--;
}

void player::move_right(){
	pos_x++;
}

void player::get_mask(){
	mask = true;
}

bool player::has_mask(){
	return mask;
}


