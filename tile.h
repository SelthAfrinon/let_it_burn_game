/*
 * tile.h
 *
 *  Created on: Apr 22, 2017
 *      Author: Selth Afrinon
 */

#ifndef TILE_H_
#define TILE_H_

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
	// initializers set up tile location.
	tile();
	tile(int, int);

	// setters to set smoke, general floorplan pieces, mask status, and exit status.
	void apply_smoke();
	void apply_fp(int);
	void set_mask(bool);
	void make_exit();

	// gettter functions to get information of tile.
	int get_x();
	int get_y();
	int get_cond();
	bool get_exit();
	bool get_mask();

	~tile() {}
};

#endif /* TILE_H_ */
