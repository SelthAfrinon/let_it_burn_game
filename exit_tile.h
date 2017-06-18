/*
 * exit_tile.h
 *
 *  Created on: Jun 17, 2017
 *      Author: Selth Afrinon
 */

#ifndef EXIT_TILE_H_
#define EXIT_TILE_H_

#include "tile.h"

class exit_tile : public tile{
public:
	exit_tile(int, int);
	exit_tile(int, int, bool);
	i_tile* activate(int);
};



#endif /* EXIT_TILE_H_ */
