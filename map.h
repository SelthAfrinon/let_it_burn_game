/*
 * map.h
 *
 *  Created on: Apr 23, 2017
 *      Author: Selth Afrinon
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>
//#include "tile.h"

class map{
private:
	int max_x, max_y;
	std::vector<tile> tiles;

	tile* 	find_tile(int, int);

public:
	// constructors
	map();
	map(int, int);

	// manipulators
	void 	add_tile(tile*);

	// getters
	tile*	get_tile(int, int);
	int 	get_cond(int,int);
	int 	get_size();

	// deconstructor
	~map() {}

};

#endif /* MAP_H_ */
