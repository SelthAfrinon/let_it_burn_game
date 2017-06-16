/*
 * wall_tile.cpp
 *
 *  Created on: Jun 16, 2017
 *      Author: Selth Afrinon
 */

#include "wall_tile.h"

wall_tile::wall_tile(int x, int y){
	this->x = x;
	this->y = y;
	type = 2;
	cond = 0;
}

i_tile* wall_tile::activate(int action){
	switch(action){
	case 0:
		if(cond ==0){
			cond = 1;
		}else if(cond == 1){
			return new broken_tile(x,y);
		}
		break;
	}
	return NULL;
}
