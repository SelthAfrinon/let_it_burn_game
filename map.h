/*
 * map.h
 *
 *  Created on: Apr 23, 2017
 *      Author: Selth Afrinon
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include "i_tile.h"
#include "tile.h"

class map{
private:
	int max_x, max_y;
	std::vector<i_tile*> tiles;

	i_tile* 	find_tile(int, int);

public:
	// constructors
	map();
	map(int, int);

	// manipulators
	void 	add_tile(i_tile*);

	// getters
	i_tile*	get_tile(int, int);
	int 	get_cond(int,int);
	int 	get_size();

	// deconstructor
	~map() {}

};

#endif /* MAP_H_ */
