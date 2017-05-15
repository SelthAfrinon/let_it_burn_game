/*
 * coord.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#include "coord.h"

coord::coord(){
	x = 0;
	y = 0;
}

coord::coord(int n_x,int n_y){
	x = n_x;
	y = n_y;
}

int coord::get_x(){
	return x;
}

int coord::get_y(){
	return y;
}

void coord::print_coord(){
	std::cout << "(" << x << "," << y << ")";
}
