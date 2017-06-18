/*
 * door_tile.cpp
 *
 *  Created on: Jun 17, 2017
 *      Author: Selth Afrinon
 */

#include "door_tile.h"

door_tile::door_tile(int x, int y){
	this->x = x;
	this->y = y;
	cond = 0;
	type = 4;
	visual = "|";
}

door_tile::door_tile(int x, int y, bool open){
	this->x = x;
	this->y = y;
	cond = open;
	if(open){
		visual = "/";
	}else{
		visual = "|";
	}
	type = 4;
}

i_tile* door_tile::activate(int action){
	switch(action){
	case 0:
		if(cond == 0){
			cond = 1;
		}
		break;
	case 1:
		return new broken_tile(x, y);
	}
	return NULL;
}
