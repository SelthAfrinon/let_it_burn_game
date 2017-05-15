/*
 * map.h
 *
 *  Created on: Apr 23, 2017
 *      Author: Selth Afrinon
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include "tile.h"

class map{
private:
	int max_x, max_y;
	std::vector<tile*> tiles;
	tile* find_tile(int, int);

public:
	map();
	map(int, int);
	void add_tile(tile*);
	tile* get_tile(coord*);
	tile* get_tile(int, int);
	int get_cond(int,int);
	int get_size();
	~map() {}

};

#endif /* MAP_H_ */
