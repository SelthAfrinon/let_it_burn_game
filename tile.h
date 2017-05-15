/*
 * tile.h
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#ifndef TILE_H_
#define TILE_H_

#include "coord.h"

class tile{
private:
	/*  S = 0	(Smoke)
		F = 1	(Fire)
		# = 2	(wall)
		| = 3	(closed door)
		/ = 4	(open door)
		'=' = 5	(damaged wall)
		_ = 6	(broken wall/door)
		' ' = 7 (open)
	*/
	int cond,x,y;
	bool mask, exit;
public:
	tile(coord*);
	tile(int, int);
	tile(coord*, bool, bool);
	tile(int, int, bool, bool);
	void apply_smoke();
	void apply_fp(int);
	coord* get_coord();
	int get_x();
	int get_y();
	int get_cond();
	bool has_mask();
	void rem_mask();
	void make_exit();
	bool is_exit();
	~tile() {}
};

#endif /* TILE_H_ */
