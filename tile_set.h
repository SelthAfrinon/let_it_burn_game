/*
 * tile_set.h
 *
 *  Created on: May 20, 2017
 *      Author: Selth Afrinon
 */

#ifndef TILE_SET_H_
#define TILE_SET_H_

#include <vector>

#include "tile.h"

class tile_set{
private:
	std::vector<tile*> tile_pointers;

public:
	// Constructors
	tile_set();

	// Mutators
	void	add_tile(tile*);

	// Getters
	tile* 	get_tile(int);
	int		get_size();

	// Destructors
	~tile_set() {}


};

#endif /* TILE_SET_H_ */
