/*
 * broken_tile.cpp
 *
 *  Created on: Jun 16, 2017
 *      Author: Selth Afrinon
 */

#include "broken_tile.h"

broken_tile::broken_tile(int x, int y){
	this->x = x;
	this->y = y;
	type = 3;
	cond = 0;
	visual = "_";
}


