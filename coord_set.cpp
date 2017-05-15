/*
 * coord_set.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#include "coord_set.h"
#include <iostream>

coord_set::coord_set():set(0){

}

void coord_set::add_coord(coord* in){
	set.push_back(in);
}

coord* coord_set::get_coord(int get){
	return set.at(get);
}

int coord_set::get_size(){
	return set.size();
}

bool coord_set::is_empty(){
	return set.empty();
}
