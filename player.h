/*
 * player.h
 *
 *  Created on: May 9, 2017
 *      Author: Selth Afrinon
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class player{
private:
	int pos_x, pos_y;
	bool mask;

public:
	player(int, int);
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	int get_x();
	int get_y();
	void get_mask();
	bool has_mask();
	~player() {}

};



#endif /* PLAYER_H_ */
