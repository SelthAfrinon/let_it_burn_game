/*
 * map.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: Selth Afrinon
 */

#include "map.h"

map::map(){
	max_x = 0;
	max_y = 0;
	tiles.resize(0);
}

map::map(int in_x, int in_y){
	max_x = in_x;
	max_y = in_y;
	tiles.resize(in_x*in_y);
	for(int i = 0; i < max_y; i++){
		for(int j = 0; j < max_x; j++){
			tiles.at(i*max_x + j) = new tile(j,i);
		}
	}
}

int map::get_size(){
	return tiles.size();
}

void map::add_tile(tile* in){
	if ((in->get_coord()->get_y() < max_y) & (in->get_coord()->get_x() < max_x)){
		int pos = (in->get_coord()->get_y())*max_x + (in->get_coord()->get_y());
		tiles.at(pos) = in;
	}else{
		// out of map bounds
	}
}

tile* map::get_tile(coord* get){
	int pos = get->get_y()*max_x + get->get_x();
	if((tiles.at(pos)->get_x() == get->get_x()) & (tiles.at(pos)->get_y() == get->get_y())){
		return tiles.at(pos);
	}else{
		return find_tile(get->get_x(), get->get_y());
	}
}

tile* map::get_tile(int x, int y){
	int pos = (y)*max_x + x;
	if((tiles.at(pos)->get_x() == x) & (tiles.at(pos)->get_y() == y)){
		return tiles.at(pos);
	}else{
		return find_tile(x, y);
	}
}

int map::get_cond(int x, int y){
	int pos = (y)*max_x + x;
		if((tiles.at(pos)->get_x() == x) & (tiles.at(pos)->get_y() == y)){
			return tiles.at(pos)->get_cond();
		}else{
			return find_tile(x, y)->get_cond();
		}
}

tile* map::find_tile(int x, int y){
	for(int i = 0; i < (int)tiles.size(); i++){
		if((tiles.at(i)->get_x() == x) & (tiles.at(i)->get_y() == y)){
			return tiles.at(i);
		}
	}
	//std::cout << "Problem in \"find_tile\": tile does not exist.\n";
	return 0;
}
