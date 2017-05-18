/*
 * coord.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#include "coord.h"

// initializers
coord::coord(){
	x = 0;
	y = 0;
}

coord::coord(int x,int y){
	this->x = x;
	this->y = y;
}

// getters
int coord::get_x(){
	return x;
}

int coord::get_y(){
	return y;
}
