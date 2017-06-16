/*
 * open_tile.h
 *
 *  Created on: Jun 2, 2017
 *      Author: Selth Afrinon
 */

#ifndef OPEN_TILE_H_
#define OPEN_TILE_H_

#include "combustion_tile.h"
#include "tile.h"

class open_tile : public tile{
public:
	open_tile(int, int);
	i_tile* activate(int);
};



#endif /* OPEN_TILE_H_ */
