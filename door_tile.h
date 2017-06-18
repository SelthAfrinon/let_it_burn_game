/*
 * door_tile.h
 *
 *  Created on: Jun 17, 2017
 *      Author: Selth Afrinon
 */

#ifndef DOOR_TILE_H_
#define DOOR_TILE_H_

#include "tile.h"
#include "broken_tile.h"

class door_tile : public tile{
public:
	door_tile(int, int);
	door_tile(int, int, bool);
	i_tile* activate(int);

};

#endif /* DOOR_TILE_H_ */
