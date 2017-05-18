/*
 * player.cpp
 *
 *  Created on: May 9, 2017
 *      Author: Selth Afrinon
 */

#include "player.h"

// constructors

player::player(int x, int y){
	this->x = x;
	this->y = y;
	mask = false;
}

// setters

void player::set_x(int x){
	this->x = x;
}

void player::set_y(int y){
	this->y = y;
}

// manipulators

void player::move_up(){
	y++;
}

void player::move_down(){
	y--;
}

void player::move_left(){
	x--;
}

void player::move_right(){
	x++;
}

void player::give_mask(){
	mask = true;
}

// getters

int player::get_x(){
	return x;
}

int player::get_y(){
	return y;
}

bool player::get_mask(){
	return mask;
}


