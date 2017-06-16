/*
 * tile.h
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#ifndef TILE_H_
#define TILE_H_

#include "i_tile.h"
#include <string>

class tile : public i_tile{
private:
	int cond, type, x, y;
	std::string visual;


public:
	// initializers set up tile location.
	tile();
	int get_x();
	int get_y();
	int get_cond();
	int get_type();
	std::string get_visual();
	i_tile* activate(int);

	~tile() {}
};

#endif /* TILE_H_ */
