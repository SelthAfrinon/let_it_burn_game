/*
 * wall_tile.h
 *
 *  Created on: Jun 16, 2017
 *      Author: Selth Afrinon
 */

#ifndef WALL_TILE_H_
#define WALL_TILE_H_

#include "tile.h"
#include "broken_tile.h"

class wall_tile : public tile{
public:
	wall_tile(int, int);
	i_tile* activate(int);

};



#endif /* WALL_TILE_H_ */
