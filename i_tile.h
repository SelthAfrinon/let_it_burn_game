/*
 * i_tile.h
 *
 *  Created on: Jun 2, 2017
 *      Author: Selth Afrinon
 */

#ifndef I_TILE_H_
#define I_TILE_H_

#include <string>

class i_tile{
public:
	// Accessors
	virtual std::string get_visual() = 0;
	virtual int get_cond() = 0;
	virtual int get_type() = 0;
	virtual int get_x() = 0;
	virtual int get_y() = 0;

	// Manipulators
	virtual i_tile* activate(int) = 0;

	virtual ~i_tile() {}

};

#endif /* I_TILE_H_ */
