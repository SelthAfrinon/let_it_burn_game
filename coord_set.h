/*
 * coord_set.h
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#ifndef COORD_SET_H_
#define COORD_SET_H_

#include <vector>
#include "coord.h"

class coord_set{
private:
	std::vector<coord*> set;
public:
	// initializers
	coord_set();

	// manipulators
	void add_coord(coord*);

	// getters
	coord* get_coord(int);
	int get_size();
	bool get_empty();
	~coord_set();
};

#endif /* COORD_SET_H_ */
