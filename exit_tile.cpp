/*
 * exit_tile.cpp
 *
 *  Created on: Jun 17, 2017
 *      Author: Selth Afrinon
 */

#include "exit_tile.h"

exit_tile::exit_tile(int x, int y){
	this->x = x;
	this->y = y;
	type = 5;
	cond = 1;
	visual = "E";
}

exit_tile::exit_tile(int x, int y, bool open){
	this->x = x;
	this->y = y;
	type = 5;
	if(open){
		cond = 1;
		visual = "E";
	}else{
		cond = 0;
		visual = "X";
	}
}

i_tile* exit_tile::activate(int action){
	switch(action){
	case 0:
		if(cond == 0){
			cond = 1;
		}else if(cond == 1){
			cond = 0;
		}
	}
	return NULL;
}
