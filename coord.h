/*
 * coord.h
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#ifndef COORD_H_
#define COORD_H_

class coord{
private:
	int x;
	int y;

public:
	// initializers
	coord();
	coord(int, int);

	// getters
	int get_x();
	int get_y();
	~coord();
};

#endif /* COORD_H_ */
