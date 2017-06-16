/*
 * combustion_tile.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: Selth Afrinon
 */

#include "combustion_tile.h"

combustion_tile::combustion_tile(int x, int y){
	this->x = x;
	this->y = y;
	cond = 0;
	type = 1;
}

i_tile* combustion_tile::activate(int action){
	switch(action){
	case 0:
		cond = 1;
		break;
	}
	return NULL;

}

