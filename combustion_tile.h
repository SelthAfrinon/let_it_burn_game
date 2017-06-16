/*
 * smoke_tile.h
 *
 *  Created on: Jun 2, 2017
 *      Author: Selth Afrinon
 */

#ifndef COMBUSTION_TILE_H_
#define COMBUSTION_TILE_H_

#include "tile.h"

class combustion_tile : public tile{
public:
	combustion_tile(int, int);
	i_tile* activate(int);
};

#endif /* COMBUSTION_TILE_H_ */
