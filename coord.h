/*
 * coord.h
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#ifndef COORD_H_
#define COORD_H_

#include <iostream>

class coord{
private:
	int x;
	int y;

public:
	coord();
	coord(int, int);
	int get_x();
	int get_y();
	void print_coord();
	~coord();
};

#endif /* COORD_H_ */
